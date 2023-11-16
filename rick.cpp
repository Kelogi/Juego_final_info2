#include "rick.h"

rick::rick()
{
    Imagen_rick.load(":/imagenes/sprites-rick.png");
    setPos(0, 0);
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
    if(date==1) return FuerzaEnX;
    else if(date==2) return FuerzaEnY;
}
