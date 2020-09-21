#include "GalleryDateFilterModel.h"

GalleryDateFilterModel::GalleryDateFilterModel():
    m_data(MediaDataArray::instance())
    , m_currentRow(0)
{
    qDebug() << Q_FUNC_INFO << endl;
    m_timer.setInterval(100);
    connect(&m_timer,&QTimer::timeout,this,[&](){
        qDebug() << Q_FUNC_INFO << " Removing the elements using the timer" <<endl;
        beginRemoveRows(QModelIndex(),m_start,m_end);
        endRemoveRows();
        this->m_timer.stop();
    });
}

int GalleryDateFilterModel::getDateIndex(int offset)
{
    qDebug() << Q_FUNC_INFO << " Get the index of Offset in Date=" << offset <<endl;
    return this->m_data.getDateIndex(offset);
}

void GalleryDateFilterModel::init()
{
    qDebug() << Q_FUNC_INFO << endl;
    connect(&m_data,SIGNAL(newDate(int,QDate)),this,SLOT(newDateAdded(int, QDate)),Qt::UniqueConnection);
    connect(&m_data,&MediaDataArray::newDateAddedInFilterModel,this,[this](int position){
        qWarning() << Q_FUNC_INFO << " New Date Position =" << position <<endl;
        dataChanged(this->createIndex(position,0),this->createIndex(position,0));
    });
    connect(&m_data,&MediaDataArray::allDatesProcessed,this,[this](int start,int end){
        qWarning() << Q_FUNC_INFO << " Remove all the dummy rows start =" << start << " End="<<end <<endl;
        qDebug() << Q_FUNC_INFO << " Current size of the list =" << m_data.getFilteredSize() <<endl;
        this->m_start = start;
        this->m_end = end;
        m_data.resetFilteredSize();
        beginRemoveRows(QModelIndex(),m_start,m_end);
        this->m_timer.start();
        endRemoveRows();
        disconnect(&m_data,&MediaDataArray::allDatesProcessed,0,0);
        qDebug() << Q_FUNC_INFO << " Removing all the elements complete" <<endl;
    });
}

void GalleryDateFilterModel::newDateAdded(int row, QDate date){
    qWarning() << Q_FUNC_INFO << " New row & date is added. Row = " << row << " Date =" << date << endl;
    emit newDate(row,date);
    this->setDate(row,date.toString("dd-MM-yyyy"));
}

QString GalleryDateFilterModel::getDate() const
{
    return m_date;
}

void GalleryDateFilterModel::setDate(int row, const QString &date)
{
    if (m_dateList.values().contains(date)) {
        return;
    }
    m_dateList.insert(row,date);
    m_date = date;
    emit dateChanged(row,date);
}

int GalleryDateFilterModel::getCurrentRow() const
{
    return m_currentRow;
}

void GalleryDateFilterModel::setCurrentRow(int currentIndex)
{
    int currentRow = m_data.getRow(currentIndex);
    qDebug() << Q_FUNC_INFO << " Index =" << currentIndex << " Corresponding Row=" << currentRow <<endl;
    if (m_currentRow == currentRow) return;
    m_currentRow = currentRow;
    emit currentRowChanged(m_currentRow);
}

int GalleryDateFilterModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << " Rows count =" << m_data.getFilteredSize() << endl;
    return this->m_data.getFilteredSize();
}

QVariant GalleryDateFilterModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO << " Fetch data for the Index Row = " << index.row() << endl;
    QVariant val;
    m_data.checkBounds(index.row());
    switch (role) {
    case MEDIA_DATE :
         val = QDate::currentDate();
        break;
    case MEDIA_MODEL:
        val = QVariant::fromValue(m_data.get(index.row()));
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

void GalleryDateFilterModel::gc(int index)
{
    qDebug() << Q_FUNC_INFO << " Delegate initiated object deletion=" << index <<endl;
    this->m_data.gc(index);
}

QString GalleryDateFilterModel::getDateForRow(int row)
{
   QString mydate = "";
   if (m_dateList.contains(row)){
       mydate = m_dateList.value(row);
   }
   return mydate;
}

void GalleryDateFilterModel::print()
{
     //qDebug() << Q_FUNC_INFO << " Filtered model print" << endl;
     //m_data.print();
}
