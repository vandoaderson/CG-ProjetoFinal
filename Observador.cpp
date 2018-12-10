#include "Observador.h"
#include "Matriz.h"
#include <cmath>
#include <iostream>
#include <QtConcurrent>
using namespace std;

Observador::Observador(Vertice *pos, Vertice *lookAt, Vertice *viewUp, int Nx, int Ny, float w, float h, float dist){
    this->posicao = pos;
    this->Nx = Nx;
    this->lookAt = lookAt;
    this->viewUp = viewUp;
    this->Ny = Ny;
    this->w = w;
    this->h = h;
    distancia = dist;



    cores = new Vertice**[Nx];
    for( int i=0; i<Nx; i++ ){
        cores[i] = new Vertice*[Ny];
    }
}
void Observador::calcularIJK(){
    K = posicao->diferencaVetorial(lookAt);
    K->normalizar();
    //cout << K->x << " " << K->y << " " << K->z << endl;

    viewUp = viewUp->diferencaVetorial(posicao);
    I = viewUp->produtoVetorial(K);
    //cout << I->x << " " << I->y << " " << I->z << endl;
    I->normalizar();
    //cout << I->x << " " << I->y << " " << I->z << endl;

    J = K->produtoVetorial(I);

    Tcm[0][0] = I->x; Tcm[0][1] = J->x; Tcm[0][2] = K->x; Tcm[0][3] = posicao->x;
    Tcm[1][0] = I->y; Tcm[1][1] = J->y; Tcm[1][2] = K->y; Tcm[1][3] = posicao->y;
    Tcm[2][0] = I->z; Tcm[2][1] = J->z; Tcm[2][2] = K->z; Tcm[2][3] = posicao->z;
    Tcm[3][0] = 0;    Tcm[3][1] = 0;    Tcm[3][2] = 0;    Tcm[3][3] = 1;

    Tmc[0][0] = I->x; Tmc[0][1] = I->y; Tmc[0][2] = I->z; Tmc[0][3] = -posicao->produtoEscalar(I);
    Tmc[1][0] = J->x; Tmc[1][1] = J->y; Tmc[1][2] = J->z; Tmc[1][3] = -posicao->produtoEscalar(J);
    Tmc[2][0] = K->x; Tmc[2][1] = K->y; Tmc[2][2] = K->z; Tmc[2][3] = -posicao->produtoEscalar(K);
    Tmc[3][0] = 0;    Tmc[3][1] = 0;    Tmc[3][2] = 0;    Tmc[3][3] = 1;

}

void Observador::mundoCamera(Cenario *c){
    int i, j,n,m;
    float *w;
    float u[4];

    n = c->listaObjetos.size();
    for( i=0; i<n; i++){
        Objeto* o = c->listaObjetos[i];
        m = o->listaVertices.size();
        for( j=0; j<m; j++ ){
            Vertice* v = o->listaVertices[j];
            u[0] = v->x;
            u[1] = v->y;
            u[2] = v->z;
            u[3] = 1;

            w = multiplicarVetorPorMatriz(Tmc, u);
            v->x = w[0];
            v->y = w[1];
            v->z = w[2];
        }
    }

    u[0] = c->FL->posicao->x; u[1] = c->FL->posicao->y; u[2] = c->FL->posicao->z; u[3] = 1;
    w = multiplicarVetorPorMatriz(Tmc, u);
    c->FL->posicao->x = w[0]; c->FL->posicao->y = w[1]; c->FL->posicao->z = w[2];

    posicao->x = 0;
    posicao->y = 0;
    posicao->z = 0;
}

void Observador::cameraMundo(Cenario *c){
    int i, j,n,m;
    float *w;
    float u[4];

    n = c->listaObjetos.size();
    for( i=0; i<n; i++){
        Objeto* o = c->listaObjetos[i];
        m = o->listaVertices.size();
        for( j=0; j<m; j++ ){
            Vertice* v = o->listaVertices[j];
            u[0] = v->x;
            u[1] = v->y;
            u[2] = v->z;
            u[3] = 1;

            w = multiplicarVetorPorMatriz(Tcm, u);
            v->x = w[0];
            v->y = w[1];
            v->z = w[2];
        }
    }

    u[0] = c->FL->posicao->x; u[1] = c->FL->posicao->y; u[2] = c->FL->posicao->z; u[3] = 1;
    w = multiplicarVetorPorMatriz(Tcm, u);
    c->FL->posicao->x = w[0]; c->FL->posicao->y = w[1]; c->FL->posicao->z = w[2];

    u[0] = 0;
    u[1] = 0;
    u[2] = 0;
    u[3] = 1;
    w = multiplicarVetorPorMatriz(Tcm, u);
    posicao->x = w[0];
    posicao->y = w[1];
    posicao->z = w[2];
}

void Observador::rayCasting(Cenario *c){
    int i, j, k, l, m;
    int n = c->listaObjetos.size();

    for( i=0; i<Nx; i++ ){
        for( j=0; j<Ny; j++ ){
            Vertice* pix = new Vertice(-w/2 + (w/Nx)/2 + j*(w/Nx), h/2 - (h/Ny)/2 - i*(h/Ny), -distancia );
            Face* f = nullptr;
            float t = 99999;

            for( k=0; k<n; k++ ){
                m = c->listaObjetos[k]->listaFace.size();
                for( l=0; l<m; l++ ){
                    Vertice* n = c->listaObjetos[k]->listaFace[l]->calcularNormal();

                    if( n->produtoEscalar(pix) < 0 ){
                        float tt = c->listaObjetos[k]->listaFace[l]->intersecao(pix);
                        //cout << "teste" << endl;
                        if( tt < t ){
                            t = tt;
                            f = c->listaObjetos[k]->listaFace[l];
                        }
                    }
                }
            }
            if( t<99999 )
                calcularCor(pix->produtoPorEscalar(t), f, i, j, c->FL);
            else
                cores[i][j] = new Vertice(0.2, 0.2, 0.2);
        }
    }

    normalizaCores();

}

void Observador::normalizaCores(){
    int i, j;
    float m;

    m = cores[0][0]->x;
    for( i=0; i<Nx; i++ ){
        for( j=0; j<Ny; j++ ){
            if( cores[i][j]->x > m)
                m = cores[i][j]->x;
            if( cores[i][j]->y > m)
                m = cores[i][j]->y;
            if( cores[i][j]->z > m)
                m = cores[i][j]->z;
        }
    }

    if( m>1 ){
        for( i=0; i<Nx; i++ ){
            for( j=0; j<Ny; j++ ){
                cores[i][j]->x /= m;
                cores[i][j]->y /= m;
                cores[i][j]->z /= m;
            }
        }
    }
}

void Observador::calcularCor(Vertice *PI, Face *f, int i, int j, FonteLuminosa *fl){
    Vertice* n = f->calcularNormal();

    Vertice* v = PI->produtoPorEscalar(-1);
    v->normalizar();

    Vertice* l = fl->posicao->diferencaVetorial(PI);
    l->normalizar();

    float t = 2*l->produtoEscalar(n);
    Vertice* r = n->produtoPorEscalar(t);
    r = r->diferencaVetorial(l);
    r->normalizar();

    Vertice* amb = fl->Ia->produtoCorrespondente(f->mat->Ka);

    Vertice* dif;
    if( n->produtoEscalar(l) < 0 )
        dif = new Vertice(0, 0, 0);
    else{
        float p = n->produtoEscalar(l);
        dif = fl->Id->produtoCorrespondente(f->mat->Kd);
        dif = dif->produtoPorEscalar(p);
    }

    Vertice* esp;
    if( r->produtoEscalar(v) < 0 )
        esp = new Vertice(0,0,0);
    else{
        float p = r->produtoEscalar(v);
        p = pow(p, f->mat->m);
        esp = fl->Is->produtoCorrespondente(f->mat->Ks);
        esp = esp->produtoPorEscalar(p);
    }

    amb = amb->somaVetorial(dif);
    cores[i][j] = amb->somaVetorial(esp);
}

void Observador::resetCores(){
    /*for(int i = 0; i < Nx; cores++){
        for(int j = 0; j < Ny; j++){
            delete cores[i][j];
        }
    }
    delete cores;*/

    cores = new Vertice**[Nx];
    for( int i=0; i<Nx; i++ ){
        cores[i] = new Vertice*[Ny];
    }
}

void Observador::freeMemory(){
    delete posicao;
    delete lookAt;
    delete viewUp;

    delete I;
    delete J;
    delete K;

    delete Tcm;
    delete Tmc;

    for(int i = 0; i < Nx; cores++){
        for(int j = 0; j < Ny; j++){
            delete cores[i][j];
        }
    }
    delete cores;
}
