#include "FilterProxyModel.h"

FilterProxyModel::FilterProxyModel()
{
    qDebug() << Q_FUNC_INFO <<endl;
}

int FilterProxyModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO <<" Number of Elements in proxy =" << m_mediaObjectSeq.size()<<endl;
    return this->m_mediaObjectSeq.size();
}

QVariant FilterProxyModel::data(const QModelIndex &index, int role) const
{
    qWarning() << Q_FUNC_INFO <<this->objectName() << " Index Row = " << index.row() << " Total Elements =" << m_mediaObjectSeq.size()<<endl;
    int seqkey = this->m_mediaObjectSeq.keys().at(index.row());
    MediaObject *o1 = this->m_mediaObjectSeq.value(seqkey);
    if (o1==nullptr){
        qWarning() << " No media object exist. Returning Dummy" <<endl;
        return "Dummy";
    }
    switch(role){
    case TITLE:
        return o1->title();
    case MEDIA_DATE:
        return o1->date();
    case MEDIA_INDEX:
        return o1->seqNumber();
    }
    return "Dummy";
}

QHash<int, QByteArray> FilterProxyModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO <<endl;
    QHash<int, QByteArray> roles;
    roles[TITLE]="title";
    roles[MEDIA_DATE]="date";
    roles[MEDIA_INDEX]="media_index";
    return  roles;
}

void FilterProxyModel::add(MediaObject *m)
{
    int rowStart=0;
    if (m_mediaObjectSeq.size()==0){
        rowStart=0;
    } else {
        if (m->seqNumber() > m_mediaObjectSeq.lastKey() ){
            rowStart = m_mediaObjectSeq.size();
        }
    }

    qDebug() << Q_FUNC_INFO << " Adding the new Item =" << m->seqNumber() <<endl;
    this->beginInsertRows(QModelIndex(),rowStart,rowStart);
    this->m_mediaObjectSeq.insert(m->seqNumber(),m);
    this->endInsertRows();
}

MediaObject *FilterProxyModel::get1(qint32 index)
{
    return this->m_mediaObjects.at(index);
}

MediaObject *FilterProxyModel::lastItem()
{
    return this->m_mediaObjectSeq.values().last();
}

MediaObject *FilterProxyModel::firstItem()
{
    return this->m_mediaObjectSeq.values().first();
}

MediaObject *FilterProxyModel::getItemWithSequence(qint32 seq)
{
    return m_mediaObjectSeq.value(seq);
}

void FilterProxyModel::remove(MediaObject *m)
{
    qDebug() << Q_FUNC_INFO << " Date =" << m->date() << " Removing the sequence =" <<  m->seqNumber() << "D from filter Model " << endl;
    this->m_mediaObjectSeq.remove(m->seqNumber());
}

QList<MediaObject *> FilterProxyModel::getMediaObjects() const
{
    return m_mediaObjects;
}

void FilterProxyModel::setMediaObjects(const QList<MediaObject *> &mediaObjects)
{
    m_mediaObjects = mediaObjects;
}

void FilterProxyModel::gc()
{
    foreach(MediaObject *o1,m_mediaObjects){
        qDebug() << Q_FUNC_INFO << " Cleanup =" << o1->toString() <<endl;
    }
    m_mediaObjects.clear();
    m_mediaObjectSeq.clear();
}

void FilterProxyModel::print()
{
    qDebug() << Q_FUNC_INFO << " Printing the elements " <<endl;
    foreach(int seqNumber,m_mediaObjectSeq.keys()){
        qDebug() << Q_FUNC_INFO << " Seq =" << seqNumber << m_mediaObjectSeq.value(seqNumber)->toString() <<endl;
    }
}
