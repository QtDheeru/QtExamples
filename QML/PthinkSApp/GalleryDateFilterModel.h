#ifndef GALLERYDATEFILTERMODEL_H
#define GALLERYDATEFILTERMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "MediaDataArray.h"
#include "MediaObject.h"

class GalleryDateFilterModel : public QAbstractListModel
{
    Q_OBJECT
    using MediaDate = QDate;
    using SequenceNum=int;
    enum { MEDIA_DATE=Qt::UserRole+1,MEDIA_MODEL};
public:
    GalleryDateFilterModel();
    int getDateIndex(int offset);

    // QAbstractItemModel interface
public:
    void init();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    void print();

signals:
    void fetchMoreItems(int start, int end);
    void fetchNextItems();
    void fetchPrevItems();

private :
    MediaDataArray&  m_data;
    QList<MediaDate> m_dateList;
    QMap<MediaDate,SequenceNum> m_dateListWithSequence;
};

#endif // GALLERYDATEFILTERMODEL_H
