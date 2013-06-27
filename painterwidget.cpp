#include "painterwidget.h"
#include <QPainter>
#include "datamodel.h"
#include "shape.h"
#include "point.h"
#include <QPoint>
#include <QMouseEvent>
#include <iostream>

PainterWidget::PainterWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(800,600);

    this->currentShape = new Shape(ShapeTypeArbiLine,Qt::black,Qt::black);
    this->fDraw = false;
}

void PainterWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, size().width(), size().height());

    if(this->currentShape->getPoints().size() > 1)
    {
        for (int i = 0; i < this->currentShape->getPoints().size() - 1; i++)
        {
            QPoint pre = this->currentShape->getPoints()[i];
            QPoint post = this->currentShape->getPoints()[i+1];
            painter.drawLine(pre,post);
        }
    }
}

void PainterWidget::mousePressEvent(QMouseEvent *event)
{
    this->fDraw = true;
    this->currentShape->getPoints().push_back(event->pos());

    std::cerr << "(" << event->pos().x() << "," << event->pos().y() << ")";
    update();
}
void PainterWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(this->fDraw)
    {
        this->currentShape->getPoints().push_back(event->pos());
        update();
        std::cerr << "(" << event->pos().x() << "," << event->pos().y() << ")";
    }
}
void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->fDraw)
    {
        this->currentShape->getPoints().push_back(event->pos());
        update();
        this->fDraw = false;
        std::cerr << "(" << event->pos().x() << "," << event->pos().y() << ")";
    }

}
