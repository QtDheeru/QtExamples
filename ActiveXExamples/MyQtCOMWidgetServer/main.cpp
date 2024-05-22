#include "MainWindow.h"

#include <QApplication>
#include <QAxFactory>
#include "MySlider.h"
#include <QDebug>


// This program exposed the MySlider class.
// This slider was exposed to client program
// ActiveXExamples\TestCOMWithMingW\main.cpp
// Tried with MingGW Server & MingW client.
// This combination did not work.
// MSVC Server & MINGW client worked.
// MSVC server & MSVC client worked.

QAXFACTORY_BEGIN("{5A84FBEC-917E-4589-8BE4-8B3AAC67551C}",
                 "{D0F159FE-136B-4905-8639-B86560535DBC}")
    QAXCLASS(MySlider)
QAXFACTORY_END()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QAxFactory::startServer();
    if (QAxFactory::isServer()) {
        qDebug() << Q_FUNC_INFO << " Started the COM server " << Qt::endl;
        return a.exec();
    } else {
        qDebug() << Q_FUNC_INFO << " COM server is not stated..." << Qt::endl;
    }
    return a.exec();
}
