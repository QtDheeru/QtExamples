#ifndef GALLERYMODELIMPL_H
#define GALLERYMODELIMPL_H

#include <QObject>
#include <memory>
#include "GalleryDateFilterModel.h"
#include "GalleryFlatListModel.h"
#include "MediaListServiceProxy.h"

using namespace std;

class GalleryModelImpl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(GalleryFlatListModel *flatModel READ flatModel NOTIFY flatModelChanged)
    Q_PROPERTY(GalleryDateFilterModel *dateModel READ dateModel NOTIFY dateModelChanged)
public:
    explicit GalleryModelImpl(QObject *parent = nullptr);

    GalleryFlatListModel *flatModel() const;
    void setFlatModel(GalleryFlatListModel *flatModel);

    GalleryDateFilterModel *dateModel() const;
    void setDateModel(GalleryDateFilterModel *dateModel);

    Q_INVOKABLE virtual void getSize();
    Q_INVOKABLE virtual void getListItem(qint32 index);
    Q_INVOKABLE virtual void getItems(qint32 offset, qint32 length);

    void onCallFailed(const QException &exception);
    void updateModel(qint32 offset, const QList<MediaObject >& result);
    QList<MediaObject*> getMediaObjectList(qint32 offset, const QList<MediaObject> &result);
    qint32 getFullSize() const;
    void setFullSize(const qint32 &fullSize);
    void fetchNextChunk(qint32 start, qint32 end);
    Q_INVOKABLE void selectedItem(int index, int offset);
    Q_INVOKABLE int  getGridViewIndex(int offset);

    Q_INVOKABLE void print();

private:

    // Debug Purpose only. Not required later
    void printFlatModel();
    void printDateModel();
    void setFullListSize(qint32 size);

signals:
    void flatModelChanged();
    void dateModelChanged();

private :
    GalleryFlatListModel *m_flatModel;
    GalleryDateFilterModel *m_dateModel;
    std::unique_ptr<MediaListServiceProxy> m_proxy;
    qint32 m_chunkSize;
    qint32 m_fullSize;
    qint32 m_buffersize;
    qint32 m_actualSize;
    qint32 m_lsize;
};

#endif // GALLERYMODELIMPL_H
