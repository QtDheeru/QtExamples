#include "MyWidget.h"
#include "ui_MyWidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    this->m_semLock = new QSemaphore(1);
    this->m_Consumer = new Consumer;
    this->m_Producer = new Producer;

    this->m_Consumer->setSemLock(m_semLock);
    this->m_Producer->setSemLock(m_semLock);

    connect(m_Consumer,&Consumer::sig_add_data,this,&MyWidget::setDataConsumer);
    connect(m_Producer,&Producer::sig_add_data,this,&MyWidget::setDataProducer);
}


void MyWidget::setDataConsumer(int sum){
    this->ui->lineEditConsumer->setText(QString::number(sum));
}

void MyWidget::setDataProducer(int sum){
    this->ui->lineEditProducer->setText(QString::number(sum));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    this->m_Consumer->start();
    //this->m_Producer->start();
}

void MyWidget::on_pushButtonStart_clicked()
{
    this->m_Consumer->start();
    this->m_Producer->start();
}

void MyWidget::on_pushButton_Stop_clicked()
{
    this->m_Consumer->quit();
    this->m_Producer->quit();
}
