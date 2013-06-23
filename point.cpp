#include "point.h"

Point::Point()
{
    this->x = 0.f;
    this->y = 0.f;
}

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}


float Point::getX()
{
    return this->x;
}

float Point::getY()
{
    return this->y;
}
void Point::setX(float x)
{
    this->x = x;
}

void Point::setY(float Y)
{
    this->y = y;
}
