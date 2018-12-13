#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include "HWDevice.h"

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * This program defines the states in QML
 * State change is triggered from C++ side.
 * C++ sends two signals (data1, data2) alternatively.
 * These two signals are handled in QML & state
 * change triggered.
 */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    HWDevice device;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("hwDevice",&device);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
