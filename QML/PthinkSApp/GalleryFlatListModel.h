#ifndef GALLERYFLATLISTMODEL_H
#define GALLERYFLATLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "MediaDataArray.h"

class GalleryFlatListModel : public QAbstractListModel
{
    Q_OBJECT

   enum { TITLE=Qt::UserRole+1,MEDIA_DATE,MEDIA_INDEX,FILEPATH};
public:


    GalleryFlatListModel();

    // QAbstractItemModel interface
public:
    void init();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    bool updateModel(qint32 offset, const QList<MediaObject*> &result);
    void setSize(qint32 size);
    qint32 getSize();

    void print();

    void fetchNextItems(int offset) const;
    void fetchPrevItems(int offset) const;

signals:
    void fetchNextRange(int start, int end);
private :
    MediaDataArray& m_data;
    mutable qint32 m_size;
};

#endif // GALLERYFLATLISTMODEL_H
