#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vertice.h"
#include <QColor>
#include <GL/glut.h>

#define MATERIAL_NO_DEFINE      0
//tipos pedra
#define MATERIAL_EMERALD        1
#define MATERIAL_JADE           2
#define MATERIAL_OBSIDIAN       3
#define MATERIAL_PEARL          4
#define MATERIAL_RUBY           5
#define MATERIAL_TURQUOSIE      6
//tipos metal
#define MATERIAL_BRONZE         7
#define MATERIAL_BRONZE_POLIERT 8
#define MATERIAL_CHROME         9
#define MATERIAL_GOLD           10
#define MATERIAL_GOLD_POLIERT   11
#define MATERIAL_COPPER         12 //KUPFER
#define MATERIAL_COPPER_POLIERT 13 //KUPFER
#define MATERIAL_BRASS          14 //MESSING
#define MATERIAL_SILVER         15
#define MATERIAL_SILVER_POLIERT 16
#define MATERIAL_ZINN           17
//tipos kunstoff
#define MATERIAL_GUMMI          18
#define MATERIAL_PLASTIK        19

//cores
#define MATERIAL_BLACK_PLASTIC  20
#define MATERIAL_CYAN_PLASTIC   21
#define MATERIAL_GREEN_PLASTIC  22
#define MATERIAL_RED_PLASTIC    23
#define MATERIAL_WHITE_PLASTIC  24
#define MATERIAL_YELLOW_PLASTIC 25
#define MATERIAL_BLACK_RUBBER   26
#define MATERIAL_CYAN_RUBBER    27
#define MATERIAL_GREEN_RUBER    28
#define MATERIAL_RED_RUBBER     29
#define MATERIAL_WHITE_RUBBER   30
#define MATERIAL_YELLOW_RUBBER  31


class Material
{
public:
    Material();
    Material(Vertice* Ka, Vertice* Kd, Vertice* Ks);

    void setMaterial(Material *mat, int type);
    void setMaterialOpenGL(int type);
    void setMaterialOpenGL();

    Vertice *Ka, *Kd, *Ks;
    float m;

};

#endif // MATERIAL_H
