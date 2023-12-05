#ifndef POINT_H
#define POINT_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "rick.h"

class point: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public slots:
    void Rick_obtiene_diamante();
public:
    point();
    void seleccionar_point();
    bool Evento_aleatorio();
    void cargar_posicion_point(int x, int y );
    void Obtener_personaje_principal(rick *personaje);
    void Obtener_escena(QGraphicsScene *escenita);

private:
    float probabilidad=0.6;
    QPixmap Imagen_point;
    QPixmap Imagen_point_ind;
    rick *personajePrincipal;
    QTimer *TimerDiamante;
    QGraphicsScene *escena_Diamante;
    int posicion_X;
    int posicion_Y;

};

#endif // POINT_H
