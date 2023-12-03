#ifndef BOLAPINCHOS_H
#define BOLAPINCHOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "rick.h"


class bolapinchos: public QObject , QGraphicsPixmapItem
{
private slots:
    void bolaActiva();


public:
    bolapinchos();
    void seleccion_bola();
private:
    QPixmap Imagen_bola;
    QTimer *TimerBola;
};

#endif // BOLAPINCHOS_H
