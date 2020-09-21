#include "GalleryModelImpl.h"

GalleryModelImpl::GalleryModelImpl(QObject *parent)
    : QObject(parent),
      m_chunkSize(CHUNK_SIZE),
      m_buffersize(CHUNK_SIZE*10),
      m_actualSize(0)
{
    qDebug() << Q_FUNC_INFO << endl;
    m_proxy = std::make_unique<MediaListServiceProxy>();
    m_flatModel = new GalleryFlatListModel;
    m_dateModel = new GalleryDateFilterModel;
    this->init();
}

void GalleryModelImpl::init(){

    for(int i=0;i<300;i++){
        this->m_mediaObjectFreePool.append(new MediaObject);
    }
    connect(m_flatModel,&GalleryFlatListModel::setCurrentIndex,m_dateModel,&GalleryDateFilterModel::setCurrentRow);
    connect(m_dateModel,&GalleryDateFilterModel::newDate,this,&GalleryModelImpl::newDateAdded);
    connect(m_flatModel,&GalleryFlatListModel::fetchNextRange,this,&GalleryModelImpl::fetchNextChunk);
    connect(m_flatModel,SIGNAL(reuse(QList<MediaObject*>)),this,SLOT(reuse(QList<MediaObject*>)),Qt::UniqueConnection);

    m_flatModel->init();
    m_dateModel->init();
    this->getSize();
}

void GalleryModelImpl::start() {
    emit dateModelChanged();
    emit flatModelChanged();
}

void GalleryModelImpl::reuse(QList<MediaObject*> list){
     qDebug() << Q_FUNC_INFO << " Free list received =" << list.size() <<endl;
     foreach(MediaObject *o1, list){
         qWarning() << Q_FUNC_INFO << " Media Object Id =" << o1->seqNumber() <<endl;
     }
     this->m_mediaObjectFreePool.append(list);
}

GalleryFlatListModel * GalleryModelImpl::flatModel() const
{
    qDebug() << Q_FUNC_INFO << endl;
    return m_flatModel;
}

void GalleryModelImpl::setFlatModel(GalleryFlatListModel *flatModel)
{
    qDebug() << Q_FUNC_INFO << endl;
    m_flatModel = flatModel;
}

GalleryDateFilterModel *GalleryModelImpl::dateModel() const
{
    qDebug() << Q_FUNC_INFO << endl;
    return m_dateModel;
}

void GalleryModelImpl::setDateModel(GalleryDateFilterModel *dateModel)
{
    qDebug() << Q_FUNC_INFO << endl;
    m_dateModel = dateModel;
}

void GalleryModelImpl::getSize()
{
    qDebug() << Q_FUNC_INFO <<endl;
    m_proxy->getSize(this, [this](qint32 size) {
        qDebug() << Q_FUNC_INFO << "getSize" << size <<endl;
        //the list is empty, lets say the empty content is ready
        setFullListSize(size);
        getItems(0,qMin(m_chunkSize,size));
    }, std::bind(&GalleryModelImpl::onCallFailed, this, std::placeholders::_1));
    qDebug() << Q_FUNC_INFO << " End of get Size " <<endl;

    m_flatModel->print();
}

void GalleryModelImpl::updateModel(qint32 offset, const QList<MediaObject> &result){
    qDebug() << Q_FUNC_INFO << " Updating the model offset =" << offset <<" Size =" << result.size() << endl;
    this->m_flatModel->updateModel(offset,getMediaObjectList(offset,result));
    this->m_actualSize +=result.size();
    if (m_actualSize <= m_buffersize){
        this->getItems(offset+result.size(),m_chunkSize);
    }
}

QList<MediaObject*> GalleryModelImpl::getMediaObjectList(qint32 offset, const QList<MediaObject> &result){
    QList<MediaObject*> list;
    foreach(MediaObject obj,result){
        //MediaObject *o1  = new MediaObject;
        MediaObject *o1 = this->m_mediaObjectFreePool.takeFirst();
        o1->setTitle(obj.title());
        o1->setDate(obj.date());
        o1->setSeqNumber(offset++);
        list.append(o1);
    }
    return list;
}

void GalleryModelImpl::setFullListSize(qint32 size){
    this->m_fullSize = size;
    this->m_flatModel->setSize(size);
}

qint32 GalleryModelImpl::getFullSize() const
{
    return m_fullSize;
}

void GalleryModelImpl::setFullSize(const qint32 &fullSize)
{
    m_fullSize = fullSize;
}

void GalleryModelImpl::fetchNextChunk(qint32 start, qint32 end)
{
    qDebug() << Q_FUNC_INFO << " Fetching the next chunk Start=" << start << " End =" << end <<endl;
    if (start >= this->m_fullSize) return;
    this->getItems(start,(end-start));
    qDebug() << Q_FUNC_INFO << " Fetching the next chunk is complete" <<endl;
}

void GalleryModelImpl::getListItem(qint32 index)
{
    qDebug() << Q_FUNC_INFO << endl;
}

void GalleryModelImpl::getItems(qint32 offset, qint32 length)
{
    qDebug() << Q_FUNC_INFO << endl;
    qDebug() << Q_FUNC_INFO << "getItems offset=" << offset << "length=" << length;

    m_proxy->getItems(offset, length, [this, offset](const QList<MediaObject >& result) {
        for (auto mediaObject : result) {
            qDebug() << "getItems: " << mediaObject.toString();
        }
        updateModel(offset, result);
        qDebug() << "getItems onSuccess" << "offset:=" << offset << "result.size()=" << result.size();
    }, std::bind(&GalleryModelImpl::onCallFailed, this, std::placeholders::_1));
    qDebug() << Q_FUNC_INFO << " getItems complete offset=" << offset << " Length=" << length <<endl;
}

void GalleryModelImpl::onCallFailed(const QException &exception)
{
    qDebug() << "Call failed:" << endl;
}

void GalleryModelImpl::selectedItem(int index, int offset){
    qDebug() << Q_FUNC_INFO << " Index =" << index << " Offset =" << offset <<endl;
    this->m_flatModel->print();
}

int GalleryModelImpl::getGridViewIndex(int offset)
{
    qDebug() << Q_FUNC_INFO << " Sequence number of selected Item =" << offset <<endl;
    int currentIndex = this->m_dateModel->getDateIndex(offset);
    return currentIndex;
}

void GalleryModelImpl::print()
{
     qDebug() << Q_FUNC_INFO << endl;
     this->m_flatModel->print();
     this->m_dateModel->print();
     qWarning() << Q_FUNC_INFO << " Free List Size =" << this->m_mediaObjectFreePool.size() <<endl;
}

void GalleryModelImpl::newDateAdded(int row, QDate date)
{
    qWarning() << Q_FUNC_INFO << " New row & date is added. Row = " << row << " Date =" << date << endl;
    emit newDate(row,date.toString("dd-MM-yyyy"));
}
