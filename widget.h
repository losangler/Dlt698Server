#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "service.h"
#include "threadforepoll.h"

namespace Ui {
class Client;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Client *ui;

    service myService;

    ThreadForEpoll *myEpoll;

private slots:
    void reveiveMessage(QString msg);

    void sendMessage(QString msg);
    void on_buttonSend_clicked();
    void on_buttonSend_2_clicked();
    void on_buttonSend_3_clicked();
    void on_buttonSend_4_clicked();
};

#endif // WIDGET_H
