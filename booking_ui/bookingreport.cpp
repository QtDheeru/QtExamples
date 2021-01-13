#include "bookingreport.h"

bookingReport::bookingReport(QWidget *parent) : QWidget(parent)
{
    printbutton = new QPushButton(tr("PRINT"));
    printbutton->setStyleSheet("QPushButton {color :  #000033 ;font: 25pt Times New Roman;}");//
    total_prasada=0;
    p_bar = new QProgressBar;
    //QLabel *total = new QLabel("Total Prasadas:");
    //    total->setStyleSheet("QLabel {color : '#cc00cc' ;font: 18pt Times New Roman}");
    //    l1 = new QLabel("");
    //    l1->setStyleSheet("QLabel {color : '#cc00cc' ;font: 18pt Times New Roman}");

    get_report = new QPushButton("Export Data");
    get_report->setStyleSheet("QPushButton {color : '#cc00cc' ;font: 18pt Times New Roman}");

    QHBoxLayout *hbox1= new QHBoxLayout;
    QHBoxLayout *hbox2= new QHBoxLayout;

    //listReport<<(tr("REPORT"))<<(tr("SANKALAPA POOJA"))<<(tr("THEERTHA PRASADA"));
    i_radio = 0;
    ver_main = new QVBoxLayout(this);
    hlayout8a = new QHBoxLayout;
    hlayout8c = new QHBoxLayout;
    hlayout8d = new QHBoxLayout;
    hlayout8e = new QHBoxLayout;
    hlayout8f = new QHBoxLayout;
    model=new QStandardItemModel( 0,7 );
    model->setHorizontalHeaderLabels(QStringList()<<(tr("NAME"))<<(tr("GOTHRA"))<<(tr("NAKSHATRA"))<<(tr("SEVA NAME"))<<(tr("THEERTHA PRASADA"))<<(tr("MOBILE NUMBER "))<<(tr("NOTE")));
    //    s_model=new QStandardItemModel( 0,3 );
    //    s_model->setHorizontalHeaderLabels(QStringList()<<(tr("NAME"))<<(tr("GOTHRA"))<<(tr("NAKSHATRA"))<<(tr("SEVA NAME")));
    //    t_model=new QStandardItemModel( 0,7 );
    //    t_model->setHorizontalHeaderLabels(QStringList()<<(tr("NAME"))<<(tr("GOTHRA"))<<(tr("NAKSHATRA"))<<(tr("SEVA NAME"))<<(tr("THEERTHA PRASADA"))<<(tr("MOBILE NUMBER "))<<(tr("NOTE")));
    view = new QTableView;
    view->resizeColumnsToContents();
    view->setVisible(true);
    view->resize(400,700);
    view->setModel(model);

    //    s_view = new QTableView;
    //    s_view->resizeColumnsToContents();
    //    s_view->resize(400,700);
    //    s_view->setModel(s_model);
    //    t_view = new QTableView;
    //    t_view->resizeColumnsToContents();
    //    t_view->resize(400,700);
    //    t_view->setModel(t_model);

    m_hboxtype =new QHBoxLayout;
    m_hboxname =new QHBoxLayout;

    QFont font;
    //    font.pointSize(5);
    //    font.setPointSize(font.pointSize() + 55);
    vlayout8e = new QVBoxLayout;
    calendar = new QCalendarWidget;
    calendar->setWindowModality(Qt::ApplicationModal);
    calendar->setGridVisible(true);
    calendar->setVisible(false);

    m_selectSevaType = new QLabel(tr("SELECT SEVA TYPE"));
    m_selectSevaType->setStyleSheet("QLabel {color : '#cc00cc' ;font: 18pt Times New Roman}");


    m_selectSevaName = new QLabel(tr("SELECT SEVA NAME"));
    m_selectSevaName->setStyleSheet("QLabel {color : '#cc00cc' ;font: 18pt Times New Roman}");

    C_type = new QComboBox;
    C_type->setMaximumWidth(300);
    C_type->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");

    C_seva = new QComboBox;
    C_seva->setMaximumWidth(300);

    C_seva->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    R_cdate = new QRadioButton(tr("SELECT DATE"));
    R_cdate->setStyleSheet("QRadioButton {color : '#cc00cc' ;font: 20pt Times New Roman}");

    R_cdate->setObjectName("RadioButtonCurrentDate");

    m_cdate = new QLineEdit;
    m_cdate->setMaximumWidth(210);
    m_cdate->setStyleSheet("QLineEdit {font: 18pt Times New Roman;border-style:outset;border-width:1.5px}");


    m_cdate->setText(QDate::currentDate().toString("dd-MM-yyyy"));
    m_cdate->setMaximumWidth(210);
    m_cdate->setEnabled(false);
    hlayout8c->addWidget(R_cdate);
    hlayout8c->addWidget(m_cdate);

    m_DataRange = new QRadioButton(tr("SELECT DATE RANGE"));
    m_DataRange->setStyleSheet("QRadioButton {color : '#cc00cc' ;font: 20pt Times New Roman;}");

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

    R_cmonth = new QRadioButton(tr("SELECT MONTH, YEAR"));
    R_cmonth->setStyleSheet("QRadioButton {color : '#cc00cc' ;font: 18pt Times New Roman;}");
    C_cmonth = new QComboBox;
    C_cmonth->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    C_cmonth->setMaximumWidth(210);
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
    C_year->setCurrentText(QString::number(QDate::currentDate().year()));
    hlayout8d->addWidget(R_cmonth);
    hlayout8d->addWidget(C_cmonth);
    hlayout8d->setSpacing(5);
    hlayout8d->addWidget(C_year);

    //    report = new QComboBox;
    //    report->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    //    report->addItems(listReport);

    report = new QPushButton("Display Report");
    report->setStyleSheet("QPushButton {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    hlayout8f->addWidget(report);
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
    ver_part2 = new QVBoxLayout;
    //    s_view->setVisible(false);
    //    t_view->setVisible(false);
    view->setVisible(true);
    hbox1->addWidget(view);
    //    hbox1->addWidget(s_view);
    //    hbox1->addWidget(t_view);
    //    hbox2->addWidget(total);
    //    hbox2->addWidget(l1);
    hbox2->addWidget(printbutton,0,Qt::AlignLeft);
    hbox2->addWidget(get_report,0,Qt::AlignCenter);

    get_report->setVisible(true);
    printbutton->setVisible(false);
    //printbutton->setVisible(true);
    ver_part2->addLayout(hbox1);
    ver_part2->addLayout(hbox2);
    gro_left = new QGroupBox;
    gro_left->setFlat(false);
    gro_left->setLayout(ver_part1);
    gro_left->setStyleSheet("QGroupBox {border-radius:20px;background-color:'#b3ffff';border-style:outset;border-width:3px}");

    gro_right = new QGroupBox;
    gro_right->setFlat(true);
    gro_right->setLayout(ver_part2);
    hor_main = new QHBoxLayout;
    hor_main->addWidget(gro_left,4);
    hor_main->addWidget(gro_right,8);
    font.setPointSize(15);
    //    lab1 = new QLabel(tr("Total Collections   =        "));
    //    lab1->setFont(font);
    st1 = QString("");
    da1 = new QLabel(st1);
    da1->setFont(font);
    bot_main = new QHBoxLayout;
    bot_main->addSpacing(300);
    //    bot_main->addWidget(lab1,0,Qt::AlignRight);
    //    bot_main->addWidget(da1);
    ver_main->addLayout(hlayout9);
    ver_main->addLayout(hor_main);
    ver_main->addLayout(bot_main);
    this->setLayout(ver_main);
    connect(C_type,SIGNAL(currentIndexChanged(int)),this,SLOT(combo_type(int)));
    //connect(report,SIGNAL(currentIndexChanged(int)),this,SLOT(selectReport(int)));
    connect(report,SIGNAL(clicked(bool)),this,SLOT(selectReport()));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(calendar_receive(QDate)));
    connect(R_cdate,SIGNAL(clicked()),this,SLOT(Rbutton_cdate()));
    connect(m_DataRange,SIGNAL(clicked()),this,SLOT(Rbutton_Rangedate()));
    connect(R_cmonth,SIGNAL(clicked()),this,SLOT(Rbutton_cmonth()));
    connect(printbutton,SIGNAL(clicked()),this,SLOT(printReport()));
    //connect(Export_b_xl, SIGNAL(clicked()), this, SLOT(export_booking_csv()));
    connect(get_report, SIGNAL(clicked()), this, SLOT(export_booking_report_csv()));

}

void bookingReport:: combo_function(QList<QString> list_sevaType)
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

void bookingReport:: combo_type(int type)
{
    TYPE = type;
    dbfile::getInstance()->seva_name_adding(type);
}

void bookingReport::calendar_receive(QDate date)
{
    if(i_radio==1){
        calendar_str = date.toString("dd-MM-yyyy");
        QDate Date = QDate::fromString(calendar_str,"dd-MM-yyyy");
        formatchangedcalendar_str = Date.toString("dd-MM-yyyy");
        m_cdate->setText(date.toString("dd-MM-yyyy"));
        qDebug()<<Q_FUNC_INFO<<calendar_str<<endl;
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
                msgBox.setText(tr("Please enter a valid end date"));
                msgBox.exec();
                return;
            }
            calendar_str = date.toString("dd-MM-yyyy");
            m_EndDate->setText(date.toString("dd-MM-yyyy"));
            qDebug()<<Q_FUNC_INFO<<"date ::"<<calendar_str<<endl;
            calendar->hide();
        }
    }
}

void bookingReport::submit_funtion()
{
    view->setVisible(true);
    model->clear();
    //    s_view->setVisible(false);
    //    t_view->setVisible(false);
    //    s_model->clear();
    //    t_model->clear();

    /*list should be cleared*/
//    list_sevaname.clear();
//    list_prasada.clear();
//    list_quantity.clear();
//    list_sevadate.clear();
//    list_note.clear();
//    list_pname.clear();
//    list_gotra.clear();
//    list_nakshatra.clear();
//    list_mobile.clear();

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

QStandardItemModel* bookingReport:: createModel(QObject* parent, QList<QString> list_sevaname, QList<int> list_quantity, QList<int> list_prasada, QList<QString> list_sevadate, QList<QString> list_note, QList<QString> list_pname, QList<QString> list_gotra, QList<QString> list_nakshatra, QList<QString> list_mobile)
{
    this->list_pname = list_pname;
    this->list_gotra = list_gotra;
    this->list_mobile = list_mobile;
    this->list_nakshatra = list_nakshatra;
    this->list_note = list_note;
    this->list_quantity = list_quantity;
    this->list_sevaname = list_sevaname;

    qDebug()<<Q_FUNC_INFO<< "\n\n----***List person name*****---"<< this->list_pname<< endl<<endl;
    int row,column;
    int list_size=list_sevaname.size();
    //    model->clear();
    model->setHorizontalHeaderLabels(QStringList()<<(tr("NAME"))<<(tr("GOTHRA"))<<(tr("NAKSHATRA"))<<(tr("SEVA NAME"))<<(tr("PERSONS"))<<(tr("MOBILE NUMBER "))<<(tr("NOTE")));

    //view->resizeColumnsToContents();
    for (row = 0; row < list_size; ++row)
    {
        for (column = 0; column < 7; ++column)
        {
            if(column == 0)
            {
                QStandardItem *item1 = new QStandardItem(QString("%0").arg(list_pname.at(row)));
                model->setItem(row,column,item1);
            }
            if(column == 1)
            {
                QStandardItem *item2 = new QStandardItem(QString("%0").arg(list_gotra.at(row)));
                model->setItem(row,column,item2);
            }
            if(column == 2)
            {
                QStandardItem *item3 = new QStandardItem(QString("%0").arg(list_nakshatra.at(row)));
                model->setItem(row,column,item3);
            }
            if(column == 3)
            {
                QStandardItem *item4 = new QStandardItem(QString("%0").arg(list_sevaname.at(row)));
                model->setItem(row,column,item4);
            }
            if(column == 4)
            {
                QStandardItem *item5 = new QStandardItem(QString("%0").arg(list_quantity.at(row)));
                model->setItem(row,column,item5);
            }
            if(column == 5)
            {
                QStandardItem *item6 = new QStandardItem(QString("%0").arg(list_mobile.at(row)));
                model->setItem(row,column,item6);
            }
            if(column == 6)
            {
                QStandardItem *item7 = new QStandardItem(QString("%0").arg(list_note.at(row)));
                model->setItem(row,column,item7);
            }
        }
    }
    return model;
}

void bookingReport::cdate_function()
{
    SEVA = C_seva->currentText();
    dbfile::getInstance()->booking_report_cdate_function(formatchangedcalendar_str,SEVA,TYPE);
}

void bookingReport::cmonth_function()
{
    SEVA = C_seva->currentText();
    int month = C_cmonth->currentIndex()+1;
    int year = C_year->currentText().toInt();
    dbfile::getInstance()->booking_report_cmonth_function(SEVA,TYPE,month,year);
}

void bookingReport::dataRange_function()
{
    qDebug()<<"start date"<<m_StartDate->text()<<"end date"<<m_EndDate->text()<<endl;

    //    QDate dateStart = m_StartDate->text());
    QString priviusformatdateseva_Startdate = m_StartDate->text();
    //    QDate dateStart = m_StartDate->text());
    QDate Date = QDate::fromString(priviusformatdateseva_Startdate,"dd-MM-yyyy");
    QString seva_Startdate = Date.toString("dd-MM-yyyy");
    SEVA = C_seva->currentText();

    QString priviusformatdateseva_Enddate  = m_EndDate->text();
    //    QDate dateStart = m_StartDate->text());
    QDate Date1 = QDate::fromString(priviusformatdateseva_Enddate,"dd-MM-yyyy");
    QString seva_Enddate = Date1.toString("dd-MM-yyyy");
    dbfile::getInstance()->booking_report_dataRange_function(SEVA,TYPE,seva_Startdate,seva_Enddate);
}


void bookingReport:: Rbutton_cdate()
{
    m_cdate->setEnabled(true);
    m_StartDate->setEnabled(false);
    m_EndDate->setEnabled(false);
    C_cmonth->setEnabled(false);
    C_year->setEnabled(false);

    i_radio = 1;
    calendar->setWindowTitle("Select date");
    calendar->setGeometry(600,500,500,400);

    calendar->setVisible(true);
}

void bookingReport:: Rbutton_Rangedate()
{
    m_StartDate->setEnabled(true);
    m_EndDate->setEnabled(true);
    m_cdate->setEnabled(false);
    C_cmonth->setEnabled(false);
    C_year->setEnabled(false);

    startdate = true;
    i_radio = 2;
    calendar->setWindowTitle("start date");
    calendar->setVisible(true);
    calendar->setGeometry(600,500,500,400);
    C_cmonth->setEnabled(false);
    C_year->setEnabled(false);

}

void bookingReport:: Rbutton_cmonth()
{
    C_cmonth->setEnabled(true);
    m_cdate->setEnabled(false);
    m_StartDate->setEnabled(false);
    m_EndDate->setEnabled(false);
    i_radio = 3;
    C_year->setEnabled(true);
}

//QStandardItemModel *bookingReport::createModel2(QObject* parent, QList<QString> list_sevaname, QList<int> list_quantity, QList<int> list_prasada, QList<QString> list_sevadate, QList<QString> list_note, QList<QString> list_pname, QList<QString> list_gotra, QList<QString> list_nakshatra, QList<QString> list_mobile)
//{
//    int row,column;
//    int list_size=list_sevaname.size();

//    //    this->list_sevaname = list_sevaname;
//    //    this->list_pname = list_pname;

//    qDebug()<<"\n\nSeva Name "<<this->list_sevaname <<" Devotee name "<<this->list_pname<<endl;

//    //    s_model = new QStandardItemModel(list_size,3);
//    s_model->setHorizontalHeaderLabels(QStringList()<<(tr("NAME"))<<(tr("GOTHRA"))<<(tr("NAKSHATRA"))<<(tr("SEVA NAME")));
//    s_view->resizeColumnsToContents();
//    for (row = 0; row < list_size; ++row)
//    {
//        for (column = 0; column < 4; ++column)
//        {
//            if(column == 0)
//            {
//                QStandardItem *item1 = new QStandardItem(QString("%0").arg(list_pname.at(row)));
//                s_model->setItem(row,column,item1);
//            }
//            if(column == 1)
//            {
//                QStandardItem *item2 = new QStandardItem(QString("%0").arg(list_gotra.at(row)));
//                s_model->setItem(row,column,item2);
//            }
//            if(column == 2)
//            {
//                QStandardItem *item3 = new QStandardItem(QString("%0").arg(list_nakshatra.at(row)));
//                s_model->setItem(row,column,item3);
//            }
//            if(column == 3)
//            {
//                QStandardItem *item4 = new QStandardItem(QString("%0").arg(list_sevaname.at(row)));
//                s_model->setItem(row,column,item4);
//            }

//        }
//    }
//    return s_model;
//}

void bookingReport::sevaList()
{
    view->setVisible(false);
    //    s_view->setVisible(true);
    //    t_view->setVisible(false);

}

void bookingReport::prasadaList()
{
    //    t_view->setVisible(true);
    //    s_view->setVisible(false);
    view->setVisible(false);

}

//void bookingReport::selectReport(int data)
//{
//    type=data;

//    if(type==0)
//    {
//        this->submit_funtion();
//    }
//    if(type==1)
//    {
//        this->submit_funtion();
//        this-> sevaList();
//    }
//    if(type==2)
//    {
//        this->submit_funtion();
//        this->prasadaList();
//    }
//    l1->setNum(total_prasada);
//}

void bookingReport::selectReport()
{
    this->submit_funtion();
}

void bookingReport::printreceipt()
{
    printbutton->setVisible(false);
    QHBoxLayout *p_hbox1,*p_hbox2,*p_hbox3;
    QVBoxLayout *p_vbox1;
    mylab = new mylabel(this);
    p_box =new QGroupBox;
    p_image = new QPixmap(gro_right->grab());
    mylab->setPixmap(p_image->scaled(800,800));
    mylab->setVisible(true);
    QPushButton *button1,*button2;
    p_hbox1 =new QHBoxLayout;
    p_hbox2 =new QHBoxLayout;
    p_hbox3 =new QHBoxLayout;
    p_vbox1 =new QVBoxLayout;
    button1 =new QPushButton(tr("Print"));
    button2 =new QPushButton(tr("Close"));

    p_hbox1->addWidget(mylab);
    p_hbox2->addWidget(button1);
    p_hbox2->addWidget(button2);
    p_vbox1->addLayout(p_hbox1);
    p_vbox1->addLayout(p_hbox2);
    p_box->setLayout(p_vbox1);
    p_box->setGeometry(600,100,800,800);
    p_box->setWindowFlags(Qt::Window | Qt::FramelessWindowHint |Qt::WindowCloseButtonHint);
    p_box->show();
    connect(button1,SIGNAL(clicked()),this,SLOT(printoption()));
    connect(button2,SIGNAL(clicked()),this,SLOT(closeoption()));
}

void bookingReport::printoption()
{
    p_box->close();
    printbutton->setVisible(true);

}

void bookingReport::closeoption()
{
    p_box->close();
    printbutton->setVisible(true);

}

//QStandardItemModel *bookingReport::createModel3(QObject* parent, QList<QString> list_sevaname, QList<int> list_quantity, QList<int> list_prasada, QList<QString> list_sevadate, QList<QString> list_note, QList<QString> list_pname, QList<QString> list_gotra, QList<QString> list_nakshatra, QList<QString> list_mobile)
//{
//    int row,column;
//    int list_size=list_sevaname.size();
//    //    this->list_sevaname = list_sevaname;
//    //    this->list_pname = list_pname;
//    //    t_model = new QStandardItemModel(list_size,8);
//    t_model->setHorizontalHeaderLabels(QStringList()<<(tr("NAME"))<<(tr("GOTHRA"))<<(tr("NAKSHATRA"))<<(tr("SEVA NAME"))<<(tr("THEERTHA PRASADA"))<<(tr("QUANTITY"))<<(tr("MOBILE NUMBER "))<<(tr("NOTE")));

//    t_view->resizeColumnsToContents();
//    for (row = 0; row < list_size; ++row)
//    {
//        for (column = 0; column <8; ++column)
//        {
//            if(list_prasada.at(row)!=0)
//            {
//                if(column == 0)
//                {
//                    QStandardItem *item1 = new QStandardItem(QString("%0").arg(list_pname.at(row)));
//                    t_model->setItem(row,column,item1);
//                }
//                if(column == 1)
//                {
//                    QStandardItem *item2 = new QStandardItem(QString("%0").arg(list_gotra.at(row)));
//                    t_model->setItem(row,column,item2);
//                }
//                if(column == 2)
//                {
//                    QStandardItem *item3 = new QStandardItem(QString("%0").arg(list_nakshatra.at(row)));
//                    t_model->setItem(row,column,item3);
//                }
//                if(column == 3)
//                {
//                    QStandardItem *item4 = new QStandardItem(QString("%0").arg(list_sevaname.at(row)));
//                    t_model->setItem(row,column,item4);
//                }
//                if(column == 4)
//                {
//                    QStandardItem *item5 = new QStandardItem(QString("%0").arg(list_prasada.at(row)));
//                    t_model->setItem(row,column,item5);
//                }
//                if(column == 5)
//                {
//                    QStandardItem *item6 = new QStandardItem(QString("%0").arg(list_quantity.at(row)));
//                    t_model->setItem(row,column,item6);
//                }
//                if(column == 6)
//                {
//                    QStandardItem *item7 = new QStandardItem(QString("%0").arg(list_mobile.at(row)));
//                    t_model->setItem(row,column,item7);
//                }
//                if(column == 7)
//                {
//                    QStandardItem *item8 = new QStandardItem(QString("%0").arg(list_note.at(row)));
//                    t_model->setItem(row,column,item8);
//                }
//            }
//        }
//    }
//    return t_model;
//}

void bookingReport::printReport()
{
    if(type==0)
    {
        this->printreceipt();
    }
    if(type==1)
    {
        this->printreceipt();
    }
    if(type==2)
    {
        this->printreceipt();
    }
}

void bookingReport::addingSevaname(QList<QString> seva_name)
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

void bookingReport::date_wise(QList<QString> list_sevaname, QList<int> list_quantity, QList<int> list_prasada, QList<QString> list_sevadate, QList<QString> list_note, QList<QString> list_pname, QList<QString> list_gotra, QList<QString> list_nakshatra, QList<QString> list_mobile)
{
    //    this->list_sevaname = list_sevaname;
    //    this->list_pname = list_pname;
    //    qDebug()<<"\n\n----////\\***List seva name*****////\\\\"<<this->list_sevaname<< endl<<endl;


    view->setModel(createModel(view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    view->resizeColumnsToContents();

    //    s_view->setModel(createModel2(s_view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    //    s_view->resizeColumnsToContents();
    //    t_view->setModel(createModel3(t_view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    //    t_view->resizeColumnsToContents();
}

void bookingReport::month_wise(QList<QString> , QList<int> , QList<int> , QList<QString> , QList<QString> list_note, QList<QString> , QList<QString> , QList<QString> , QList<QString> )
{
    //qDebug()<<"\n\n----////\\***List seva name*****////\\\\"<< this->list_sevaname<< endl<<endl;

    //    this->list_sevaname = list_sevaname;
    //    this->list_pname = list_pname;

    view->setModel(createModel(view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    view->resizeColumnsToContents();
    //    s_view->setModel(createModel2(s_view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    //    s_view->resizeColumnsToContents();
    //    t_view->setModel(createModel3(t_view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    //    t_view->resizeColumnsToContents();
}

void bookingReport::date_range(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)
{
    //    qDebug()<<"\n\n----////\\***List seva name*****////\\\\"<< list_sevaname<< endl<<endl;

    view->setModel(createModel(view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    view->resizeColumnsToContents();
    //    s_view->setModel(createModel2(s_view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    //    s_view->resizeColumnsToContents();
    //    t_view->setModel(createModel3(t_view,list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile));
    //    t_view->resizeColumnsToContents();
}

void bookingReport::export_booking_csv()
{
    qDebug()<<"\n----*********Total report to csv*********-----\n";
    //qDebug()<<"-------***Seva Name, Total Amount----****"<<this->list_sevaname<<", list dev bname"<<this->list_pname<<endl<<endl;
    retriveSevabookingDetails("Total_report.csv");
}

void bookingReport::export_booking_report_csv()
{
    qDebug()<<"\n------------*********Booking report to csv***********----------\n";
    QString filename = "Booking_report.csv";
    QFile file(filename);

    qDebug() << "Sl.No, Name, Gothra, Nakshatra, Seva Name, Persons, Mob No." << endl;
    qDebug() << QString::number(1) << ", " << list_pname.at(0)<<", " << list_gotra.at(0)<<endl ; // ", " << list_nakshatra.at(0)<< ", " << list_sevaname.at(0) << ", "<< QString::number(list_quantity.at(0)) << ", "<< list_mobile.at(0) <<endl;

    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << "Sl.No, Name, Gothra, Nakshatra, Seva Name, Persons, Mob No." << endl;
        //qDebug() << "Sl.No, Name, Gothra, Nakshatra, Seva Name, Persons, Mob No." << endl;

        for(int i=0; i < list_pname.size(); i++)
        {
            qDebug()<<"\n---Inside for after  file Stream--"<< i+1 <<endl;
            qDebug() << QString::number(i+1) << ", " << list_pname.at(i)<<", " << list_gotra.at(i)<< ", " << list_nakshatra.at(i)<< ", " << list_sevaname.at(i) << ", "<< QString::number(list_quantity.at(i)) << ", "<< list_mobile.at(i) <<endl;

            stream << QString::number(i+1) << ", " << list_pname.at(i)<< ", " << list_gotra.at(i)<< ", " << list_nakshatra.at(i)<< ", " << list_sevaname.at(i) << ", "<< QString::number(list_quantity.at(i)) << ", "<< list_mobile.at(i) <<endl;
        }
    }


}

void bookingReport::retriveSevabookingDetails(QString file_name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString currentPath=qApp->applicationDirPath()+"/nseva.db";
    db.setDatabaseName(currentPath);

    QFile file(file_name);
    QString slNo,sevaName,quantity,sevaDate,recieptDate,sevaCost,additionalCost,sevaTotalPrice,note,cash,bank,bank_name;

    QTextStream csv_data_stream(&file);
    csv_data_stream<< "Recpt No,Seva Name,Quantity,Seva Date,Reciept Date,Seva Cost,Additional Cost,Seva Total Price,Note,Cash,Bank Amt, Bank Name\n";

    file.open(QIODevice::ReadWrite | QIODevice::Text);
    if(db.open()){
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
}

bookingReport::~bookingReport()
{

}
