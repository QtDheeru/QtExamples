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
    qDebug() << Q_FUNC_INFO << " I am dying =" <<this->objectName() << endl;
    delete ui;
}
