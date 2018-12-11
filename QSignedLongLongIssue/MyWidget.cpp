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

void MyWidget::handleData(signed long long data)
{
   qDebug() << " Handle the data" << data <<endl;
}

void MyWidget::on_pushButton_clicked()
{
   signed long long dt;
   dt = 1000;
   emit sendLong(dt);
}
