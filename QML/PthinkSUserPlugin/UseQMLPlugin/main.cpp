#include <QGuiApplication>
#include <QQmlApplicationEngine>
/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * This example shows how to use the QML plugin
 */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //DESTDIR = $$PWD/../bins - Directory where plugin exist
    //This comes from Plugin pro file
    //So replace the followign path appropriately
    engine.addImportPath("/Users/dheeru/Desktop/TSTS/bins");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
