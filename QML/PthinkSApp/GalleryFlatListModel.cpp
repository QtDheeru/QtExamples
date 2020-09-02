#include "GalleryFlatListModel.h"

GalleryFlatListModel::GalleryFlatListModel():
    m_data(MediaDataArray::instance())
{
    qDebug() << Q_FUNC_INFO << endl;
    connect(&m_data,&MediaDataArray::fetchNextRange,
            this,&GalleryFlatListModel::fetchNextRange);
}

void GalleryFlatListModel::init()
{
    qDebug() << Q_FUNC_INFO << endl;
}

int GalleryFlatListModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << endl;
    m_size = const_cast<GalleryFlatListModel*>(this)->getSize();
    return m_size;
}

QVariant GalleryFlatListModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO << "Fetching the data for Row=" << index.row() << endl;
    MediaObject *o1 = m_data.getMe(index.row());
    switch (role) {
    case TITLE :
         return o1->title();
         break;
    case MEDIA_DATE :
         return o1->date();
         break;
    case MEDIA_INDEX :
         return o1->seqNumber();
         break;
    }
    return "No-Data";
}

void GalleryFlatListModel::fetchNextItems(int offset) const{
     qDebug() << Q_FUNC_INFO << " Reached the end" <<endl;
     m_data.fetchNextItems(offset);
}
void GalleryFlatListModel::fetchPrevItems(int offset) const{
     qDebug() << Q_FUNC_INFO << " Reached beginning" <<endl;
}

QHash<int, QByteArray> GalleryFlatListModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO << endl;
    QHash<int, QByteArray> roles;
    roles[TITLE] = "title";
    roles[MEDIA_DATE] = "date";
    roles[MEDIA_INDEX] = "media_index";
    return roles;
}

bool GalleryFlatListModel::updateModel(qint32 offset, const QList<MediaObject*> &result)
{
    qDebug() << Q_FUNC_INFO << endl;
    this->m_data.addItems(offset,(offset+result.size()),result);
    return true;
}

void GalleryFlatListModel::setSize(qint32 size)
{
    this->m_data.setFullSize(size);
}

qint32 GalleryFlatListModel::getSize()
{
    return m_data.getFullSize();
}

void GalleryFlatListModel::print() {
    qDebug() << Q_FUNC_INFO << endl;
    this->m_data.print();
}
