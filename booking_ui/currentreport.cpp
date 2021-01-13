#include "currentreport.h"

CurrentReport::CurrentReport(QWidget *parent) :
    QWidget(parent)
{

    i_radio = 0;
    ver_main = new QVBoxLayout(this);
    hlayout8a = new QHBoxLayout;
    hlayout8c = new QHBoxLayout;
    hlayout8d = new QHBoxLayout;
    hlayout8e = new QHBoxLayout;
    hlayout8f = new QHBoxLayout;
    m_hboxtype= new QHBoxLayout;
    m_hboxname= new QHBoxLayout;

    QFont font;
    //    font.pointSize(5);
    //    font.setPointSize(font.pointSize() + 55);
    vlayout8e = new QVBoxLayout;
    calendar = new QCalendarWidget;
    calendar->setWindowModality(Qt::ApplicationModal);
    calendar->setGridVisible(true);
    calendar->setVisible(false);
    model=new QStandardItemModel;

    m_selectSevaType = new QLabel(tr("SELECT SEVA TYPE"));
    m_selectSevaType->setStyleSheet("QLabel {color : '#cc00cc' ;font: 18pt Times New Roman}");


    m_selectSevaName = new QLabel(tr("SELECT SEVA NAME"));
    m_selectSevaName->setStyleSheet("QLabel {color : '#cc00cc' ;font: 18pt Times New Roman}");

    C_type      = new QComboBox;
    C_type->setMaximumWidth(300);
    C_type->setStyleSheet("QComboBox {color : '#cc00cc' ;font: 18pt Times New Roman}");

    C_seva      = new QComboBox;
    C_seva->setMaximumWidth(300);
    C_seva->setStyleSheet("QComboBox {color : '#cc00cc' ;font: 18pt Times New Roman}");
    R_cdate  = new QRadioButton(tr("SELECT DATE"));
    R_cdate->setStyleSheet("QRadioButton {color : '#cc00cc' ;font: 20pt Times New Roman}");

    R_cdate->setObjectName("RadioButtonCurrentDate");

    m_cdate = new QLineEdit;

    m_cdate->setStyleSheet("QLineEdit {font: 18pt Times New Roman;border-style:outset;border-width:1.5px}");

    m_cdate->setMaximumWidth(210);

    m_cdate->setText(QDate::currentDate().toString("dd-MM-yyyy"));
    m_cdate->setEnabled(false);
    hlayout8c->addWidget(R_cdate);
    hlayout8c->addWidget(m_cdate);

    m_DataRange = new QRadioButton(tr("SELECT DATE RANGE"));
    m_DataRange->setStyleSheet("QRadioButton {color : '#cc00cc' ;font: 20pt Times New Roman}");

    m_DataRange->setObjectName("RadioButtonSetDateRange");
    m_StartDate = new QLineEdit;

    m_StartDate->setStyleSheet("QLineEdit {font: 18pt Times New Roman;border-style:outset;border-width:1.5px}");
    m_StartDate->setEnabled(false);
    m_EndDate = new QLineEdit;

    m_EndDate->setStyleSheet("QLineEdit {font: 18pt Times New Roman;border-style:outset;border-width:1.5px}");
    m_EndDate->setEnabled(false);
    hlayout8e->addWidget(m_DataRange);
    vlayout8e->addWidget(m_StartDate,0,Qt::AlignRight);
    vlayout8e->addWidget(m_EndDate,0,Qt::AlignRight);
    hlayout8e->setSpacing(5);
    hlayout8e->addLayout(vlayout8e);

    R_cmonth = new QRadioButton(tr("SELECT MONTH & YEAR"));
    R_cmonth->setStyleSheet("QRadioButton {color : '#cc00cc' ;font: 18pt Times New Roman;}");
    C_cmonth = new QComboBox;
    C_cmonth->setMaximumWidth(210);
    C_cmonth->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    C_cmonth->setEnabled(false);
    QList<QString> list_month;
    list_month<<(tr("January"))<<(tr("February"))<<(tr("March"))<<(tr("April"))<<(tr("May"))<<(tr("June"))<<(tr("July"))<<(tr("August"))<<(tr("September"))<<(tr("October"))<<(tr("November"))<<(tr("December"));
    C_cmonth->addItems(list_month);
    C_cmonth->setCurrentIndex(QDate::currentDate().month()-1);
    C_year = new QComboBox;
    C_year->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    C_year->setEnabled(false);
    QList<QString> list_year;
    list_year<<(tr("2015"))<<(tr("2016"))<<(tr("2017"))<<(tr("2018"))<<(tr("2019"))<<(tr("2020"))<<(tr("2021"))<<(tr("2022"))<<(tr("2023"))<<(tr("2024"))<<(tr("2025"))<<(tr("2026"))<<(tr("2027"))<<(tr("2028"))<<(tr("2029"))<<(tr("2030"))<<(tr("2031"))<<(tr("2032"))<<(tr("2033"))<<(tr("2034"))<<(tr("2035"))<<(tr("2036"))<<(tr("2037"))<<(tr("2038"))<<(tr("2039"))<<(tr("2040"))<<(tr("2041"))<<(tr("2042"))<<(tr("2043"))<<(tr("2044"))<<(tr("2045"))<<(tr("2046"))<<(tr("2047"))<<(tr("2048"))<<(tr("2049"))<<(tr("2050"));
    C_year->addItems(list_year);
    C_year->setCurrentText(QString::number((QDate::currentDate().year())));

    hlayout8d->addWidget(R_cmonth);
    hlayout8d->addWidget(C_cmonth);
    hlayout8d->setSpacing(5);
    hlayout8d->addWidget(C_year);


    B_submit = new QPushButton(tr("SUBMIT"));
    B_submit->setStyleSheet("QPushButton {color :  #000033 ;font: 25pt Times New Roman;background-color: rgba(51, 204, 0);}");//
    hlayout8f->addWidget(B_submit);

    ver_part1 = new QVBoxLayout;
    ver_part1->setSpacing(15);
    m_hboxtype->addWidget(m_selectSevaType);
    m_hboxtype->addWidget(C_type);
    m_hboxname->addWidget(m_selectSevaName);
    m_hboxname->addWidget(C_seva);
    ver_part1->addLayout(m_hboxtype);
    ver_part1->addLayout(m_hboxname);
    ver_part1->addLayout(hlayout8c);
    ver_part1->setSpacing(50);
    ver_part1->addLayout(hlayout8e);
    ver_part1->addLayout(hlayout8d);
    ver_part1->addLayout(hlayout8f);
    font.setPointSize(15);
    lab = new QLabel(tr("                                       SEVA DETAILS AS ON "));
    lab->setStyleSheet("QLabel {color : '#cc00cc' ;font: 25pt Times New Roman}");

    lab->setFont(font);
    st = QString("");
    da = new QLabel(st);
    da->setFont(font);
    da->setStyleSheet("QLabel {color : '#cc00cc' ;font: 25pt Times New Roman}");
    hlayout9 = new QHBoxLayout;
    hlayout9->addSpacing(300);
    hlayout9->addWidget(lab,0,Qt::AlignCenter);
    hlayout9->addWidget(da);
    view = new QTableView;
    view->resizeColumnsToContents();
    view->setVisible(true);
    view->resize(400,700);
    ver_part2 = new QVBoxLayout;
    ver_part2->addWidget(view);
    gro_left = new QGroupBox;
    gro_left->setFlat(false);
    gro_left->setLayout(ver_part1);
    gro_left->setStyleSheet("QGroupBox {border-radius:20px;background-color:'#80ffaa';border-style:outset;border-width:3px}");
    gro_right = new QGroupBox;
    gro_right->setFlat(true);
    gro_right->setLayout(ver_part2);
    hor_main = new QHBoxLayout;
    hor_main->addWidget(gro_left,4);
    hor_main->addWidget(gro_right,8);
    font.setPointSize(16);
    lab1 = new QLabel(tr("              Total Collections  =  "));
    lab1->setFont(font);
    st1 = QString("");
    da1 = new QLabel(st1);
    da1->setFont(font);
    summary = new QPushButton("Summary");
    summary->setFont(font);
    report_date_wise = new QPushButton("Datewise Report");
    report_date_wise->setFont(font);
    report_range = new QPushButton("Report b/n Dates");
    report_range->setFont(font);
    report_month_wise = new QPushButton("Monthwise Report");
    report_month_wise->setFont(font);
    Export_c_xl = new QPushButton("Export All Data");
    Export_c_xl->setFont(font);
    bot_main = new QHBoxLayout;
    bot_main->addSpacing(300);
    bot_main->addWidget(lab1,0,Qt::AlignLeft);
    bot_main->addWidget(da1,0,Qt::AlignLeft);
    bot_main->addWidget(summary,0,Qt::AlignLeft);
    bot_main->addWidget(report_date_wise,0,Qt::AlignLeft);
    bot_main->addWidget(report_range,0,Qt::AlignLeft);
    bot_main->addWidget(report_month_wise,0,Qt::AlignLeft);
    bot_main->addWidget(Export_c_xl,0,Qt::AlignRight);
    ver_main->addLayout(hlayout9);
    ver_main->addLayout(hor_main);
    ver_main->addLayout(bot_main);
    this->setLayout(ver_main);

    report_date_wise->hide();
    report_range->hide();
    report_month_wise->hide();

    connect(C_type,SIGNAL(highlighted(int)),this,SLOT(combo_type(int)));
    connect(C_seva,SIGNAL(highlighted(QString)),this,SLOT(combo_seva(QString)));
    connect(B_submit,SIGNAL(clicked()),this,SLOT(submit_funtion()));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(calendar_receive(QDate)));
    connect(R_cdate,SIGNAL(clicked()),this,SLOT(Rbutton_cdate()));
    connect(m_DataRange,SIGNAL(clicked()),this,SLOT(Rbutton_Rangedate()));
    connect(R_cmonth,SIGNAL(clicked()),this,SLOT(Rbutton_cmonth()));
    connect(summary,SIGNAL(clicked()),this, SLOT(export_creport_csv()));
    connect(report_date_wise,SIGNAL(clicked()),this, SLOT(export_report_date_wise()));
    connect(report_month_wise,SIGNAL(clicked()),this, SLOT(export_report_month_wise()));
    connect(report_range,SIGNAL(clicked()),this, SLOT(export_report_range()));

    connect(Export_c_xl,SIGNAL(clicked()),this, SLOT(export_booking_csv()));
}

void CurrentReport:: combo_function(QList<QString> list_sevaType)
{
    TYPE = 0;
    int size=list_sevaType.size();
    C_type->clear();
    C_type->addItem("ALL SEVA TYPE");
    for(int i=0;i<size;i++)
    {
        C_type->addItem(list_sevaType.at(i));
    }
}
void CurrentReport:: combo_type(int type)
{
    TYPE = type;
    dbfile::getInstance()->seva_name_adding(type);
}
void CurrentReport::calendar_receive(QDate date)
{
    if(i_radio==1){
        calendar_str = date.toString("dd-MM-yyyy");
        //    QDate dateStart = m_StartDate->text());
        QDate Date = QDate::fromString(calendar_str,"dd-MM-yyyy");
        formatchangedcalendar_str = Date.toString("dd-MM-yyyy");
        m_cdate->setText(date.toString("dd-MM-yyyy"));
        qDebug()<<Q_FUNC_INFO<<"date ::"<<calendar_str<<endl;
        calendar->hide();
    }
    else if(i_radio==2){

        if(startdate){
            calendar_str = date.toString("dd-MM-yyyy");
            m_StartDate->setText(date.toString("dd-MM-yyyy"));
            startdate = false;
            dateCheck = date;

            calendar->setWindowTitle("End Date");
            calendar->hide();
            QThread::msleep(500);
            calendar->show();
        }
        else{
            qint64 daysBetween = date.toJulianDay() - dateCheck.toJulianDay();
            //qDebug()<<daysBetween<<endl;
            if(daysBetween<1)
            {
                QMessageBox msgBox;
                msgBox.setText(tr("Please enter a valid End date"));
                msgBox.exec();
                return;
            }
            calendar_str = date.toString("dd-MM-yyyy");
            m_EndDate->setText(date.toString("dd-MM-yyyy"));
            qDebug()<<Q_FUNC_INFO<<"date ::"<<calendar_str<<endl;
            calendar->hide();
        }
    }
    B_submit->setEnabled(true);

}
void CurrentReport::submit_funtion()
{
    /*list should be cleared*/
    list_name.clear();
    list_ticket.clear();
    list_cost.clear();
    list_total.clear();

    if(i_radio == 1)
    {
        da->setText(calendar_str);
        cdate_function();
    }
    else if(i_radio == 2)
    {
        da->setText(m_StartDate->text()+"  -  "+m_EndDate->text());
        dataRange_function();
    }
    else if(i_radio == 3)
    {
        da->setText(C_cmonth->currentText());
        cmonth_function();
    }
}

void CurrentReport::combo_seva(QString)
{
    B_submit->setEnabled(true);
}

QStandardItemModel* CurrentReport:: createModel(QObject* parent, QList<QString> list_name, QList<int> list_ticket, QList<float> list_cost, QList<float> list_total, QString total_sum)
{
    int row,column;
    int list_size= list_name.size();
    model->clear();
    model->setHorizontalHeaderLabels(QStringList()<<(tr("                                 Seva Name                             "))<<(tr("   Cost  "))<<(tr("No. of Persons"))<<(tr("Total Amount")));
    for (row = 0; row < list_size; ++row)
    {
        for (column = 0; column < 4; ++column)
        {
            if(column == 0)
            {
                QStandardItem *item1 = new QStandardItem(QString("%0").arg(list_name.at(row)));
                model->setItem(row,column,item1);
            }
            if(column == 1)
            {
                QStandardItem *item3 = new QStandardItem(QString("%0").arg(list_cost.at(row)));
                model->setItem(row,column,item3);
            }
            if(column == 2)
            {
                QStandardItem *item2 = new QStandardItem(QString("%0").arg(list_ticket.at(row)));
                model->setItem(row,column,item2);
            }
            if(column == 3)
            {
                QStandardItem *item4 = new QStandardItem(QString("%0").arg(list_total.at(row)));
                model->setItem(row,column,item4);
            }
        }
    }
    return model;
}

void CurrentReport::cdate_function()
{
    SEVA = C_seva->currentText();
    dbfile::getInstance()->account_report_cdate_function(SEVA,TYPE,formatchangedcalendar_str);
}
void CurrentReport::cmonth_function()
{
    int sum=0;
    SEVA = C_seva->currentText();
    int month = C_cmonth->currentIndex()+1;
    int year = C_year->currentText().toInt();
    dbfile::getInstance()->account_report_cmonth_function(SEVA,TYPE,month,year);
}

void CurrentReport::dataRange_function()
{
    SEVA = C_seva->currentText();
    qDebug()<<"start date"<<m_StartDate->text()<<"end date"<<m_EndDate->text()<<endl;

    QString priviusformatdateseva_Startdate = m_StartDate->text();
    QDate Date = QDate::fromString(priviusformatdateseva_Startdate,"dd-MM-yyyy");
    QString seva_Startdate = Date.toString("dd-MM-yyyy");
    QString priviusformatdateseva_Enddate  = m_EndDate->text();
    QDate Date1 = QDate::fromString(priviusformatdateseva_Enddate,"dd-MM-yyyy");
    QString seva_Enddate = Date1.toString("dd-MM-yyyy");
    dbfile::getInstance()->account_report_dataRange_function(SEVA,TYPE,seva_Startdate,seva_Enddate);
}


void CurrentReport:: Rbutton_cdate()
{
    m_cdate->setEnabled(true);
    m_StartDate->setEnabled(false);
    m_EndDate->setEnabled(false);
    C_cmonth->setEnabled(false);
    C_year->setEnabled(false);
    report_date_wise->show();
    report_range->hide();
    report_month_wise->hide();

    i_radio = 1;
    calendar->setWindowTitle("Select date");
    calendar->setGeometry(600,500,500,400);

    calendar->setVisible(true);
    //qDebug()<<"*************************************"<<endl;
}
void CurrentReport:: Rbutton_Rangedate()
{
    m_StartDate->setEnabled(true);
    m_EndDate->setEnabled(true);
    m_cdate->setEnabled(false);
    C_cmonth->setEnabled(false);
    C_year->setEnabled(false);
    report_range->show();
    report_date_wise->hide();
    report_month_wise->hide();

    startdate = true;
    i_radio = 2;
    calendar->setWindowTitle("start date");
    calendar->setVisible(true);
    calendar->setGeometry(600,500,500,400);
    C_cmonth->setEnabled(false);
    C_year->setEnabled(false);
}

void CurrentReport:: Rbutton_cmonth()
{
    C_cmonth->setEnabled(true);
    m_cdate->setEnabled(false);
    m_StartDate->setEnabled(false);
    m_EndDate->setEnabled(false);
    i_radio = 3;
    C_year->setEnabled(true);
    report_month_wise->show();
    report_date_wise->hide();
    report_range->hide();
}

void CurrentReport::addingSevaname(QList<QString> seva_name)
{
    C_seva->setEnabled(true);
    C_seva->clear();
    int size=seva_name.size();
    if(TYPE!=0){
        C_seva->setEnabled(true);
        C_seva->addItem("All");
    }
    for(int i=0;i<size;i++)
    {
        C_seva->addItem(seva_name.at(i));
    }
    qDebug()<<Q_FUNC_INFO<<C_seva->currentIndex();
    C_seva->setCurrentIndex(0);
    SEVA = 1;
}

void CurrentReport::date_wise(QList<QString> list_name, QList<int> list_ticket, QList<float> list_cost, QList<float> list_total, QString total_sum)
{
    da1->setText(total_sum);
    this->list_name = list_name;
    this->list_ticket = list_ticket;
    this->list_cost = list_cost;
    this->list_total = list_total;
    total_amt = total_sum;
    view->setModel(createModel(view,list_name,list_ticket,list_cost,list_total,total_sum));
    view->resizeColumnsToContents();
}

void CurrentReport::export_creport_csv()
{
    QString filename = "Summary.csv";
    QFile file(filename);

    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << "Sl.No, Seva Name, Cost, No. of Persons, Total Amount" << endl;
        for(int i=0; i < list_total.size(); i++)
        {
            stream << QString::number(i+1) << ", " << list_name.at(i) << ", "<< QString::number(list_cost.at(i)) << ", "<< QString::number(list_ticket.at(i)) << ", "<< QString::number(list_total.at(i))<<endl;
        }
    }

    qDebug()<<"\n------------*********Current report to csv***********----------\n";
    qDebug()<<"-------***Seva Name, Total Amount----****"<<this->list_name<<", list total"<<this->list_total<<endl<<endl;
}

void CurrentReport::month_wise(QList<QString> list_name, QList<int> list_ticket, QList<float> list_cost, QList<float> list_total, QString total_sum)
{
    this->list_name = list_name;
    this->list_ticket = list_ticket;
    this->list_cost = list_cost;
    this->list_total = list_total;
    total_amt = total_sum;

    da1->setText(total_sum);
    view->setModel(createModel(view,list_name,list_ticket,list_cost,list_total,total_sum));
    view->resizeColumnsToContents();
}

void CurrentReport::date_range(QList<QString> list_name, QList<int> list_ticket, QList<float> list_cost, QList<float> list_total, QString total_sum)
{
    this->list_name = list_name;
    this->list_ticket = list_ticket;
    this->list_cost = list_cost;
    this->list_total = list_total;
    total_amt = total_sum;
    da1->setText(total_sum);
    view->setModel(createModel(view,list_name,list_ticket,list_cost,list_total,total_sum));
    view->resizeColumnsToContents();
}

void CurrentReport::export_booking_csv()
{
    qDebug()<<"\n------------*********Booking report to csv***********----------\n";
    //qDebug()<<"-------***Seva Name, Total Amount----****"<<this->list_sevaname<<", list dev bname"<<this->list_pname<<endl<<endl;
    retriveSevabookingDetails("Total_report.csv");
}

void CurrentReport::export_report_date_wise()
{
    qDebug()<<Q_FUNC_INFO<<"Export datewise\n"<<endl;

    DatewiseReport();
}

void CurrentReport::export_report_range()
{
    qDebug()<<Q_FUNC_INFO<<"Export range\n"<<endl;
    reportBetweenDates();
}

void CurrentReport::export_report_month_wise()
{
    qDebug()<<Q_FUNC_INFO<<"Export monthwise\n"<<endl;

    reportMonthly();
}

void CurrentReport::retriveSevabookingDetails(QString file_name)
{
    QSqlDatabase db1;
    db1 = QSqlDatabase::addDatabase("QSQLITE");
    QString currentPath=qApp->applicationDirPath()+"/nseva.db";
    db1.setDatabaseName(currentPath);

    QFile file(file_name);
    QString slNo,sevaName,quantity,sevaDate,recieptDate,sevaCost,additionalCost,sevaTotalPrice,note,cash,bank,bank_name;

    QTextStream csv_data_stream(&file);
    csv_data_stream<< "Recpt No,Seva Name,Quantity,Seva Date,Reciept Date,Seva Cost,Additional Cost,Seva Total Price,Note,Cash,Bank Amt, Bank Name\n";

    file.open(QIODevice::ReadWrite | QIODevice::Text);
    if(db1.open()){
        QSqlQuery query;
        query.exec("SELECT SNO,SEVANAME,QUANTITY,SEVA_DATE,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS FROM sevabooking");
        while(query.next()){
            slNo = query.value(0).toString();
            sevaName = query.value(1).toString();
            quantity = query.value(2).toString();
            sevaDate = query.value(3).toString();
            recieptDate = query.value(4).toString();
            sevaCost = query.value(5).toString();
            additionalCost = query.value(6).toString();
            sevaTotalPrice = query.value(7).toString();
            note = query.value(8).toString();
            cash = query.value(9).toString();
            bank = query.value(10).toString();
            bank_name = query.value(11).toString();

            QString csv_content;
            csv_content = slNo+","+sevaName+","+quantity+","+sevaDate+","+recieptDate+","+sevaCost+","+additionalCost+","+sevaTotalPrice+","+note+","+cash+","+bank+","+bank_name;
            csv_data_stream<<csv_content<<endl;

        }
    }
    db1.close();
}

void CurrentReport::openFile(QFile *file)
{
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream header(file);
    header<<"Recpt No,Seva Name,Quantity,Seva Date,Reciept Date,Seva Cost,Additional Cost,Seva Total Price,Note,Cash,Bank Amt, Bank Name\n";
;
    file->close();
    file->open(QIODevice::Append | QIODevice::Text);
}


//function to retrive the data for selected date
void CurrentReport::DatewiseReport()
{
    QSqlDatabase db1;
    db1 = QSqlDatabase::addDatabase("QSQLITE");
    QString currentPath=qApp->applicationDirPath()+"/nseva.db";
    db1.setDatabaseName(currentPath);

    QFile file("Datewise_report.csv");
    QString slNo,sevaName,quantity,sevaDate,recieptDate,sevaCost,additionalCost,sevaTotalPrice,note,cash,bank,bank_name;

    QString line1;
    line1= "'"+m_cdate->text()+"'";
    qDebug()<<"Date is: "<<line1<<endl;
    QTextStream csv_data_stream(&file);
    csv_data_stream<< "Recpt No,Seva Name,Quantity,Seva Date,Reciept Date,Seva Cost,Additional Cost,Seva Total Price,Note,Cash,Bank Amt, Bank Name\n";

    file.open(QIODevice::ReadWrite | QIODevice::Text);
    if(db1.open()){
        qDebug()<<"DB opened"<<endl;
        QSqlQuery query;
        QString que1;

        que1 = ("SELECT SNO,SEVANAME,QUANTITY,SEVA_DATE,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS FROM sevabooking where sevabooking.RECEIPT_DATE='%1' Group by sevabooking.SEVANAME");
        que1 = que1.arg(formatchangedcalendar_str);
        query.prepare(que1);
        query.exec();
        while(query.next()){
            slNo = query.value(0).toString();
            sevaName = query.value(1).toString();
            quantity = query.value(2).toString();
            sevaDate = query.value(3).toString();
            recieptDate = query.value(4).toString();
            sevaCost = query.value(5).toString();
            additionalCost = query.value(6).toString();
            sevaTotalPrice = query.value(7).toString();
            note = query.value(8).toString();
            cash = query.value(9).toString();
            bank = query.value(10).toString();
            bank_name = query.value(11).toString();

            QString csv_content;
            csv_content = slNo+","+sevaName+","+quantity+","+sevaDate+","+recieptDate+","+sevaCost+","+additionalCost+","+sevaTotalPrice+","+note+","+cash+","+bank+","+bank_name;
            csv_data_stream<<csv_content<<endl;

        }
    }

}



//function to retrive the data for selected month
void CurrentReport::reportMonthly()
{
    QSqlDatabase db1;
    db1 = QSqlDatabase::addDatabase("QSQLITE");
    QString currentPath=qApp->applicationDirPath()+"/nseva.db";
    db1.setDatabaseName(currentPath);

    QFile file("Monthwise_report.csv");
    QString slNo,sevaName,quantity,sevaDate,recieptDate,sevaCost,additionalCost,sevaTotalPrice,note,cash,bank,bank_name;

    QString line1;
    line1= "'"+m_cdate->text()+"'";
    qDebug()<<"Date is: "<<line1<<endl;
    QTextStream csv_data_stream(&file);
    csv_data_stream<< "Recpt No,Seva Name,Quantity,Seva Date,Reciept Date,Seva Cost,Additional Cost,Seva Total Price,Note,Cash,Bank Amt, Bank Name\n";

    file.open(QIODevice::ReadWrite | QIODevice::Text);
    if(db1.open()){
        qDebug()<<"DB opened"<<endl;
        QSqlQuery query;
        QString que1;

        int month = C_cmonth->currentIndex()+1;
        int year = C_year->currentText().toInt();

        que1 = ("SELECT SNO,SEVANAME,QUANTITY,SEVA_DATE,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS FROM sevabooking WHERE S_MONTH = (:month) and S_YEAR = (:year)");
        query.prepare(que1);
        query.bindValue(":month",month);
        query.bindValue(":year",year);
        query.exec();

        while(query.next()){
            slNo = query.value(0).toString();
            sevaName = query.value(1).toString();
            quantity = query.value(2).toString();
            sevaDate = query.value(3).toString();
            recieptDate = query.value(4).toString();
            sevaCost = query.value(5).toString();
            additionalCost = query.value(6).toString();
            sevaTotalPrice = query.value(7).toString();
            note = query.value(8).toString();
            cash = query.value(9).toString();
            bank = query.value(10).toString();
            bank_name = query.value(11).toString();

            QString csv_content;
            csv_content = slNo+","+sevaName+","+quantity+","+sevaDate+","+recieptDate+","+sevaCost+","+additionalCost+","+sevaTotalPrice+","+note+","+cash+","+bank+","+bank_name;
            csv_data_stream<<csv_content<<endl;

        }
    }

}

//function to retrive the data from date till to date

void CurrentReport::reportBetweenDates()
{
//    QSqlDatabase db1;
//    db1 = QSqlDatabase::addDatabase("QSQLITE");
//    QString currentPath=qApp->applicationDirPath()+"/nseva.db";
//    db1.setDatabaseName(currentPath);

//    /*
//    QFile file("FromToDateReport.csv");
//    QString line1;
//    line1= "'"+m_cdate->text()+"'";
//    qDebug()<<"Date is: "<<line1<<endl;
//    QTextStream csv_data_stream(&file);
//    csv_data_stream<< "Recpt No,Seva Name,Quantity,Seva Date,Reciept Date,Seva Cost,Additional Cost,Seva Total Price,Note,Cash,Bank Amt, Bank Name\n";

//    file.open(QIODevice::ReadWrite | QIODevice::Text); */

//    if(db1.open()){
//        qDebug()<<"Slot called"<<endl;

//        QString fromDate,toDate;

//        fromDate = m_StartDate->text();
//        toDate = m_EndDate->text();

//        qDebug()<<"from date "<<fromDate<<endl;
//        qDebug()<<"To date"<<toDate<<endl;
//        QFile file("FromToDateReport.csv");
//        openFile(&file);
//        QSqlQuery query;
//        query.prepare("SELECT SNO,SEVANAME,QUANTITY,SEVA_DATE,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS FROM sevabooking WHERE SEVA_DATE >= (:from) and SEVA_DATE <= (:to)");
//        query.bindValue(":from",fromDate);
//        query.bindValue(":to",toDate);
//        query.exec();
//        while(query.next()){
//            QTextStream data(&file);
//            QString finalStream;
//            finalStream = query.value(0).toString()+","+query.value(1).toString()+","+query.value(2).toString()+","+query.value(3).toString()+","+
//                    query.value(4).toString()+","+query.value(5).toString()+","+query.value(6).toString()+","+query.value(7).toString()+","+
//                    query.value(8).toString()+","+query.value(9).toString()+","+query.value(10).toString()+","+query.value(11).toString()+","+
//                    query.value(12).toString()+","+query.value(13).toString()+","+query.value(14).toString()+","+query.value(15).toString()+","+
//                    query.value(16).toString();
//            data<<finalStream<<endl;
//        }
//    }

}

CurrentReport::~CurrentReport()
{

}
