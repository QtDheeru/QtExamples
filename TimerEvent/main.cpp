#include "TimerHandling.h"
#include <QApplication>

/*
 * http://www.pthinks.com - dheerendra@ptinks.com
 * This program helps to start the timer from GPRS.
 * When you compile & launch the program it will
 * display the button. Click on the button. It will start the timer
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerHandling w;
    w.show();

    return a.exec();
}
