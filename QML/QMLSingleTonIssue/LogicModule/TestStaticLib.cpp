#include "TestStaticLib.h"

TestStaticLib::TestStaticLib(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}
