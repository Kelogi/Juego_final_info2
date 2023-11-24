#ifndef POINT_H
#define POINT_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
 #include <QGraphicsScene>

class point: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    point();
    void seleccionar_point();
    void cargar_posicion_point(int x, int y );

private:
    QPixmap Imagen_point;
    QPixmap Imagen_point_ind;
    int posicion_X;
    int posicion_Y;

};

#endif // POINT_H
