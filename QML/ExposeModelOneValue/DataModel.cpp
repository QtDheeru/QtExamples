#include "DataModel.h"

DataModel::DataModel()
{
    for(int i=0;i<10;i++){
        QString str  = QString("Dheerendra-%1").arg(i);
        Car *car = new Car;
        car->setName(str);
        this->m_cars.append(car);
        connect(car,&Car::nameChanged,this,&DataModel::updateDataChanged);
    }
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    return 10;
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    Car *car = this->m_cars.at(index.row());
    return car->getName();
}

QHash<int,QByteArray> DataModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO << " Roles name is called"<<endl;
    QHash<int, QByteArray> role;
    role[0] = QByteArray("name");
    role[1] = QByteArray("cost");
    return role;
}

void DataModel::updateDataChanged()
{
     qDebug() << Q_FUNC_INFO << " Update the UI" <<endl;
     QModelIndex start = this->createIndex(0,0);
     QModelIndex end = this->createIndex(9,0);
     emit dataChanged(start,start);
}

Car *DataModel::getCar(int idx)
{
    QModelIndex index = this->createIndex(idx,0);
    Car *car = this->m_cars.at(idx);
    if(car!=nullptr){
        return car;
    }
}
