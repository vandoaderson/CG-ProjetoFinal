#ifndef CENARIO_H
#define CENARIO_H

#include "Objeto.h"
#include "FonteLuminosa.h"
#include <vector>
using namespace std;

class Cenario
{
public:
    Cenario(FonteLuminosa* fl);

    vector<Objeto*> listaObjetos;
    FonteLuminosa* FL;
    bool wired, solid;

    void adicionarObjeto(Objeto* o);
    void modelar();
    void resetar();
    void freeMemory();
};

#endif // CENARIO_H
