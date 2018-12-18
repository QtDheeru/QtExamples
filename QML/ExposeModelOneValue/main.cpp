#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "DataModel.h"

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * DataModel is exposed to QML
 * DataModel as list of Cars.
 * This exmple show you can access the individual model
 * object directly if required.
 * When the object is exposed to QML, need to register
 * the Car class using qmlRegisterType.
 */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    DataModel modl;
    QQmlApplicationEngine engine;
    qmlRegisterType<Car>();
    engine.rootContext()->setContextProperty("dataModel",&modl);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
