#include "point.h"

point::point()
{
    Imagen_point.load(":/imagenes/sprites-points.png");
    setPos(0, 0);
}

void point::seleccionar_point()
{
    Imagen_point_ind=Imagen_point.copy(0, 0, 470, 266).scaled(30, 30);
    setPixmap(Imagen_point_ind);
}

void point::cargar_posicion_point(int x, int y)
{
    posicion_X=x;
    posicion_Y=y;
}