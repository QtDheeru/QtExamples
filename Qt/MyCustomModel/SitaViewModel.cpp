#include "SitaViewModel.h"
#include <QVariant>
#include <QFont>
#include <QColor>

SitaViewModel::SitaViewModel()
{
    for(int i=0;i<10;i++){
        a.append((i+1)*(100));
    }
}

int SitaViewModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << a.size() << endl;
    if (this->objectName().compare("Single")==0) {
        return 1;
    }
    return a.size();
}

int SitaViewModel::columnCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << a.size() << endl;
    if (this->objectName().compare("Single")==0) {
        return 1;
    }
    return 1;
}

QVariant SitaViewModel::data(const QModelIndex &index, int role) const
{
    QVariant var;
    if (this->objectName().compare("Single")==0) {
        var = a.at(0);
        return var;
    }
    var = a[index.row()];
    qDebug() << index.row() << endl;
    switch(role){
    case Qt::FontRole: {
        qDebug() << "Asking font role"<<endl;
        QVariant var1;
        QFont font;
        if (index.row()==2){
            font.setBold(true);
            font.setPixelSize(10);
        }else {
            font.setPixelSize(10);
        }
        var1 = font;
        return var1;
        break;
    }
    case Qt::BackgroundRole: {
        QColor col1(0,255,255);
        QVariant var2 = col1;
        return var2;
    }
        break;
    case Qt::ForegroundRole:{
        QColor col2(0,0,0);
        QVariant var3 = col2;
        return var3;
        break;
    }

    case Qt::ToolTipRole :
        QString val = "Go to Hell";
        return val;
    }
    return var;
}

void SitaViewModel::insertData()
{
     qDebug() << Q_FUNC_INFO << a.size() << endl;
     int z = a.at(a.size()-1);
     this->beginInsertRows(QModelIndex(),0,0);
     //a.insert(0,z);
     a.append(z);
     this->endInsertRows();
}

void SitaViewModel::startInsert()
{
    QTimer *tim = new QTimer;
    tim->setInterval(5000);
    tim->start();
    connect(tim,SIGNAL(timeout()),this,SLOT(insertData()));
}
