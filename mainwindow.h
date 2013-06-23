#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class PainterWidget;
class ChatWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    PainterWidget* painterWidget;
    ChatWidget* chatWidget;

};

#endif // MAINWINDOW_H
