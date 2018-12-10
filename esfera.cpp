#include "esfera.h"
#include "math.h"
#include "iostream"

#define PI 3.14159265

Esfera::Esfera()
{
    int R=12,count =0;
    double raio = 0.5,teta = 0,fi=0;
    //adicionarVertice( new Vertice(0,0.5,0) );
    //adicionarVertice( new Vertice(0,-0.5,0) );
    for(int i=0;i<R;i++){
        for(int j=0;j<R;j++){
            adicionarVertice( new Vertice(raio*cos(fi)*cos(teta),
                                          raio*sin(fi),
                                          raio*cos(fi)*sin(teta)) );
            count++;
            cout << "Vertice: "<< count<<endl;
            cout << raio*cos(fi)*cos(teta)<< endl;
            cout << raio*cos(fi)*sin(teta)<< endl;
            cout << raio*sin(fi)<< endl;

            fi += 360/R;
         }
         teta += 360/R;
    }
    Vertice* v1 = new Vertice(0.1,0.5,0.1);
    Vertice* v2 = new Vertice(0.2,0.7,0.2);
    Vertice* v3 = new Vertice(0.8,0.9,0.8);
    Material* m  = new Material(v1, v2, v3);

   for(int a=0;a<listaVertices.size();a++)
        for(int b=0;b<listaVertices.size();b++)
            for(int c=0;c<listaVertices.size();c++)
                if(a != b && a!=c && b!=c)
                adicionarFace(new Face(listaVertices[a], listaVertices[b], listaVertices[c], m) );




}

