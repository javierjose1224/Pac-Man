#include "cuerpo.h"

cuerpo::cuerpo(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}

int cuerpo::getR() const
{
    return r;
}

void cuerpo::setR(int value)
{
    r = value;
}

int cuerpo::getPosx() const
{
    return posx;
}

void cuerpo::setPosx(int value)
{
    posx = value;
}

int cuerpo::getPosy() const
{
    return posy;
}

void cuerpo::setPosy(int value)
{
    posy = value;
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void cuerpo::up()
{
    posy -= 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::down()
{
    posy += 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::left()
{
    posx -= 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::right()
{
    posx += 1*velocidad;
    setPos(posx, posy);
}

