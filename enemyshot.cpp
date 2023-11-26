#include "enemyshot.h"

void enemyshot::EnemyshotActivo()
{

    if(sprite_Enemyshot==4){

        srand(time(NULL));
        int Vx_azar=20+rand()%(60-20);
        int Vy_azar=20+rand()%(60-20);
         //Se escogio en el sprite 3 el enemyshot siempre lanza una bala
        diamondEnemyShot=new diamante();
        diamondEnemyShot->Cargar_Vxo_movimiento(-Vx_azar);
        diamondEnemyShot->Cargar_Vyo_movimiento(Vy_azar);

        diamondEnemyShot->seleccion_diamante(0);
        diamondEnemyShot->cargar_quien_dispara(false);
        diamondEnemyShot->cargarPos_Inicial(this->posicionX_Enemyshot(),this->posicionY_Enemyshot()+5);
        diamondEnemyShot->setPos(this->posicionX_Enemyshot(),this->posicionY_Enemyshot()+5);
        escenaEnemyshot->addItem(diamondEnemyShot);
        //se carga la escena en la clase diamante
        diamondEnemyShot->obtenerEscena_Diamante(escenaEnemyshot);
        //Se carga en el diamante la direccion del objeto de la clase rick;
        diamondEnemyShot->obtener_personaje(personajeRick);
        sprite_Enemyshot=0;
    }
    else{
        seleccion_Enemyshot(sprite_Enemyshot);
        sprite_Enemyshot++;
    }

}

enemyshot::enemyshot()
{
    Imagenes_enemyshot.load(":/imagenes/Sprite-enemyshot.png");
    setPos(0, 0);

    TimerEnemyActivo= new QTimer(this);
    connect(TimerEnemyActivo, SIGNAL(timeout()), this, SLOT(EnemyshotActivo()));
    TimerEnemyActivo->start(400);

}

void enemyshot::seleccion_Enemyshot(int tipo)
{
    enemyshot_ind=Imagenes_enemyshot.copy(size_spritex*tipo, 0, size_spritex, size_spritey).scaled(50,60);
    setPixmap(enemyshot_ind);
}

void enemyshot::obtener_Escena_Enemyshot(QGraphicsScene *escenita)
{
    escenaEnemyshot=escenita;
}

void enemyshot::obtener_personaje(rick *personaje)
{
    personajeRick=personaje;
}

void enemyshot::cargarPosicion_Enemyshot(int x, int y)
{
    posicionX=x;
    posicionY=y;
}

int enemyshot::posicionX_Enemyshot()
{
    return posicionX;
}

int enemyshot::posicionY_Enemyshot()
{
    return posicionY;
}

