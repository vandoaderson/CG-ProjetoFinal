#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QOpenGLWidget>
#include <QTimer>
#include "Cenario.h"
#include "Observador.h"
class GLWidget : public QOpenGLWidget
{
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    Cenario* c;
    Observador* o;
    void drawPlane(int size);
    void drawAxisCameraView(float tam);
    void gluClosedCylinder(GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);

};

#endif // GLWIDGET_H
