#include "goldenenemy.h"

void goldenenemy::goldenenemyActivo()
{
    //preguntarse si colisiona con rick

    if(personajePrincipal->collidesWithItem(this) and personajePrincipal->saberRick_herido()==false){
        if(spriteGoldenenemy==1 or spriteGoldenenemy==2 or spriteGoldenenemy==3 or spriteGoldenenemy==4){
            personajePrincipal->actualizarVidas(personajePrincipal->saberVidas()-1);
            personajePrincipal->actualizarFuerzas(0,0);
            personajePrincipal->Seleccion_rick(9);
            personajePrincipal->actualizar_Rickherido(true);
            QTimer::singleShot(1500, this, SLOT(Actualizar_Rick_No_herido()));

        }
    }

    if(spriteGoldenenemy==0) spriteGoldenenemy=7;
    else{
        seleccion_goldenenemy(spriteGoldenenemy);
        spriteGoldenenemy--;
    }

    if(posicion_X>=0){
        this->setX(posicion_X-10);
        posicion_X-=10;
    }

}

void goldenenemy::Actualizar_Rick_No_herido()
{
    personajePrincipal->actualizar_Rickherido(false);
}

goldenenemy::goldenenemy()
{
    Imagen_goldenenemy.load(":/imagenes/Goldensprites.png");
    setPos(0, 0);
    TimerGoldenenemy= new QTimer(this);
    connect(TimerGoldenenemy, SIGNAL(timeout()), this, SLOT(goldenenemyActivo()));
    TimerGoldenenemy->start(300);

}

void goldenenemy::cargarPosicion_goldenenemy(int x, int y)
{
    posicion_X=x;
    posicion_Y=y;
}

void goldenenemy::seleccion_goldenenemy(int tipo)
{
    //los 6 primeros de los sprites--------------------
    goldenenemy_ind=Imagen_goldenenemy.copy(size_spritex*tipo, 0, size_spritex, size_spritey).scaled(90,90);
    setPixmap(goldenenemy_ind);

}

void goldenenemy::obtener_personaje_principal(rick *personaje)
{
    personajePrincipal=personaje;
}

void goldenenemy::obtener_escena_Goldenenemy(QGraphicsScene *escenita)
{
    escena_goldenenemy=escenita;
}

void goldenenemy::goldenenemy_muerto()
{
    TimerGoldenenemy->stop();
    escena_goldenenemy->removeItem(this);
    delete this;
}
