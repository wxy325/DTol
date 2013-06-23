#include "painterwidget.h"
#include <QPainter>
#include "datamodel.h"

PainterWidget::PainterWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(800,600);
}



void PainterWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, size().width(), size().height());
}

void PainterWidget::mousePressEvent(QMouseEvent *event)
{

}
void PainterWidget::mouseMoveEvent(QMouseEvent *event)
{

}
void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{

}
