#include "point.h"

void point::Rick_obtiene_diamante()
{
    if(personajePrincipal->collidesWithItem(this)){
        personajePrincipal->actualizarPuntos(personajePrincipal->saberPuntos()+100);
        escena_Diamante->removeItem(this);
        delete this;
    }

    //preguntarnos si rick tiene 500 puntos para que obtenga un nuevo disparo o una nueva vida.
    if(personajePrincipal->saberPuntos()==500){
        personajePrincipal->actualizarPuntos(0);
        // rick adquiere una nueva vida o un nuevo disparo
    }

}

point::point()
{
    Imagen_point.load(":/imagenes/sprites-points.png");
    setPos(0, 0);

    //El diamante se pregunta en cada instante si colisiona con rick...
    TimerDiamante= new QTimer(this);
    connect(TimerDiamante, SIGNAL(timeout()), this,SLOT(Rick_obtiene_diamante()));
    TimerDiamante->start(10);
}

void point::seleccionar_point()
{
    Imagen_point_ind=Imagen_point.copy(0, 0, 470, 266).scaled(30, 30);
    setPixmap(Imagen_point_ind);
}

void point::cargar_posicion_point(int x, int y)
{
    posicion_X=x;
    posicion_Y=y;
}

void point::Obtener_personaje_principal(rick *personaje)
{
    personajePrincipal=personaje;
}

//Recibir la escena del juego para eliminar de la misma los diamantes cuando rick los coja
void point::Obtener_escena(QGraphicsScene *escenita)
{
    escena_Diamante=escenita;
}


bool point::Evento_aleatorio(){
         int num_rand = rand(), x;
         x = probabilidad*(RAND_MAX+1)-1;
         return num_rand <= x;
}

