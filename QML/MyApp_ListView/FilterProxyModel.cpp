#include "FilterProxyModel.h"

FilterProxyModel::FilterProxyModel():
    m_count(5)
  , m_dateModel(false)
  , m_addCount(0)
{
    qDebug() << Q_FUNC_INFO <<endl;
}

FilterProxyModel::~FilterProxyModel()
{
   qDebug() << Q_FUNC_INFO << " Destroyed =" << this->objectName() <<endl;
}

int FilterProxyModel::rowCount(const QModelIndex &parent) const
{
    //qDebug() << Q_FUNC_INFO << " Date =" << this->objectName() << " Elements in Proxy =" << m_count<<endl;
    return this->m_mediaObjectSeq.size();
}

QVariant FilterProxyModel::data(const QModelIndex &index, int role) const
{
    MediaObject *o1 = nullptr;
    int startSeq = m_dummy.firstKey();
    int internalIndex = startSeq + index.row();
    //qWarning() << Q_FUNC_INFO <<this->objectName() << " Index" << index.row() << " Seq=" << internalIndex << " role =" << role << endl;;
    if (m_mediaObjectSeq.keys().contains(internalIndex)){
        qDebug() << Q_FUNC_INFO << " Returning existing object =" << internalIndex << " Index =" << index.row() << endl;
        int seqkey = this->m_dummy.keys().at(index.row());
        o1 = this->m_mediaObjectSeq.value(seqkey);
        Q_ASSERT(o1);
        m_date = o1->date();
    }else {
        qDebug() << Q_FUNC_INFO << " Returning dummy for Index =" << internalIndex << " Index =" << index.row() << endl;
        o1 = new MediaObject;
        o1->setTitle("Proxy-Dummy");
        o1->setSeqNumber(index.row()+startSeq);
        o1->setDate(m_date);
    }

    Q_ASSERT(o1!=nullptr);
    if (o1==nullptr){
        qWarning() << " No media object exist. Returning Dummy" <<endl;
        return "Dummy";
    }
    switch(role){
    case TITLE:
        return o1->title();
    case MEDIA_DATE:
        return o1->date().toString("dd-MM-yyyy");
    case MEDIA_INDEX:
        return o1->seqNumber();
    }
    qDebug() << Q_FUNC_INFO << this->objectName() << " Data fetch is complete " <<endl;
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

void FilterProxyModel::resetSize()
{
    qDebug() << Q_FUNC_INFO << " Resetting the model " <<endl;
    beginResetModel();
    endResetModel();
}

void FilterProxyModel::setSize(int size)
{
    m_count =  size;
}

int FilterProxyModel::count()
{
    return m_count;
}

void FilterProxyModel::setCount(int count)
{
    if (count != m_count){
        count = m_count;
    }
    emit countChanged();
}

void FilterProxyModel::add(MediaObject *m)
{
    Q_ASSERT(m!=nullptr);
    m_addCount++;
    if (m_mediaObjectSeq.contains(m->seqNumber())){
        qDebug() << Q_FUNC_INFO << " Some old residue exist. Clean this. It may be causing the issue." <<endl;
        m_mediaObjectSeq.remove(m->seqNumber());
    }

    this->m_mediaObjectSeq.insert(m->seqNumber(),m);
    this->m_dummy.insert(m->seqNumber(),0);

    int position = this->m_dummy.keys().indexOf(m->seqNumber());
    QModelIndex left = this->createIndex(position,0);
    emit dataChanged(left,left);
    qDebug() << Q_FUNC_INFO << " Adding the MediaObject =" << m->toString() <<endl;
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
    qDebug() << Q_FUNC_INFO << " Date =" << m->date() << " Removing the sequence =" <<  m->seqNumber() << "from filter Model " << endl;
    this->m_mediaObjectSeq.remove(m->seqNumber());
    m_count--;
}

void FilterProxyModel::gc()
{
    // Dont' delete media object here. It is deleted with flat list.
    foreach(MediaObject *o1,m_mediaObjectSeq.values()){
        qDebug() << Q_FUNC_INFO << " Cleanup =" << o1->toString() <<endl;
    }
    m_dummy.clear();
    m_mediaObjectSeq.clear();
}

void FilterProxyModel::print()
{
    qDebug() << Q_FUNC_INFO << " Printing the elements =" <<m_mediaObjectSeq.size() << endl;
    foreach(int seqNumber,m_mediaObjectSeq.keys()){
        MediaObject *obj = m_mediaObjectSeq.value(seqNumber);
        Q_ASSERT(obj !=nullptr);
        qDebug() << Q_FUNC_INFO << obj->toString() <<endl;
    }
}
