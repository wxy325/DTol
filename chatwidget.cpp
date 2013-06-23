#include "chatwidget.h"
#include <QTextBrowser>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSplitter>

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    messageBrowser(new QTextBrowser(this)),
    inputWidget(new QLineEdit(this)),
    sendButton(new QPushButton(this))
{
//    QSplitter* splitter = new QSplitter(Qt::Vertical);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(this->messageBrowser);
    layout->addWidget(this->inputWidget);
    layout->addWidget(this->sendButton);
    this->setLayout(layout);
}


//ChatWidget::~ChatWidget()
//{
//    if (this->messageBrowser)
//    {
//        delete this->messageBrowser;
//    }
//    if (this->inputWidget)
//    {
//        delete this->inputWidget;
//    }
//    if (this->sendButton)
//    {
//        delete this->sendButton;
//    }
//}
