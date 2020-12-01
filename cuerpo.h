#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsItem>
#include <QPainter>

class cuerpo: public QGraphicsItem
{
    int r;
    int posx, posy;
    int velocidad = 10;

public:
    cuerpo(int r_, int x, int y);
    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void up();
    void down();
    void left();
    void right();
};

#endif // CUERPO_H
