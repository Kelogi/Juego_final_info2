#include "enemyshot.h"

void enemyshot::EnemyshotActivo()
{
    if(sprite_Enemyshot==4){
         //Se escogio en el sprite 3 el enemyshot siempre lanza una bala
        diamondEnemyShot=new diamante();

        diamondEnemyShot->seleccion_diamante(0);
        diamondEnemyShot->cargarPos_Inicial(personajeRick->saberDatos(2)+50,personajeRick->saberDatos(3)+20);
        diamond->setPos(personajeRick->saberDatos(2)+50,personajeRick->saberDatos(3)+20);
        escena->addItem(diamond);
        //se carga la escena en la clase diamante
        diamond->obtenerEscena_Diamante(escena);

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

    /*TimerDiamante= new QTimer(this);
    connect(TimerDiamante, SIGNAL(timeout()), this, SLOT(CicloAutomatico_diamante()));
    TimerDiamante->start(1000*T);*/

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

int enemyshot::posicionX_Enemyshot()
{
    return posicionX;
}

int enemyshot::posicionY_Enemyshot()
{
    return posicionY;
}
