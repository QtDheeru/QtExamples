#include "KeysInterceptor.h"
#include <QKeyEvent>

KeysInterceptor::KeysInterceptor(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO << endl;
}

bool KeysInterceptor::eventFilter(QObject *watched, QEvent *event)
{
    if(watched->objectName().compare("Dheerendra")==0){
        QKeyEvent *e = dynamic_cast<QKeyEvent*>(event);
        if (event->type()==QEvent::Type::KeyPress){
            qDebug() << Q_FUNC_INFO << " Yes Dheerendra is caught " << endl;
        }
        if (e !=NULL){
            qDebug() << Q_FUNC_INFO << " Yes Dheerendra is Key Event " << endl;
        }
    }
    return QObject::eventFilter(watched,event);
}
