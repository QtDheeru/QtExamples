#include "MediaDataArray.h"

MediaDataArray::MediaDataArray(QObject *parent) : QObject(parent)
  , m_optimalCapacity(CHUNK_SIZE*10)
  , m_chunkSize(CHUNK_SIZE)
  , m_fullSize(-1)
  , m_realSize(0)
  , m_mode(0)
  , m_filteredSize(-1)
{
    qDebug() << Q_FUNC_INFO << endl;
}

void MediaDataArray::addItems(int start, int end, const QList<MediaObject *> list)
{
    qDebug() << Q_FUNC_INFO << " Start =" << start << " end =" << end << " Number of Elements =" << list.size() << endl;
    this->updateDateRange(start, end,list);
    this->m_realSize +=list.size();
    qDebug() << Q_FUNC_INFO << " Current Size =" << m_realSize <<endl;
}

bool MediaDataArray::updateDateRange(int start, int end, const QList<MediaObject *> list){
    int seq=start;
    foreach(MediaObject *o1, list){
        QDate date = o1->date();
        if (m_filteredModels.contains(date)){
            qDebug() << Q_FUNC_INFO << " Date already exist in DB=" << date << endl;
            FilterProxyModel *proxy = qobject_cast<FilterProxyModel*>(m_filteredModels.value(date));
            proxy->add(o1);
            int val = m_dateList.value(date);
            m_dateList.insert(date,++val);
        }else {
            qDebug() << Q_FUNC_INFO << " Adding new date =" << date << endl;
            FilterProxyModel *proxy  = new FilterProxyModel;
            proxy->setObjectName(o1->date().toString());
            proxy->add(o1);
            this->m_filteredModels.insert(date,proxy);
            if (!m_dateList.contains(date)) {
                this->m_dateList.insert(date,1);
                emit newDateAdded(date);
            }else {
                int row = m_dateList.keys().indexOf(date);
                emit newDateAddedInFilterModel(row);
            }
        }
        this->m_seqNumber2Date.insert(seq,o1->date());
        this->m_flatList.insert(seq,o1);
        seq++;
    }
    qDebug() << Q_FUNC_INFO << " Seq="<<seq << " start ="<<start << " (end-start)="<<(end-start) <<" List.size() = "<<list.size() << endl;
    Q_ASSERT((end-start)==list.size());
    return true;
}

QAbstractListModel *MediaDataArray::get(MediaDataArray::MediaDate date)
{
    qDebug() << Q_FUNC_INFO << " Fetching the data model =" << date <<endl;
    return this->m_filteredModels.value(date);
}

int MediaDataArray::getFullSize() const
{
    return m_fullSize;
}

void MediaDataArray::setFullSize(int fullSize)
{
    m_fullSize = fullSize;
    this->setFilteredSize(fullSize);
}

int MediaDataArray::getFlatSize()
{
    return this->m_sequenceList.size();
}

QDate MediaDataArray::fetchData(int index) {

    qDebug() << Q_FUNC_INFO << " Requesting the data for Date-Index =" << index << endl;

    if (index < m_dateList.size()){
        MediaDate date = this->m_dateList.keys().at(index);
        if ( index == 0) return date ;
        qDebug() << Q_FUNC_INFO << "Fetching existing Date...Check date.." <<date<<endl;
        if (!m_filteredModels.contains(date)){
            qDebug() << Q_FUNC_INFO << " Model is not present for date =" << date << endl;
            if (date<this->m_filteredModels.firstKey()){
                // backward direction
                qDebug() << Q_FUNC_INFO << " Going Backword. Current date =" << date << endl;
                FilterProxyModel *firstModel = qobject_cast<FilterProxyModel*>(this->m_filteredModels.first());
                Q_ASSERT(firstModel!=nullptr);
                MediaObject *firstItem = (firstModel)->firstItem();
                if (firstItem->seqNumber()==0) return date;
                this->fetchPreviousItems(firstItem->seqNumber());
            }
            if (date>this->m_filteredModels.lastKey()){
                // forward direction
                qDebug() << Q_FUNC_INFO << " Going forwrd. Current date =" << date << endl;
                FilterProxyModel *lastModel = qobject_cast<FilterProxyModel*>(this->m_filteredModels.last());
                Q_ASSERT(m_filteredModels.last());
                MediaObject *lastItem = (lastModel)->lastItem();
                if (lastItem->seqNumber()==this->m_fullSize) return date;
                this->fetchNextItems(lastItem->seqNumber()+1);
            }
        }else {
            qDebug() << Q_FUNC_INFO << " Model exist for date =" << date << endl;
            // check if all the elements for date exist. If not we need to fetch
        }
    } else {
        qDebug() << Q_FUNC_INFO << " Index not found. It means all dates are not fetched"<<endl;
        while(index >= m_dateList.size()){
            if (m_seqNumber2Date.size()==m_fullSize) {
                qDebug() << Q_FUNC_INFO << " All the items are fetched ="<<this->m_seqNumber2Date.size() <<endl;
                //this->setFilteredSize(m_dateList.size());
                emit allDatesProcessed(m_dateList.size(),m_fullSize);
                break;
            }
            if (m_seqNumber2Date.size() < this->m_fullSize){
                qDebug() << Q_FUNC_INFO << " Last key fetched =" << m_seqNumber2Date.lastKey() <<endl;
                this->fetchNextItems(m_seqNumber2Date.lastKey()+1);
            }
        }
    }
    // By this time date exist in the model
    if (index == m_dateList.size()){
        return QDate();
    }
    MediaDate date = this->m_dateList.keys().at(index);
    return date;
}

MediaObject *MediaDataArray::getMe(qint32 index)
{
    bool offsetPresent = this->m_flatList.contains(index);
    int lastKey  = m_flatList.lastKey();
    if (lastKey == index && lastKey != m_seqNumber2Date.lastKey()){
        this->fetchNextItems(index);
    }else {
        if (!offsetPresent){
            if (m_flatList.contains(index+1)){
                // It is backward move
                qDebug() << Q_FUNC_INFO << " Backward Move. Index =" << index <<endl;
                this->fetchPreviousItems(index+1);
            }else {
                if (m_flatList.contains((index-1))){
                    // forward move
                    qDebug() << Q_FUNC_INFO << " Forward Move. Index =" << index <<endl;
                    this->fetchNextItems(index-1);
                }
            }
        }
    }

    if (m_flatList.contains(index)){
        return m_flatList.value(index);
    }else {
        MediaObject *dummy = new MediaObject;
        dummy->setDate(QDate(0,0,0));
        dummy->setTitle("Dummy");
        dummy->setSeqNumber(-1);
        return dummy;
    }
}

int MediaDataArray::getDateIndex(qint32 offset)
{
    qDebug() << Q_FUNC_INFO << " Date Index of offset =" << offset << " is  Date =" << m_seqNumber2Date.value(offset) << " DateIndex ="<<m_dateList.keys().indexOf(this->m_seqNumber2Date.value(offset))<<endl;
    return m_dateList.keys().indexOf(this->m_seqNumber2Date.value(offset));
}

void MediaDataArray::fetchNextItems(int seq){
    qDebug() << Q_FUNC_INFO << " Sequence =" << seq <<endl;
    int start = seq;
    int end = start + m_chunkSize;
    if (end >= m_fullSize){
        end = m_fullSize;
    }
    if (this->m_flatList.size()>= m_optimalCapacity){
        qDebug() << Q_FUNC_INFO << " Garbage collector first items" <<endl;
        int firstKey = m_flatList.firstKey();
        // I know keys are sequential
        int gcEnd = firstKey+m_chunkSize-1;
        qDebug() << Q_FUNC_INFO << " GC Start =" << firstKey << " gcEnd="<<gcEnd;
        gc(firstKey,gcEnd);
    }
    qDebug() << Q_FUNC_INFO << " Start =" << start << " End=" << end << endl;
    this->fetchNextRange(start,end);
}
void MediaDataArray::fetchPreviousItems(int seq){
    qDebug() << Q_FUNC_INFO << " Sequence =" << seq <<endl;
    int start = seq - m_chunkSize;
    int end = seq;
    if (start <= 0){
        start = 0;
    }
    if (this->m_flatList.size()>= m_optimalCapacity){
        qDebug() << Q_FUNC_INFO << " Garbage collector last items" <<endl;
        int lastKey = m_flatList.lastKey();
        // I know keys is sequential
        int gcStart = lastKey-m_chunkSize+1;
        if (gcStart<0) gcStart = 0;

        qDebug() << Q_FUNC_INFO << " GC Start =" << gcStart << " gcEnd="<<lastKey;
        gc(gcStart,lastKey);
    }
    qDebug() << Q_FUNC_INFO << " Start =" << start << " End=" << end << endl;
    this->fetchNextRange(start,end);
}

void MediaDataArray::gc(int gcStart,int gcEnd) {
    qDebug() << Q_FUNC_INFO << " Current Size of Flat list =" << m_flatList.size() <<endl;
    int count=0;
    for(int i=gcStart;i<=gcEnd;i++){
        qDebug() << Q_FUNC_INFO << " Removing the sequence =" << i <<" Count "<< count++ << endl;
        MediaObject *obj = this->m_flatList.take(i);
        Q_ASSERT(obj!=nullptr);
        m_flatList.remove(i);
        // delete from date list as well
        FilterProxyModel *firstModel = qobject_cast<FilterProxyModel*>(m_filteredModels.value(obj->date()));
        Q_ASSERT(firstModel!=nullptr);
        firstModel->remove(obj);
        if (firstModel->rowCount(QModelIndex())==0){
            qDebug() << Q_FUNC_INFO << " Deleting the filter model for Date =" << obj->date() <<endl;
            this->m_filteredModels.remove(obj->date());
            delete firstModel;
        }
        delete obj;
    }
    qDebug() << Q_FUNC_INFO << " Current Flat list =" << m_flatList.size() <<endl;
}

void MediaDataArray::printFlatList()
{
    qDebug() << Q_FUNC_INFO << " **** Printing flat data ****** " <<endl;
    QList<SequenceNo> keys = m_flatList.keys();
    foreach(SequenceNo key, keys){
        qDebug() << Q_FUNC_INFO << " Seq " << key << " Media =" << m_flatList.value(key)->toString();
        qDebug() << Q_FUNC_INFO << " Date ="  << m_seqNumber2Date.value(key) <<endl;
    }
}

void MediaDataArray::printFilteredList()
{
    qDebug() << Q_FUNC_INFO << " ##### Printing filtered date data #####" <<endl;
    int sum = 0;
    QList<MediaDate> dates = m_dateList.keys();
    foreach(MediaDate ldate, dates){
        qDebug() << Q_FUNC_INFO << " Date =" << ldate << " Number of existing dates =" << m_dateList.value(ldate) <<endl;
        sum += m_dateList.value(ldate);
    }
    qDebug() << Q_FUNC_INFO << " Total number of elements =" << sum <<endl;
    QList<MediaDate> keys = m_filteredModels.keys();
    foreach(MediaDate date, keys){
        qDebug() << Q_FUNC_INFO << " Date =" << date << " Element Count =" << (m_dateList.value(date)) <<endl;
        FilterProxyModel *proxy = qobject_cast<FilterProxyModel*>(m_filteredModels.value(date));
        Q_ASSERT(proxy!=nullptr);
        proxy->print();
    }
}

void MediaDataArray::print()
{
    qDebug() << Q_FUNC_INFO << " Printing all the data for debug purpose" <<endl;
    printFlatList();
    printFilteredList();
    qDebug() << Q_FUNC_INFO << " Current Sequence queried =" << this->m_seqNumber2Date.size() <<endl;
    if (m_seqNumber2Date.size() != this->getFullSize()){
        qDebug() << Q_FUNC_INFO << " ***** All the elements are not queried yet" <<endl;
    }else {
        qDebug() << Q_FUNC_INFO << " ##### All the elements are queried " <<endl;
    }
}

MediaDataArray& MediaDataArray::instance()
{
    qDebug() << Q_FUNC_INFO << endl;
    static MediaDataArray self;
    return self;
}

bool MediaDataArray::updateItems(int start, int end, QList<MediaObject *> list)
{
    qDebug() << Q_FUNC_INFO << endl;
}
