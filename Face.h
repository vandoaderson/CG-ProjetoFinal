#ifndef FACE_H
#define FACE_H

#include "Vertice.h"
#include "Material.h"

class Face{
public:
    Face(Vertice* v1, Vertice* v2, Vertice* v3, Material* mat);
    Vertice* calcularNormal();
    float intersecao(Vertice *u);

    Material* mat;
    Vertice *v1, *v2, *v3;
};

#endif // FACE_H
