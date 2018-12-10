#include "Objeto.h"

Objeto::Objeto(){}

void Objeto::adicionarVertice(Vertice *v){
    listaVertices.push_back(v);
}

void Objeto::adicionarFace(Face *f){
    listaFace.push_back(f);
}

void Objeto::transladar(Vertice *t){
    int n = listaVertices.size();
    int i;

    for( i=0; i<n; i++ )
        listaVertices[i]->transladar(t);
}

void Objeto::escalar(Vertice *s){
    int n = listaVertices.size();
    int i;

    for( i=0; i<n; i++ )
        listaVertices[i]->escalar(s);
}

void Objeto::rotacao(Vertice *eixo, float angulo){
    int n = listaVertices.size();
    int i;

    for( i=0; i<n; i++ )
        listaVertices[i]->rotacao(eixo, angulo);
}

void Objeto::rotacaoY(float angulo)
{
    int n = listaVertices.size();
    int i;

    for( i=0; i<n; i++ )
        listaVertices[i]->rotacaoY(angulo);
}

void Objeto::setFacesMaterialOpenGL(int type)
{
    for(int i = 0; i<listaFace.size(); i++){
        listaFace[i]->mat->setMaterialOpenGL(type);
    }
}
void Objeto::desenhar()
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
         //listaFace[i]->mat->setMaterialOpenGL(9);


         GLfloat ambient[] = { 0.3, 0.0, 0.0, 1.0 };
         GLfloat diffuse[] = { 0.6, 0.0, 0.0, 1.0 };
         GLfloat specular[] = {0.8, 0.6, 0.6, 1.0 };
         GLfloat shininess = 32.0; /*
         [0..128]
         */
         glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
         glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
         glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
         glMaterialf(GL_FRONT, GL_SHININESS, shininess);
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
