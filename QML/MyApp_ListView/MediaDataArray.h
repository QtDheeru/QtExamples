#pragma once

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QAbstractListModel>
#include <QQmlEngine>
#include "FilterProxyModel.h"
#include "MediaObject.h"

class MediaDataArray : public QObject
{
    Q_OBJECT
    using  MediaDate=QDate;
    using  Key = int;
    using  SequenceNo = int;
    using  RowCount = int;

    enum SWIPE_DIRECTION {
        FORWARD,
        BACKWARD
    };

public:
    explicit MediaDataArray(QObject *parent = nullptr);
    void addItems(int start, int end, const QList<MediaObject*> list);
    bool updateItems(int start, int end, QList<MediaObject*> list);
    QAbstractListModel* get(RowCount date);
    MediaObject* getMe(qint32 index);
    int getDateIndex(qint32 offset);

    int getRow(int index);

    static MediaDataArray& instance();

    int getFullSize() const;
    void setFullSize(int fullSize);
    int getFlatSize();

    int getFilteredSize(){return this->m_filteredSize;}
    void setFilteredSize(int fsize) { this->m_filteredSize=fsize;}
    void resetFilteredSize(){this->setFilteredSize(this->m_seqNumber2Row.size());}

    void fetchNextItems(int seq);
    void fetchPreviousItems(int seq);

    bool checkBounds(int index);
    bool gc(int rowIndex);

    void printFlatList();
    void printFilteredList();
    void print();


private :
    bool updateDateRange(int start, int end, const QList<MediaObject *> list);
    bool updateRangeForward(int start, int end, const QList<MediaObject *> list);
    bool updateRangeBackward(int start, int end, const QList<MediaObject *> list);
    void initFreePool();
    void gc(int gcStart, int gcEnd);

signals:
    void fetchNextRange(int start,int offset);
    void newDateAdded(MediaDate);
    void newDateAddedInFilterModel(int row);
    void allDatesProcessed(int start,int end);
    void newDate(int row,QDate date);
    void reuse(QList<MediaObject*>);

private :
    QMap<RowCount,QAbstractListModel*> m_filteredModels;
    QMap<MediaDate,int> m_dateList;
    QMap<MediaDate,RowCount> m_mediaDate2RowCount;

    QMap<SequenceNo,MediaObject*> m_flatList;
    QMap<SequenceNo,MediaDate> m_seqNumber2Date;
    QList<SequenceNo> m_sequenceList;

    QMap<RowCount,QList<SequenceNo>> m_row2SequenceList;
    QMap<SequenceNo,RowCount>  m_seqNumber2Row;

    QMap<RowCount,QAbstractListModel*> m_rowModels;
    QList<FilterProxyModel*> m_freeProxyModelPool;

    int m_optimalCapacity;
    int m_chunkSize;
    int m_fullSize;
    int m_realSize;

    int m_filteredSize;

    SWIPE_DIRECTION   m_swipeDirection;

    QDate m_prevDate;
    int   m_UiColumnCount;
    int   m_UiRowCount;
    int   m_activeRowStart;
    int   m_activeRowEnd;

    const int MAX_MODELS = 20;

};
