#include "roca.h"
void roca::rickinRock()
{
    if(personajePrincipal->collidesWithItem(this) and personajePrincipal->saberDatos(3)>=posY_rock){
        personajePrincipal->setPos(posX_rock+5,posY_rock-60);
        personajePrincipal->actualizarFuerzas(0,0);
    }
}

roca::roca()
{
    Imagen_rocas.load(":/imagenes/sprite_roca.png");
    setPos(0, 0);
    TimerRick_Rock= new QTimer;
    connect(TimerRick_Rock, SIGNAL(timeout()), this, SLOT(rickinRock()));
    TimerRick_Rock->start(20);

}

void roca::seleccionar_roca(int tipo)
{
    Imagen_roca_ind=Imagen_rocas.copy(sizeSpriteX*tipo,0,sizeSpriteX,sizeSpriteY).scaled(70,30);
    setPixmap(Imagen_roca_ind);
}

void roca::obetener_personaje(rick *personaje)
{
    personajePrincipal=personaje;
}

void roca::cargar_posicion_rock(int x, int y)
{
    posX_rock=x;
    posY_rock=y;
}
