#include "TimerHandling.h"
#include "ui_TimerHandling.h"

TimerHandling::TimerHandling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerHandling)
{
    ui->setupUi(this);
    this->m_gprs = new GPRS;
}

TimerHandling::~TimerHandling()
{
    delete ui;
}

void TimerHandling::on_pushButton_clicked()
{
    qDebug() << Q_FUNC_INFO << "Starting the GPRS Timer " <<endl;
    m_gprs->fun();
}
