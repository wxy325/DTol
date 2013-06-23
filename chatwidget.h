#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <string>
class QPushButton;
//class QTextView;
class QTextEdit;
class QLineEdit;
//class std::String;

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QWidget *parent = 0);
    QTextEdit* messageView;
    QLineEdit* inputWidget;
    QPushButton* sendButton;




signals:

public slots:
    void sendMessage();
private:
    void addMessageToBrowser(std::string& string);
};

#endif // CHATWIDGET_H
