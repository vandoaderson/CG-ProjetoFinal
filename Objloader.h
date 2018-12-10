#ifndef OBJLOADER_H
#define OBJLOADER_H
#include "Cenario.h"

class ObjLoader
{
public:
    ObjLoader();
    Objeto* loadOBJ(char* nome);
    vector<Objeto*> loadScene();
    vector<Material*> loadMat(char* nome);

};

#endif // OBJLOADER_H
