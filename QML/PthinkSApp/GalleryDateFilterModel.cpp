#include "GalleryDateFilterModel.h"

GalleryDateFilterModel::GalleryDateFilterModel():
    m_data(MediaDataArray::instance())
{
    qDebug() << Q_FUNC_INFO << endl;
}

int GalleryDateFilterModel::getDateIndex(int offset)
{
    qDebug() << Q_FUNC_INFO << " Get the index of Offset in Date=" << offset <<endl;
    return this->m_data.getDateIndex(offset);
}

void GalleryDateFilterModel::init()
{
    int static count=0;
    qDebug() << Q_FUNC_INFO << endl;
    connect(&m_data,&MediaDataArray::newDateAdded,this,[this](MediaDate date){
        qWarning() << Q_FUNC_INFO << " Count =" << count++ << " New Date is added =" << date << endl;
        beginInsertRows(QModelIndex(),m_dateList.size(),m_dateList.size());
        this->m_dateList.append(date);
        endInsertRows();
    });
    connect(&m_data,&MediaDataArray::newDateAddedInFilterModel,this,[this](int position){
        qWarning() << Q_FUNC_INFO << " New Date Position =" << position <<endl;
        dataChanged(this->createIndex(position,0),this->createIndex(position,0));
    });
    connect(&m_data,&MediaDataArray::allDatesProcessed,this,[this](int start,int end){
        qWarning() << Q_FUNC_INFO << " Remove all the dummy rows start =" << start << " End="<<end <<endl;
        qDebug() << Q_FUNC_INFO << " Current size of the list =" << m_data.getFilteredSize() <<endl;
        beginRemoveRows(QModelIndex(),start,end);
        removeRows(start,(end-start));
        m_data.resetFilteredSize();
        endRemoveRows();
        disconnect(&m_data,&MediaDataArray::allDatesProcessed,0,0);
        qDebug() << Q_FUNC_INFO << " Removing all the elements complete" <<endl;
    });
}

int GalleryDateFilterModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << " Rows count =" << m_dateList.size() << endl;
    return this->m_data.getFilteredSize();
}

QVariant GalleryDateFilterModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO << " Fetch data for the Index Row = " << index.row() << endl;
    QVariant val;
    MediaDate date = m_data.fetchData(index.row());
    switch (role) {
    case MEDIA_DATE :
         val = date;
        break;
    case MEDIA_MODEL:
        val = QVariant::fromValue(m_data.get(date));
    }
    return val;
}

QHash<int, QByteArray> GalleryDateFilterModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO << endl;
    QHash<int, QByteArray> roles;

    roles[MEDIA_DATE] = "date";
    roles[MEDIA_MODEL] = "filteredModel";
    return roles;
}

void GalleryDateFilterModel::print()
{
     //qDebug() << Q_FUNC_INFO << " Filtered model print" << endl;
     //m_data.print();
}
