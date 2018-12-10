#include "Cubo.h"

Cubo::Cubo(){
    adicionarVertice( new Vertice(1,-1,1) );
    adicionarVertice( new Vertice(1,-1,-1) );
    adicionarVertice( new Vertice(-1,-1,-1) );
    adicionarVertice( new Vertice(-1,-1,1) );
    adicionarVertice( new Vertice(1,1,1) );
    adicionarVertice( new Vertice(1,1,-1) );
    adicionarVertice( new Vertice(-1,1,-1) );
    adicionarVertice( new Vertice(-1,1,1) );

    Vertice* v1 = new Vertice(0.1,0.5,0.1);
    Vertice* v2 = new Vertice(0.2,0.7,0.2);
    Vertice* v3 = new Vertice(0.8,0.9,0.8);
    Material* m  = new Material(v1, v2, v3);


    adicionarFace(new Face(listaVertices[3], listaVertices[0], listaVertices[7], m) );
    adicionarFace( new Face(listaVertices[0], listaVertices[4], listaVertices[7], m) );
    adicionarFace( new Face(listaVertices[0], listaVertices[5], listaVertices[4], m) );
    adicionarFace( new Face(listaVertices[0], listaVertices[1], listaVertices[5], m) );
    adicionarFace( new Face(listaVertices[2], listaVertices[3], listaVertices[6], m) );
    adicionarFace( new Face(listaVertices[3], listaVertices[7], listaVertices[6], m) );
    adicionarFace( new Face(listaVertices[1], listaVertices[2], listaVertices[5], m) );
    adicionarFace( new Face(listaVertices[2], listaVertices[6], listaVertices[5], m) );
    adicionarFace( new Face(listaVertices[0], listaVertices[3], listaVertices[1], m) );
    adicionarFace( new Face(listaVertices[3], listaVertices[2], listaVertices[1], m) );
    adicionarFace( new Face(listaVertices[7], listaVertices[4], listaVertices[6], m) );
    adicionarFace( new Face(listaVertices[4], listaVertices[5], listaVertices[6], m) );
}
/*
void Cubo::desenhar()
{
     glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

     glPushMatrix();


    // setMaterial(0);
     //setMaterials();

     //glColor3f(0.2,0.2,0.2);
     //GLfloat yellow[] = {0.5f, 0.5f, 0.5f, 1.0f};
     //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
     //glMultMatrixd(transform.getMatrix());
     for(unsigned int i=0;i<listaFace.size();i++){
         //glColor3f(0.5,0.5,0.5);
         //glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
         //drawNormalFace(faces[i]);
         listaFace[i]->mat->setMaterialOpenGL();
         glBegin(GL_POLYGON);
            glNormal3f(listaFace[i]->calcularNormal()->x,listaFace[i]->calcularNormal()->y,listaFace[i]->calcularNormal()->z);
            glVertex3f(listaFace[i]->v1->x,listaFace[i]->v1->y,listaFace[i]->v1->z);
            glVertex3f(listaFace[i]->v2->x,listaFace[i]->v2->y,listaFace[i]->v2->z);
            glVertex3f(listaFace[i]->v3->x,listaFace[i]->v3->y,listaFace[i]->v3->z);

         glEnd();
//            glColor3f(1,0,0);
//            glBegin(GL_LINES);
//            for(unsigned int j=0;j<faces[i].vertexs.size();j++){
//                if(j<faces[i].normals.size() && faces[i].normals.size()>1){
//                glVertex3dv(&faces[i].vertexs[j]->x1);
//                glVertex3d(faces[i].vertexs[j]->x1+0.5*faces[i].normals[j]->x1,faces[i].vertexs[j]->x2+0.5*faces[i].normals[j]->x2,faces[i].vertexs[j]->x3+0.5*faces[i].normals[j]->x3);
//                }
//                glColor3f(0.0,1,0.0);
//                if(j<faces[i].normals.size() && faces[i].normals.size()>1){
//                glVertex3dv(&faces[i].vertexs[j]->x1);
//                glVertex3d(faces[i].vertexs[j]->x1+0.5+0.5*faces[i].normals[j]->x1,faces[i].vertexs[j]->x2+0.5+0.5*faces[i].normals[j]->x2,faces[i].vertexs[j]->x3+0.5+0.5*faces[i].normals[j]->x3);
//                }
//            }
//            glEnd();
           //
       }

       glPopMatrix();
}
*/
