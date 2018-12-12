#include "MyWidget.h"
#include "ui_MyWidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
   proc = new QProcess;
   QString pingMe = "ping 192.168.0.2";
   proc->start(pingMe);
   proc->waitForStarted(1000);
   qDebug() << " Started the process" <<endl;
   connect(proc,SIGNAL(readyRead()),this,SLOT(readData()));
}

void MyWidget::readData() {
    QString text = ui->textEdit->toPlainText();
    qDebug() << " Current Text =" << text <<endl;
    text = text + proc->readAll();
    qDebug() <<text << endl;
    ui->textEdit->setPlainText(text);
}
