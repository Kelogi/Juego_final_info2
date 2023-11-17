#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class rick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public slots:
    void CicloAutomatico_Rick();

public:
    rick();
    void Seleccion_rick(int Tipo);
    //actualizar fuerza en un instante
    void actualizarFuerzas(float fuerzaX, float fuerzaY);
    float saberDatos(int date);

private:
    QPixmap Imagen_rick;
    QTimer *TimerRick;
    QPixmap rick_ind;
    //pueden ser macros----
    int size_spritex=188;
    int size_spritey=210;
    //======================

    float Aceleracion_X=0,Velocidad_X=0,Posicion_X, masa=200, FuerzaEnX=0,FuerzaEnY, T=100, friccionX;

};

#endif // RICK_H
