#include "MediaDataArray.h"

MediaDataArray::MediaDataArray(QObject *parent) : QObject(parent)
  , m_optimalCapacity(CHUNK_SIZE*10)
  , m_chunkSize(CHUNK_SIZE)
  , m_fullSize(-1)
  , m_realSize(0)
  , m_filteredSize(-1)
  , m_swipeDirection(FORWARD)
  , m_prevDate(0,0,0)
  , m_UiColumnCount(0)
  , m_UiRowCount(-1)
  , m_activeRowStart(0)
  , m_activeRowEnd(0)
{
    qDebug() << Q_FUNC_INFO << endl;
    this->initFreePool();
}

void MediaDataArray::initFreePool() {
    for(int i=0;i<MAX_MODELS;i++){
        FilterProxyModel *proxy = new FilterProxyModel;
        this->m_freeProxyModelPool.append(proxy);
    }
}

void MediaDataArray::addItems(int start, int end, const QList<MediaObject *> list)
{
    qDebug() << Q_FUNC_INFO << " Start =" << start << " end =" << end << " Number of Elements =" << list.size() << endl;
    this->updateDateRange(start, end,list);
    this->m_realSize +=list.size();
    qDebug() << Q_FUNC_INFO << " Current Size =" << m_realSize <<endl;
}

bool MediaDataArray::updateDateRange(int start, int end, const QList<MediaObject *> list){
    switch (m_swipeDirection) {
        case FORWARD:{
            updateRangeForward(start,end,list);
        break;
        }
        case BACKWARD:{
            updateRangeBackward(start,end,list);
        break;
        }
        default:{
            qWarning() << Q_FUNC_INFO << " You should never see this message. If you see this, your logic is wrong"<<endl;
        }
    }
}

bool MediaDataArray::updateRangeForward(int start, int end, const QList<MediaObject *> list){
    qDebug() << Q_FUNC_INFO << " Start =" << start << " End=" << end  <<endl;
    int seq=start;
    foreach(MediaObject *o1, list){
        QDate date = o1->date();
        Q_ASSERT(seq == o1->seqNumber());
        if (m_seqNumber2Row.contains(o1->seqNumber())){
            m_UiRowCount = m_seqNumber2Row.value(o1->seqNumber());
            qDebug() << Q_FUNC_INFO << " Row =" << m_UiRowCount << " found for the seq =" << o1->seqNumber() << endl;
        } else {
            qDebug() << Q_FUNC_INFO << "Adding -> Seq =" << o1->seqNumber() << " Date =" << date << " PrevDate =" << m_prevDate << " Row =" << m_UiRowCount << endl;
            if (date == m_prevDate){
                qDebug() << Q_FUNC_INFO << "Dates are equal. Date =" << date << " PrevDate =" << m_prevDate << " Row =" << m_UiRowCount << endl;
                if (m_UiColumnCount>=COLUMN_COUNT){
                    m_UiColumnCount=0;
                    m_UiRowCount++;
                    QList<SequenceNo> sList;
                    this->m_row2SequenceList.insert(m_UiRowCount,sList);
                    qDebug() << Q_FUNC_INFO << "5 Elements added. Start next Row - Date =" << date << " PrevDate =" << m_prevDate << " Row =" << m_UiRowCount << endl;
                }
                QList<SequenceNo> seqList = m_row2SequenceList.value(m_UiRowCount);
                seqList.append(o1->seqNumber());
                this->m_row2SequenceList.insert(m_UiRowCount,seqList);
                int val = m_dateList.value(date);
                m_dateList.insert(date,++val);
                m_UiColumnCount++;
                m_prevDate = date;
            }else {
                qDebug() << Q_FUNC_INFO << " Dates are not same. Prev Date =" << m_prevDate << " Processing Date=" << date <<endl;
                m_UiRowCount++;
                m_UiColumnCount=0;
                qDebug() << Q_FUNC_INFO << " Adding new Row =" << m_UiRowCount << " For Date =" << date << endl;
                m_UiColumnCount=0;
                QList<SequenceNo> seqList;
                seqList.append(o1->seqNumber());
                this->m_row2SequenceList.insert(m_UiRowCount,seqList);
                m_mediaDate2RowCount.insert(date,m_UiRowCount);
                m_UiColumnCount++;
                m_prevDate = date;
                emit newDate(m_UiRowCount,date);
            }
            this->m_seqNumber2Date.insert(seq,o1->date());
            this->m_seqNumber2Row.insert(seq,m_UiRowCount);
        }
        this->m_flatList.insert(seq,o1);
        seq++;
    }

    int firstSeq = this->m_flatList.firstKey();
    int lastSeq = this->m_flatList.lastKey();
    this->m_activeRowStart = this->m_seqNumber2Row.value(firstSeq);
    this->m_activeRowEnd = this->m_seqNumber2Row.value(lastSeq);

    qDebug() << Q_FUNC_INFO << "FirstKey=" << firstSeq << " LastKey=" << lastSeq  << " First Row =" << m_activeRowStart << " Current Last Row=" << m_activeRowEnd <<endl;
    Q_ASSERT(m_activeRowEnd >= m_activeRowStart);
    qDebug() << Q_FUNC_INFO << " ************* It is complete **************" <<endl;
    qDebug() << Q_FUNC_INFO << " Seq="<<seq << " start ="<<start << " (end-start)="<<(end-start) <<" List.size() = "<<list.size() << endl;
    Q_ASSERT((end-start)==list.size());
    return true;
}

bool MediaDataArray::updateRangeBackward(int start, int end, const QList<MediaObject *> list) {

    int seq=start;
    foreach(MediaObject *o1, list){
        this->m_flatList.insert(seq,o1);
        seq++;
    }
    int firstSeq = this->m_flatList.firstKey();
    int lastSeq = this->m_flatList.lastKey();
    this->m_activeRowStart = this->m_seqNumber2Row.value(firstSeq);
    this->m_activeRowEnd = this->m_seqNumber2Row.value(lastSeq);

    Q_ASSERT(m_activeRowEnd > m_activeRowStart);
    qDebug() << Q_FUNC_INFO << " First Row =" << m_activeRowStart << " Current Last Row=" << m_activeRowEnd <<endl;

    return true;
}

QAbstractListModel *MediaDataArray::get(MediaDataArray::RowCount row)
{
    FilterProxyModel *proxy = nullptr;
    QList<SequenceNo> list = this->m_row2SequenceList.value(row);
    this->printFlatList();
    qDebug() << Q_FUNC_INFO << " Fetching the data model for Row=" << row <<" Sequences =" << list << endl;
    if (m_rowModels.contains(row)){
        qDebug() << Q_FUNC_INFO << " Existing Model for the Row =" << row << endl;
        proxy = qobject_cast<FilterProxyModel*>(m_rowModels.value(row));
        proxy->resetSize();
        foreach(auto seqNo, list){
            MediaObject *obj = m_flatList.value(seqNo);
            if (obj==nullptr) continue;
            proxy->add(obj);
        }
    }else {
        qDebug() << Q_FUNC_INFO << " New Model for the Row =" << row << endl;
        QQmlEngine::setObjectOwnership(proxy,QQmlEngine::CppOwnership);
        if (!m_freeProxyModelPool.isEmpty()){
            proxy = m_freeProxyModelPool.takeFirst();
        }else {
            qWarning() << Q_FUNC_INFO << " You should never come here. If you see this message increase MAX_MODELS count" <<endl;
        }
        foreach(auto seqNo, list){
            MediaObject *obj = m_flatList.value(seqNo);
            if (obj==nullptr) continue;
            proxy->add(obj);
        }
        this->m_rowModels.insert(row,proxy);
    }
    return proxy;
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

bool MediaDataArray::checkBounds(int index) {
    qDebug() << Q_FUNC_INFO << " Requesting the data for Row-Index =" << index << " ActiveStart =" << m_activeRowStart << " End ="<< m_activeRowEnd <<  endl;
    //if (m_activeRowStart <= (index-2) || m_activeRowStart == index){
    auto checkRange =[](int start, int end, int value)->bool {
         return (value >=start && value <=end);
    };
    if (m_activeRowStart == (index-2) || m_activeRowStart == (index-1) ){
        qDebug() << Q_FUNC_INFO << " Active Row start =" << index <<endl;
        if (index == 0) return true;
        int firstSequence = this->m_flatList.firstKey();
        qDebug() << Q_FUNC_INFO << " Get the previous data for Index =" << index << " first Key in Flat list =" << firstSequence <<endl;
        m_swipeDirection=BACKWARD;
        this->fetchPreviousItems(firstSequence);
    }
    if (m_activeRowEnd == (index+2) || (index+1) == m_activeRowEnd){
        int lastSequence = this->m_flatList.lastKey();
        m_swipeDirection=FORWARD;
        qDebug() << Q_FUNC_INFO << " Get the Next data for Index =" << index << " first Key in Flat list =" << lastSequence <<endl;
        this->fetchNextItems(lastSequence+1);
    }
    qDebug() << Q_FUNC_INFO << " Check bounds complete for Index =" << index <<endl;
    return true;
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

int MediaDataArray::getRow(int index)
{
    return this->m_seqNumber2Row.value(index);
}

void MediaDataArray::fetchNextItems(int seq){
    qDebug() << Q_FUNC_INFO << " Start fetching next items at Sequence =" << seq <<endl;
    if (seq == this->getFullSize()) {
        qDebug() << Q_FUNC_INFO << " There is nothing to fetch. This is last Index. Stop it now.." <<endl;
        qDebug() << Q_FUNC_INFO << " Number of rows =" << m_row2SequenceList.size() <<endl;
        emit allDatesProcessed(m_row2SequenceList.size(),this->getFullSize());
        return;
    }
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
    if (seq == 0) {
        qDebug() << Q_FUNC_INFO << " There is nothing to fetch. This is the start. Stop it now.." <<endl;
        return;
    }
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
    printFlatList();
    QList<MediaObject*> freeList;
    for(int i=gcStart;i<=gcEnd;i++){
        qDebug() << Q_FUNC_INFO << " Removing the sequence =" << i <<" Count "<< count++ << endl;
        MediaObject *obj = this->m_flatList.take(i);
        Q_ASSERT(obj!=nullptr);
        obj->reset();
        freeList.append(obj);
    }
    emit reuse(freeList);
    qDebug() << Q_FUNC_INFO << " Current Flat list =" << m_flatList.size() <<endl;
}

bool MediaDataArray::gc(int index)
{
    qDebug() << Q_FUNC_INFO << " Delegated initiated Row deletion. Row =" <<index <<endl;
    FilterProxyModel *m1 = qobject_cast<FilterProxyModel*>(m_rowModels.value(index));
    Q_ASSERT(m1!=nullptr);
    m1->gc();
    this->m_rowModels.remove(index);
    this->m_freeProxyModelPool.append(m1);
    return true;
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
    qDebug() << Q_FUNC_INFO << " First Row =" << m_activeRowStart << " Current Last Row=" << m_activeRowEnd <<endl;
    QList<SequenceNo> seqs = this->m_seqNumber2Row.keys();
    foreach(int seq, seqs){
        qDebug() << Q_FUNC_INFO << " Seq =" << seq << " Row =" << m_seqNumber2Row.value(seq);
    }
    QList<RowCount> rows = this->m_row2SequenceList.keys();
    foreach(int row, rows){
        qDebug() << Q_FUNC_INFO << "Row  =" << row << " SequencList =" << m_row2SequenceList.value(row) <<endl;
    }
    foreach(auto date, m_mediaDate2RowCount.keys()){
        qDebug() << Q_FUNC_INFO << date.toString("dd-MM-yyyy") << " = " << m_mediaDate2RowCount.value(date) <<endl;
    }
    qDebug() << Q_FUNC_INFO << " ##### Printing filtered data Complete #####" <<endl;
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
