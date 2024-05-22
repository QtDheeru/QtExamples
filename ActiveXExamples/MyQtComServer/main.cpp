#include "MainWindow.h"

#include <QApplication>
#include <QAxFactory>
#include <QDebug>
#include "MySum.h"

// This macro exposes the MySum class as ActiveX
// Component. Y first two GUIDs used not aware.
// May be used for TypeLib.
// Usage program - UseSumAxControl\main.cpp
QAXFACTORY_BEGIN("{BFB4CEA6-FBA0-4c93-892F-4657109AD2E8}",
                 "{B1919C90-407C-40a3-AE21-5EE122F795BB}")
    QAXCLASS(MySum)
    //QAXCLASS(MySum1)
QAXFACTORY_END()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Starts the COM server.
    QAxFactory::startServer();
    // started by COM - don't do anything
    if (QAxFactory::isServer()) {
        qDebug() << Q_FUNC_INFO << " Started the COM server " << Qt::endl;
        return a.exec();
    } else {
        qDebug() << Q_FUNC_INFO << " COM server is not stated..." << Qt::endl;
    }

    return a.exec();
}
