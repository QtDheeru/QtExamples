#include "MediaListServiceProxy.h"

MediaListServiceProxy::MediaListServiceProxy(QObject *parent)
    : QObject(parent),
      m_listSize(MAX_SIZE),
      m_randomSize(RANDOM_SIZE),
      m_date(2012,01,01)
{
    qDebug() << Q_FUNC_INFO << " Proxy for data Generation" <<endl;
    this->createFullList();
}

QList<MediaObject> MediaListServiceProxy::getItems(int offset, int count,std::function<void(QList<MediaObject >)> onSuccess,
                                                   std::function<void(const QException& ex)> onError){
    Q_UNUSED(onSuccess)
    Q_UNUSED(onError)
    qDebug() << Q_FUNC_INFO << "Offset ="<<offset <<" count =" << count <<endl;
    QList<MediaObject> mediaObjects;
    for(int i=offset;i<(offset+count);i++) {
        mediaObjects.append(this->m_fullListMediaObjects.at(i));
    }
    onSuccess(mediaObjects);
    qDebug() << Q_FUNC_INFO << " First Element =" << mediaObjects.first().title() << " Last Item =" << mediaObjects.last().toString() <<endl;
    return mediaObjects;
}

void MediaListServiceProxy::getSize(QObject *context, std::function<void (qint32)> onSuccess,
                                    std::function<void(const QException& ex)> onError)
{
    Q_UNUSED(context)
    //Q_UNUSED(onSuccess)
    Q_UNUSED(onError)
    qDebug() << Q_FUNC_INFO << this->getListSize() <<endl;
    onSuccess(getListSize());
}

void MediaListServiceProxy::createFullList()
{
    int randNumber = this->getRandomNumber();
    qDebug() << Q_FUNC_INFO << randNumber<<endl;
    for(int i=0;i<m_listSize;i++) {
        MediaObject mediaObject;
        mediaObject.setTitle("Benz-"+QString::number(i));
        randNumber--;
        mediaObject.setDate(m_date);
        if (randNumber==0){
            randNumber = this->getRandomNumber();
            m_date = m_date.addDays(1);
            m_date = m_date.addMonths(1);
        }
        mediaObject.setSeqNumber(i);
        this->m_fullListMediaObjects.append(mediaObject);
    }
    auto printList = [this](){
        foreach(MediaObject object,m_fullListMediaObjects){
            qDebug() << Q_FUNC_INFO << " Proxy constructed Data =" << object.toString();
        }
    };
    printList();
}

qint32 MediaListServiceProxy::getListSize() const
{
    return m_listSize;
}

void MediaListServiceProxy::setListSize(const qint32 &listSize)
{
    m_listSize = listSize;
}
int MediaListServiceProxy::getRandomNumber(){
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    //return qrand() % ((10 + 1) - 5) + 5;

    return QRandomGenerator::global()->bounded(15,20);
}
