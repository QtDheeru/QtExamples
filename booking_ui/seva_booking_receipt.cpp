#include "seva_booking_receipt.h"
static int RID;
static int  total;
static int  counting;

seva_booking_receipt::seva_booking_receipt(QWidget *parent) : QWidget(parent)
{
    RID=0;
    total=0;
    counting=1;
    count=1;
    //    booking =new sevabooking_report;
    RS_listPrint = new print_file;
    RS_single_print = new print_file;
    print_res = new printreceipt;
    m_time = new QLabel(tr("Seva Time"));
    m_time->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    m_timeEdit = new QTimeEdit(QTime::currentTime());
    m_timeEdit->setMaximumWidth(280);
    m_timeEdit->setMinimumWidth(200);
    m_timeEdit->setMinimumHeight(40);
    m_timeEdit->setStyleSheet("QTimeEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    
    seva_charge_label =new QLabel(tr(""));
    seva_charge_label->setVisible(false);
    seva_charge_label->setStyleSheet("QLabel {color : '#cc00ff' ;font: 16pt Times New Roman}");
    calendarreceipt =new QCalendarWidget;
    calendarSeva =new QCalendarWidget;
    mobilelabel=new QLabel(tr("Mobile Number"));
    mobilelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    namelabel=new QLabel(tr("Name"));
    namelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    sevachargeslabel=new QLabel(tr("Seva Charges"));
    sevachargeslabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    additionalchargelabel=new QLabel(tr("Extra"));
    additionalchargelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    countlabel=new QLabel(tr("Count"));
    countlabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    naksathralabel=new QLabel(tr("Nakshatra"));
    naksathralabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    gothralabel=new QLabel(tr("Gothra"));
    gothralabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    r_datelabel=new QLabel(tr("    Date :"));
    r_datelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    s_datelabel=new QLabel(tr("Seva Date                  "));
    s_datelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    notelabel=new QLabel(tr("Note"));
    notelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    receiptnolabel=new QLabel(tr("Recpt No:"));
    receiptnolabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    r_no=new QLabel(tr(""));
    r_no->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    s_type = new mylabel(this);
    typelabel=new QLabel(tr("Seva Name:"));
    typelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    type_user=new QLabel(tr(""));
    type_user->setMouseTracking(true);
    type_user->setStyleSheet("QLabel {color : '#0066ff' ;font: 16pt Times New Roman}");
    box1 =new QGroupBox;
    box3 =new QGroupBox;
    s_date = new mylabel(this);
    r_date =new mylabel(this);
    image = new QPixmap("://calen.png");
    image1 = new QPixmap("://calen.png");
    s_date->setPixmap(image->scaled(50,30));
    s_date->setVisible(true);
    r_date->setPixmap(image1->scaled(50,30));
    r_date->setVisible(true);
    //    box1->setTitle(tr("SEVA "));
    mobileedit=new QLineEdit;
    mobileedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    mobileedit->setMaximumWidth(280);
    nameedit=new QLineEdit;
    nameedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    nameedit->setMaximumWidth(280);
    sevachargesedit=new QLineEdit;
    sevachargesedit->setMaximumWidth(280);
    sevachargesedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    
    countedit=new QLineEdit;
    countedit->setMaximumWidth(200);
    countedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    countedit->setText("1");
    r_dateedit=new QLineEdit;
    r_dateedit->setMaximumWidth(200);
    r_dateedit->setText(calendarreceipt->selectedDate().toString("dd-MM-yyyy"));
    r_dateedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    
    s_dateedit=new QLineEdit;
    //    s_dateedit->setMinimumWidth(240);
    s_dateedit->setMaximumWidth(160);
    s_dateedit->setText(calendarSeva->selectedDate().toString("dd-MM-yyyy"));
    s_dateedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    
    noteedit=new QLineEdit;
    noteedit->setMaximumWidth(280);
    noteedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    
    additionalchargeedit =new QLineEdit;
    additionalchargeedit->setMaximumWidth(280);
    additionalchargeedit->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    additionalchargeedit->setText("0");

    cheque_box = new QCheckBox(" Bank ");
    cheque_box->setStyleSheet("QCheckBox {color : '#0066ff' ;font: 16pt Times New Roman}");
    cash_box = new QCheckBox(" Cash ");
    cash_box->setStyleSheet("QCheckBox {color : '#0066ff' ;font: 16pt Times New Roman}");
    cheque_line = new QLineEdit;
    cheque_line->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    cash_line = new QLineEdit;
    cash_line->setStyleSheet("QLineEdit {color : '#cc00ff' ;font: 16pt Times New Roman}");
    bank_combo = new QComboBox;
    bank_combo->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 12pt Times New Roman}");
    bank_combo->setEnabled(false);
    //bank_combo->setVisible(false);
    bank_combo->setEditable(true);
    bank_combo->setMinimumWidth(200);
    bank_combo->setMaximumHeight(40);

    nakshatracom =new QComboBox;
    nakshatracom->setMaximumWidth(260);
    nakshatracom->setMinimumWidth(260);
    nakshatracom->setMaximumHeight(35);
    list_nakshatra<<(tr("Ashwini"))<<(tr("Bharani"))<<(tr("Krithika"))<<(tr("Rohini"))<<(tr("Mrigashira"))<<(tr("Ardra"))<<(tr("Punarvasu"))<<(tr("Pushya"))<<(tr("Ashlesha"))<<(tr("Magha"))<<(tr("Purvaphalguni"))<<(tr("Uttaraphalguni"))<<(tr("Hasta"))<<(tr("Chitra"))<<(tr("Swati"))<<(tr("Vishakha"))<<(tr("Anuradha"))<<(tr("Jyeshtha"))<<(tr("Moola"))<<(tr("Purvashadha"))<<(tr("Uttarashadha"))<<(tr("Shravana"))<<(tr("Dhanishtha"))<<(tr("Shathabhisha"))<<(tr("Purvabhadrapada"))<<(tr("Uttarabhadrapada"))<<(tr("Revati"))<<(tr("-"));
    
    nakshatracom->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 12pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");//
    nakshatracom->addItems(list_nakshatra);
    nakshatracom->setFrame(true);
    nakshatracom->setMaxVisibleItems(5);

    gothracom =new QComboBox;
    gothracom->setEditable(true);
    gothracom->setMaximumWidth(260);
    gothracom->setMinimumWidth(260);
    
    gothracom->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 15pt Times New Roman}");
    m_submit =new QPushButton(tr("SUBMIT"));
    m_submitaddmore =new QPushButton(tr("-SUBMIT-"));
    
    m_clear =new QPushButton(tr("CLEAR"));
    m_next =new QPushButton(tr("NEXT"));
    m_print =new QPushButton(tr("PRINT"));
    m_addmore=new QPushButton(tr("ADD MORE"));
    m_alldata=new QPushButton(tr("ALL DATA"));
    m_delete=new QPushButton(tr("DELETE"));
    m_lasttransaction=new QPushButton(tr("LAST TRANSACTION"));
    
    hbox1 =new QHBoxLayout;
    hbox2 =new QHBoxLayout;
    hbox3 =new QHBoxLayout;
    hbox4 =new QHBoxLayout;
    hbox5 =new QHBoxLayout;
    hbox6 =new QHBoxLayout;
    hbox7 =new QHBoxLayout;
    hbox8 =new QHBoxLayout;
    hbox9 =new QHBoxLayout;
    hbox10 =new QHBoxLayout;
    hbox11 =new QHBoxLayout;
    hbox12 =new QHBoxLayout;
    hbox13 =new QHBoxLayout;
    hbox14 =new QHBoxLayout;
    hbox15 =new QHBoxLayout;
    hbox16 =new QHBoxLayout;
    
    vbox1 =new QVBoxLayout;
    vbox2 =new QVBoxLayout;
    vbox3 =new QVBoxLayout;
    vbox4 =new QVBoxLayout;
    vbox5 =new QVBoxLayout;


    
    hbox1->addWidget(receiptnolabel,0,Qt::AlignLeft);
    hbox1->addWidget(r_no,0,Qt::AlignLeft);
    hbox1->addWidget(r_datelabel,0,Qt::AlignLeft);
    hbox1->addWidget(r_dateedit,0,Qt::AlignLeft);
    hbox1->addWidget(r_date,0,Qt::AlignLeft);
    hbox2->addWidget(typelabel,0,Qt::AlignLeft);
    hbox2->addWidget(type_user,0,Qt::AlignLeft);
    hbox3->addWidget(mobilelabel,0,Qt::AlignLeft);
    hbox3->addWidget(mobileedit,0,Qt::AlignLeft);
    hbox4->addWidget(namelabel,0,Qt::AlignLeft);
    hbox4->addWidget(nameedit,0,Qt::AlignLeft);
    hbox5->addWidget(naksathralabel,0,Qt::AlignLeft);
    hbox5->addWidget(nakshatracom,0,Qt::AlignLeft);
    hbox6->addWidget(gothralabel,0,Qt::AlignLeft);
    hbox6->addWidget(gothracom,0,Qt::AlignLeft);
    hbox7->addWidget(sevachargeslabel,0,Qt::AlignLeft);
    hbox7->addWidget(seva_charge_label,0,Qt::AlignLeft);
    hbox7->addWidget(sevachargesedit,0,Qt::AlignLeft);
    hbox7->addWidget(additionalchargelabel,0,Qt::AlignLeft);
    hbox7->addWidget(additionalchargeedit,0,Qt::AlignLeft);

    hbox8->addWidget(cash_box,0,Qt::AlignLeft);
    hbox8->addWidget(cash_line,0,Qt::AlignLeft);
    hbox8->addWidget(cheque_box,0,Qt::AlignRight);
    hbox8->addWidget(cheque_line,0,Qt::AlignRight);

    hbox9->addWidget(countlabel,0,Qt::AlignLeft);
    hbox9->addWidget(countedit,0,Qt::AlignLeft);
    hbox9->addWidget(countlabel,0,Qt::AlignLeft);
    hbox9->addWidget(bank_combo,0,Qt::AlignLeft);

    hbox11->addWidget(s_datelabel,0,Qt::AlignLeft);
    hbox11->addWidget(s_dateedit,0,Qt::AlignLeft);
    hbox11->addWidget(s_date,0,Qt::AlignLeft);
    hbox12->addWidget(m_time,0,Qt::AlignLeft);
    hbox12->addWidget(m_timeEdit,0,Qt::AlignLeft);
    hbox13->addWidget(notelabel,0,Qt::AlignLeft);
    hbox13->addWidget(noteedit,0,Qt::AlignLeft);
    vbox1->setSpacing(20);
    vbox1->addLayout(hbox1);
    vbox1->addLayout(hbox2);
    vbox1->addLayout(hbox3);
    vbox1->addLayout(hbox4);
    vbox1->addLayout(hbox5);
    vbox1->addLayout(hbox6);
    vbox1->addLayout(hbox7);
    vbox1->addLayout(hbox8);
    vbox1->addLayout(hbox9);
    vbox1->addLayout(hbox10);
    vbox1->addLayout(hbox11);
    vbox1->addLayout(hbox12);
    vbox1->addLayout(hbox13);
    m_submitaddmore->setVisible(false);
    //for summary
    box1->setMaximumSize(600,830);
    box1->setLayout(vbox1);
    hbox14->addWidget(m_clear);
    hbox14->addWidget(m_next);
    hbox14->addWidget(m_addmore);
    hbox14->addWidget(m_submit);
    hbox14->addWidget(m_submitaddmore);
    
    hbox14->addWidget(m_print);
    hbox14->addWidget(m_alldata);
    hbox14->addWidget(m_lasttransaction);
    vbox2->addLayout(hbox14);
    box3->setMaximumSize(1800,310);
    box3->setLayout(vbox2);
    hbox15->addWidget(box1);
    hbox15->addWidget(print_res);
    hbox16->addWidget(box3);
    vbox4->addLayout(hbox15);
    vbox4->addLayout(hbox16);
    box1->setVisible(true);
    box3->setVisible(true);
    m_next->setEnabled(false);
    this->setLayout(vbox4);
    QRegExp re1("[5-9][0-9]{9}");
    mobileedit->setValidator(new QRegExpValidator(re1));
    QRegExp re2("^[a-zA-Z ,]+$");
    nameedit->setValidator(new QRegExpValidator(re2));
    QRegExp re4("[0-9]{10}");
    sevachargesedit->setValidator(new QRegExpValidator(re4));
    QRegExp re5("[0-9]{10}");
    additionalchargeedit->setValidator(new QRegExpValidator(re5));
    QRegExp re6("[0-9]{10}");
    m_print->setEnabled(false);
    countedit->setValidator(new QRegExpValidator(re4));

    pd = new QList<Print_Detail>;

    cash_line->setText("0");
    cheque_line->setText("0");
    cash_line->setEnabled(false);
    cheque_line->setEnabled(false);

    connect(s_date,SIGNAL(mylabelclicked()),this,SLOT(calendarSeva_popup()));
    connect(calendarSeva,SIGNAL(clicked(QDate)),this,SLOT(calendarSeva_hide(QDate)));
    connect(r_date,SIGNAL(mylabelclicked()),this,SLOT(calendarreceipt_popup()));
    connect(calendarreceipt,SIGNAL(clicked(QDate)),this,SLOT(calendarreceipt_hide()));
    connect(m_submit,SIGNAL(clicked()),this,SLOT(chek_persondetails_db_submit()));
    connect(m_submitaddmore,SIGNAL(clicked()),this,SLOT(addmoresubmitted()));
    connect(mobileedit,SIGNAL(textChanged(QString)),this,SLOT(search(QString)));
    connect(m_clear,SIGNAL(clicked()),this,SLOT(home()));
    connect(m_next,SIGNAL(clicked()),this,SLOT(nextoption()));
    connect(m_addmore,SIGNAL(clicked()),this,SLOT(addmore()));
    connect(m_alldata,SIGNAL(clicked()),this,SLOT(alldata()));
    connect(m_print,SIGNAL(clicked()),this,SLOT(print_receipt()));
    connect(m_lasttransaction,SIGNAL(clicked()),this,SLOT(lasttransaction()));
    connect(cheque_box,SIGNAL(clicked()),this,SLOT(change_state_box()));
    connect(cash_box,SIGNAL(clicked()),this, SLOT(change_state_box()));
    connect(bank_combo, SIGNAL(currentTextChanged(const QString)),this, SLOT(combo_state_changed()));
}

seva_booking_receipt::~seva_booking_receipt()
{
    
}

void seva_booking_receipt::calendarSeva_popup()
{
    calendarSeva->setVisible(true);
    calendarSeva->setGeometry(600,500,500,400);
    calendarSeva->show();
}

void seva_booking_receipt::calendarSeva_hide(QDate)
{
    s_dateedit->setText(calendarSeva->selectedDate().toString("dd-MM-yyyy"));
    calendarSeva->hide();
}

void seva_booking_receipt::calendarreceipt_popup()
{
    calendarreceipt->setVisible(true);
    calendarreceipt->setGeometry(600,500,500,400);
    calendarreceipt->show();
}

void seva_booking_receipt::calendarreceipt_hide()
{
    
    r_dateedit->setText(calendarreceipt->selectedDate().toString("dd-MM-yyyy"));
    calendarreceipt->hide();
}


void seva_booking_receipt::gettingdevotes_seva_details(QString data)
{
    type_user->setText(data);
    this->show();
    seva_name =data;
    dbfile::getInstance()->Checking_sevacharge(data);
}
void seva_booking_receipt::fixed_sevacharge(int sevaCharges)
{
    sevachargesedit->setText("0");
    additionalchargeedit->setText("0");
    seva_charge_label->setVisible(true);
    sevachargesedit->setVisible(false);
    seva_charge_label->setNum(sevaCharges);
    additionalchargeedit->setVisible(true);
    additionalchargelabel->show();
}

void seva_booking_receipt::variable_sevacharge()
{
    additionalchargeedit->setText("0");
    additionalchargeedit->setVisible(false);
    seva_charge_label->setVisible(false);
    sevachargesedit->setVisible(true);
    additionalchargelabel->hide();
}

void seva_booking_receipt::set_fixed_sevacharges(QString seav_charges)
{
    devoteSevacharge=seav_charges;
}

void seva_booking_receipt::set_variable_sevacharges()
{
    devoteSevacharge= sevachargesedit->text();
    
}

void seva_booking_receipt::set_receipt_num(int receipt_num)
{
    rspt_no=receipt_num;
    rspt_no=rspt_no+1;
    r_no->setNum(rspt_no);
}

void seva_booking_receipt::change_state_box()
{
    QStringList bankslist;
    //bankslist =
    dbfile::getInstance()->bank_list();

    if(cheque_box->isChecked() == true){
        cheque_line->setEnabled(true);
        bank_combo->setVisible(true);
        bank_combo->setEnabled(true);
    }
    else{
        cheque_line->setText("0");
        cheque_line->setEnabled(false);
        bank_combo->setEnabled(false);
    }

    if(cash_box->isChecked() == true)
        cash_line->setEnabled(true);
    else{
        cash_line->setText("0");
        cash_line->setEnabled(false);
    }

}

void seva_booking_receipt::combo_state_changed()
{
    qDebug()<<"\nBank selected is: "<<bank_combo->currentText()<<endl;
}

QString seva_booking_receipt::NumberToWord(const unsigned int number)
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

bool seva_booking_receipt::chek_persondetails_db_addmore()
{

    QString devoteMobile = mobileedit->text();
    seva_struct.MOB_NO = devoteMobile;

    QString devoteName =nameedit->text();
    seva_struct.NAME = devoteName;

    QString devoteNakshatra =nakshatracom->currentText();
    seva_struct.NAKSHATRA = devoteNakshatra;

    QString devoteGotra = gothracom->currentText();
    seva_struct.GOTHRA = devoteGotra;

    QString devoteAdditionalcharges =additionalchargeedit->text();

    QString devoteCount = countedit->text();
    seva_struct.QTY = devoteCount;

    QString priviusformatdatdevotiresitdate =r_dateedit->text();
    QDate Datedevotereceiptdate = QDate::fromString(priviusformatdatdevotiresitdate,"dd-MM-yyyy");
    QString devotereceiptdate = Datedevotereceiptdate.toString("dd-MM-yyyy");
    seva_struct.DATE = devotereceiptdate;

    QString priviusformatdatesevadate = s_dateedit->text();
    QDate DatedevoteSevadate = QDate::fromString(priviusformatdatesevadate,"dd-MM-yyyy");
    QString devoteSevadate = DatedevoteSevadate.toString("dd-MM-yyyy");
    seva_struct.SEVA_DATE = devoteSevadate;

    QString devoteNote = noteedit->text();
    seva_struct.NOTE = devoteNote;

    QMessageBox msgbox;
    QString  devoteSevaName = type_user->text();
    seva_struct.SEVA_DESCR = devoteSevaName;

    QString mobileP = mobileedit->text();
    QString devoteTime = m_timeEdit->text();
    seva_struct.SEVA_TIME = devoteTime;

    seva_struct.RECPT_NO = QString::number(rspt_no);

    int count= devoteCount.toInt();
    int addistionalcost = devoteAdditionalcharges.toInt();
    int cost;
    dbfile::getInstance()->Checking_sevacharge(seva_name);
    QRegularExpression r1("[5-9][0-9]{9}");
    QRegularExpressionMatch m1=r1.match(mobileP);
    //change_state_box();
    QString Bank_name = bank_combo->currentText();
    
    if((nameedit->text()!=nullptr)&&(nakshatracom->currentText()!=nullptr)&&(gothracom->currentText()!=nullptr)&&(sevachargesedit->text()!= nullptr)&&(additionalchargeedit->text()!= nullptr)&&(countedit->text()!=nullptr)&&(r_dateedit->text()!= nullptr)&&(s_dateedit->text()!= nullptr)&&(noteedit->text()!=nullptr)&&(type_user->text()!= nullptr))
    {
        if(m1.hasMatch())
        {
            seva_struct.RATE = devoteSevacharge;
            int sevacharge =devoteSevacharge.toInt();

            cost = (sevacharge*count)+addistionalcost;
            seva_struct.AMT = QString::number(cost);

            total=total+cost;
            totalcost = QString::number(total);
            //qDebug() << Q_FUNC_INFO <<total<<"$$$$$$$$$$$$$$$$$$$$$$"<<devoteSevaName<<"$$$$$$$$$$$$$$$$$$$$$$";

            QString word= NumberToWord(total);

            seva_struct.TOTAL_AMT = totalcost;
            seva_struct.TOTAL_IN_WORDS = word;

            seva_struct.CASH = cash_line->text();
            seva_struct.BANK_REF = cheque_line->text();

            qDebug()<<"\nBank Line contents: "<<seva_struct.CASH<<endl;
            qDebug()<<"\nCash Line contents: "<<seva_struct.BANK_REF<<endl;

            pd->append(seva_struct);

            RS_listPrint->list_seva->append(devoteSevaName);
            RS_listPrint->list_tickets->append(devoteCount);
            RS_listPrint->list_cost->append(sevacharge);
            RS_listPrint->list_sevadate->append(priviusformatdatesevadate);
            dbfile::getInstance()->topersondetailsdb(devoteMobile,devoteName,devoteNakshatra,devoteGotra,devoteSevacharge,devoteAdditionalcharges,devoteCount,devotereceiptdate,devoteSevadate,devoteNote);
            dbfile::getInstance()->sevabookingdb(devoteMobile,devoteName,devoteNakshatra,devoteGotra,devoteSevacharge,devoteAdditionalcharges,devoteCount,devotereceiptdate,devoteSevadate,devoteNote,devoteSevaName,cost,rspt_no,seva_struct.CASH,seva_struct.BANK_REF, Bank_name);
            print_res->display(devoteName,devoteSevacharge,devoteAdditionalcharges,devoteCount,devotereceiptdate,devoteSevadate,devoteSevaName,cost,total,devoteMobile,devoteNakshatra,devoteGotra,rspt_no,devoteNote,devoteTime);
            countedit->clear();
            m_timeEdit->clear();
            cheque_line->setText("0");
            cash_line->setText("0");
        }
        else
        {
            qWarning() << Q_FUNC_INFO << " Seva Type not found... Serious" <<endl;
            msgbox.setText(tr("Plz enter the all field "));
            msgbox.exec();
            return 1;
        }
    }
    else
    {
        qWarning() << Q_FUNC_INFO << " Seva Type not found... Serious" <<endl;
        msgbox.setText(tr("Please enter all the fields"));
        msgbox.exec();
        return 1;
    }
    return  true;
}
bool seva_booking_receipt::chek_persondetails_db_submit()
{
    //counting=0;
    m_addmore->setEnabled(false);
    m_submit->setEnabled(false);
    m_clear->setEnabled(true);
    m_print->setEnabled(true);
    
    QString devoteMobile = mobileedit->text();
    seva_struct.MOB_NO = devoteMobile;

    QString   devoteName =nameedit->text();
    seva_struct.NAME = devoteName;

    QString  devoteNakshatra =nakshatracom->currentText();
    seva_struct.NAKSHATRA = devoteNakshatra;

    QString  devoteGotra = gothracom->currentText();
    seva_struct.GOTHRA = devoteGotra;

    QString   devoteAdditionalcharges =additionalchargeedit->text();

    QString  devoteCount = countedit->text();
    seva_struct.QTY = devoteCount;

    QString priviusformatdatdevotiresitdate =r_dateedit->text();
    QDate Datedevotereceiptdate = QDate::fromString(priviusformatdatdevotiresitdate,"dd-MM-yyyy");
    QString devotereceiptdate = Datedevotereceiptdate.toString("dd-MM-yyyy");
    seva_struct.DATE = devotereceiptdate;

    QString priviusformatdatesevadate = s_dateedit->text();
    QDate DatedevoteSevadate = QDate::fromString(priviusformatdatesevadate,"dd-MM-yyyy");
    QString devoteSevadate = DatedevoteSevadate.toString("dd-MM-yyyy");
    seva_struct.SEVA_DATE = devoteSevadate;

    QString devoteNote = noteedit->text();
    seva_struct.NOTE = devoteNote;

    QMessageBox msgbox;
    QString  devoteSevaName = type_user->text();
    seva_struct.SEVA_DESCR = devoteSevaName;

    QString mobileP = mobileedit->text();
    QString devoteTime  = m_timeEdit->text();
    seva_struct.SEVA_TIME = devoteTime;

    seva_struct.RECPT_NO = QString::number(rspt_no);

    int count= devoteCount.toInt();
    int addistionalcost = devoteAdditionalcharges.toInt();
    int cost;
    dbfile::getInstance()->Checking_sevacharge(seva_name);
    QRegularExpression r1("[5-9][0-9]{9}");
    QRegularExpressionMatch m1=r1.match(mobileP);
    QString Bank_name = bank_combo->currentText();
    //change_state_box();
    
    if((mobileedit->text()!=nullptr)&&(nameedit->text()!=nullptr)&&(nakshatracom->currentText()!=nullptr)&&(gothracom->currentText()!=nullptr)&&(sevachargesedit->text()!= nullptr)&&(additionalchargeedit->text()!= nullptr)&&(countedit->text()!=nullptr)&&(r_dateedit->text()!= nullptr)&&(s_dateedit->text()!= nullptr)&&(noteedit->text()!=nullptr)&&(type_user->text()!= nullptr))
    {
        if(m1.hasMatch())
        {
            seva_struct.RATE = devoteSevacharge;
            int sevacharge =devoteSevacharge.toInt();

            cost = (sevacharge*count)+addistionalcost;
            seva_struct.AMT = QString::number(cost);

            total=total+cost;
            totalcost = QString::number(total);

            QString word= NumberToWord(total);
            seva_struct.TOTAL_AMT = totalcost;
            seva_struct.TOTAL_IN_WORDS = word;

            seva_struct.CASH = cash_line->text();
            seva_struct.BANK_REF = cheque_line->text();

            qDebug()<<"\nCash Line contents: "<<seva_struct.CASH<<endl;
            qDebug()<<"\nBank Line contents: "<<seva_struct.BANK_REF<<endl;

            pd->append(seva_struct);

            RS_single_print->singleentry(devoteSevaName,devoteCount,sevacharge,priviusformatdatesevadate);
            //            qDebug()<<"!!!!!!!!!!!!!!!!!____________________!!!!!!!!!!!!!!!!!!!!!!___________________!!!!!!!!!!comming!!!!!!!!!!!_____________________!!!!!!!!!!!!!!!!!!!!______________________!!!!!!!!!!!!!!!!!"<<endl;
            dbfile::getInstance()->topersondetailsdb(devoteMobile,devoteName,devoteNakshatra,devoteGotra,devoteSevacharge,devoteAdditionalcharges,devoteCount,devotereceiptdate,devoteSevadate,devoteNote);
            dbfile::getInstance()->sevabookingdb(devoteMobile,devoteName,devoteNakshatra,devoteGotra,devoteSevacharge,devoteAdditionalcharges,devoteCount,devotereceiptdate,devoteSevadate,devoteNote,devoteSevaName,cost,rspt_no,seva_struct.CASH,seva_struct.BANK_REF, Bank_name);
            print_res->display(devoteName,devoteSevacharge,devoteAdditionalcharges,devoteCount,devotereceiptdate,devoteSevadate,devoteSevaName,cost,total,devoteMobile,devoteNakshatra,devoteGotra,rspt_no,devoteNote,devoteTime);
            countedit->clear();
            cheque_line->setText("0");
            cash_line->setText("0");
            m_next->setEnabled(true);
            
        }
        else
        {
            qWarning() << Q_FUNC_INFO << " Seva Type not found... Serious" <<endl;
            msgbox.setText(tr("Plz enter the all field "));
            m_submit->setEnabled(true);

            msgbox.exec();
            return 1;
        }
    }
    else
    {
        qWarning() << Q_FUNC_INFO << " Seva Type not found... Serious" <<endl;
        msgbox.setText(tr("Plz enter the all field "));
        m_submit->setEnabled(true);
        msgbox.exec();
        return 1;
    }
    return  true;
}

void seva_booking_receipt::search(QString mobile_no)
{
    dbfile::getInstance()->mobileNumberSearching(mobile_no);
}

void seva_booking_receipt::home()
{
    type_user->clear();
    nameedit->clear();
    mobileedit->clear();
    sevachargesedit->clear();
    additionalchargeedit->setText("0");
    countedit->setText("1");
    noteedit->clear();
    //    gothracom->clear();
    gothracom->setEnabled(true);
    mobileedit->setEnabled(true);
}

void seva_booking_receipt::addmore()
{
    this->chek_persondetails_db_addmore();
    counting++;
    type_user->clear();
    sevachargesedit->clear();
    countedit->setText("1");
    m_submit->setVisible(false);
    cheque_line->setText("0");
    cash_line->setText("0");
    m_submitaddmore->setVisible(true);

}
void seva_booking_receipt::alldata()
{
    this->show();
    dbfile::getInstance()->dbtable_view();
}

void seva_booking_receipt::printintdata()
{
    QPushButton *button1,*button2;
    QHBoxLayout *p_hbox1,*p_hbox2;
    QVBoxLayout *p_vbox1;
    n_date = new mylabel(this);
    p_image = new QPixmap(print_res->grab());
    n_date->setPixmap(p_image->scaled(800,800));
    n_date->setVisible(true);
    p_box =new QGroupBox;
    p_hbox1 =new QHBoxLayout;
    p_hbox2 =new QHBoxLayout;
    p_vbox1 =new QVBoxLayout;
    button1 =new QPushButton(tr("Print"));
    button2 =new QPushButton(tr("Close"));
    
    p_hbox1->addWidget(n_date);
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

void seva_booking_receipt::closeoption()
{
    p_box->close();
}

void seva_booking_receipt::printoption()
{
    p_box->close();
}


void seva_booking_receipt::lasttransaction()
{
    //    last_tran->datashow();
    dbfile::getInstance()->table_view_forlast_ten_tran();
    //    datamanager::getInstance()->lastTenTran();
    
}

void seva_booking_receipt::nextoption()
{
    total=0;
    m_next->setEnabled(false);
    m_addmore->setEnabled(true);
    m_submit->setEnabled(true);
    m_clear->setEnabled(true);
    m_print->setEnabled(false);
    
    type_user->clear();
    nameedit->clear();
    mobileedit->clear();
    sevachargesedit->clear();
    additionalchargeedit->clear();
    countedit->clear();
    noteedit->clear();
    //    gothracom->clear();
    gothracom->setEnabled(true);
    mobileedit->setEnabled(true);
    rspt_no=rspt_no+1;
    r_no->setNum(rspt_no);
    m_submit->setVisible(true);
    m_submitaddmore->setVisible(false);
    print_res->clear();
    RS_listPrint->list_seva->clear();
    RS_listPrint->list_tickets->clear();
    RS_listPrint->list_cost->clear();
    RS_listPrint->list_sevadate->clear();
    counting=1;

    pd->clear();
    
}


void seva_booking_receipt::addmoresubmitted()
{
    QMessageBox msgbox;
    m_print->setEnabled(true);
    
    qWarning() << Q_FUNC_INFO << "SEVA BOOKING SUCCESS" <<endl;
    msgbox.setText(tr("SEVA BOOKING COMPLETED"));
    msgbox.exec();
    chek_persondetails_db_submit();
    m_submit->setEnabled(false);
    m_submitaddmore->setVisible(false);
    m_next->setEnabled(true);
}

void seva_booking_receipt::print_receipt()
{
    RS_listPrint->printing_file(pd);

    //RS_listPrint->printing_file(seva_name,namePrint,gothramPrint,nakshatramPrint,costPrint,seva_datePrint,mobilePrint, timePrint, counting, totalcost, QString::number(rspt_no));
    //RS_listPrint->svg_receipt(namePrint, gothramPrint,nakshatramPrint, costPrint,seva_datePrint,counting,countPrint,totalcost,mobilePrint);
}

void seva_booking_receipt::addGotraList(QList<QString> Gotra)
{
    
    QStringList list;
    int size=Gotra.size();
    list.clear();
    for(int i=0;i<size;i++)
    {
        list.append(Gotra.at(i));
        QStringListModel *model = new QStringListModel;
        model->setStringList(list);
        gothracom->setModel(model);
    }
}

void seva_booking_receipt::addBankList(QList<QString> Banks)
{

    QStringList list;
    int size=Banks.size();
    list.clear();
    for(int i=0;i<size;i++)
    {
        list.append(Banks.at(i));
        QStringListModel *model = new QStringListModel;
        model->setStringList(list);
        bank_combo->setModel(model);
    }
}

void seva_booking_receipt::mobile_num_there(QString d_Mobile,QString d_Name,QString d_Nakshatra,QString d_Gotra)
{
    mobileedit->setText(d_Mobile);
    nameedit->setText(d_Name);
    nakshatracom->setCurrentText(d_Nakshatra);
    gothracom->setCurrentText(d_Gotra);
//    nakshatracom->setEnabled(false);
//    mobileedit->setEnabled(false);
//    nameedit->setEnabled(false);
//    gothracom->setEnabled(false);
    
}

void seva_booking_receipt::mobile_num_notthere()
{
    nameedit->setText("");
    mobileedit->setEnabled(true);
    nameedit->setEnabled(true);
    nakshatracom->setEnabled(true);
}
