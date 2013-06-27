#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <shape.h>
#include <QColor>

class PainterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PainterWidget(QWidget *parent = 0);

    const QColor& getCurrentStrokeColor() const{return this->currentStrokeColor;}
    const QColor& getCurrentFillColor() const {return this->currentFillColor;}
    void setCurrentStrokeColor(const QColor& color){this->currentStrokeColor = color;}
    void setCurrentFillColor(const QColor& color){this->currentFillColor = color;}

signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);    
private :
    Shape* currentShape;

    ShapeType currentType;

    QColor currentStrokeColor;
    QColor currentFillColor;

    bool fDraw;



    
};

#endif // PAINTERWIDGET_H
