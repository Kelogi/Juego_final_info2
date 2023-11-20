#ifndef ENEMYSHOT_H
#define ENEMYSHOT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class enemyshot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:

public:
    enemyshot();
    void seleccion_Enemyshot(int tipo);
private:
    QPixmap Imagenes_enemyshot;
    QPixmap enemyshot_ind;
    QTimer *TimerEnemyActivo;

    int posicionX;
    int posicionY;

    //Para moverme en los pixeles de los sprites del enemyshot
    int size_spritex=100;
    int size_spritey=99;
    //==============================
};

#endif // ENEMYSHOT_H

