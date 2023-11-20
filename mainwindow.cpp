#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    if(tecla->key() == Qt::Key_D and personajeRick->saberSalta_Rick()==false){
        //actualizar fuerza en esa direccion
        personajeRick->actualizarFuerzas(personajeRick->saberDatos(0)+2.0,personajeRick->saberDatos(1));
    }

    if(tecla->key() == Qt::Key_A and personajeRick->saberSalta_Rick()==false){
        //actualizar fuerza en esa direccion
        personajeRick->actualizarFuerzas(personajeRick->saberDatos(0)-2.0,personajeRick->saberDatos(1));
    }

    //rick salta

    if(tecla->key() == Qt::Key_W and personajeRick->saberSalta_Rick()==false){
        //actualizar fuerza en esa direccion
        personajeRick->Rick_salto();
    }

    if(tecla->key() == Qt::Key_Space){


        personajeRick->actualizarFuerzas(0,personajeRick->saberDatos(1));
        personajeRick->Seleccion_rick(4);
        diamond=new diamante();
        diamond->seleccion_diamante(0);
        diamond->cargarPos_Inicial(personajeRick->saberDatos(2)+50,personajeRick->saberDatos(3)+20);
        diamond->setPos(personajeRick->saberDatos(2)+50,personajeRick->saberDatos(3)+20);
        escena->addItem(diamond);
        //se carga la escena en la clase diamante
        diamond->obtenerEscena_Diamante(escena);
    }



}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pantalla->setGeometry(0,0,width(),height());

    //Creamos la escena.
    escena=new  QGraphicsScene;
    escena->setSceneRect(0,0,ui->pantalla->width()-2,ui->pantalla->height()-2);
    personajeRick=new rick();


    personajeRick->Seleccion_rick(4);
    personajeRick->setPos(0,300);
    escena->addItem(personajeRick);

    ui->pantalla->setScene(escena);

    //pruebaaaaa
    enemigo1=new enemyshot();
    enemigo1->seleccion_Enemyshot(0);
    enemigo1->setPos(500,200);
    escena->addItem(enemigo1);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete personajeRick;
    delete diamond;
}
