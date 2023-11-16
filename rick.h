#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class rick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    rick();
    void Seleccion_rick(int Tipo);
    //actualizar fuerza en un instante
    void actualizarFuerzas(float fuerzaX, float fuerzaY);
    float saberDatos(int date);
private:
    QPixmap Imagen_rick;
    QPixmap rick_ind;
    //pueden ser macros----
    int size_spritex=188;
    int size_spritey=210;


    float FuerzaEnX;
    float FuerzaEnY;


};

#endif // RICK_H
