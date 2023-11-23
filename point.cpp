#include "point.h"

point::point()
{
    Imagen_point.load(":/imagenes/spritediamante .png");
    setPos(0, 0);
}

void point::seleccionar_pint()
{
    Imagen_point_ind=Imagen_point.copy(0, 0, 473, 269).scaled(30, 30);
    setPixmap(Imagen_point_ind);
}

void point::cargar_posicion_pint(int x, int y)
{
    posicion_X=x;
    posicion_Y=y;
}
