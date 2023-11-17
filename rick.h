#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class rick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void CicloAutomatico_Rick();

public:
    rick();
    void Seleccion_rick(int Tipo);
    //actualizar fuerza en un instante
    void actualizarFuerzas(float fuerzaX, float fuerzaY);
    float saberDatos(int date);
    void Mover_derecha();
    void Mover_izquierda();

private:
    QPixmap Imagen_rick;
    QTimer *TimerRick;
    QPixmap rick_ind;
    //Para moverme en los pixeles de los sprites de rick
    int size_spritex=188;
    int size_spritey=210;
    //==============================


    int spriteMovDerecha=5;
    int spriteMovIzquierda=0;
    //======================

    float Aceleracion_X=0,Velocidad_X=0,Posicion_X, posicion_Y=300, masa=250, FuerzaEnX=0,FuerzaEnY, T=100, friccionX=2;

};

#endif // RICK_H
