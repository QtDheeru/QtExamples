#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T11:20:04
#
#-------------------------------------------------

QT       += core gui sql printsupport widgets svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI_1
TEMPLATE = app
DESTDIR = $$PWD/bins
TRANSLATIONS =kannada.ts\

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#RC_FILE = Icon.qrc

RC_ICONS = $$PWD/123.ico

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    hedderforprintreceipt.cpp \
        main.cpp \
    hedder_screen.cpp \
    mylabel.cpp \
    login.cpp \
    printreceipt.cpp \
    menuscreen.cpp \
    print_file.cpp

HEADERS += \
    common.h \
    hedder_screen.h \
    hedderforprintreceipt.h \
    mylabel.h \
    login.h \
    current .h \
    printreceipt.h \
    menuscreen.h \
    print_file.h

include(dbinterface/dbinterface.pri)
include(seva/seva.pri)
include(booking_ui/booking_ui.pri)
include(booking_report/booking_report.pri)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    123.qrc \
    Icon.qrc \
    Rules.qrc \
    abc.qrc \
    cal1.qrc \
    cal2.qrc \
    cal3.qrc \
    settings.qrc \
    settings2.qrc \
    transalation_kannada.qrc \
    temp_trans.qrc

DISTFILES +=




