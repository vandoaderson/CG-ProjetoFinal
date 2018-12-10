#ifndef OBJETO_H
#define OBJETO_H

#include <vector>
#include "Vertice.h"
#include "Face.h"
using namespace std;

class Objeto{
public:
    Objeto();

    vector<Vertice*> listaVertices;
    vector<Face*> listaFace;

    void desenhar();

    void adicionarVertice(Vertice* v);
    void adicionarFace(Face* f);

    void transladar(Vertice* t);
    void escalar(Vertice* s);
    void rotacao(Vertice* eixo, float angulo);
    void rotacaoY(float angulo);
    void setFacesMaterialOpenGL(int type);
};

#endif // OBJETO_H
