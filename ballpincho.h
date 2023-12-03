#ifndef BALLPINCHO_H
#define BALLPINCHO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <cmath>
#include "rick.h"

class ballpincho: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void ballActiva();
public:
    ballpincho();

    void PosicionInicial(int x, int y);
    void obtenerRick(rick *personaje);

private:

    rick *PersonajePrincipal;
    float posicionX, posicionY;
    int posXo,posYo;
    float t,n=0.0,T=1.0;
    QPixmap imagenBall;
    QTimer *timerBall;
};

#endif // BALLPINCHO_H

