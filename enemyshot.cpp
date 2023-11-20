#include "enemyshot.h"

enemyshot::enemyshot()
{
    Imagenes_enemyshot.load(":/imagenes/Sprite-enemyshot.png");
    setPos(0, 0);

    /*TimerDiamante= new QTimer(this);
    connect(TimerDiamante, SIGNAL(timeout()), this, SLOT(CicloAutomatico_diamante()));
    TimerDiamante->start(1000*T);*/

}

void enemyshot::seleccion_Enemyshot(int tipo)
{
    enemyshot_ind=Imagenes_enemyshot.copy(size_spritex*tipo, 0, size_spritex, size_spritey).scaled(50,60);
    setPixmap(enemyshot_ind);
}
