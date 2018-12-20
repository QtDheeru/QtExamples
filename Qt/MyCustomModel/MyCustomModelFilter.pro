#-------------------------------------------------
#
# Project created by QtCreator 2017-07-26T09:29:42
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhoneBook
TEMPLATE = app
win32 {
DESTDIR = /Users/dheeru/Qt/bins
LIBS += -L<libdir> -l<libname>
}
macx {
SOURCES += main.cpp\
        MyWidget.cpp \
    SitaViewModel.cpp

HEADERS  += MyWidget.h \
    SitaViewModel.h
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#include(MyLogin/MyLogin.pri)

HEADERS += \
    MyProxyModel.h

SOURCES += \
    MyProxyModel.cpp

