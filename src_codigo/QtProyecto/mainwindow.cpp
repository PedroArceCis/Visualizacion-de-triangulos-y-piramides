#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include "myglwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPuntos(float lado1, float lado2, float lado3){
    pir = false;
    if(lado1==lado2 && lado2==lado3){
        lado_equilatero = lado3;
    }
    else{
        y2 = lado1-50;
        float potencia1, potencia2, potencia3, numerador, denominador;
        potencia1 = pow(lado2,2);
        potencia2 = pow(lado3,2);
        potencia3 = pow(lado1,2);
        numerador = potencia1 - potencia2 - potencia3 + (50*50);
        denominador = -2*(lado1+50);
        //Sacar puntos a partir de las distancias de uno a otro.
        y1 = numerador/denominador;
        float f;
        f = 50-y1;
        x1 = 500- sqrt( abs(pow(lado2,2) - pow(f,2)) );
    }
}

void MainWindow::getTipo(int tipo){
    this->tipo = tipo;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    if(pir){
    }

    else{
    if(tipo==1){

        QRectF rect = QRectF(0, 0, lado_equilatero, lado_equilatero);

        QPainterPath path;
        path.moveTo(rect.left() + (rect.width() / 2), rect.top());
        path.lineTo(rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.lineTo(rect.left() + (rect.width() / 2), rect.top());

        painter.fillPath(path, QBrush(QColor ("blue")));
    }

    else{

    static const QPointF points[3] = {
        QPointF(500, 50), //Punto fijo.
        QPointF(x1, y1),
        QPointF(500, y2) //Punto en base a la distancia de un lado.
    };

    if(tipo == 2){
        painter.setBrush(Qt::green);
    }
    else if(tipo == 3){
        painter.setBrush(Qt::red);
    }

    painter.drawConvexPolygon(points, 3);

    }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

