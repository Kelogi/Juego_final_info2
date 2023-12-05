#ifndef ROCA_H
#define ROCA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "rick.h"
#include <QTimer>


class roca:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void rickinRock();

public:

    roca();
    void seleccionar_roca(int tipo);
    void obetener_personaje(rick *personaje);
    void cargar_posicion_rock(int x, int y);

private:
    QPixmap Imagen_rocas;
    QPixmap Imagen_roca_ind;
    QTimer *TimerRick_Rock;
    int posX_rock;
    int posY_rock;
    //la roca se pregunta si esta colisionan con rick;
    rick *personajePrincipal;
    //para movernos en los pixeles de la imagen Imagen_rocas y elegir la roca que se desea
    int sizeSpriteX=223;
    int sizeSpriteY=74;

};

#endif // ROCA_H


