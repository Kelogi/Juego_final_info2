#include "rick.h"

void rick::CicloAutomatico_Rick()
{
    //Aplicar las leyes de la dinamica al personaje Rick en direccion del eje X:
    Aceleracion_X = FuerzaEnX/masa;
    Velocidad_X = Aceleracion_X*T;
    //Se actuliza la nueva posicion en X de Rick
    Posicion_X = Posicion_X + Velocidad_X;
    //Dependiendo el signo de la velocidad se mueve Rick hacia la derecha o hacia la izquierda.
    if(FuerzaEnX!=0){
        if(Velocidad_X>0)this->Mover_derecha();
        if(Velocidad_X<0)this->Mover_izquierda();
        //Siempre actua la fuerza de friccion en el personaje, dependiendo el signo de la Fx de Rick se le suma o resta la de friccion.
        if(FuerzaEnX>0)FuerzaEnX -=friccionX;
        else  FuerzaEnX+=friccionX;
     }
    else Seleccion_rick(4);

    //Aplicar las leyes de la dinamica al personaje Rick en direcicno del eje Y
    if(salto==true){
        t=k*n*TY;
        posicion_Y=300-Vyo*t+0.5*g*t*t;

        if(posicion_Y<=300)this->setY(posicion_Y);
        else {
            salto=false;
            setY(300);
            n=0.0;
        }
        n+=1.0;
    }
}

rick::rick()
{
    Imagen_rick.load(":/imagenes/sprites-rick.png");
    setPos(0, 0);
    TimerRick= new QTimer(this);
    connect(TimerRick, SIGNAL(timeout()), this, SLOT(CicloAutomatico_Rick()));
    TimerRick->start(50);
}

void rick::Seleccion_rick(int Tipo)
{

    if(Tipo < 5){
        rick_ind = Imagen_rick.copy(size_spritex*Tipo, 0, size_spritex, size_spritey).scaled(50, 60);
    }
    else if(Tipo < 9){
        rick_ind = Imagen_rick.copy(size_spritex*(Tipo-5), size_spritey, size_spritex, size_spritey).scaled(50, 60);
    }
    setPixmap(rick_ind);

}

void rick::actualizarFuerzas(float fuerzaX, float fuerzaY)
{
    FuerzaEnX=fuerzaX;
    FuerzaEnY=fuerzaY;
}

float rick::saberDatos(int date)
{
    if(date==0) return FuerzaEnX;
    else if(date==1) return FuerzaEnY;
    else if (date==2) return Posicion_X;
    else if(date==3) return posicion_Y;
}

void rick::Mover_derecha()
{
    //se efectua el cambio de sprites.
    if(spriteMovDerecha<9) Seleccion_rick(spriteMovDerecha);

    else if(spriteMovDerecha==9) spriteMovDerecha=5;

    spriteMovDerecha++;
    //se actualiza la posicion de Rick
    this->setX(Posicion_X);

}

void rick::Mover_izquierda()
{
    //se efectua el cambio de sprites.
    if(spriteMovIzquierda<4) Seleccion_rick(spriteMovIzquierda);

    else if(spriteMovIzquierda==4) spriteMovIzquierda=0;

    spriteMovIzquierda++;
    //se actualiza la posicion de Rick
    this->setX(Posicion_X);
}

void rick::Rick_salto()
{
    FuerzaEnX=0;
    salto=true;
}

bool rick::saberSalta_Rick()
{
    return salto;
}
