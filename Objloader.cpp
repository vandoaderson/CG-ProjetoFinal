#include "Objloader.h"
#include <vector>
#include "Objeto.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <dirent.h>
using namespace std;

ObjLoader::ObjLoader()
{

}

Objeto* ObjLoader::loadOBJ(char* nome)
{
    Objeto* ob = new Objeto();
    Vertice* vert;
    Vertice* Ka;
    Vertice* Kd;
    Vertice* Ks;
    Face* fac;
    vector<Material*> mat;
    Material* matAtivo;
    vector<Vertice*> vertices;
    vector<Face*> faces;
    float x, y, z, c[3];
    int aux[3],posMatAtivo;
    char tipo, line[100],path[50], line2[100];
    /*path[0]='\0';
    strcat(path,nome);
    strcat(path,".mtl");
    std::ifstream file2(path);
    printf("Arquivo mtl aberto\n");
    //ignorando as primeiras 5 linhas do arquivo (que são puramente informações para o blender)
    for (int k=0;k<13;k++){
        file2 >> line;
    }

    file2 >> tipo;
    file2 >> tipo;
    file2 >> c[0];
    file2 >> c[1];
    file2 >> c[2];
    Ka = new Vertice(c[0],c[1],c[2]);
    cout<<"Ka: "<<Ka->x<<" "<<Ka->y<<" "<<Ka->z<<endl;

    file2 >> tipo;
    file2 >> tipo;
    file2 >> c[0];
    file2 >> c[1];
    file2 >> c[2];
    Kd = new Vertice(c[0],c[1],c[2]);
    cout<<"Kd: "<<Kd->x<<" "<<Kd->y<<" "<<Kd->z<<endl;
    file2 >> tipo;
    file2 >> tipo;
    file2 >> c[0];
    file2 >> c[1];
    file2 >> c[2];
    Ks = new Vertice(c[0],c[1],c[2]);
    cout<<"Ks: "<<Ks->x<<" "<<Ks->y<<" "<<Kd->z <<endl;
    mat = new Material(Ka,Kd,Ks);*/
    mat = loadMat(nome);
    for(int i = 0; i < mat.size(); i++){
        mat[i]->m = 5;
    }
    path[0]='\0';
    strcat(path,nome);
    strcat(path,".obj");
    std::ifstream file(path);
    if(file){
      printf("Arquivo obj aberto\n");

      //ignorando as primeiras 3 linhas do arquivo (que são puramente informações para o blender)
      for (int k=0;k<3;k++){
        file >> line;
        cout<<"Ignorou  "<<line<<endl;
      }
      while(file >> tipo){
          if(tipo == 'o'){
              file >> line;
              cout<<"Tipo o  "<<line<<endl;
          }
          else if(tipo == 'v'){
              file >> x;
              file >> y;
              file >> z;
              vert = new Vertice(x,y,z);
              cout<<vertices.size()<<" : "<<vert->x<<" "<<vert->y<<" "<<vert->z<<endl;
              vertices.push_back(vert);
              ob->adicionarVertice(vert);
              cout<<"O objeto possui "<<ob->listaVertices.size()<<" vertices"<<endl;
          }

          else if(tipo=='f'){
              file >> aux[0];
              file >> aux[1];
              file >> aux[2];
              cout<<aux[0]<<" "<<aux[1]<<" "<<aux[2]<<endl;
              //cout<<vertices[aux[0]-1]->x<<" "<<vertices[aux[1]-1]->y<<" "<<vertices[aux[2]-1]->z<<endl;
              fac = new Face(vertices[aux[0]-1],vertices[aux[1]-1],vertices[aux[2]-1],matAtivo);
              faces.push_back(fac);
              ob->adicionarFace(fac);
          }
          else if(tipo == 'u'){
              file >> line;
              cout<<line<<endl;
              file >> line;
              cout<<line<<endl;
              if(strcmp(line,"Material") == 0){
                 matAtivo = mat[0];
              } else {
                 posMatAtivo = line[11]-'0';
                 cout<<posMatAtivo<<endl;
                 matAtivo = mat[posMatAtivo];
                 //matAtivo = mat[0];
              }
          }
          else {
            file >> line;
            cout<<tipo<<line<<endl;
          }
      }
      cout<<"O objeto possui "<<ob->listaFace.size()<<" faces"<<endl;
      return ob;
    }else {

          std::cout<<"nao abre o arquivo"<<std::endl;
          Objeto* objeto;
          return objeto;

    }

}

vector<Objeto*> ObjLoader::loadScene()
{
    vector<Objeto*> objs;
    DIR* dir;
    struct dirent *lsdir;
    char* nome;
    int i,j,k=0;
    dir = opendir("cenario");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        i = strlen(lsdir->d_name);

        if ((lsdir->d_name[i-1]=='j')&&((lsdir->d_name[i-2]=='b'))&&((lsdir->d_name[i-3]=='o'))){
            nome = (char*)malloc((i-4)*sizeof(char));
            for(j=0;j<i-4;j++){
                nome[j] = lsdir->d_name[j];
            }
            nome[j] = '\0';
            objs.push_back(loadOBJ(nome));

            printf("%s, %d \n",nome,j);
            k++;
        }
    }

   closedir(dir);


}

vector<Material*> ObjLoader::loadMat(char *nome)
{
    vector<Material*> mat;
    Vertice* Ka;
    Vertice* Kd;
    Vertice* Ks;
    float c[3];
    char tipo, line[100],path[50], line2[100];
    path[0]='\0';
    strcat(path,nome);
    strcat(path,".mtl");
    std::ifstream file2(path);
    printf("Arquivo mtl aberto\n");
    //ignorando as primeiras 5 linhas do arquivo (que são puramente informações para o blender)
    for (int k=0;k<13;k++){
        file2 >> line;
    }
    file2 >> tipo;
    file2 >> tipo;
    file2 >> c[0];
    file2 >> c[1];
    file2 >> c[2];
    Ka = new Vertice(c[0],c[1],c[2]);
    cout<<"Ka: "<<Ka->x<<" "<<Ka->y<<" "<<Ka->z<<endl;

    file2 >> tipo;
    file2 >> tipo;
    file2 >> c[0];
    file2 >> c[1];
    file2 >> c[2];
    Kd = new Vertice(c[0],c[1],c[2]);
    cout<<"Kd: "<<Kd->x<<" "<<Kd->y<<" "<<Kd->z<<endl;
    file2 >> tipo;
    file2 >> tipo;
    file2 >> c[0];
    file2 >> c[1];
    file2 >> c[2];
    Ks = new Vertice(c[0],c[1],c[2]);
    cout<<"Ks: "<<Ks->x<<" "<<Ks->y<<" "<<Ks->z <<endl;
    cout<<endl<<endl;
    mat.push_back(new Material(Ka,Kd,Ks));
    while(!file2.eof()){
        for (int k=0;k<14;k++){
            file2 >> line;
        }
        file2 >> tipo;
        file2 >> tipo;
        file2 >> c[0];
        file2 >> c[1];
        file2 >> c[2];
        Ka = new Vertice(c[0],c[1],c[2]);
        cout<<"Ka: "<<Ka->x<<" "<<Ka->y<<" "<<Ka->z<<endl;

        file2 >> tipo;
        file2 >> tipo;
        file2 >> c[0];
        file2 >> c[1];
        file2 >> c[2];
        Kd = new Vertice(c[0],c[1],c[2]);
        cout<<"Kd: "<<Kd->x<<" "<<Kd->y<<" "<<Kd->z<<endl;
        file2 >> tipo;
        file2 >> tipo;
        file2 >> c[0];
        file2 >> c[1];
        file2 >> c[2];
        Ks = new Vertice(c[0],c[1],c[2]);
        cout<<"Ks: "<<Ks->x<<" "<<Ks->y<<" "<<Ks->z <<endl;
        mat.push_back(new Material(Ka,Kd,Ks));
        cout<<endl<<endl;
    }
    return mat;
}
