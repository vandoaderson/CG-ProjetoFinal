#ifndef FONTELUMINOSA_H
#define FONTELUMINOSA_H

#include "Vertice.h"

class FonteLuminosa{
public:
    FonteLuminosa(Vertice* Ia, Vertice* Id, Vertice* Is, Vertice* pos);

    Vertice *Ia, *Id, *Is;
    Vertice* posicao;
};

#endif // FONTELUMINOSA_H
