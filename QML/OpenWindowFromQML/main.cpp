#include <QGuiApplication>
#include <QQmlApplicationEngine>
/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * Program to launch one window from
 * other window
 */
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
