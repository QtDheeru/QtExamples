#include "Consumer.h"

Consumer::Consumer()
{

}
void Consumer::run()
{
    int b = 0;
    int c = 0;
    qDebug("ADD_");
    for (int a = 0; a < 10;++a)
    {
        semLock->acquire();
        c = a + b;
        semLock->release();
        qDebug("ADD_DATA %d",c);
        sleep(1);
        b = c;
        emit sig_add_data(c);
    }
    qDebug("ADD_DATA %d",c);
}

void Consumer::setSemLock(QSemaphore *value)
{
    semLock = value;
}
