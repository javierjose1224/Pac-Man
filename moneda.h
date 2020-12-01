#ifndef MONEDA_H
#define MONEDA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsItem>
#include <QPainter>

class moneda: public QGraphicsItem
{

    int r;
    int posx, posy;

public:
    moneda(int r_, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void eliminar();
};

#endif // MONEDA_H







