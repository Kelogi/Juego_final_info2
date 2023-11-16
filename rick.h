#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class rick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    rick();
    void Seleccion_rick(int Tipo);
private:
    QPixmap Imagen_rick;
    QPixmap rick_ind;
    //pueden ser macros----
    int size_spritex=188;
    int size_spritey=210;


};

#endif // RICK_H
