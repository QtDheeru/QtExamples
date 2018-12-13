#include "GPRS.h"

GPRS::GPRS(QObject *parent) : QObject(parent)
{

}

void GPRS::fun()
{
    qDebug() << Q_FUNC_INFO << " Timer is started " <<endl;
    this->m_timer = new QTimer;
    connect(m_timer,&QTimer::timeout,this,&GPRS::timerExpired);
    this->m_timer->start(2000);
}

void GPRS::timerExpired()
{
    qDebug() << Q_FUNC_INFO << "Timer expired " <<endl;
}
