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
    ~MainWindow();

private:
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

    //QGraphicsPixmapItem *fondo;

    roca *roquita;


};
#endif // MAINWINDOW_H
