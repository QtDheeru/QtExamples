#ifndef MEDIALISTSERVICEPROXY_H
#define MEDIALISTSERVICEPROXY_H

#include <QDebug>
#include <QObject>
#include <QException>
#include <QList>
#include <QDate>
#include <QTime>
#include <QRandomGenerator>
#include "MediaObject.h"
#include<functional>
class MediaListServiceProxy : public QObject
{
    Q_OBJECT
public:
    explicit MediaListServiceProxy(QObject *parent = nullptr);
    bool isConnected() { return true;}
    QList<MediaObject> getItems(int offset, int count,std::function<void(QList<MediaObject >)> onSuccess,
                                std::function<void(const QException& ex)> onError);
    void getSize(QObject *context,std::function<void(qint32)> onSuccess,std::function<void(const QException& ex)> onError);

    qint32 getListSize() const;
    void setListSize(const qint32 &listSize);

    int getDate();

    int getRandomNumber();
private :
    void createFullList();
signals:
    void listChanged(qint32 newListSize);
    void listMetadataChanged(qint32 offset, qint32 length);

private :

    qint32 m_listSize;
    qint32 m_randomSize;
    QList<MediaObject> m_fullListMediaObjects;
    QDate m_date;
};

#endif // MEDIALISTSERVICEPROXY_H
