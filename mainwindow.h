#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "rick.h"
#include "diamante.h"
#include "enemyshot.h"
#include <QKeyEvent>

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
    diamante *diamond;
    enemyshot *enemigo1;
};
#endif // MAINWINDOW_H
