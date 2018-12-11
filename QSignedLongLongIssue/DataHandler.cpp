#include "DataHandler.h"

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
    //qRegisterMetaType<signed long long>("signed long long");
}

void DataHandler::handleData(signed long long dt)
{
   qDebug() << " Data Received =" << dt << endl;
}
