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
    QMenu *fileMenu;
    QAction* saveAction;

    QMenu *connectMenu;
    QAction* connectAction;
    QAction* disconnectAction;
    QAction* waitForConnectAction;

    QMenu *drawMenu;
    QAction *chooseStrokeColorAction;
    QAction * chooseFillColorAction;

    //Color
    QColor strokeColor;
    QColor fillColor;

public slots:
    void chooseStrokeColor();
    void chooseFillColor();
};

#endif // MAINWINDOW_H
