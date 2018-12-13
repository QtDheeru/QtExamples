#ifndef GPRS_H
#define GPRS_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class GPRS : public QObject
{
    Q_OBJECT
public:
    explicit GPRS(QObject *parent = nullptr);

    void fun();
signals:

public slots:
    void timerExpired();

private :
    QTimer *m_timer;
};

#endif // GPRS_H
