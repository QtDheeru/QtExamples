#include "printreceipt.h"

printreceipt::printreceipt(QWidget *parent) : QWidget(parent)
{
    m_hbox1 =new QHBoxLayout;
    m_hbox2 =new QHBoxLayout;
    m_hbox3 =new QHBoxLayout;
    m_hbox4 =new QHBoxLayout;
    m_hbox5 =new QHBoxLayout;

    m1_hbox2 =new QHBoxLayout;
    m1_hbox3 =new QHBoxLayout;
    m1_hbox4 =new QHBoxLayout;
    m1_hbox5 =new QHBoxLayout;
    m1_hbox6 =new QHBoxLayout;
    m1_hbox7 =new QHBoxLayout;
    m1_hbox8 =new QHBoxLayout;
    m1_hbox9=new QHBoxLayout;
    m1_hbox10=new QHBoxLayout;
    m1_hbox11=new QHBoxLayout;

    m_hbox6 =new QHBoxLayout;
    m_hbox7 =new QHBoxLayout;
    m_hbox8 =new QHBoxLayout;
    m_hbox9 =new QHBoxLayout;
    m_hbox10 =new QHBoxLayout;
    m_vbox1 =new QVBoxLayout;
    m_vbox2 =new QVBoxLayout;
    m_vbox3=new QVBoxLayout;
    m_vbox4=new QVBoxLayout;
    b_hbox1 =new QHBoxLayout;
    b_hbox2 =new QHBoxLayout;
    b_hbox3 =new QHBoxLayout;
    b_hbox4 =new QHBoxLayout;
    f_hbox1 =new QHBoxLayout;
    f_hbox2 =new QHBoxLayout;
    f_hbox3 =new QHBoxLayout;
    f_hbox4 =new QHBoxLayout;
    f_hbox5 =new QHBoxLayout;
    m_rulesPixmap =new QPixmap("://Rules.jpeg");
    m_rulesImage =new QLabel();
    m_rulesImage->setPixmap(m_rulesPixmap->scaled(this->width()+20,150));
    head =new hedder_screen;
    head->receipt();
    p_view=new QTableView;
    p_view->setVisible(true);
    p_view->horizontalHeader()->setStretchLastSection(true);
    p_model=new QStandardItemModel( 0,3 );
    p_model->setHorizontalHeaderLabels(QStringList()<<(tr("Sl. No"))<<(tr("NAME OF THE SEVA"))<<(tr("AMOUNT"))<<(tr("PERSONS"))<<(tr("ADDNAL AMT"))<<(tr("TOTAL")));
    p_view->setModel(p_model);
    m_r_no =new QLabel(tr("                     Rcpt No.:"));
    m_r_no->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_r_noprint =new QLabel(tr(""));
    m_r_noprint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_Name =new QLabel(tr("Name:           "));
    m_Name->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_user_name =new QLabel("");
    m_user_name->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_sevadate =new QLabel(tr("                     Seva date:"));
    m_sevadate->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_sevatime =new QLabel(tr("                     Seva Time:      "));
    m_sevatime->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_sevatimePrint =new QLabel;
    m_sevatimePrint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_sevadateprint =new QLabel("");
    m_sevadateprint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_Total=new QLabel(tr("                                                                                                                                    Total:"));
    m_Total->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_Note=new QLabel(tr("Note:"));
    m_Notedetails=new QLabel;
    m_trustName=new QLabel(tr("For SMSR&C Trust"));
    m_totalInWords=new QLabel(tr("Total Amount In words :"));
    m_totalInWordslabel=new QLabel(tr(""));

    m_Totalvalue=new QLabel(tr(""));
    m_Totalvalue->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");
    m_date =new QLabel(tr("                     Date:                          "));
    m_date->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_dateprint =new QLabel(tr(""));
    m_dateprint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_gotra =new QLabel(tr("Gothra:"));
    m_gotra->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_gotraprint =new QLabel(tr(""));
    m_gotraprint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");


    m_nakshatra =new QLabel(tr("Nakshatra:"));
    m_nakshatra->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_nakshatraprint =new QLabel(tr(""));
    m_nakshatraprint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_mobile =new QLabel(tr("Mobile No:"));
    m_mobile->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");

    m_mobileprint =new QLabel(tr(""));
    m_mobileprint->setStyleSheet("QLabel {color : '#330000' ;font: 13pt Times New Roman}");


    box1 =new QGroupBox;
    box2 =new QGroupBox;
    m_hbox1->addWidget(head);
    m_hbox2->addWidget(m_mobile,Qt::AlignLeft);
    m_hbox2->addWidget(m_mobileprint,Qt::AlignLeft);
    m_hbox3->addWidget(m_Name,Qt::AlignLeft);
    m_hbox3->addWidget(m_user_name,Qt::AlignLeft);
    m_hbox4->addWidget(m_gotra,Qt::AlignLeft);
    m_hbox4->addWidget(m_gotraprint,Qt::AlignLeft);
    m_hbox5->addWidget(m_nakshatra,Qt::AlignLeft);
    m_hbox5->addWidget(m_nakshatraprint,Qt::AlignLeft);
    m_vbox3->addLayout(m_hbox3);
    m_vbox3->addLayout(m_hbox2);
    m_vbox3->addLayout(m_hbox4);
    m_vbox3->addLayout(m_hbox5);


    m1_hbox2->addWidget(m_r_no,0,Qt::AlignLeft);
    m1_hbox2->addWidget(m_r_noprint,0,Qt::AlignRight);
    m1_hbox3->addWidget(m_date,0,Qt::AlignLeft);
    m1_hbox3->addWidget(m_dateprint,0,Qt::AlignRight);
    m1_hbox4->addWidget(m_sevadate,0,Qt::AlignLeft);
    m1_hbox4->addWidget(m_sevadateprint,0,Qt::AlignRight);
    m1_hbox5->addWidget(m_sevatime,Qt::AlignLeft);
    m1_hbox5->addWidget(m_sevatimePrint,0,Qt::AlignCenter);
    m_vbox4->addLayout(m1_hbox2);
    m_vbox4->addLayout(m1_hbox3);
    m_vbox4->addLayout(m1_hbox4);
    m_vbox4->addLayout(m1_hbox5);

    //    p_view->resizeColumnToContents(100);
    //    p_view->resizeRowToContents(100);
    p_view->setMaximumHeight(200);
    m1_hbox6->addLayout(m_vbox3);
    m1_hbox6->addLayout(m_vbox4);

    box1->setLayout(m1_hbox6);
    f_hbox5->addWidget(box1);
    m_hbox6->addWidget(p_view);
    m_hbox7->addWidget(m_Total,0,Qt::AlignRight);
    m_hbox7->addWidget(m_Totalvalue,0,Qt::AlignRight);
    m1_hbox8->addWidget(m_totalInWords,0,Qt::AlignLeft);
    m1_hbox8->addWidget(m_totalInWordslabel,Qt::AlignLeft);
    m1_hbox9->addWidget(m_Note,0,Qt::AlignLeft);
    m1_hbox9->setSpacing(10);
    m1_hbox9->addWidget(m_Notedetails,Qt::AlignLeft);
    m1_hbox10->addWidget(m_trustName,0,Qt::AlignRight);
    m1_hbox11->addWidget(m_rulesImage);

    m_vbox2->addLayout(m_hbox1);
    m_vbox2->addLayout(f_hbox5);
    m_vbox2->addLayout(m_hbox6);
    m_vbox2->addLayout(m_hbox7);
    m_vbox2->addLayout(m1_hbox7);
    m_vbox2->addLayout(m1_hbox8);
    m_vbox2->addLayout(m1_hbox9);
    m_vbox2->addLayout(m1_hbox10);
    m_vbox2->addLayout(m1_hbox11);


    box2->setMaximumSize(750,830);
    box2->setLayout(m_vbox2);
    m_hbox8->addWidget(box2);
    this->setLayout(m_hbox8);

}


void printreceipt::clear()
{
    p_model->clear();
    p_model->setHorizontalHeaderLabels(QStringList()<<(tr("Sl. No"))<<(tr("NAME OF THE SEVA"))<<(tr("AMOUNT"))<<(tr("PERSONS"))<<(tr("ADDNAL AMT"))<<(tr("TOTAL")));
    m_r_noprint->clear();
    m_dateprint->clear();
    m_user_name->clear();
    m_gotraprint->clear();
    m_nakshatraprint->clear();
    m_mobileprint->clear();
    m_sevadateprint->clear();
    m_Totalvalue->clear();
    m_totalInWordslabel->clear();
}
void printreceipt::display(QString devoteName, QString devoteSevacharge, QString devoteAdditionalcharges, QString devoteCount, QString devotereceiptdate, QString devoteSevadate, QString devoteSevaName, int cost, int total, QString mobile_no, QString devoteNakshatra, QString devoteGotra, int res_no,QString devoteNote,QString devoteTime)
{
    qDebug()<<"_________________aditional____________________"<<cost<<endl;
    m_mobileprint->setText(mobile_no);
    m_dateprint->setText(devotereceiptdate);
    m_sevadateprint->setText(devoteSevadate);
    m_gotraprint->setText(devoteGotra);
    m_nakshatraprint->setText(devoteNakshatra);
    m_user_name->setText(devoteName);
    m_r_noprint->setNum(res_no);
    int row =p_model->rowCount();
    QString value1 = QString("%1").arg(row+1);
    QStandardItem *item1 = new QStandardItem(value1);
    p_model->setItem(row, 0, item1);
    QString value2 = QString("%1").arg(devoteSevaName);
    QStandardItem *item2 = new QStandardItem(value2);
    p_model->setItem(row, 1, item2);
    QString value3 = QString("%1").arg(devoteSevacharge);
    QStandardItem *item3 = new QStandardItem(value3);
    p_model->setItem(row, 2, item3);
    QString value4 = QString("%1").arg(devoteCount);
    QStandardItem *item4 = new QStandardItem(value4);
    p_model->setItem(row, 3, item4);
    QString value5 = QString("%1").arg(devoteAdditionalcharges);
    QStandardItem *item5= new QStandardItem(value5);
    p_model->setItem(row, 4, item5);
    QString value6 = QString("%1").arg(cost);
    QStandardItem *item6= new QStandardItem(value6);
    p_model->setItem(row, 5, item6);
    m_Totalvalue->setNum(total);
    QString word=NumberToWord(total);
    m_totalInWordslabel->setText(word);
    m_Notedetails->setText(devoteNote);
    m_sevatimePrint->setText(devoteTime);
}

printreceipt::~printreceipt()
{

}

QString printreceipt::NumberToWord(const unsigned int number)
{
    const std::vector<QString> first14=
    {"Zero", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
     "Twelve", "Thirteen", "Fourteen" };
    const std::vector<QString> prefixes=
    {"Twen","Thir","For","Fif","Six","Seven","Eigh","Nine"};

    if( number <= 14 )
    {
        return first14.at(number);
    }
    if( number < 20 )
    {
        return prefixes.at(number-12) + "teen";
    }
    if( number < 100 )
    {
        unsigned int remainder = number - (static_cast<int>(number/10)*10);
        return prefixes.at(number/10-2) + (0 != remainder ? "ty " + NumberToWord(remainder) : "ty");
    }
    if( number < 1000 )
    {
        unsigned int remainder = number - (static_cast<int>(number/100)*100);
        return first14.at(number/100) + (0 != remainder ? " Hundred " + NumberToWord(remainder) : " Hundred");
    }
    if( number < 100000 )
    {
        unsigned int thousands = static_cast<int>(number/1000);
        unsigned int remainder = number - (thousands*1000);
        return NumberToWord(thousands) + (0 != remainder ? " Thousand " + NumberToWord(remainder) : " Thousand");
    }
    if( number < 10000000 )
    {
        unsigned int millions = static_cast<int>(number/100000);
        unsigned int remainder = number - (millions*100000);
        return NumberToWord(millions) + (0 != remainder ? " Lakhs " + NumberToWord(remainder) : " Lakhs");
    }

    throw std::out_of_range("NumberToWord() value too large");
}
