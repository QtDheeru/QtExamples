#include <QApplication>
#include"adminscreen.h"
#include"dbfile.h"
#include "login.h"
#include <QDesktopWidget>
#include<QDebug>
#include"menuscreen.h"
#include<QTranslator>
#include<QScreen>
#include <QMessageLogger>
#include<QMutex>

QScopedPointer<QFile> m_logFile;
QMutex mlock;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString logFileName = "E:/Logging_from_app.txt";
    m_logFile.reset(new QFile(logFileName));
    m_logFile.data()->open(QFile::WriteOnly | QFile::Truncate | QFile::Text |QFile::Append);
    qInstallMessageHandler(messageHandler);
    dbfile::init = dbfile::getInstance();
    QTranslator t;
    if(t.load(":/kannada.qm"))
    {
        qDebug()<<"Loaded  transl*r"<<endl;
        //        a.installTranslator(&t);
    }
    else
    {
        qWarning()<<"Not loaded"<<endl;
    }

    qDebug() << Q_FUNC_INFO << "Stmt before admin screen " << endl;
    adminScreen *screen = new adminScreen;
     qDebug() << Q_FUNC_INFO << "Stmt after admin screen " << endl;
    login *log1=new login;
     qDebug() << Q_FUNC_INFO << "Stmt after admin screen" << endl;
    log1->onlylogin();

    menuScreen *m_screen=new menuScreen;
    QScreen *displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    log1->resize(width,height);
    screen->resize(width,height);
    m_screen->setGeometry(width/3,height/4,600,600);

    QObject::connect(dbfile::getInstance(),SIGNAL(success()),m_screen,SLOT(menu_show()));
    QObject::connect(dbfile::getInstance(),SIGNAL(success()),log1,SLOT(screenVisibleFalse()));
    QObject::connect(m_screen,SIGNAL(type(int)),screen,SLOT(displaying_type(int)));

    qDebug() << Q_FUNC_INFO << "Stmt after  displaying_type slot connect" << endl;
    return a.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    mlock.lock();
    // Open stream file writes
    QTextStream out(m_logFile.data());
    // Write the date of recording
    out << QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss.zzz ");
    // By type determine to what level belongs message
    switch (type)
    {
    case QtInfoMsg:     out << "INF "; break;
    case QtDebugMsg:    out << "DBG "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
    }
    // Write to the output category of the message and the message itself
    out << context.category << ": "<< msg << endl;
    out.flush();    // Clear the buffered data
    mlock.unlock();
}
