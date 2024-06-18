#include "Message.h"

Message::Message(QObject *parent)
    : QObject{parent}
{

}

bool Message::print()
{
    qDebug() << Q_FUNC_INFO << " Print is called " << Qt::endl;
    return true;
}
