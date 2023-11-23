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
    void actualizarVidas();
    float saberDatos(int date);
    void Mover_derecha();
    void Mover_izquierda();
    void Rick_salto();
    bool saberSalta_Rick();
    bool saberRick_herido();
    void actualizar_Rickherido(bool herido);

private:
    bool rick_herido=false;
    int vidas=10;
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

    float n=0.0, k=5.0,TY=0.1, g=9.8,Vyo=45.0, t, posicion_Y=300,xo_Salto,Vxo=20.0;
    float Aceleracion_X=0,Velocidad_X=0,Posicion_X=0, masa=250, FuerzaEnX=0,FuerzaEnY, T=100, friccionX=2;
    bool salto=false;

};

#endif // RICK_H
