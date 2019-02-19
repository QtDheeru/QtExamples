#include <QGuiApplication>
#include <QQmlApplicationEngine>

/* Example to demostrate how to pass the signal
 * from one qml object to other qml object
 * Monitor object is created in main.qml
 * http://www.pthinks.com
 * dheerendra@pthinks.com
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
