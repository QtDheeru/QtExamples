#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "KeysInterceptor.h"

/* http://www.pthinks.com
 * This program shows how to handle Key Events &
 * forward the key events to one object.
 * We can find the time difference between the key events
 * Everything is done in QML side
 */
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject *obj = engine.rootObjects().at(0);
    qDebug() << engine.rootObjects().size() <<endl;
    foreach(QObject *o,obj->children()){
        qDebug() << o->objectName() <<endl;
        if(o->objectName().compare("Dheerendra")==0){
            //qDebug() << Q_FUNC_INFO << " Yes Dheerendra is caught " << endl;
            //o->installEventFilter(keyI);
        }
    }

    return app.exec();
}
