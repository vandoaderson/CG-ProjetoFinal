#ifndef OBSERVADOR_H
#define OBSERVADOR_H

#include "Vertice.h"
#include "Cenario.h"

class Observador{
public:
    Observador(Vertice* pos, Vertice* lookAt, Vertice* viewUp, int Nx, int Ny, float w, float h, float dist);
    void calcularIJK();
    void mundoCamera(Cenario* c);
    void cameraMundo(Cenario* c);
    void rayCasting(Cenario* c);
    void normalizaCores();
    void calcularCor(Vertice* PI, Face* f, int i, int j, FonteLuminosa* fl);

    float distancia;
    Vertice* posicao;
    Vertice* lookAt;
    Vertice *viewUp;
    Vertice *I, *J, *K;
    float Tcm[4][4];
    float Tmc[4][4];
    int Nx, Ny;
    float w, h;
    Vertice*** cores;

    void resetCores();
    void freeMemory();
};

#endif // OBSERVADOR_H
