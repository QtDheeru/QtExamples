#include "MainWindow.h"

#include <QApplication>
#include <ObjBase.h>
#include <unknwn.h>
#include <Propvarutil.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // CoInitialize ( NULL );
    // IBVAC_moder* ps = NULL;
    // HRESULT hrA = CoCreateInstance(CLSID_BVAC, NULL, CLSCTX_INPROC_SERVER, IID_IBVAC_moder, (void**)&ps );


    HRESULT hr;
    CLSID clsid;
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    CLSIDFromProgID(OLESTR("WScript.Shell"), &clsid);

    return a.exec();
}
