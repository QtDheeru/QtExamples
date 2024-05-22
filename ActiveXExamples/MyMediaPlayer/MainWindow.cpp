#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QAxObject>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_mediaWidget = new MyMediaWidget;
    this->setCentralWidget(m_mediaWidget);
    //    if (!m_mediaWidget->setControl("{00020820-0000-0000-C000-000000000046}")){

    // This opens the Media control from Windows.
    //m_mediaWidget->setControl("{6BF52A52-394A-11d3-B153-00C04F79FAA6}");
    if (!m_mediaWidget->setControl("{6BF52A52-394A-11d3-B153-00C04F79FAA6}")){
        qWarning() << Q_FUNC_INFO << " Unable to open the COM object " << Qt::endl;
        return;
    } else {
        qDebug() << " Media Object opened successfully" << Qt::endl;
    }

    //m_mediaWidget->setControl("{00020812-0000-0000-C000-000000000046}");
    //m_mediaWidget->dynamicCall("Open(const QString&)", "C:/Users/91973/Downloads/Panchanga_2023_24.xlsx");

    //this->readExcel();

    //QString filePath = "C:\\Users\\prana\\OneDrive\\Desktop\\QT-QML-projects\\QtAxMSExel\\students.xlsx";
    //excelWidget->dynamicCall("Open(const QString&)", filePath);
}

// With this tried to open the excel.
// Some how this did not work properly.
void MainWindow::readExcel() {
    QAxObject* excel = new QAxObject( "Excel.Application", 0 );
    QAxObject* workbooks = excel->querySubObject( "Workbooks" );
    QAxObject* workbook = workbooks->querySubObject( "Open(const QString&)", "C:/Users/91973/Downloads/Panchanga_2023_24.xlsx" );
    QAxObject* sheets = workbook->querySubObject( "Worksheets" );
    QList<QVariantList> data; //Data list from excel, each QVariantList is worksheet row

    int count = sheets->dynamicCall("Count()").toInt();
    qDebug() << " Number of Sheets =" << count << Qt::endl;

    QFile file1("C:/Users/91973/Downloads/sheet2.html");
    file1.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file1);
    out << excel->generateDocumentation();
    file1.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
