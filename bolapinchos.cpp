#include "bolapinchos.h"

void bolapinchos::bolaActiva()
{

}

bolapinchos::bolapinchos()
{
    TimerBola=new QTimer;
    connect(TimerBola,SIGNAL(timeout()),this,SLOT(bolaActiva()));
    TimerBola->start(50);

}

void bolapinchos::seleccion_bola()
{
    Imagen_bola.load(":/imagenes/pinchos.png");
    Imagen_bola=Imagen_bola.scaled(20,20);
    setPixmap(Imagen_bola);
}
