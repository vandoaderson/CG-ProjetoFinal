#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "Observador.h"
#include "Objloader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);    ~MainWindow();
    void raycast();
    QImage matrizDePixels(Observador* o,int Nx, int Ny);
    int Nx,Ny;
    float w,h,d,posCX,posCY,posCZ,lax,lay,laz,vupx,vupy,vupz,tsX,tsY,tsZ,scX,scY,scZ,ang,Flx,Fly,Flz;
    Observador* o;
    Cenario* c;
    ObjLoader* loader;
    void carregarCenarios();

private slots:


    void on_raycast_clicked();

    void on_posCX_valueChanged(double arg1);

    void on_posCY_valueChanged(double arg1);

    void on_posCZ_valueChanged(double arg1);

    void on_lax_valueChanged(double arg1);

    void on_lay_valueChanged(double arg1);

    void on_laz_valueChanged(double arg1);

    void on_vupx_valueChanged(double arg1);

    void on_vupy_valueChanged(double arg1);

    void on_vupz_valueChanged(double arg1);

    void on_solid_clicked(bool checked);

    void on_wired_clicked(bool checked);

    void on_tsX_valueChanged(double arg1);

    void on_tsY_valueChanged(double arg1);

    void on_tsZ_valueChanged(double arg1);

    void on_scX_valueChanged(double arg1);

    void on_scY_valueChanged(double arg1);

    void on_scZ_valueChanged(double arg1);

    void on_ang_valueChanged(double arg1);

    void on_Fly_valueChanged(double arg1);

    void on_Flx_valueChanged(double arg1);

    void on_Flz_valueChanged(double arg1);

    void on_load_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
