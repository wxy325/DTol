#include "mainwindow.h"
#include "painterwidget.h"
#include "chatwidget.h"
#include <QSplitter>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      painterWidget(new PainterWidget(this)),
      chatWidget(new ChatWidget(this))
{
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setWidget(painterWidget);
    QSplitter* splitter = new QSplitter(Qt::Horizontal);
//    splitter->addWidget(painterWidget);
    splitter->addWidget(scrollArea);
    splitter->addWidget(chatWidget);
    this->setCentralWidget(splitter);
    resize(1000,600);
}

MainWindow::~MainWindow()
{
//    delete painterWidget;
}

//void MainWindow::resizeEvent(QResizeEvent* event)
//{

//}
