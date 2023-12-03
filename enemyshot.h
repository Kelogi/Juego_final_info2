#ifndef ENEMYSHOT_H
#define ENEMYSHOT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
//enemyshot al disparar crea objetos de la clase diamante
#include "diamante.h"
//para generar las velocidades de los disparos al azar
#include <stdlib.h>
#include <time.h>
//para pasarle la direccion de memoria del rick a los diamantes;
#include "rick.h" 



class enemyshot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void EnemyshotActivo();

public:
    enemyshot();
    void seleccion_Enemyshot(int tipo);
    void obtener_Escena_Enemyshot(QGraphicsScene *escenita);
    void obtener_personaje(rick *personaje);
    void cargarPosicion_Enemyshot(int x, int y);
    int posicionX_Enemyshot();
    int posicionY_Enemyshot();


private:
    QPixmap Imagenes_enemyshot;
    QPixmap enemyshot_ind;
    QTimer *TimerEnemyActivo;
    int sprite_Enemyshot=0;
    diamante *diamondEnemyShot;
    QGraphicsScene *escenaEnemyshot;
    rick *personajeRick;

    int posicionX;
    int posicionY;

    //Para moverme en los pixeles de los sprites del enemyshot
    int size_spritex=100;
    int size_spritey=99;
    //==============================

};

#endif // ENEMYSHOT_H

