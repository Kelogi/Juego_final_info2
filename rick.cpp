#include "rick.h"

void rick::CicloAutomatico_Rick()
{
    //Aplicar las leyes de la dinamica al personaje Rick:
    Aceleracion_X = FuerzaEnX/masa;
    Velocidad_X = Aceleracion_X*T;
    //Se actuliza la nueva posicion en X de Rick
    Posicion_X = Posicion_X + Velocidad_X;
    //Dependiendo el signo de la velocidad se mueve Rick hacia la derecha o hacia la izquierda.
    if(Velocidad_X>0)this->Mover_derecha();
    if(Velocidad_X<0)this->Mover_izquierda();
    //Siempre actua la fuerza de friccion en el personaje, dependiendo el signo de la Fx de Rick se le suma o resta la de friccion.
    if(FuerzaEnX>0)FuerzaEnX -=friccionX;
    else  FuerzaEnX+=friccionX;
}

rick::rick()
{
    Imagen_rick.load(":/imagenes/sprites-rick.png");
    setPos(0, 0);
    connect(TimerRick, SIGNAL(timeout()), this, SLOT(CicloAutomatico_Rick()));
    TimerRick->start(50);
}

void rick::Seleccion_rick(int Tipo)
{

    if(Tipo < 5){
        rick_ind = Imagen_rick.copy(size_spritex*Tipo, 0, size_spritex, size_spritey).scaled(50, 60);
    }
    else if(Tipo < 12){
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
}
