#ifndef MEDIADATAARRAY_H
#define MEDIADATAARRAY_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QAbstractListModel>
#include "FilterProxyModel.h"
#include "MediaObject.h"

class MediaDataArray : public QObject
{
    Q_OBJECT
    using  MediaDate=QDate;
    using  Key = int;
    using  SequenceNo = int;
    enum POSITION {
        BACK,
        FRONT
    };

public:
    explicit MediaDataArray(QObject *parent = nullptr);
    void addItems(int start, int end, const QList<MediaObject*> list);
    bool updateItems(int start, int end, QList<MediaObject*> list);
    bool updateRange();
    bool updateDateRange(int start, int end, const QList<MediaObject *> list);
    QAbstractListModel* get(MediaDate date);
    MediaObject* getMe(qint32 index);
    int getDateIndex(qint32 offset);

    static MediaDataArray& instance();

    int getFullSize() const;
    void setFullSize(int fullSize);
    int getFlatSize();

    int getFilteredSize(){return this->m_filteredSize;}
    void setFilteredSize(int fsize) { this->m_filteredSize=fsize;}
    void resetFilteredSize(){this->setFilteredSize(this->m_dateList.size());}

    void fetchNextItems(int seq);
    void fetchPreviousItems(int seq);

    MediaDate fetchData(int index);

    void printFlatList();
    void printFilteredList();
    void print();

signals:
    void fetchNextRange(int start,int offset);
    void newDateAdded(MediaDate);
    void newDateAddedInFilterModel(int row);
    void allDatesProcessed(int start,int end);

private :
    QMap<MediaDate,QAbstractListModel*> m_filteredModels;
    QMap<MediaDate,int> m_dateList;

    QMap<SequenceNo,MediaObject*> m_flatList;
    QMap<SequenceNo,MediaDate> m_seqNumber2Date;
    QList<SequenceNo> m_sequenceList;

    int m_optimalCapacity;
    int m_chunkSize;
    int m_fullSize;
    int m_realSize;

    int m_filteredSize;

    const int flat_buffer_size = 40;
    int   m_mode;


private :
    void gc(int gcStart, int gcEnd);
};

#endif // MEDIADATAARRAY_H
