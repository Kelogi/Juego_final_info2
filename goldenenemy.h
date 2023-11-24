#ifndef GOLDENENEMY_H
#define GOLDENENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "rick.h"


class goldenenemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void goldenenemyActivo();
    void Actualizar_Rick_No_herido();

public:
    goldenenemy();
    void cargarPosicion_goldenenemy(int x, int y);
    void seleccion_goldenenemy(int tipo);
    void obtener_personaje_principal(rick *personaje);
    void obtener_escena_Goldenenemy(QGraphicsScene *escenita);

private:
    QPixmap Imagen_goldenenemy;
    QPixmap goldenenemy_ind;
    QTimer *TimerGoldenenemy;
    int posicion_X;
    int posicion_Y;
    //Para moverme en los pixeles de los sprites del goldenenemy
    int size_spritex=113;
    int size_spritey=88;
    //==============================
    int spriteGoldenenemy=7;

    //Siempre que un goldenenemy se mueva preguntarse si esta colisionando con el personaje principal
    //obtener direccion de memoria del personaje
    rick *personajePrincipal;
    //obtener escen del juego en la clase
    QGraphicsScene *escena_goldenenemy;


};

#endif // GOLDENENEMY_H



