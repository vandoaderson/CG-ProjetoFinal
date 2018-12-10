#include "glwidget.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;
GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent){

}
void GLWidget:: initializeGL(){
    glClearColor(0.2,0.2,0.2,1);

    GLfloat amb[] = {c->FL->Ia->x,c->FL->Ia->y,c->FL->Ia->z,1.0};
    GLfloat dif[] = {c->FL->Id->x,c->FL->Id->y,c->FL->Id->z,1.0};
    GLfloat esp[] = {c->FL->Is->x,c->FL->Is->y,c->FL->Is->z,1.0};
    GLfloat pos[] = {c->FL->posicao->x,c->FL->posicao->y,c->FL->posicao->z,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);

    glLightfv(GL_LIGHT0, GL_SPECULAR, esp);

    glLightfv(GL_LIGHT0, GL_POSITION, pos);


    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_DEPTH_FUNC);
    //glEnable(GL_POINT_SMOOTH);
    glEnable(GL_NORMALIZE);
    //glEnable(GL_RESCALE_NORMAL);
}

void GLWidget:: paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(o->posicao->x,o->posicao->y,o->posicao->z,    o->lookAt->x,o->lookAt->y,o->lookAt->z,    o->viewUp->x,o->viewUp->y,o->viewUp->z);
    //drawPlane(20);
    int l,k = c->listaObjetos.size();

    for(int i = 0; i<k; i++){

        //if(c->solid){
           // c->listaObjetos[i]->desenhar();
        //}
        l = c->listaObjetos[i]->listaFace.size();

        for(int j = 0; j < l; j++){

            if(c->solid){
                glBegin(GL_TRIANGLES);
                    glColor3f(c->listaObjetos[i]->listaFace[j]->mat->Kd->x,c->listaObjetos[i]->listaFace[j]->mat->Kd->y,c->listaObjetos[i]->listaFace[j]->mat->Kd->z);
                    glNormal3f(c->listaObjetos[i]->listaFace[j]->calcularNormal()->x,c->listaObjetos[i]->listaFace[j]->calcularNormal()->y,c->listaObjetos[i]->listaFace[j]->calcularNormal()->z);
                    glVertex3f(c->listaObjetos[i]->listaFace[j]->v1->x,c->listaObjetos[i]->listaFace[j]->v1->y,c->listaObjetos[i]->listaFace[j]->v1->z);
                    glVertex3f(c->listaObjetos[i]->listaFace[j]->v2->x,c->listaObjetos[i]->listaFace[j]->v2->y,c->listaObjetos[i]->listaFace[j]->v2->z);
                    glVertex3f(c->listaObjetos[i]->listaFace[j]->v3->x,c->listaObjetos[i]->listaFace[j]->v3->y,c->listaObjetos[i]->listaFace[j]->v3->z);
                glEnd();
            }
            if(c->wired){
                glBegin(GL_LINE_LOOP);
                    if(c->solid){
                        glColor3f(0,0,0);
                    } else {
                        glColor3f(c->listaObjetos[i]->listaFace[j]->mat->Kd->x,c->listaObjetos[i]->listaFace[j]->mat->Kd->y,c->listaObjetos[i]->listaFace[j]->mat->Kd->z);
                    }
                    glVertex3f(c->listaObjetos[i]->listaFace[j]->v1->x,c->listaObjetos[i]->listaFace[j]->v1->y,c->listaObjetos[i]->listaFace[j]->v1->z);
                    glVertex3f(c->listaObjetos[i]->listaFace[j]->v2->x,c->listaObjetos[i]->listaFace[j]->v2->y,c->listaObjetos[i]->listaFace[j]->v2->z);
                    glVertex3f(c->listaObjetos[i]->listaFace[j]->v3->x,c->listaObjetos[i]->listaFace[j]->v3->y,c->listaObjetos[i]->listaFace[j]->v3->z);
                glEnd();
            }


        }
    }
    //drawAxisCameraView(2);
}

void GLWidget:: resizeGL(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,  (float)w/h,  0.01, 100.0);

    update();
}

void GLWidget::drawPlane(int size)
{
    glLineWidth(0.7);
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINES);
    for(int i=-size;i<=size;i+=2){
        for(int j=size;j>=-size;j-=2){
            glVertex3f(i,0,j);
            glVertex3f(i,0,-j);
            glVertex3f(i,0,j);
            glVertex3f(-i,0,j);
        }
    }
    glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}
void GLWidget::drawAxisCameraView(float tam)
{
      const GLfloat redMaterial[]={1.,0.,0.,1.};
      const GLfloat greenMaterial[]={0.,1.,0.,1.};
      const GLfloat blueMaterial[]={0.,0.,1.,1.};
      const GLfloat blackMaterial[]={0.,0.,0.,1.};

     // glMaterialfv(GL_FRONT, GL_AMBIENT, blackMaterial);
      //glMaterialfv(GL_FRONT, GL_DIFFUSE, blackMaterial);
      //glMaterialfv(GL_FRONT, GL_SPECULAR, blackMaterial);

      GLUquadricObj *quad = gluNewQuadric();

      glLineWidth( 2 ) ;

      //x
      glMaterialfv(GL_FRONT, GL_AMBIENT, redMaterial);

      glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(tam,0,0);
      glEnd();
      glPushMatrix();
        glRotated(90,0,1,0);
        glTranslated(0,0,tam);
        gluClosedCylinder(quad, 0.1*tam, 0, 0.2*tam, 10, 10);
      glPopMatrix();
      //y
      glMaterialfv(GL_FRONT, GL_AMBIENT, greenMaterial);

      glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,tam,0);
      glEnd();
      glPushMatrix();
        glRotated(90,-1,0,0);
        glTranslated(0,0,tam);
        gluClosedCylinder(quad, 0.1*tam, 0, 0.2*tam, 10, 10);
      glPopMatrix();
      //z
      glMaterialfv(GL_FRONT, GL_AMBIENT, blueMaterial);

      glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,0,tam);
      glEnd();
      glPushMatrix();
        glTranslated(0,0,tam);
        gluClosedCylinder(quad, 0.1*tam, 0, 0.2*tam, 10, 10);
      glPopMatrix();

      glLineWidth( 1 ) ;

      gluDeleteQuadric( quad );
      glPopMatrix();
}

void GLWidget::gluClosedCylinder(GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks)
{
    gluQuadricNormals(quad, GLU_SMOOTH);			// Create Smooth Normals
    gluQuadricTexture(quad, GL_TRUE);		  		// Create Texture Coords

    glPushMatrix();
    gluCylinder(quad, base, top, height, slices, stacks);
    glTranslated(0,0,height);
    gluDisk(quad, 0, top, slices, stacks);
    glRotated(180,0,1,0);
    glTranslated(0,0,height);
    gluDisk(quad, 0, base, slices, stacks);
    glPopMatrix();
}
