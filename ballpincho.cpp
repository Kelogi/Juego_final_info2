#include "ballpincho.h"

void ballpincho::ballActiva()
{



}

ballpincho::ballpincho()
{
    imagenBall.load(":/imagenes/pinchos.png");
    setPos(0,0);
    imagenBall=imagenBall.scaled(20,20);
    setPixmap(imagenBall);
    timerBall=new QTimer;
    connect(timerBall,SIGNAL(timeout()),this,SLOT(ballActiva()));
    timerBall->start(50);

}

void ballpincho::PosicionInicial(int x, int y)
{
    posXo=x;
    posYo=y;
}

void ballpincho::obtenerRick(rick *personaje)
{
    PersonajePrincipal=personaje;
}
