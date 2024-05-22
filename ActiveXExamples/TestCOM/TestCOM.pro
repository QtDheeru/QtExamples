QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SumCom.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    ISum.h \
    MainWindow.h \
    SumCom.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L"C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A/Lib/x64" -l"kernel32" -l"user32" -l"gdi32" -l"winspool" -l"comdlg32" -l"advapi32" -lole32 -loleaut32
