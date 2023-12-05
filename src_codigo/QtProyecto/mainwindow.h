#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDesktopWidget>
#include <QPainterPath>

#include <QWidget>
#include <QSlider>

#include <iostream>
#include <cmath>
#define PI 3.14159265

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);

    virtual void getPuntos(float lado1, float lado2, float lado3);
    virtual void getTipo(int tipo);
    float x1, y1, y2;
    float lado_equilatero;
    int tipo;
    bool pir = true;

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

//Structs.
struct geometria2d{
    int tipo;
    float lado1, lado2, lado3;
};

struct geometria3d{
    float altura;
};

struct geometria{
    geometria2d triforce;
    geometria3d pyramid;
};
