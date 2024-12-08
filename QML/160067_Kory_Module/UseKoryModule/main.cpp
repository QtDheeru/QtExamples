#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QPluginLoader>
#include <QDir>
#include <QDirIterator>

bool loadQrc(QString dirName){
    QDirIterator it(dirName, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << it.next();
    }

    QDirIterator it1(":", QDirIterator::Subdirectories);
    while (it1.hasNext()) {
        qDebug() << it1.next();
    }
    return true;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // Assuming the pluging is present in the directory - libPthinkSKoryUtilplugin
    // This is coming form camkelist.txt present in 'Kory' directory
    engine.addImportPath("/Users/dheeru/Examples/Forum/160067_Kory_Module/KoryModule/bins");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    //engine.loadFromModule("UseKoryModule", "Main");

    loadQrc("qrc:/qt/qml");
    const QUrl url("qrc:/qt/qml/PthinkS/Kory/Two/KoryMain.qml");
    engine.loadFromModule("PthinkS.Kory.Two", "KoryMain");
    engine.load(url);
    return app.exec();
}
