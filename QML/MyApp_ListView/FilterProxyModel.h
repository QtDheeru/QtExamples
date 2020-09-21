
#pragma once

#include <QDebug>
#include <QAbstractListModel>
#include <QDebug>
#include <QDate>
#include "MediaObject.h"

class FilterProxyModel : public QAbstractListModel
{
    Q_OBJECT
    using sequenceNumber = qint32;
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool dateModel MEMBER m_dateModel)
public:
    FilterProxyModel();
    ~FilterProxyModel();

    enum { TITLE=Qt::UserRole+1,MEDIA_DATE,MEDIA_INDEX};
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    void resetSize();
    void setSize(int);

    int count();
    void setCount(int count);

    void add(MediaObject *m);
    MediaObject* lastItem();
    MediaObject* firstItem();
    MediaObject* getItemWithSequence(qint32 seq);
    void remove(MediaObject *m);

    QList<MediaObject *> getMediaObjects() const;
    void setMediaObjects(const QList<MediaObject *> &mediaObjects);
    void gc();
    void print();

signals :
    void countChanged();
    void fetchNextItems(int startIndex);
    void fetchPrevItems(int startIndex);

private :
    QMap<sequenceNumber, MediaObject*> m_mediaObjectSeq;
    QMap<sequenceNumber, MediaObject*> m_dummy;
    int m_count;
    mutable QDate m_date;
    bool m_dateModel;
    int m_addCount;
};
