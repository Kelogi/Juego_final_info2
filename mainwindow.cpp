#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    if(tecla->key() == Qt::Key_D and personajeRick->saberSalta_Rick()==false and personajeRick->saberRick_herido()==false){
        //actualizar fuerza en esa direccion
        personajeRick->actualizarFuerzas(personajeRick->saberDatos(0)+2.0,personajeRick->saberDatos(1));
        escena->setSceneRect(personajeRick->x()-100,0,escena->width(),escena->height());
    }

    if(tecla->key() == Qt::Key_A and personajeRick->saberSalta_Rick()==false and personajeRick->saberRick_herido()==false){
        //actualizar fuerza en esa direccion
        personajeRick->actualizarFuerzas(personajeRick->saberDatos(0)-2.0,personajeRick->saberDatos(1));
    }

    //rick salta
    if(tecla->key() == Qt::Key_W and personajeRick->saberSalta_Rick()==false and personajeRick->saberRick_herido()==false){
        //actualizar fuerza en esa direccion
        personajeRick->Rick_salto();
        personajeRick->recibir_Vyo(45.0);
    }
    if(tecla->key() == Qt::Key_S and personajeRick->saber_Rick_in_Rock()==true){
        personajeRick->actualizar_RickinRock(false);
        personajeRick->Rick_salto();
    }

    if(tecla->key() == Qt::Key_Space and personajeRick->saberRick_herido()==false and personajeRick->saberDisparos()!=0){

        //rick prenta un disparo menos
        personajeRick->actualizarDisparos(personajeRick->saberDisparos()-1);
        //se actualzia la nueva cnatidad de disparos en el Qlabel
        ui->disparos->setNum(personajeRick->saberDisparos());
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
    //para actualizar datos:
    ActualizarDatos=new QTimer;
    connect(ActualizarDatos,SIGNAL(timeout()),this,SLOT(Actualizardatos()));
    ActualizarDatos->start(10);

    ui->pantalla->setGeometry(0,0,width(),height());
    ui->pantalla->setVisible(false);
    ui->vidas->setVisible(false);
    ui->puntaje->setVisible(false);
    ui->disparos->setVisible(false);

    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);

    //Creamos la escena.
    escena=new  QGraphicsScene;
    fondo = new QGraphicsPixmapItem;
    //QPixmap img(":/imagenes/fondo.png");
    QImage p(":/imagenes/fondo.png");
    QBrush img(p);
    ui->pantalla->setBackgroundBrush(img);
    //ui->label->setPixmap(":/imagenes");
    //fondo->setPixmap(img.scaled(img.width(),img.height()));
    escena->setSceneRect(0,0,ui->pantalla->width()-2,ui->pantalla->height()-2);
    personajeRick=new rick();


    personajeRick->Seleccion_rick(4);
    personajeRick->setPos(0,300);
    escena->addItem(personajeRick);
    personajeRick->setZValue(1);


    ui->pantalla->setScene(escena);
    set_focus(personajeRick);




    //Se crean los objetos enemyshot y se guardan en el vector.
    //Ademas se crean los objetos tipo roca, encima de estos estaran los enemyshot

    int posVectorRoca=0;
    int posVectorPoint=0;

    for(int i=0;i<3;i++){
        (vectorEnemyshots).push_back(new enemyshot());
        (vectorEnemyshots)[i]->seleccion_Enemyshot(0);
        (vectorEnemyshots)[i]->cargarPosicion_Enemyshot(400*(i+1),30);
        (vectorEnemyshots)[i]->setPos(400*(i+1),30);
        (vectorEnemyshots)[i]->obtener_Escena_Enemyshot(escena);
        (vectorEnemyshots)[i]->obtener_personaje(personajeRick);
        escena->addItem((vectorEnemyshots)[i]);
        (vectorEnemyshots)[i]->setZValue(1);
        //Se crea el objeto tipo roca--------------
        vectorRocas.push_back(new roca());
        vectorRocas[posVectorRoca]->seleccionar_roca(1);
        vectorRocas[posVectorRoca]->setPos(400*(i+1)-25,80);
        vectorRocas[posVectorRoca]->cargar_posicion_rock(400*(i+1)-25,80);
        vectorRocas[posVectorRoca]->obetener_personaje(personajeRick);
        escena->addItem(vectorRocas[posVectorRoca]);
        (vectorRocas)[posVectorRoca]->setZValue(1);
        posVectorRoca++;
    }

    //Se crean las rocas que tendra el juego, ademas a traves de la funcion probabilidad vemos si encima de la roca se crea un objeto point
    int posY_crear_objetos=180;
    for(int i=0;i<7;i++){
        vectorRocas.push_back(new roca());
        vectorRocas[posVectorRoca]->seleccionar_roca(0);
        vectorRocas[posVectorRoca]->setPos(300*(i+1),posY_crear_objetos);
        vectorRocas[posVectorRoca]->cargar_posicion_rock(300*(i+1),posY_crear_objetos);
        vectorRocas[posVectorRoca]->obetener_personaje(personajeRick);
        escena->addItem(vectorRocas[posVectorRoca]);
        (vectorRocas)[posVectorRoca]->setZValue(1);
        posVectorRoca++;

        //nos preguntamos si se crea un objeto point encima de la roca----------------
        if(Evento_aleatorio()==true){
            vectorPoints.push_back(new point());
            vectorPoints[posVectorPoint]->seleccionar_point();
            vectorPoints[posVectorPoint]->setPos(300*(i+1)+30,posY_crear_objetos-30);
            vectorPoints[posVectorPoint]->cargar_posicion_point(300*(i+1)+30,posY_crear_objetos-30);
            vectorPoints[posVectorPoint]->Obtener_escena(escena);
            vectorPoints[posVectorPoint]->Obtener_personaje_principal(personajeRick);
            escena->addItem(vectorPoints[posVectorPoint]);
            (vectorPoints)[posVectorPoint]->setZValue(1);
            posVectorPoint++;
        }

        if(posY_crear_objetos==180) posY_crear_objetos=200;
        else posY_crear_objetos=180;

    }

    //Se crean mas objetos puntos y se guardan en el vector
    posY_crear_objetos=330;
    for(int i=0;i<4;i++){
        vectorPoints.push_back(new point());
        vectorPoints[posVectorPoint]->seleccionar_point();
        vectorPoints[posVectorPoint]->setPos(300*(i+1),posY_crear_objetos);
        vectorPoints[posVectorPoint]->cargar_posicion_point(300*(i+1),posY_crear_objetos);
        vectorPoints[posVectorPoint]->Obtener_escena(escena);
        vectorPoints[posVectorPoint]->Obtener_personaje_principal(personajeRick);
        escena->addItem(vectorPoints[posVectorPoint]);
        (vectorPoints)[posVectorPoint]->setZValue(1);
        posVectorPoint++;
        if(posY_crear_objetos==330) posY_crear_objetos=300;
        else posY_crear_objetos=330;
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
        (vectorGoldenenemy)[i]->setZValue(1);
    }



    escena->addItem(fondo);
    fondo->setPos(0,0);
    fondo->setZValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete personajeRick;
    delete diamond;
}

void MainWindow::set_focus(QGraphicsPixmapItem *item)
{
    escena->setSceneRect(item->x(),0,escena->width(),escena->height());
}

bool MainWindow::Evento_aleatorio(){

         int num_rand = rand(), x;
         x = probabilidad*(RAND_MAX+1)-1;
         return num_rand <= x;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pantalla->setVisible(true);
    ui->widget->setVisible(false);

    ui->vidas->setVisible(true);
    ui->vidas->setNum(personajeRick->saberVidas());
    ui->vidas->setStyleSheet("color:white");

    ui->puntaje->setVisible(true);
    ui->puntaje->setNum(personajeRick->saberPuntos());
    ui->puntaje->setStyleSheet("color:white");

    ui->disparos->setVisible(true);
    ui->disparos->setNum(personajeRick->saberDisparos());
    ui->disparos->setStyleSheet("color:white");

    ui->label_2->setVisible(true);
    ui->label_2->setStyleSheet("color:white");
    ui->label_3->setVisible(true);
    ui->label_3->setStyleSheet("color:white");
    ui->label_4->setVisible(true);
    ui->label_4->setStyleSheet("color:white");


}

void MainWindow::Actualizardatos()
{
    ui->vidas->setNum(personajeRick->saberVidas());
    ui->puntaje->setNum(personajeRick->saberPuntos());
    ui->disparos->setNum(personajeRick->saberDisparos());
}

