#include "MySum.h"
#include <QDebug>

MySum::MySum(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO << " Com Sum object is started...." << Qt::endl;
}

// This is method called from Example
int MySum::sum(int x, int y)
{
    qDebug() << Q_FUNC_INFO << " Sum Method is called" << Qt::endl;
    return (x+y);
}
