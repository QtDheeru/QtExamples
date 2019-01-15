#include "SitaViewModel.h"
#include <QVariant>
#include <QFont>
#include <QColor>

SitaViewModel::SitaViewModel()
{
    for(int i=0;i<10;i++){
        a.append((i+1)*(100));
    }
    this->m_idex = 5;
    this->startInsert();
}

int SitaViewModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << a.size() << endl;
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

    var = a[index.row()];
    qDebug() << Q_FUNC_INFO <<  index.row() << endl;
    switch(role){
        case Qt::DisplayRole :
            qDebug() << Q_FUNC_INFO << " Returning the data =" << var <<endl;
            break;
        case Qt::FontRole: {
            qDebug() << "Asking font role"<<endl;
            QFont font;
            if (index.row()==2){
                font.setBold(true);
                font.setPixelSize(10);
            }else {
                font.setPixelSize(10);
            }
            var = font;
            }
            break;
    case Qt::TextAlignmentRole:
            return Qt::AlignLeft + Qt::AlignVCenter;
        break;
    case Qt::SizeHintRole :{
        QSize size(100,25);
        var = size;
        break;
    }
    }
    return var;
}

void SitaViewModel::insertData()
{
    qDebug() << Q_FUNC_INFO << a.size() << endl;
    int idx = a.size()-1;
    int z = a.at(a.size()-1)+7;
    this->beginInsertRows(QModelIndex(),idx,1);
    //a.insert(0,z);
    a.append(z);
    this->endInsertRows();
}

void SitaViewModel::updateData()
{
    qDebug() << Q_FUNC_INFO << a.size() << endl;
    int z = a.at(a.size()-1)+7;
    a.insert(m_idex,z);
    QModelIndex top = this->index(m_idex);
    QModelIndex bot = this->index(m_idex);
    m_idex++;
    emit dataChanged(top,bot);
}

void SitaViewModel::startInsert()
{
    QTimer *tim = new QTimer;
    tim->setInterval(3000);
    tim->start();
    connect(tim,SIGNAL(timeout()),this,SLOT(updateData()));
}

void SitaViewModel::addData(int val)
{
    qDebug() << Q_FUNC_INFO << a.size() << endl;
    int idx = a.size()-1;
    this->beginInsertRows(QModelIndex(),idx,1);
    a.append(val);
    this->endInsertRows();
}
