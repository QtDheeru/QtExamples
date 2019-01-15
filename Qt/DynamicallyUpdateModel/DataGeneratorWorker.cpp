#include "DataGeneratorWorker.h"

DataGeneratorWorker::DataGeneratorWorker(QObject *parent) : QObject(parent)
{

}

void DataGeneratorWorker::generateData() {
    QTimer *ti = new QTimer;
    ti->setInterval(5000);
    this->count = 2000;
    connect(ti,&QTimer::timeout,[=](){
        count +=17;
        qWarning() << Q_FUNC_INFO << "Sending the Data =" << count << " Thread "  << QThread::currentThreadId() << endl;
        emit sendData(count);
    });
    ti->start();
}
