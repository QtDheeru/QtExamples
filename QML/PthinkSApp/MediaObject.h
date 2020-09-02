#ifndef MEDIAOBJECT_H
#define MEDIAOBJECT_H

#include <QObject>
#include <QString>
#include <iostream>
#include <QMetaType>
#include <QDate>
#include <QDebug>

// How many elements we have maximum
#define MAX_SIZE 10000
#define RANDOM_SIZE 20
// How many elements we query each time
#define CHUNK_SIZE 20
#define BUFFER_SIZE 25
#define L_SWIPVIEW_BUFFER 20
// Optimal capacity 3 times the chunk size
#define OPTIMAL_CAPACITY 60
class MediaObject
{
    Q_GADGET
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString date READ date WRITE setDate)

public:
    QString title() const
    {
        return m_title;
    }

    void setTitle(const QString &title)
    {
        m_title = title;
    }
    QString toString(){
        return (QString::number(m_seqNumber) + " " +  m_title + " " + m_date.toString("MM-dd-yyyy"));
    }

    QDate date() const
    {
        return m_date;
    }

    void setDate(const QDate &date)
    {
        m_date = date;
    }

    int seqNumber() const
    {
        return m_seqNumber;
    }

    void setSeqNumber(int seqNumber)
    {
         m_seqNumber = seqNumber;
    }
    ~MediaObject() {
        //qDebug() << Q_FUNC_INFO << " Deleting the object " << this->seqNumber() <<endl;
    }

private :
    QString m_title;
    QDate   m_date;
    int     m_seqNumber=0;
};
#endif // MEDIAOBJECT_H




