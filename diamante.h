#ifndef DIAMANTE_H
#define DIAMANTE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class diamante:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void CicloAutomatico_diamante();


public:
    diamante();
    void cargarPos_Inicial(int x, int y);
    void seleccion_diamante(int tipo);


private:
    QPixmap Imagen_diamantes;
    QPixmap Diamante_ind;
    QTimer *TimerDiamante;
    int posInicialX;
    int posInicialY;
    int posicionX,posicionY;
    float k=2.5, n=0.0, T=0.01, g=9.8, Vxo=45.0,Vyo=30.0, t;
    //Para moverme en los pixeles de los sprites de rick
    int size_spritex=51;
    int size_spritey=38;
    //==============================

};

#endif // DIAMANTE_H

