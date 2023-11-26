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
        diamond->recibir_enemygolds(&vectorGoldenenemy);
        diamond->cargar_quien_dispara(true);
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
    //set_focus(personajeRick);




    //Se crean los objetos enemyshot y se guardan en el vector.

    for(int i=0;i<3;i++){
        (vectorEnemyshots).push_back(new enemyshot());
        (vectorEnemyshots)[i]->seleccion_Enemyshot(0);
        (vectorEnemyshots)[i]->cargarPosicion_Enemyshot(450*(i+1),50);
        (vectorEnemyshots)[i]->setPos(450*(i+1),50);
        (vectorEnemyshots)[i]->obtener_Escena_Enemyshot(escena);
        (vectorEnemyshots)[i]->obtener_personaje(personajeRick);
        escena->addItem((vectorEnemyshots)[i]);
    }
    //Se crean los objetos goldenenemy y se guardan en el vector.
    for(int i=0;i<10;i++){
        (vectorGoldenenemy).push_back(new goldenenemy());
        (vectorGoldenenemy)[i]->seleccion_goldenenemy(7);
        (vectorGoldenenemy)[i]->cargarPosicion_goldenenemy(300*(i+1),270);
        (vectorGoldenenemy)[i]->setPos(300*(i+1),270);
        (vectorGoldenenemy)[i]->obtener_personaje_principal(personajeRick);
        (vectorGoldenenemy)[i]->obtener_escena_Goldenenemy(escena);
        escena->addItem((vectorGoldenenemy)[i]);
    }


    //Se crean los objetos puntos y se guardan en un vector
    int posY=330;
    for(int i=0;i<3;i++){
        vectorPoints.push_back(new point());
        vectorPoints[i]->seleccionar_point();
        vectorPoints[i]->setPos(300*(i+1),posY);
        vectorPoints[i]->cargar_posicion_point(300*(i+1),posY);
        vectorPoints[i]->Obtener_escena(escena);
        vectorPoints[i]->Obtener_personaje_principal(personajeRick);
        escena->addItem(vectorPoints[i]);
        if(posY==330) posY=300;
        else posY=330;
    }
    roquita=new roca();
    roquita->seleccionar_roca(0);
    roquita->setPos(300,230);
    roquita->cargar_posicion_rock(300,230);
    roquita->obetener_personaje(personajeRick);
    escena->addItem(roquita);







    //personajeRick->setZValue(1);
    //enemigo1->setZValue(1);
    //enemigo2->setZValue(0);

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
