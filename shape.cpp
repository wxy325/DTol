#include "shape.h"
#include "point.h"


using namespace std;
Shape::Shape(ShapeType type, QColor strokeColor, QColor fillColor):
    points(vector<Point>())
{
    this->type = type;
    this->strokeColor = strokeColor;
    this->fillColor = fillColor;
}



//Getter And Setter Method
QColor Shape::getStrokeColor()
{
    return this->strokeColor;
}
QColor Shape::getFillColor()
{
    return this->fillColor;
}
void Shape::setStrokeColor(QColor c)
{
    this->strokeColor = c;
}
void Shape::setFillColor(QColor c)
{
    this->fillColor = c;
}
vector<Point>& Shape::getPoints()
{
    return this->points;
}
