#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QObject>
#include <QSemaphore>
#include <QDebug>

class Producer : public QThread
{
    Q_OBJECT
public:
    Producer();

    void setSemLock(QSemaphore *value);

protected:
    void run();

signals :
    void sig_add_data(int c);

private :
    QSemaphore *semLock;
};

#endif // PRODUCER_H
