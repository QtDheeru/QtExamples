#pragma once

#include <QAbstractListModel>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "MediaDataArray.h"
#include "MediaObject.h"

class GalleryDateFilterModel : public QAbstractListModel
{
    Q_OBJECT
    using MediaDate = QDate;
    using SequenceNum=int;
    enum { MEDIA_DATE=Qt::UserRole+1,MEDIA_MODEL};
    Q_PROPERTY(int currentRow READ getCurrentRow WRITE setCurrentRow NOTIFY currentRowChanged)
    Q_PROPERTY(QString date READ getDate NOTIFY dateChanged)

public:
    GalleryDateFilterModel();
    int getDateIndex(int offset);

    // QAbstractItemModel interface
public:
    void init();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void gc(int index);
    Q_INVOKABLE QString getDateForRow(int row);

    void print();

    int getCurrentRow() const;
    void setCurrentRow(int currentIndex);

    QString getDate() const;
    void setDate(int row, const QString &date);

public slots:
    void newDateAdded(int row, QDate date);

signals:
    void fetchMoreItems(int start, int end);
    void fetchNextItems();
    void fetchPrevItems();

    void newDate(int row, QDate date);
    void newRow(int row);
    void currentRowChanged(int row);
    void dateChanged(int row, QString date);

private :
    MediaDataArray&  m_data;
    QMap<int, QString> m_dateList;
    QMap<MediaDate,SequenceNum> m_dateListWithSequence;
    QTimer m_timer;
    int m_start,m_end;
    QString m_date;

    int m_currentRow;
};
