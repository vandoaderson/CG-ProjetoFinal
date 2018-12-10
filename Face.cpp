#include "Face.h"
#include "SistemaLinear.h"
#include <iostream>
using namespace std;

Face::Face(Vertice *v1, Vertice *v2, Vertice *v3, Material *mat){
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    this->mat = mat;
}

Vertice *Face::calcularNormal(){
    Vertice* w1 = v2->diferencaVetorial(v1);
    Vertice* w2 = v3->diferencaVetorial(v1);

    Vertice* n = w1->produtoVetorial(w2);

    n->normalizar();

    return n;
}

float Face::intersecao(Vertice *u){
    Vertice* w1 = v1->diferencaVetorial(v2);
    Vertice* w2 = v1->diferencaVetorial(v3);

    float b[3] = {v1->x, v1->y, v1->z};
    float A[3][3] = {{u->x, w1->x, w2->x}, {u->y, w1->y, w2->y}, {u->z, w1->z, w2->z}};

    float* x = gauss(A, b);

    float c = 1-x[1]-x[2];
    if( x[1]>0 && x[2]>0 && c>0 ){
        //cout << "teste" << endl;
        return x[0];
    }

    return 99999;
}
