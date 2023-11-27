#include "roca.h"
void roca::rickinRock()
{
    if(personajePrincipal->collidesWithItem(this) and personajePrincipal->saberDatos(3)>=posY_rock){
        personajePrincipal->setPos(posX_rock+25,posY_rock-50);
        personajePrincipal->actualizarFuerzas(0,0);
        personajePrincipal->actualizar_posicionRick(posX_rock+25,posY_rock-50);
        personajePrincipal->Seleccion_rick(4);
        personajePrincipal->actualizar_RickinRock(true);
        TimerRick_Rock->stop();
        personajePrincipal->recibir_Vyo(0);
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
    Imagen_roca_ind=Imagen_rocas.copy(sizeSpriteX*tipo,0,sizeSpriteX,sizeSpriteY).scaled(100,40);
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
