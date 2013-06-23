#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(float x, float y);

    float getX();
    float getY();
    void setX(float x);
    void setY(float Y);
private:
    float x;
    float y;
};

#endif // POINT_H
