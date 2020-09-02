#ifndef FILTERPROXYMODEL_H
#define FILTERPROXYMODEL_H

#include <QDebug>
#include <QAbstractListModel>
#include <QDebug>
#include "MediaObject.h"

class FilterProxyModel : public QAbstractListModel
{
    Q_OBJECT
    using sequenceNumber = qint32;
public:
    FilterProxyModel();

    enum { TITLE=Qt::UserRole+1,MEDIA_DATE,MEDIA_INDEX};
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    void add(MediaObject *m);
    MediaObject* get1(qint32 index);
    MediaObject* lastItem();
    MediaObject* firstItem();
    MediaObject* getItemWithSequence(qint32 seq);
    void remove(MediaObject *m);

    QList<MediaObject *> getMediaObjects() const;
    void setMediaObjects(const QList<MediaObject *> &mediaObjects);
    void gc();
    void print();

private :
    QList<MediaObject*> m_mediaObjects;
    QMap<sequenceNumber, MediaObject*> m_mediaObjectSeq;
};

#endif // FILTERPROXYMODEL_H
