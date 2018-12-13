#include "HWDevice.h"

HWDevice::HWDevice(QObject *parent) : QObject(parent)
{
    QTimer *t1 = new QTimer;
    connect(t1,&QTimer::timeout,this,&HWDevice::data1);

    QTimer *t2 = new QTimer;
    connect(t2,&QTimer::timeout,this,&HWDevice::data2);

    t1->start(3000);
    t2->start(7000);
}
