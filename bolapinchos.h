#ifndef BOLAPINCHOS_H
#define BOLAPINCHOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
//Se obtiene direccion de memoria del obecjto de la clase rick.
#include "rick.h"
//para funciones seno y coseno.
#include <cmath>


class bolapinchos: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
//private slots:
    //void bolaActiva();
    //void Actualizar_Rick_No_herido();

public:
    bolapinchos();
    void cargarPosicionInicial(int xo, int yo);
    void recibirRick(rick *personaje);
private:
    rick *PersonajePrincipal;
    float posicionX;
    float posicionY;
    //posicion Inicial bola
    int Xo,Yo;
    QPixmap Imagen_bola;
    QTimer *TimerBola;
    float n=1.0,T=1,t;;
};

#endif // BOLAPINCHOS_H
