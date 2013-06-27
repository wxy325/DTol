#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <QColor>
#include <QPoint>
#include <QPainter>

enum ShapeType{
    ShapeTypeArbiLine,  //任意线,任意点
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
    std::vector<QPoint>& getPoints();

    void draw(QPainter& painter) const;
    void drawPreview(QPainter& painter) const;
private:
    std::vector<QPoint> points;
    ShapeType type;

    QColor strokeColor;     //线条颜色
    QColor fillColor;       //填充颜色

    void drawShape(QPainter& painter) const;
};

#endif // SHAPE_H
