#include "chatwidget.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSplitter>
#include <string>
#include <QTextCursor>
#include "datamodel.h"

using namespace std;

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    messageView(new QTextEdit(this)),
    inputWidget(new QLineEdit(this)),
    sendButton(new QPushButton(this))
{
//    QSplitter* splitter = new QSplitter(Qt::Vertical);
    this->sendButton->setText(QString("发送"));
    this->messageView->setReadOnly(true);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(this->messageView);
    layout->addWidget(this->inputWidget);
    layout->addWidget(this->sendButton);
    this->setLayout(layout);       

    connect(this->sendButton, SIGNAL(clicked()),this, SLOT(sendMessage()));
}

void ChatWidget::sendMessage()
{
    DataModel* p_DataModel = DataModel::shareDataModel();
    QString qStrMessage = this->inputWidget->text();
    char* chMessage =  qStrMessage.toLatin1().data();
    string strMessage = string(chMessage);
    p_DataModel->sendMessage(strMessage);
    this->addMessageToBrowser(strMessage);
    this->inputWidget->setText(QString(""));
}
void ChatWidget::addMessageToBrowser(string &string)
{
    QString qStr =QString(string.c_str());
    QString preMessage = this->messageView->toPlainText();
    if(preMessage.length() != 0)
    {
        preMessage.append(QString("\n"));
    }
    preMessage.append(qStr);
    this->messageView->setText(preMessage);
    this->scrollMessageViewToBottom();
}
void ChatWidget::scrollMessageViewToBottom()
{
    QTextCursor cursor = this->messageView->textCursor();
    cursor.movePosition(QTextCursor::End);
    this->messageView->setTextCursor(cursor);
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
