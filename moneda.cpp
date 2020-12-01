#include "moneda.h"
#include <cuerpo.h>

moneda::moneda(int r_,int x, int y)
{
    posx=x;
    posy=y;
    r=r_;
    setPos(posx,posy);
}

QRectF moneda::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}


