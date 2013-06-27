#include "painterwidget.h"
#include <QPainter>
#include "datamodel.h"
#include "shape.h"
#include "point.h"
#include <QPoint>
#include <QMouseEvent>
#include <iostream>
#include <stdlib.h>

PainterWidget::PainterWidget(QWidget *parent) :
    QWidget(parent),
    currentType(ShapeTypeArbiLine),
    currentShape(NULL),
    fDraw(false)
{
    this->setFixedSize(800,600);
}

void PainterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, size().width(), size().height());

    DataModel* dataModel = DataModel::shareDataModel();
    dataModel->drawAllShape(painter);
    if (this->currentShape)
    {
        currentShape->draw(painter);
    }
//    if(this->currentShape->getPoints().size() > 1)
//    {
//        for (int i = 0; i < this->currentShape->getPoints().size() - 1; i++)
//        {
//            QPoint pre = this->currentShape->getPoints()[i];
//            QPoint post = this->currentShape->getPoints()[i+1];
//            painter.drawLine(pre,post);
//        }
//    }
}

void PainterWidget::mousePressEvent(QMouseEvent *event)
{
    this->fDraw = true;
    this->currentShape = new Shape(this->currentType,this->getCurrentStrokeColor(),this->getCurrentFillColor());
    this->currentShape->getPoints().push_back(event->pos());

//    std::cerr << "(" << event->pos().x() << "," << event->pos().y() << ")";
    update();
}
void PainterWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(this->fDraw)
    {
        this->currentShape->getPoints().push_back(event->pos());
        update();
//        std::cerr << "(" << event->pos().x() << "," << event->pos().y() << ")";
    }
}
void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->fDraw)
    {
        this->currentShape->getPoints().push_back(event->pos());
        DataModel* dataModel = DataModel::shareDataModel();
        dataModel->addShape(currentShape);
        currentShape = NULL;
        update();
        this->fDraw = false;
//        std::cerr << "(" << event->pos().x() << "," << event->pos().y() << ")";
    }

}
