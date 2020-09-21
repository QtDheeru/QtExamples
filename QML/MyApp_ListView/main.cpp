#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ViewBindingBreaker.h"
#include "GalleryModelImpl.h"
#include <QList>
/* Tested with range of 295 to 300  elements in each date.
 * I moved back-and-forth 20 times
 * Deleting the FilterProxyModel when the delegate gets
 * deleted. Delegate calls the model method present in the
 * datemodel.
 * This program has Fixed Cost allocation for the FilterProxyModel
 * Initially it allocates only 20 FilterProxy Model. After that
 * those objects are re-used.
 * This program has fixed Cost allocation for the MediaObject as
 * It will create only  optimcal_capacity + 100 objects media objects.
 * It will keep  re-using the same MediaObjects again & again.
 * newDate signal is not coming properly.
 */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ViewBindingBreaker viewBindingBreaker;

    qmlRegisterType<GalleryModelImpl>("Gallery",1,0,"MediaList");
    qmlRegisterType<ViewBindingBreaker>("Gallery",1,0,"BindingBreaker");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
