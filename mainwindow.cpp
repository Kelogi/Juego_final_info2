#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pantalla->setGeometry(0,0,width(),height());

    //Creamos la escena.
    escena=new  QGraphicsScene;
    escena->setSceneRect(0,0,ui->pantalla->width()-2,ui->pantalla->height()-2);
    personajeRick=new rick;


    personajeRick->Seleccion_rick(4);
    personajeRick->setPos(0,200);
    escena->addItem(personajeRick);

    ui->pantalla->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
}
