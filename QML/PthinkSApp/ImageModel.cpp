#include "ImageModel.h"
#include <QTimer>


ImageModel::ImageModel():m_size(1000)
{
    for(int i=0;i<1000;i++){
        QString value = "Dheerendra-"+QString::number(i);
        qDebug() << Q_FUNC_INFO << value << endl;
        m_items.append(value);
    }
    QTimer *t = new QTimer;
    t->setInterval(20000);
    t->start();
    connect(t,&QTimer::timeout,this,[&,t](){
        beginRemoveRows(QModelIndex(),10,1000);
        int i=1000;
        while(i>10){
           this->m_items.removeLast();
           i--;
        }
        t->stop();
        endRemoveRows();
        qWarning() << Q_FUNC_INFO << " Close the same" <<endl;
    });
}


int ImageModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << " Row count " << m_size <<endl;
    return  this->m_items.size();
}

QVariant ImageModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO << " Index Row =" << index.row() <<endl;
    if (index.row() > m_items.size())
        return  "Suteerhta";
    switch(role){
    case NAME:
         return this->m_items.at(index.row());
        break;
    }
    return "Benz";
}

QHash<int, QByteArray> ImageModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NAME]="name";
    return roles;
}
