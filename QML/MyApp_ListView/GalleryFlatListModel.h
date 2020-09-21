#pragma once

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

    Q_INVOKABLE QString get(int index);

    void print();

    void fetchNextItems(int offset) const;
    void fetchPrevItems(int offset) const;

signals:
    void fetchNextRange(int start, int end);
    void setCurrentIndex(int index);
    void reuse(QList<MediaObject*>);

private :
    MediaDataArray& m_data;
    mutable qint32 m_size;
};

