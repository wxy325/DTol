#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <QColor>

enum ShapeType{
    ShapeTypeLine,  //直线,2点
    ShapeTypeRect,  //矩形,2点
    ShapeTypeEllipse    //椭圆,2点
};

class Point;
class Shape
{
public:
    Shape(ShapeType type, QColor strokeColor, QColor fillColor);

    QColor getStrokeColor();
    QColor getFillColor();
    void setStrokeColor(QColor c);
    void setFillColor(QColor c);
    std::vector<Point>& getPoints();
private:
    std::vector<Point> points;
    ShapeType type;

    QColor strokeColor;     //线条颜色
    QColor fillColor;       //填充颜色
};

#endif // SHAPE_H
