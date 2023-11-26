#ifndef DIAMANTE_H
#define DIAMANTE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "rick.h"
#include "goldenenemy.h"
#include <QVector>
class diamante:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void CicloAutomatico_diamante();
    void Actualizar_Rick_No_herido();


public:
    diamante();
    void cargarPos_Inicial(int x, int y);
    void seleccion_diamante(int tipo);
    void obtenerEscena_Diamante(QGraphicsScene *escenita);
    void obtener_personaje(rick *personaje);
    void Cargar_Vxo_movimiento(int Vx);
    void Cargar_Vyo_movimiento(int Vy);
    //se recibe la direccion de memoria en donde esta un vector que contiene los objetos tipo enemygold
    void recibir_enemygolds(QVector <goldenenemy*>*Vector);
    void cargar_quien_dispara(bool disparo);

private:
    bool quienDispara;
    QPixmap Imagen_diamantes;
    QPixmap Diamante_ind;
    QTimer *TimerDiamante;
    int posInicialX;
    int posInicialY;
    int posicionX,posicionY;
    float k=4, n=0.0, T=0.01, g=9.8, t;
    int Vxo,Vyo;
    QGraphicsScene *escenaDiamante; //recibir la escena del juego en la clase diamante
    rick *personaje_principal;
    //Para moverme en los pixeles de los sprites de rick
    int size_spritex=51;
    int size_spritey=38;
    //==============================
    QVector <goldenenemy*>*Vector_goldenenemy;

};

#endif // DIAMANTE_H

