#include "mainwindow.h"
#include "painterwidget.h"
#include "chatwidget.h"
#include "shape.h"

#include <QSplitter>
#include <QScrollArea>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      painterWidget(new PainterWidget(this)),
      chatWidget(new ChatWidget(this))
{   
    this->createAction();
    this->createMenuBar();

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

void MainWindow::createAction()
{
    //File Actions
    this->saveAction = new QAction(tr("&Save"),this);

    //Connect Actions
    this->connectAction = new QAction(tr("&Connect"),this);
    this->disconnectAction = new QAction(tr("&Disconnect"),this);
    this->waitForConnectAction = new QAction(tr("&Wait For Connect"),this);



    //Draw Actions
    //Choose Color
    this->chooseFillColorAction = new QAction(tr("Fill Color"),this);
    connect(this->chooseFillColorAction,SIGNAL(triggered()),this,SLOT(chooseFillColor()));
    this->chooseFillColorTransparentAction = new QAction(tr("Fill Color Transparent"),this);
    connect(this->chooseFillColorTransparentAction,SIGNAL(triggered()),this,SLOT(chooseFillColorTransparent()));

    this->chooseStrokeColorAction = new QAction(tr("Stroke Color"),this);
    connect(this->chooseStrokeColorAction,SIGNAL(triggered()),this,SLOT(chooseStrokeColor()));
    this->chooseStrokeColorTransparentAction = new QAction(tr("Stroke Color Transparent"),this);
    connect(this->chooseStrokeColorTransparentAction,SIGNAL(triggered()),this,SLOT(chooseStrokeColorTransparent()));

    //Choose Shape
    this->chooseShapeArbiLineAction = new QAction(tr("Arbitrary Line"),this);
    connect(this->chooseShapeArbiLineAction ,SIGNAL(triggered()),this,SLOT(chooseShapeArbiLine()));
    this->chooseShapeArbiLineAction->setCheckable(true);
    this->chooseShapeArbiLineAction->setChecked(true);

    this->chooseShapeLineAction = new QAction(tr("Line"),this);
    connect(this->chooseShapeLineAction ,SIGNAL(triggered()),this,SLOT(chooseShapeLine()));
    this->chooseShapeLineAction->setCheckable(true);

    this->chooseShapeRectAction = new QAction(tr("Rect"),this);
    connect(this->chooseShapeRectAction ,SIGNAL(triggered()),this,SLOT(chooseShapeRect()));
    this->chooseShapeRectAction ->setCheckable(true);

    this->chooseShapeEllipseAction = new QAction(tr("Ellipse"),this);
    connect(this->chooseShapeEllipseAction ,SIGNAL(triggered()),this,SLOT(chooseShapeEllipse()));
    this->chooseShapeEllipseAction->setCheckable(true);
}

void MainWindow::createMenuBar()
{
    //File Menu
    this->fileMenu = menuBar()->addMenu(tr("File"));
    this->fileMenu->addAction(this->saveAction);

    //Connect Menu
    this->connectMenu = menuBar()->addMenu(tr("Connect"));
    this->connectMenu->addAction(this->connectAction);
    this->connectMenu->addAction(this->disconnectAction);
    this->connectMenu->addAction(this->waitForConnectAction);

    //Draw Menu
    this->drawMenu = menuBar()->addMenu(tr("Draw"));
    this->colorMenu = this->drawMenu->addMenu(tr("Color"));
    this->colorMenu->addAction(this->chooseStrokeColorAction);
    this->colorMenu->addAction(this->chooseFillColorAction);
    this->colorMenu->addAction(this->chooseStrokeColorTransparentAction);
    this->colorMenu->addAction(this->chooseFillColorTransparentAction);
    this->shapeMenu = this->drawMenu->addMenu(tr("Shape"));
    this->shapeMenu->addAction(this->chooseShapeArbiLineAction);
    this->shapeMenu->addAction(this->chooseShapeLineAction);
    this->shapeMenu->addAction(this->chooseShapeRectAction);
    this->shapeMenu->addAction(this->chooseShapeEllipseAction);

}


void MainWindow::chooseStrokeColor()
{
    QColor color = QColorDialog::getColor(Qt::white,this,tr("Choose Stroke Color"));
//    this->strokeColor = color;
    this->painterWidget->setCurrentStrokeColor(color);

}
void MainWindow::chooseFillColor()
{
    QColor color = QColorDialog::getColor(Qt::white,this,tr("Choose Stroke Color"));
//    this->fillColor = color;
    this->painterWidget->setCurrentFillColor(color);

}

void MainWindow::chooseShapeArbiLine()
{
    this->painterWidget->setCurrentType(ShapeTypeArbiLine);
    this->uncheckAllShape();
    this->chooseShapeArbiLineAction->setChecked(true);
}
void MainWindow::chooseShapeLine()
{
    this->painterWidget->setCurrentType(ShapeTypeLine);
    this->uncheckAllShape();
    this->chooseShapeLineAction->setChecked(true);
}
void MainWindow::chooseShapeRect()
{
    this->painterWidget->setCurrentType(ShapeTypeRect);
    this->uncheckAllShape();
    this->chooseShapeRectAction->setChecked(true);
}
void MainWindow::chooseShapeEllipse()
{
    this->painterWidget->setCurrentType(ShapeTypeEllipse);
    this->uncheckAllShape();
    this->chooseShapeEllipseAction->setChecked(true);
}

void MainWindow::uncheckAllShape()
{
    this->chooseShapeArbiLineAction->setChecked(false);
    this->chooseShapeLineAction->setChecked(false);
    this->chooseShapeRectAction->setChecked(false);
    this->chooseShapeEllipseAction->setChecked(false);
}

void MainWindow::chooseFillColorTransparent()
{
    this->painterWidget->setCurrentFillColor(Qt::transparent);
}
void MainWindow::chooseStrokeColorTransparent()
{
    this->painterWidget->setCurrentStrokeColor(Qt::transparent);
}

//void MainWindow::resizeEvent(QResizeEvent* event)
//{

//}
