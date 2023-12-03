#include "bolapinchos.h"

/*void bolapinchos::bolaActiva()
{
    //preguntarse si la bola de pinchos colision con rick
    if(PersonajePrincipal->collidesWithItem(this) and PersonajePrincipal->saberRick_herido()==false){
        PersonajePrincipal->actualizarVidas(PersonajePrincipal->saberVidas()-1);
        PersonajePrincipal->actualizarFuerzas(0,0);
        PersonajePrincipal->Seleccion_rick(9);
        PersonajePrincipal->actualizar_Rickherido(true);
        QTimer::singleShot(1500, this, SLOT(Actualizar_Rick_No_herido()));
        TimerBola->stop();

    }
    else{
        t=n*T;
        posicionX=Xo+70*cos(0.2*t);
        posicionY=Yo+70*sin(0.2*t);
        n+=1.0;
        this->setX(posicionX);
        this->setY(posicionY);

    }

}*/


/*void bolapinchos::Actualizar_Rick_No_herido()
{
    PersonajePrincipal->actualizar_Rickherido(false);
    PersonajePrincipal->Seleccion_rick(4);
    delete this;
}*/

void bolapinchos::cargarPosicionInicial(int xo, int yo)
{
    Xo=xo;
    Yo=yo;
}

void bolapinchos::recibirRick(rick *personaje)
{
    PersonajePrincipal=personaje;
}

bolapinchos::bolapinchos()
{
    Imagen_bola.load(":/imagenes/pinchos.png");
    setPos(0,0);
    Imagen_bola=Imagen_bola.scaled(20,20);
    setPixmap(Imagen_bola);
    //TimerBola=new QTimer;
    //connect(TimerBola,SIGNAL(timeout()),this,SLOT(bolaActiva()));
    //TimerBola->start(50);

}

