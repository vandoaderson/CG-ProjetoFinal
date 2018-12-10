#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T15:34:43
#
#-------------------------------------------------

QT       += core gui opengl concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoCG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Vertice.cpp \
    Matriz.cpp \
    Face.cpp \
    Material.cpp \
    SistemaLinear.cpp \
    Objeto.cpp \
    Cubo.cpp \
    FonteLuminosa.cpp \
    Cenario.cpp \
    Observador.cpp \
    glwidget.cpp \
    Objloader.cpp \
    esfera.cpp

HEADERS  += mainwindow.h \
    Vertice.h \
    Matriz.h \
    Face.h \
    Material.h \
    SistemaLinear.h \
    Objeto.h \
    Cubo.h \
    FonteLuminosa.h \
    Cenario.h \
    Observador.h \
    glwidget.h \
    Objloader.h \
    esfera.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGLU
