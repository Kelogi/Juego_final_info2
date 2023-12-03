#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "diamante.h"
#include "enemyshot.h"
#include "goldenenemy.h"
#include <QKeyEvent>
#include <QVector>
#include "point.h"
#include "roca.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void keyPressEvent(QKeyEvent *tecla);
    MainWindow(QWidget *parent = nullptr);
    void set_focus(QGraphicsPixmapItem *item);
    ~MainWindow();

    bool Evento_aleatorio();

private slots:
    void on_pushButton_clicked();

private:

    float probabilidad=0.6;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    rick *personajeRick;
    //Los enemigos se guardan en un vector que contiene objetos tipo enemyshots.
    QVector<enemyshot*>vectorEnemyshots;
    diamante *diamond;
    //Los enemigos se guardan en un vector que contiene objetos tipo goldenemys.
    QVector<goldenenemy*>vectorGoldenenemy;

    //Los points se guardan en un vector que contiene objetos tipo point.
    QVector<point*>vectorPoints;

    //Las rocas se guardan en un vector que contiene objeticos tipo roca
    QVector<roca*>vectorRocas;

    //para el fondo del juego
    QGraphicsPixmapItem *fondo;


};
#endif // MAINWINDOW_H
