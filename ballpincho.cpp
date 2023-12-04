#include "ballpincho.h"

void ballpincho::ballActiva()
{
    if(PersonajePrincipal->collidesWithItem(this)==true and PersonajePrincipal->saberRick_herido()==false){
        PersonajePrincipal->actualizarVidas(PersonajePrincipal->saberVidas()-1);
        PersonajePrincipal->actualizarFuerzas(0,0);
        PersonajePrincipal->Seleccion_rick(9);
        PersonajePrincipal->actualizar_Rickherido(true);
        QTimer::singleShot(1500, this, SLOT(Actualizar_Rick_No_herido()));
        timerBall->stop();


    }
    else{
        t=n*T;
        posicionX=posXo+70*cos(0.2*t);
        posicionY=posYo+70*sin(0.2*t);
        n+=1.0;
        this->setX(posicionX);
        this->setY(posicionY);
    }


}

void ballpincho::Actualizar_Rick_No_herido()
{
    PersonajePrincipal->actualizar_Rickherido(false);
    PersonajePrincipal->Seleccion_rick(4);
    delete this;
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
