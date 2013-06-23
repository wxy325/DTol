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

