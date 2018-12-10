#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QGraphicsScene>
#include "Cenario.h"
#include "Observador.h"
#include "Cubo.h"
#include "esfera.h"
#include <iostream>
#include <math.h>
#include "Objloader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     Nx = 500;
     Ny = 500;
     w = 140;
     h = 140;
     d = 100;
     posCX = 1,posCY = 3,posCZ = 7,lax = 0,lay = 0,laz = 0,vupx = 0,vupy = 120,vupz = 0,tsX = 0,tsY = 0, tsZ = 0,scX = 1, scY = 1, scZ = 1,ang = 0,Flx = 30,Fly = 30,Flz = 30;
     o = new Observador(new Vertice(posCX, posCY, posCZ), new Vertice(lax, lay, laz), new Vertice(vupx, vupy, vupz), Nx, Ny, w, h, d);
     c = new Cenario( new FonteLuminosa(new Vertice(0,0,0), new Vertice(1,1,1), new Vertice(1,1,1), new Vertice(Flx,Fly,Flz)) );



    Cubo* campo = new Cubo();
    Cubo* trave1 = new Cubo();
    Cubo* trave2 = new Cubo();
    Cubo* travessao1 = new Cubo();
    Cubo* trave3 = new Cubo();
    Cubo* trave4 = new Cubo();
    Cubo* travessao2 = new Cubo();
    Esfera* teste123 = new Esfera();

    teste123->escalar(new Vertice(2,2,2));
    teste123->transladar(new Vertice(2,2,2));
    for(int i = 0; i < teste123->listaFace.size();i++){
            teste123->listaFace[i]->mat->setMaterialOpenGL(24);
       }

    trave1->escalar(new Vertice(0.01,0.244,0.01));
    trave1->transladar(new Vertice(9,0.244,0.732));
        for(int i = 0; i < trave1->listaFace.size();i++){
            trave1->listaFace[i]->mat->setMaterialOpenGL(24);
        }
    trave2->escalar(new Vertice(0.01,0.244,0.01));
    trave2->transladar(new Vertice(9,0.244,-0.732));
        for(int i = 0; i < trave2->listaFace.size();i++){
            trave2->listaFace[i]->mat->setMaterialOpenGL(24);
        }
    travessao1->escalar(new Vertice(0.01,0.01,0.732));
    travessao1->transladar(new Vertice(9,0.488,0));
        for(int i = 0; i < travessao1->listaFace.size();i++){
            travessao1->listaFace[i]->mat->setMaterialOpenGL(24);
        }
    trave3->escalar(new Vertice(0.01,0.244,0.01));
    trave3->transladar(new Vertice(-9,0.244,0.732));
        for(int i = 0; i < trave3->listaFace.size();i++){
            trave3->listaFace[i]->mat->setMaterialOpenGL(24);
        }
    trave4->escalar(new Vertice(0.01,0.244,0.01));
    trave4->transladar(new Vertice(-9,0.244,-0.732));
        for(int i = 0; i < trave4->listaFace.size();i++){
            trave4->listaFace[i]->mat->setMaterialOpenGL(24);
        }
    travessao2->escalar(new Vertice(0.01,0.01,0.732));
    travessao2->transladar(new Vertice(-9,0.488,0));
        for(int i = 0; i < travessao2->listaFace.size();i++){
            travessao2->listaFace[i]->mat->setMaterialOpenGL(24);
        }
    campo->escalar(new Vertice(9,0.001,4.5));
    campo->transladar(new Vertice(0, 0, 0));
    for(int i = 0; i < campo->listaFace.size();i++){
        campo->listaFace[i]->mat->setMaterialOpenGL(22);
    }

    ui->setupUi(this);
    loader = new ObjLoader();
    //vector<Material*> mat = loader->loadMat("test12");
    //Objeto* monkey = loader->loadOBJ("scenev15");
   // c->adicionarObjeto(monkey);
    c->adicionarObjeto(teste123);
    //c->adicionarObjeto(campo);
   // c->adicionarObjeto(trave1);
    //c->adicionarObjeto(trave2);
   // c->adicionarObjeto(travessao1);
    //c->adicionarObjeto(trave3);
   // c->adicionarObjeto(trave4);
    //c->adicionarObjeto(travessao2);
    ui->openw->o = o;
    ui->openw->c = c;
    //aqui
    //o->mundoCamera(c);
    //o->rayCasting(c);

    /*QImage image = QImage(Nx, Ny, QImage::Format_RGB32);
    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            image.setPixel(j,i, qRgb(o->cores[i][j]->x*255, o->cores[i][j]->y*255,o->cores[i][j]->z*255));
        }
    }
    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    //ui->graphicsView->setScene(graphic);
    o->cameraMundo(c);
    */




}

MainWindow::~MainWindow(){

    o->freeMemory();
    c->freeMemory();

    delete ui;
}

void MainWindow::raycast(){
    o->calcularIJK();
    o->mundoCamera(c);
    cout<<"Startou"<<endl;

    o->rayCasting(c);
    QImage image = matrizDePixels(o,Nx,Ny);
    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    //ui->graphicsView->setScene(graphic);
    o->cameraMundo(c);

    o->resetCores();
}

QImage MainWindow::matrizDePixels(Observador* o, int Nx, int Ny)
{
    QImage image = QImage(Nx, Ny, QImage::Format_RGB32);
    for(int i=0; i<Nx; i++){
        for(int j=0; j<Ny; j++){
            image.setPixel(j,i, qRgb(o->cores[i][j]->x*255, o->cores[i][j]->y*255,o->cores[i][j]->z*255));
        }
    }
    return image;
}

void MainWindow::carregarCenarios()
{
    /*
    DIR* dir;
    struct dirent *lsdir;
    char* nome;
    int i,j,k=0;
    ObjLoader* loader = new ObjLoader();
    dir = opendir("cenarios");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        i = strlen(lsdir->d_name);

        if ((lsdir->d_name[i-1]=='j')&&((lsdir->d_name[i-2]=='b'))&&((lsdir->d_name[i-3]=='o'))){
            nome = (char*)malloc((i-4)*sizeof(char));
            for(j=0;j<i-4;j++){
                nome[j] = lsdir->d_name[j];
            }
            nome[j] = '\0';
            //c->adicionarObjeto();


            printf("%s, %d \n",nome,j);
            k++;
        }
    }

   closedir(dir);
*/
}

void MainWindow::on_raycast_clicked()
{
    ui->raycast->setDisabled(true);
    raycast();
    o = new Observador(new Vertice(posCX,posCY,posCZ),new Vertice(lax,lay,laz),new Vertice(vupx,vupy,vupz),Nx,Ny,w,h,o->distancia);
    ui->openw->o = o;
    if(ui->tabWidget->currentIndex() == 0){
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
    }
    ui->raycast->setDisabled(false);
}

void MainWindow::on_posCX_valueChanged(double arg1)
{
    posCX = arg1;
    o->posicao->x = posCX;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_posCY_valueChanged(double arg1)
{
    posCY = arg1;
    o->posicao->y = posCY;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_posCZ_valueChanged(double arg1)
{
    posCZ = arg1;
    o->posicao->z = posCZ;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_lax_valueChanged(double arg1)
{
    lax = arg1;
    o->lookAt->x = lax;
   // o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_lay_valueChanged(double arg1)
{
    lay = arg1;
    o->lookAt->y = lay;
   // o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_laz_valueChanged(double arg1)
{
    laz = arg1;
    o->lookAt->z = laz;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_vupx_valueChanged(double arg1)
{
    vupx = arg1;
    o->viewUp->x = vupx;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_vupy_valueChanged(double arg1)
{
    vupy = arg1;
    o->viewUp->y = vupy;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_vupz_valueChanged(double arg1)
{
    vupz = arg1;
    o->viewUp->z = vupz;
    //o->calcularIJK();
    ui->openw->update();
}

void MainWindow::on_solid_clicked(bool checked)
{
    ui->solid->setDisabled(true);
    c->solid = checked;
    ui->openw->update();
    ui->solid->setDisabled(false);
}

void MainWindow::on_wired_clicked(bool checked)
{
    ui->wired->setDisabled(true);
    c->wired = checked;
    ui->openw->update();
    ui->wired->setDisabled(false);
}

void MainWindow::on_tsX_valueChanged(double arg1)
{
    float diff = arg1 - tsX;
    Vertice* ts = new Vertice(diff,0,0);
    c->listaObjetos[0]->transladar(ts);
    ui->openw->update();
    tsX = arg1;
    delete ts;
}

void MainWindow::on_tsY_valueChanged(double arg1)
{
    float diff = arg1 - tsY;
    Vertice* ts = new Vertice(0,diff,0);
    c->listaObjetos[0]->transladar(ts);
    ui->openw->update();
    tsY = arg1;
    delete ts;
}

void MainWindow::on_tsZ_valueChanged(double arg1)
{
    float diff = arg1 - tsZ;
    Vertice* ts = new Vertice(0,0,diff);
    c->listaObjetos[0]->transladar(ts);
    ui->openw->update();
    tsZ = arg1;
    delete ts;
}

void MainWindow::on_scX_valueChanged(double arg1)
{
    float div = arg1/scX;
    Vertice* ts = new Vertice(div,1,1);
    c->listaObjetos[0]->escalar(ts);
    ui->openw->update();
    scX = arg1;
    delete ts;
}

void MainWindow::on_scY_valueChanged(double arg1)
{
    float div = arg1/scY;
    Vertice* ts = new Vertice(1,div,1);
    c->listaObjetos[0]->escalar(ts);
    ui->openw->update();
    scY = arg1;
    delete ts;
}

void MainWindow::on_scZ_valueChanged(double arg1)
{
    float div = arg1/scZ;
    Vertice* ts = new Vertice(1,1,div);
    c->listaObjetos[0]->escalar(ts);
    ui->openw->update();
    scZ = arg1;
    delete ts;
}

void MainWindow::on_ang_valueChanged(double arg1)
{
    float diff = arg1 - ang;
    Vertice* rt = new Vertice(0,1,0);
    float dg = (diff*180)/M_PI;
    c->listaObjetos[0]->rotacao(rt,dg);
    ui->openw->update();
    ang = arg1;
    delete rt;

}

void MainWindow::on_Fly_valueChanged(double arg1)
{
    Fly = arg1;
    c->FL->posicao->y = Fly;
    ui->openw->update();
}

void MainWindow::on_Flx_valueChanged(double arg1)
{
    Flx = arg1;
    c->FL->posicao->x = Flx;
    ui->openw->update();
}

void MainWindow::on_Flz_valueChanged(double arg1)
{
    Flz = arg1;
    c->FL->posicao->z = Flz;
    ui->openw->update();
}

void MainWindow::on_load_clicked()
{
    //ui->load->setDisabled(true);
   // c->resetar();
    //QString str = ui->sName->text();
    //string nome2 = str.toStdString();
    //char* nome = new char[nome2.size() + 1];
    //strcpy(nome,nome2.c_str());
    //Objeto* obj = loader->loadOBJ(nome);
    //c->adicionarObjeto(obj);
    //ui->comboBox->addItem(nome);
   // ui->openw->update();
    //ui->load->setDisabled(false);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}
