#include "Vertice.h"
#include "Matriz.h"
#include <cmath>
using namespace std;

Vertice::Vertice(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
    //this->w = 1.0;
}

Vertice *Vertice::somaVetorial(Vertice *v){
    Vertice* u = new Vertice( x + v->x, y + v->y, z + v->z );

    return u;
}

Vertice *Vertice::diferencaVetorial(Vertice *v){
    Vertice* u = new Vertice( x - v->x, y - v->y, z - v->z );

    return u;
}

float Vertice::produtoEscalar(Vertice *v){
    float s = x*v->x + y*v->y + z*v->z;

    return s;
}

Vertice *Vertice::produtoPorEscalar(float k){
    Vertice* u = new Vertice( k*x, k*y, k*z );

    return u;
}

Vertice *Vertice::produtoVetorial(Vertice *v){
    Vertice* u = new Vertice( y*v->z - z*v->y, z*v->x - x*v->z, x*v->y - y*v->x);

    return u;
}

Vertice *Vertice::produtoCorrespondente(Vertice *v){
    Vertice* u = new Vertice( x*v->x, y*v->y, z*v->z);

    return u;
}

float Vertice::norma()
{
    return sqrt(this->produtoEscalar(this));
}

void Vertice::normalizar()
{
    float n = norma();

    x = x/n;
    y = y/n;
    z = z/n;
}

void Vertice::transladar(Vertice *t){
    x = x + t->x;
    y = y + t->y;
    z = z + t->z;
}

void Vertice::escalar(Vertice *s){
    x = x * s->x;
    y = y * s->y;
    z = z * s->z;
}

void Vertice::rotacao(Vertice *eixo, float angulo){
    float w = cos(angulo/2);
    float s = sin(angulo/2);

    float x1 = eixo->x*s, y1 = eixo->y*s, z1 = eixo->z*s;

    float A[4][4] = {{w*w + x1*x1 - y1*y1 - z1*z1, 2*x1*y1 - 2*w*z1, 2*x1*z1 + 2*w*y1, 0},
                     {2*x1*y1 + 2*w*z1, w*w - x1*x1 + y1*y1 - z1*z1, 2*z1*y1 - 2*w*x1, 0},
                     {2*x1*z1 - 2*w*y1, 2*z1*y1 + 2*w*z1, w*w - x1*x1 - y1*y1 + z1*z1, 0},
                     {0, 0, 0, w*w + x1*x1 + y1*y1 + z1*z1}};
    float u[4] = {x, y, z ,1};
    float* v = multiplicarVetorPorMatriz(A, u);

    x = v[0];
    y = v[1];
    z = v[2];
}

void Vertice::rotacaoY(float angulo)
{
    z = (z*cos(angulo) - x*sin(angulo));
    x = (x*cos(angulo) + z*sin(angulo));
}
