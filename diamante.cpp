#include "diamante.h"


void diamante::CicloAutomatico_diamante()
{
    //preguntarnos si el diamante colisiona con un objeto goldenenemy.

    if(quienDispara==true){ //El diamante fue creado por la clase rick(rick dispara el diamante)

        for(int i=0;i<(*Vector_goldenenemy).size();i++){
            if((*Vector_goldenenemy)[i]->collidesWithItem(this)){
                (*Vector_goldenenemy)[i]->goldenenemy_muerto();
                (*Vector_goldenenemy).remove(i);
            }
        }
    }
    //preguntarnos si el diamante colisiona con rick y ademas rick no esta herido.
    if(personaje_principal->collidesWithItem(this) and personaje_principal->saberRick_herido()==false){
        personaje_principal->actualizarVidas();
        personaje_principal->actualizarFuerzas(0,0);
        personaje_principal->Seleccion_rick(9);
        personaje_principal->actualizar_Rickherido(true);
        QTimer::singleShot(1500, this, SLOT(Actualizar_Rick_No_herido()));
        TimerDiamante->stop();


    }
    else{

        t=k*n*T;
        posicionX=posInicialX+Vxo*t;
        posicionY=posInicialY-Vyo*t+0.5*g*t*t;
        if(posicionY<=300+60){ //diamante toca el suelo
            this->setX(posicionX);
            this->setY(posicionY);
        }

        else{
            escenaDiamante->removeItem(this);
            delete this;
        }
        n+=1.0;
    }

}

void diamante::Actualizar_Rick_No_herido()
{
    personaje_principal->actualizar_Rickherido(false);
    personaje_principal->Seleccion_rick(4);
    escenaDiamante->removeItem(this);
    delete this;
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

void diamante::obtenerEscena_Diamante(QGraphicsScene *escenita)
{
    escenaDiamante=escenita;
}

void diamante::obtener_personaje(rick *personaje)
{
    personaje_principal=personaje;
}

void diamante::Cargar_Vxo_movimiento(int Vx)
{
    Vxo=Vx;
}

void diamante::Cargar_Vyo_movimiento(int Vy)
{
    Vyo=Vy;
}

void diamante::recibir_enemygolds(QVector<goldenenemy *> *Vector)
{
    Vector_goldenenemy=Vector;
}

void diamante::cargar_quien_dispara(bool disparo)
{
    quienDispara=disparo;
}
