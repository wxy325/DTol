#include "shape.h"
#include "point.h"
#include <QBrush>
#include <QRect>


using namespace std;
Shape::Shape(ShapeType type, QColor strokeColor, QColor fillColor):
    points(vector<QPoint>())
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
vector<QPoint>& Shape::getPoints()
{
    return this->points;
}


//Draw Method
void Shape::draw(QPainter& painter) const
{
    QBrush fillBrush = QBrush(this->fillColor);
    painter.setBrush(fillBrush);
    painter.setPen(this->strokeColor);

    this->drawShape(painter);
}

void Shape::drawPreview(QPainter& painter) const
{

}

void Shape::drawShape(QPainter& painter) const
{
    painter.setRenderHint(QPainter::Antialiasing, true);    //反走样
    switch (this->type)
    {
    case ShapeTypeArbiLine:
        if (this->points.size() > 1)
        {
            for (int i = 0; i < this->points.size() - 1; i++)
            {
                painter.drawLine(this->points[i],this->points[i + 1]);
            }
        }
        else
        {
            return;
        }

        break;
    case ShapeTypeLine:
        if (this->points.size() != 2)
        {
            return;
        }
        else
        {
            painter.drawLine(this->points[0],this->points[1]);
        }
        break;
    case ShapeTypeRect:
        if (this->points.size() != 2)
        {
            return;
        }
        else
        {
            painter.drawRect(QRect(this->points[0],this->points[1]));
        }
        break;
    case ShapeTypeEllipse:
        if (this->points.size() != 2)
        {
            return;
        }
        else
        {
            painter.drawEllipse(QRect(this->points[0],this->points[1]));
        }
        break;
    }
}
