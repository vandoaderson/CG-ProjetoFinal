#include "Cenario.h"

Cenario::Cenario(FonteLuminosa *fl){
    FL = fl;
    solid = true;
    wired = false;
}

void Cenario::adicionarObjeto(Objeto *o){
    listaObjetos.push_back(o);
}

void Cenario::modelar(){}

void Cenario::resetar()
{
    for(int i = listaObjetos.size(); i > 0; i--){
        listaObjetos.pop_back();
    }
}

void Cenario::freeMemory(){
    for(int i = 0; i < listaObjetos.size(); i++){
        for(int j = 0; j < listaObjetos.at(i)->listaFace.size(); j++){
            delete listaObjetos.at(i)->listaFace.at(j)->mat;
            delete listaObjetos.at(i)->listaFace.at(j);
        }
        for(int j = 0; i < listaObjetos.at(i)->listaVertices.size(); j++){
            delete listaObjetos.at(i)->listaVertices.at(j);
        }
    }
    delete FL;
    delete this;

}
