#include "Car.h"

Car::Car(QObject *parent) : QObject(parent)
{
    QTimer *t = new QTimer;
    count =1000;
    connect(t,&QTimer::timeout, [this](){
            this->setName(QString::number(count));
            count++;
    });
    t->setInterval(5000);
    t->start();
}

void Car::updateName() {
    this->setName(QString::number(count));
    count++;
}

QString Car::getName() const
{
    return name;
}

void Car::setName(const QString &value)
{
    qDebug() << Q_FUNC_INFO << " Updating the Value =" << value << endl;
    if (value.compare(name)==0) return;
    name = value;
    emit nameChanged();
}
