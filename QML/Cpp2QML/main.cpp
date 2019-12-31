#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "xmlReader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QGuiApplication app(argc, argv);

        xmlReader xmlReaderH;
        xmlReaderH.setName("Dheerendra");
        xmlReaderH.setHelloText("guru");
        QQmlApplicationEngine engine;
        QQmlContext *ctx = engine.rootContext();
        ctx->setContextProperty("xmlReaderCpp", &xmlReaderH);
        ctx->setContextProperty("appdir", QGuiApplication::applicationDirPath());

        const QUrl url(QStringLiteral("qrc:/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                         &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
        engine.load(url);

        return app.exec();
}
