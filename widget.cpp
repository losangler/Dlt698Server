#include "widget.h"
#include "ui_client.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    myEpoll = new ThreadForEpoll();

    myEpoll->start();
}

Widget::~Widget()
{
    this->myEpoll->interrupt();
    delete this->myEpoll;
    delete ui;
}

void Widget::reveiveMessage(QString msg)
{
    this->ui->textEditRecv->setText(msg);
}

void Widget::sendMessage(QString msg)
{
    this->ui->textEditSend->setText(msg);
}

void Widget::on_buttonSend_clicked()
{
    vector<BYTE> msg = this->myService.doResponse();

    BYTE *bytes = &msg[0];
    QString show = this->myService.byteToString(bytes, msg.size());
    this->ui->textEditSend->setText(show);
}

void Widget::on_buttonSend_2_clicked()
{
    vector<BYTE> msg = this->myService.doLinkResponse();

    BYTE *bytes = &msg[0];
    QString show = this->myService.byteToString(bytes, msg.size());
    this->ui->textEditSend->setText(show);
}

void Widget::on_buttonSend_3_clicked()
{
    vector<BYTE> msg = this->myService.doReportResponseRecordList();

    BYTE *bytes = &msg[0];
    QString show = this->myService.byteToString(bytes, msg.size());
    this->ui->textEditSend->setText(show);
}

void Widget::on_buttonSend_4_clicked()
{
    vector<BYTE> msg = this->myService.doConnectResponse();

    BYTE *bytes = &msg[0];
    QString show = this->myService.byteToString(bytes, msg.size());
    this->ui->textEditSend->setText(show);
}
