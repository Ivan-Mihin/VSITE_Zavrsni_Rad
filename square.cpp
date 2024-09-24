#include "square.h"

Square::Square(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Square::getX() const
{
    return x;
}

int Square::getY() const
{
    return y;
}

void Square::setX(int x)
{
    this->x = x;
}

void Square::setY(int y)
{
    this->y = y;
}