#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    if(tecla->key() == Qt::Key_D and personajeRick->saberSalta_Rick()==false and personajeRick->saberRick_herido()==false){
        //actualizar fuerza en esa direccion
        personajeRick->actualizarFuerzas(personajeRick->saberDatos(0)+2.0,personajeRick->saberDatos(1));

    }

    if(tecla->key() == Qt::Key_A and personajeRick->saberSalta_Rick()==false and personajeRick->saberRick_herido()==false){
        //actualizar fuerza en esa direccion
        personajeRick->actualizarFuerzas(personajeRick->saberDatos(0)-2.0,personajeRick->saberDatos(1));
    }

    //rick salta

    if(tecla->key() == Qt::Key_W and personajeRick->saberSalta_Rick()==false and personajeRick->saberRick_herido()==false){
        //actualizar fuerza en esa direccion
        personajeRick->Rick_salto();
    }

    if(tecla->key() == Qt::Key_Space and personajeRick->saberRick_herido()==false){

        personajeRick->actualizarFuerzas(0,personajeRick->saberDatos(1));
        personajeRick->Seleccion_rick(4);
        diamond=new diamante();
        diamond->Cargar_Vxo_movimiento(45);
        diamond->Cargar_Vyo_movimiento(30);
        diamond->seleccion_diamante(0);
        diamond->cargarPos_Inicial(personajeRick->saberDatos(2)+50,personajeRick->saberDatos(3)+20);
        diamond->setPos(personajeRick->saberDatos(2)+50,personajeRick->saberDatos(3)+20);
        diamond->obtener_personaje(personajeRick);
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
    //fondo = new QGraphicsPixmapItem;
    //QPixmap img(":/imagenes/prueba.png");
    //fondo->setPixmap(img.scaled(img.width()*2,img.height()*2));
    escena->setSceneRect(0,0,ui->pantalla->width()-2,ui->pantalla->height()-2);
    personajeRick=new rick();


    personajeRick->Seleccion_rick(4);
    personajeRick->setPos(0,300);
    escena->addItem(personajeRick);

    ui->pantalla->setScene(escena);

    //pruebaaaaa
    enemigo1=new enemyshot();
    enemigo1->seleccion_Enemyshot(0);
    enemigo1->cargarPosicion_Enemyshot(500,50);
    enemigo1->setPos(500,50);
    enemigo1->obtener_Escena_Enemyshot(escena);
    enemigo1->obtener_personaje(personajeRick);
    escena->addItem(enemigo1);

    //prueba
    enemigo2=new goldenenemy();
    enemigo2->seleccion_goldenenemy(7);
    enemigo2->cargarPosicion_goldenenemy(700,270);
    enemigo2->setPos(700,270);
    enemigo2->obtener_personaje_principal(personajeRick);
    enemigo2->obtener_escena_Goldenenemy(escena);
    escena->addItem(enemigo2);

    personajeRick->setZValue(1);
    enemigo1->setZValue(1);
    enemigo2->setZValue(0);

    //escena->addItem(fondo);
    //fondo->setPos(0,0);
    //fondo->setZValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete personajeRick;
    delete diamond;
}

/*void MainWindow::set_focus(QGraphicsPixmapItem *item)
{
    escena->setSceneRect(item->x(),0,escena->width(),escena->height());
}*/
