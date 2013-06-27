#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>

class PainterWidget;
class ChatWidget;

class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    PainterWidget* painterWidget;
    ChatWidget* chatWidget;


    //MenuBar
    void createMenuBar();
    void createAction();
    //File
    QMenu *fileMenu;
    QAction* saveAction;

    //Connect
    QMenu *connectMenu;
    QAction* connectAction;
    QAction* disconnectAction;
    QAction* waitForConnectAction;

    //Draw
    QMenu *drawMenu;
    QMenu *colorMenu;
    QMenu *shapeMenu;
    //Choose Color
    QAction *chooseStrokeColorAction;
    QAction *chooseStrokeColorTransparentAction;
    QAction *chooseFillColorAction;
    QAction *chooseFillColorTransparentAction;

    //Choose Shape
    QAction *chooseShapeArbiLineAction;
    QAction *chooseShapeLineAction;
    QAction *chooseShapeRectAction;
    QAction *chooseShapeEllipseAction;

    void uncheckAllShape();

    //Color
    QColor strokeColor;
    QColor fillColor;

public slots:
    void chooseStrokeColor();
    void chooseFillColor();
    void chooseFillColorTransparent();
    void chooseStrokeColorTransparent();

    void chooseShapeArbiLine();
    void chooseShapeLine();
    void chooseShapeRect();
    void chooseShapeEllipse();
};

#endif // MAINWINDOW_H
