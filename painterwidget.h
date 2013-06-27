#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>

class Shape;
class PainterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PainterWidget(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private :
    Shape* currentShape;
    bool fDraw;
    
};

#endif // PAINTERWIDGET_H
