#include "diamante.h"

void diamante::CicloAutomatico_diamante()
{
    t=k*n*T;
    posicionX=posInicialX+Vxo*t;
    posicionY=posInicialY-Vyo*t+0.5*g*t*t;
    this->setX(posicionX);
    this->setY(posicionY);
    n+=1.0;
}

diamante::diamante()
{

    Imagen_diamantes.load(":/imagenes/spritediamante .png");
    setPos(0, 0);
    TimerDiamante= new QTimer(this);
    connect(TimerDiamante, SIGNAL(timeout()), this, SLOT(CicloAutomatico_diamante()));
    TimerDiamante->start(1000*T);
}

void diamante::cargarPos_Inicial(int x, int y)
{
    posInicialX=x;
    posInicialY=y;

}

void diamante::seleccion_diamante(int tipo)
{
    if(tipo<4) Diamante_ind=Imagen_diamantes.copy(size_spritex*tipo, 0, size_spritex, size_spritey).scaled(15,15);
    else Diamante_ind=Imagen_diamantes.copy(size_spritex*(tipo-4),  size_spritey, size_spritex, size_spritey).scaled(15,15);
    setPixmap(Diamante_ind);
}
