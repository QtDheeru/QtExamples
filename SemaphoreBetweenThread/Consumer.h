#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QObject>
#include <QSemaphore>
#include <QDebug>

class Consumer : public QThread
{
    Q_OBJECT
public:
    Consumer();
    void setSemLock(QSemaphore *value);

protected:
    void run();

signals :
    void sig_add_data(int c);

private :
    QSemaphore *semLock;
};

#endif // CONSUMER_H
