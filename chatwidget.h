#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

class QPushButton;
class QTextBrowser;
class QTextEdit;
class QLineEdit;

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QWidget *parent = 0);
    QTextBrowser* messageBrowser;
    QLineEdit* inputWidget;
    QPushButton* sendButton;

signals:
    
public slots:
    
};

#endif // CHATWIDGET_H
