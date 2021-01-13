#include "fullsevatransactiondetails.h"

fullSevaTransactionDetails::fullSevaTransactionDetails(QWidget *parent) : QWidget(parent)
{
    w1= new QWidget;
    w2= new QWidget;
    m_view=new QTableView;
    m_hbox=new QHBoxLayout;
    m_model =new QStandardItemModel;
    m_view->setVisible(true);
    m_hbox->addWidget(m_view);
    m_model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("PERSONID"))<<(tr("SEVA TYPE"))<<(tr("SEVANAME"))<<(tr("QUANTITY"))<<(tr("S_DATE"))<<(tr("S_MONTH"))<<(tr("S_YEAR"))<<(tr("SEVA_DATE"))<<(tr("R_DATE"))<<(tr("R_MONTH"))<<(tr("R_YEAR"))<<(tr("RECEIPT_DATE"))<<(tr("SEVACOST"))<<(tr("ADDITIONALCOST"))<<(tr("SEVATOTALPRICE"))<<(tr("NOTE")));
    m_view->setModel(m_model);
    w2->setLayout(m_hbox);
    m_sevachargeslabel=new QLabel(tr(" Seva Charges"));
    calendarSeva =new QCalendarWidget;
    calendarSeva->setGeometry(600,500,500,400);
    calendarreceipt =new QCalendarWidget;
    calendarreceipt->setGeometry(600,500,500,400);
    seva_charge_label =new QLabel(tr("!!!!!!!!!!!!!!!!!!!"));
    r_no=new QLabel(tr(""));
    r_no->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_mobilelabel=new QLabel(tr("Mobile Number"));
    m_mobilelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_namelabel=new QLabel(tr("Name"));
    m_namelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_sevachargeslabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_additionalchargelabel=new QLabel(tr("Additional Charges"));
    m_additionalchargelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 18pt Times New Roman}");
    m_countlabel=new QLabel(tr("Count"));
    m_countlabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_naksathralabel=new QLabel(tr("Nakshatra"));
    m_naksathralabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_gothralabel=new QLabel(tr("Ghotra"));
    m_gothralabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    r_datelabel=new QLabel(tr("Reciept Date"));
    r_datelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    s_datelabel=new QLabel(tr("Seva Date"));
    s_datelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_mobileedit=new QLineEdit;   
    m_nameedit=new QLineEdit;   
    m_sevachargesedit=new QLineEdit;    
    box1 =new QGroupBox;
    box2 =new QGroupBox;
    box1->setTitle(tr("SEVA "));
    m_countedit=new QLineEdit;
    s_date = new mylabel(this);
    r_date =new mylabel(this);
    image = new QPixmap("://calen.png");
    image1 = new QPixmap("://calen.png");
    s_date->setPixmap(*image);
    s_date->setVisible(true);
    r_date->setPixmap(*image1);
    r_date->setVisible(true);
    r_dateedit=new QLineEdit;
    r_dateedit->setText(calendarreceipt->selectedDate().toString("dd-MM-yyyy"));
    m_type_user=new QLabel(tr(""));
    m_type_user->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    s_dateedit=new QLineEdit;
    s_dateedit->setText(calendarSeva->selectedDate().toString("dd-MM-yyyy"));
    noteedit=new QLineEdit;
    m_typelabel=new QLabel(tr("Seva Name"));
    m_typelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    m_additionalchargeedit =new QLineEdit;
    m_delete=new QPushButton(tr("DELETE"));
    m_modify=new QPushButton(tr("MODIFY"));
    m_back=new QPushButton(tr("BACK"));
    
    m_nakshatracom =new QComboBox;
    list_nakshatra<<(tr("Ashwini"))<<(tr("Bharani"))<<(tr("Krittika"))<<(tr("Rohini"))<<(tr("Mrigshirsha"))<<(tr("Ardra"))<<(tr("Punarvasu"))<<(tr("Pushya"))<<(tr("Ashlesha"))<<(tr("Magha"))<<(tr("Purvaphalguni"))<<(tr("Uttaraphalguni"))<<(tr("Hasta"))<<(tr("Chitra"))<<(tr("Swati"))<<(tr("Vishakha"))<<(tr("Anuradha"))<<(tr("Jyeshtha"))<<(tr("Moola"))<<(tr("Purvashadha"))<<(tr("Uttarashadha"))<<(tr("Shravana"))<<(tr("Dhanishtha"))<<(tr("Shatbhisha"))<<(tr("Poorvabhadrapada"))<<(tr("Uttarabhadrapada"))<<(tr("Revati"))<<(tr("No"));
    m_nakshatracom->setMaximumHeight(30);
    m_nakshatracom->addItems(list_nakshatra);
    m_gothracom =new QComboBox;
    m_gothracom->setEditable(true);
    m_gothracom->setMaximumHeight(30);
    m_gothracom->addItem("NO");
    notelabel=new QLabel(tr("Note"));
    notelabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
    receiptnolabel=new QLabel(tr("receipt Num"));
    receiptnolabel->setStyleSheet("QLabel {color : '#0066ff' ;font: 20pt Times New Roman}");
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
    vbox1 =new QVBoxLayout;
    vbox2 =new QVBoxLayout;
    vbox3 =new QVBoxLayout;
    hbox1->addWidget(receiptnolabel);
    hbox1->addWidget(r_no,0,Qt::AlignRight);
    hbox2->addWidget(m_typelabel);
    hbox2->addWidget(m_type_user,0,Qt::AlignRight);
    hbox3->addWidget(m_mobilelabel);
    hbox3->addWidget(m_mobileedit);
    hbox4->addWidget(m_namelabel);
    hbox4->addWidget(m_nameedit);
    hbox5->addWidget(m_naksathralabel);
    hbox5->addWidget(m_nakshatracom);
    hbox6->addWidget(m_gothralabel);
    hbox6->addWidget(m_gothracom);
    hbox7->addWidget(m_sevachargeslabel);
    hbox7->addWidget(m_sevachargesedit);
    hbox7->addWidget(seva_charge_label,0,Qt::AlignLeft);
    hbox8->addWidget(m_additionalchargelabel);
    hbox8->addWidget(m_additionalchargeedit);
    hbox9->addWidget(m_countlabel);
    hbox9->addWidget(m_countedit);
    hbox10->addWidget(r_datelabel);
    hbox10->addWidget(r_dateedit,0,Qt::AlignRight);
    hbox10->addWidget(r_date);
    hbox11->addWidget(s_datelabel);
    hbox11->addWidget(s_dateedit,0,Qt::AlignRight);
    hbox11->addWidget(s_date);
    hbox12->addWidget(notelabel);
    hbox12->addWidget(noteedit);
    vbox1->setSpacing(40);
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
    hbox13->addWidget(m_delete);
    hbox13->addWidget(m_modify);
    hbox13->addWidget(m_back);
    vbox1->addLayout(hbox13);

    box1->setLayout(vbox1);
    box1->setMinimumWidth(600);
//    box2->setMinimumWidth(600);

//    box2->setLayout(hbox13);
    vbox3->addWidget(box1,0,Qt::AlignCenter);
//    vbox3->addWidget(box2,0,Qt::AlignCenter);
    w1->setLayout(vbox3);
    this->setEnabled(true);
    connect(m_delete,SIGNAL(clicked()),this,SLOT(deletedata()));
    connect(m_back,SIGNAL(clicked()),this,SLOT(backtoscreen()));
    connect(m_modify,SIGNAL(clicked()),this,SLOT(modifydata()));
}

fullSevaTransactionDetails::~fullSevaTransactionDetails()
{
    
}
void fullSevaTransactionDetails::table_view(QList<QString> l_sno,QList<QString> l_person_id,QList<QString> l_sevatype,QList<QString> l_sevaname,QList<QString> l_quantity,QList<QString> l_s_date,QList<QString> l_s_month,QList<QString> l_s_year,QList<QString> l_sevadate,QList<QString> l_r_date,QList<QString> l_r_month,QList<QString> l_r_year,QList<QString> l_receiptdate,QList<QString> l_seva_cost,QList<QString> l_add_cost,QList<QString> l_total_cost,QList<QString> l_note)
{
    this->setLayout(m_hbox);
    m_model->clear();
    m_model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("PERSONID"))<<(tr("SEVA TYPE"))<<(tr("SEVANAME"))<<(tr("QUANTITY"))<<(tr("S_DATE"))<<(tr("S_MONTH"))<<(tr("S_YEAR"))<<(tr("SEVA_DATE"))<<(tr("R_DATE"))<<(tr("R_MONTH"))<<(tr("R_YEAR"))<<(tr("RECEIPT_DATE"))<<(tr("SEVACOST"))<<(tr("ADDITIONALCOST"))<<(tr("SEVATOTALPRICE"))<<(tr("NOTE")));
    int row,column;
    int size_list= l_sevaname.size();
    for (row = 0; row < size_list; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            if(column == 0)
            {
                QString value1 = QString("%1").arg(l_sno.at(row));
                QStandardItem *item1 = new QStandardItem(value1);
                m_model->setItem(row,column,item1);
            }
            if(column == 1)
            {
                QString value2 = QString("%1").arg(l_person_id.at(row));
                QStandardItem *item2 = new QStandardItem(value2);
                m_model->setItem(row,column,item2);
            }
            if(column == 2)
            {
                QString value3 = QString("%1").arg(l_sevatype.at(row));
                QStandardItem *item3 = new QStandardItem(value3);
                m_model->setItem(row,column,item3);
            }
            if(column == 3)
            {
                QString value4 = QString("%1").arg(l_sevaname.at(row));
                QStandardItem *item4 = new QStandardItem(value4);
                m_model->setItem(row,column,item4);
            }
            if(column == 4)
            {
                QString value5 = QString("%1").arg(l_quantity.at(row));
                QStandardItem *item5 = new QStandardItem(value5);
                m_model->setItem(row,column,item5);
            }
            if(column == 5)
            {
                QString value6 = QString("%1").arg(l_s_date.at(row));
                QStandardItem *item6 = new QStandardItem(value6);
                m_model->setItem(row,column,item6);
            }
            if(column == 6)
            {
                QString value7 = QString("%1").arg(l_s_month.at(row));
                QStandardItem *item7 = new QStandardItem(value7);
                m_model->setItem(row,column,item7);
            }
            if(column == 7)
            {
                QString value8 = QString("%1").arg(l_s_year.at(row));
                QStandardItem *item8 = new QStandardItem(value8);
                m_model->setItem(row,column,item8);
            }
            if(column == 8)
            {
                QString value9 = QString("%1").arg(l_sevadate.at(row));
                QStandardItem *item9 = new QStandardItem(value9);
                m_model->setItem(row,column,item9);
            }
            if(column == 9)
            {
                QString value10 = QString("%1").arg(l_r_date.at(row));
                QStandardItem *item10 = new QStandardItem(value10);
                m_model->setItem(row,column,item10);
            }
            if(column == 10)
            {
                QString value11 = QString("%1").arg(l_r_month.at(row));
                QStandardItem *item11 = new QStandardItem(value11);
                m_model->setItem(row,column,item11);
            }
            if(column == 11)
            {
                QString value12 = QString("%1").arg(l_r_year.at(row));
                QStandardItem *item12 = new QStandardItem(value12);
                m_model->setItem(row,column,item12);
            }
            if(column == 12)
            {
                QString value13 = QString("%1").arg(l_receiptdate.at(row));
                QStandardItem *item13 = new QStandardItem(value13);
                m_model->setItem(row,column,item13);
            }
            if(column == 13)
            {
                QString value14 = QString("%1").arg(l_seva_cost.at(row));
                QStandardItem *item14 = new QStandardItem(value14);
                m_model->setItem(row,column,item14);
            }
            if(column == 14)
            {
                QString value15 = QString("%1").arg(l_add_cost.at(row));
                QStandardItem *item15 = new QStandardItem(value15);
                m_model->setItem(row,column,item15);
            }
            if(column == 15)
            {
                QString value16 = QString("%1").arg(l_total_cost.at(row));
                QStandardItem *item16 = new QStandardItem(value16);
                m_model->setItem(row,column,item16);
            }
            if(column == 16)
            {
                QString value17 = QString("%1").arg(l_note.at(row));
                QStandardItem *item17 = new QStandardItem(value17);
                m_model->setItem(row,column,item17);
            }
        }
    }
    this->showMaximized();
//    this->show();
    connect(m_view, SIGNAL(clicked(const QModelIndex &)),this, SLOT(onTableClicked(const QModelIndex &)));
}


bool fullSevaTransactionDetails::onTableClicked(const QModelIndex &index)
{
    row = index.row();
    QString sno = index.sibling(row, 0).data().toString();
    QString  person_id = index.sibling(row, 1).data().toString();
    QString sevatype= index.sibling(row, 2).data().toString();
    QString sevaname =index.sibling(row, 3).data().toString();
    QString quantity=index.sibling(row, 4).data().toString();
    QString s_date =index.sibling(row, 5).data().toString();
    QString  s_month = index.sibling(row, 6).data().toString();
    QString s_year= index.sibling(row, 7).data().toString();
    QString sevadate =index.sibling(row, 8).data().toString();
    QString r_date = index.sibling(row, 9).data().toString();
    QString  r_month = index.sibling(row, 10).data().toString();
    QString r_year = index.sibling(row, 11).data().toString();
    QString receiptdate =index.sibling(row, 12).data().toString();
    QString seva_cost =index.sibling(row, 13).data().toString();
    QString add_cost= index.sibling(row, 14).data().toString();
    QString total_cost=index.sibling(row, 15).data().toString();
    QString note=index.sibling(row, 16).data().toString();
    qDebug()<<"\n"<<sno<<"\n"<<person_id<<"\n"<<sevatype<<"\n"<<sevaname<<"\n"<<quantity<<"\n"<<s_date<<"\n"<<s_month<<"\n"<<s_year<<"\n"<<sevadate<<"\n"<<r_date<<"\n"<<r_month<<"\n"<<r_year<<"\n"<<receiptdate<<"\n"<<seva_cost<<"\n"<<add_cost<<"\n"<<total_cost<<"\n"<<note<<endl;
    m_type_user->setText(sevaname);
    r_no->setText(sno);
    QString devoteSevacharge;

    dbfile::getInstance()->getpersondetails(person_id);
    dbfile::getInstance()->getsevadetails(sevaname);
    if(m_sevacost==1)
    {
        m_sevachargesedit->setVisible(true);
        qDebug()<<"\n"<<m_sevacost<<"******************"<<endl;
        m_sevachargesedit->setText(seva_cost);
        seva_charge_label->setVisible(false);

    }
    else
    {
        qDebug()<<"\n"<<"seva_cost"<<seva_cost<<m_sevacost<<endl;
        m_sevachargesedit->setVisible(false);
        seva_charge_label->setVisible(true);
        seva_charge_label->setNum(m_sevacost);

    }
    m_mobileedit->setText(m_mobile);
    m_nameedit->setText(m_person_name);
    m_gothracom->setCurrentText(m_gotra);
    m_nakshatracom->setCurrentText(m_nakshatra);
    m_countedit->setText(quantity);
    r_dateedit->setText(receiptdate);
    s_dateedit->setText(sevadate);
    noteedit->setText(note);
    m_additionalchargeedit->setText(add_cost);
    m_mobileedit->setEnabled(false);
    m_nameedit->setEnabled(false);
    m_gothracom->setEnabled(false);
    m_nakshatracom->setEnabled(false);
    r_dateedit->setEnabled(false);
    s_dateedit->setEnabled(true);
    this->setEnabled(false);
    w1->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w1->showFullScreen();
//    w1->setGeometry(0,0,this->width(),this->height());
//    w1->show();
}
void fullSevaTransactionDetails::deletedata()
{
    QMessageBox msgbox;
    QFont font;
    font.setPointSize(font.pointSize() + 7);
    msgbox.setFont(font);
    QPalette palette;
    palette.setColor(QPalette::Background, (QColor("#ffc2b3")));
    msgbox.setPalette(palette);
    msgbox.setStandardButtons(QMessageBox::No| QMessageBox::Ok);
    msgbox.setText(tr("Are you sure,Do you want to Delete Data"));
    int ret = msgbox.exec();
    switch (ret) {
    case QMessageBox::No:
        // Save was clicked
        break;
    case QMessageBox::Ok:
        int s_no = r_no->text().toInt();
        dbfile::getInstance()->deletesevabookingentry(s_no);
        this->setEnabled(true);
        w1->close();
        break;
    }
}
//}
void fullSevaTransactionDetails::modifydata()
{
    QMessageBox msgbox;
    QFont font;
    font.setPointSize(font.pointSize() + 7);
    msgbox.setFont(font);
    QPalette palette;
    palette.setColor(QPalette::Background, (QColor("#ffc2b3")));
    msgbox.setPalette(palette);
    msgbox.setStandardButtons(QMessageBox::No| QMessageBox::Ok);
    msgbox.setText(tr("Are you sure,Do you want to Modify Data"));
    int ret = msgbox.exec();
    switch (ret) {
    case QMessageBox::No:
        // Save was clicked
        break;
    case QMessageBox::Ok:
        int s_no = r_no->text().toInt();
        int count = m_countedit->text().toInt();
        QString sevadate=s_dateedit->text();
        QDate Date1 = QDate::fromString(sevadate,"dd-MM-yyyy");
        QString seva_date =Date1.toString("dd-MM-yyyy");
        int s_date=Date1.day();
        int s_mont=Date1.month();
        int s_year=Date1.year();
        if(m_sevacost==1)
        {
            sevacharge=m_sevachargesedit->text().toInt();
        }
        else
        {
            sevacharge=seva_charge_label->text().toInt();
        }
        int addchr= m_additionalchargeedit->text().toInt();
        int total=((sevacharge*count)+addchr);
        QString note = noteedit->text();
        dbfile::getInstance()->getsevabookingmodifaing(s_no,count,s_date,s_mont,s_year,seva_date,sevacharge,addchr,total,note);
        qDebug()<<Q_FUNC_INFO<<s_no<<endl;
        qDebug()<<Q_FUNC_INFO<<sevacharge<<endl;
        qDebug()<<Q_FUNC_INFO<<addchr<<endl;
        qDebug()<<Q_FUNC_INFO<<total<<endl;
        qDebug()<<Q_FUNC_INFO<<note<<endl;
        QString value0 = QString("%1").arg(s_no);
        QStandardItem *item = new QStandardItem(value0);
        m_model->setItem(row, 0, item);
        QString value1 = QString("%1").arg(count);
        QStandardItem *item1 = new QStandardItem(value1);
        m_model->setItem(row, 4, item1);
        QString value2 = QString("%1").arg(s_date);
        QStandardItem *item2 = new QStandardItem(value2);
        m_model->setItem(row, 5, item2);
        QString value3 = QString("%1").arg(s_mont);
        QStandardItem *item3 = new QStandardItem(value3);
        m_model->setItem(row, 6, item3);
        QString value4 = QString("%1").arg(s_year);
        QStandardItem *item4 = new QStandardItem(value4);
        m_model->setItem(row, 7, item4);
        QString value5 = QString("%1").arg(sevadate);
        QStandardItem *item5 = new QStandardItem(value5);
        m_model->setItem(row, 8, item5);
        QString value6 = QString("%1").arg(sevacharge);
        QStandardItem *item6 = new QStandardItem(value6);
        m_model->setItem(row, 13, item6);
        QString value7 = QString("%1").arg(addchr);
        QStandardItem *item7 = new QStandardItem(value7);
        m_model->setItem(row, 14, item7);
        QString value8 = QString("%1").arg(total);
        QStandardItem *item8 = new QStandardItem(value8);
        m_model->setItem(row, 15, item8);
        QString value9 = QString("%1").arg(note);
        QStandardItem *item9 = new QStandardItem(value9);
        m_model->setItem(row, 16, item9);
    }
}

void fullSevaTransactionDetails::getpersondetails(QString id,QString person_name,QString gotra,QString nakshatra,QString date,QString mobile,QString email)
{
    m_id=id;
    m_person_name=person_name;
    m_gotra=gotra;
    m_nakshatra=nakshatra;
    m_date=date;
    m_mobile=mobile;
    m_email=email;
    qDebug()<<"\n"<<m_mobile<<mobile<<endl;
}

void fullSevaTransactionDetails::backtoscreen()
{
    w1->close();
    this->setEnabled(true);
}
void fullSevaTransactionDetails::delete_ofter()
{
    QVBoxLayout *vlayout9a;
    QHBoxLayout *hlayout9;
    model_query = new QSqlQueryModel;
    model_query->setQuery("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking");
    model_query->setHeaderData(0, Qt::Horizontal, tr("SNO"));
    model_query->setHeaderData(1, Qt::Horizontal, tr("PERSONID"));
    model_query->setHeaderData(2, Qt::Horizontal, tr("SEVATYPE"));
    model_query->setHeaderData(3, Qt::Horizontal, tr("SEVANAME"));
    model_query->setHeaderData(4, Qt::Horizontal, tr("QUANTITY"));
    model_query->setHeaderData(5, Qt::Horizontal, tr("S_DATE"));
    model_query->setHeaderData(6, Qt::Horizontal, tr("S_MONTH"));
    model_query->setHeaderData(7, Qt::Horizontal, tr("S_YEAR"));
    model_query->setHeaderData(8, Qt::Horizontal, tr("SEVA_DATE"));
    model_query->setHeaderData(9, Qt::Horizontal, tr("R_DATE"));
    model_query->setHeaderData(10, Qt::Horizontal, tr("R_MONTH"));
    model_query->setHeaderData(11, Qt::Horizontal, tr("R_YEAR"));
    model_query->setHeaderData(12, Qt::Horizontal, tr("RECEIPT_DATE"));
    model_query->setHeaderData(13, Qt::Horizontal, tr("SEVACOST"));
    model_query->setHeaderData(14, Qt::Horizontal, tr("ADDITIONALCOST"));
    model_query->setHeaderData(15, Qt::Horizontal, tr("SEVATOTALPRICE"));
    model_query->setHeaderData(16, Qt::Horizontal, tr("NOTE"));
    view = new QTableView;
    view->setModel(model_query);
    view->resizeColumnsToContents();
    vlayout9a = new QVBoxLayout(this);
    hlayout9 = new QHBoxLayout;
    hlayout9->addWidget(view,Qt::AlignVCenter);
    vlayout9a->addLayout(hlayout9);
    
    vlayout9a->addWidget(view);
    view->setMinimumSize(2000,1000);
    view->show();
}

void fullSevaTransactionDetails::getsevadetails(QString sevaname, int sevacost)
{
    m_sevaname=sevaname;
    m_sevacost=sevacost;
    qDebug()<<Q_FUNC_INFO<<m_sevaname<<m_sevacost<<endl;
}
void fullSevaTransactionDetails::table_viewlastten(QList<QString> l_sno,QList<QString> l_person_id,QList<QString> l_sevatype,QList<QString> l_sevaname,QList<QString> l_quantity,QList<QString> l_s_date,QList<QString> l_s_month,QList<QString> l_s_year,QList<QString> l_sevadate,QList<QString> l_r_date,QList<QString> l_r_month,QList<QString> l_r_year,QList<QString> l_receiptdate,QList<QString> l_seva_cost,QList<QString> l_add_cost,QList<QString> l_total_cost,QList<QString> l_note)
{
    this->setLayout(m_hbox);
//    QScreen *displayscreensize = QGuiApplication::primaryScreen();
//    QRect  screenGeometry = displayscreensize->geometry();
//    int height = screenGeometry.height();
//    int width = screenGeometry.width();
//    this->setFixedSize(width,height);
    this->showMaximized();
    m_model->clear();
    m_model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("PERSONID"))<<(tr("SEVA TYPE"))<<(tr("SEVANAME"))<<(tr("QUANTITY"))<<(tr("S_DATE"))<<(tr("S_MONTH"))<<(tr("S_YEAR"))<<(tr("SEVA_DATE"))<<(tr("R_DATE"))<<(tr("R_MONTH"))<<(tr("R_YEAR"))<<(tr("RECEIPT_DATE"))<<(tr("SEVACOST"))<<(tr("ADDITIONALCOST"))<<(tr("SEVATOTALPRICE"))<<(tr("NOTE")));
    int row,column;
    int size_list= l_sevaname.size();

    for (row =0; row < size_list; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            if(column == 0)
            {
                QString value1 = QString("%1").arg(l_sno.at(row));
                QStandardItem *item1 = new QStandardItem(value1);
                m_model->setItem(row,column,item1);
            }
            if(column == 1)
            {
                QString value2 = QString("%1").arg(l_person_id.at(row));
                QStandardItem *item2 = new QStandardItem(value2);
                m_model->setItem(row,column,item2);
            }
            if(column == 2)
            {
                QString value3 = QString("%1").arg(l_sevatype.at(row));
                QStandardItem *item3 = new QStandardItem(value3);
                m_model->setItem(row,column,item3);
            }
            if(column == 3)
            {
                QString value4 = QString("%1").arg(l_sevaname.at(row));
                QStandardItem *item4 = new QStandardItem(value4);
                m_model->setItem(row,column,item4);
            }
            if(column == 4)
            {
                QString value5 = QString("%1").arg(l_quantity.at(row));
                QStandardItem *item5 = new QStandardItem(value5);
                m_model->setItem(row,column,item5);
            }
            if(column == 5)
            {
                QString value6 = QString("%1").arg(l_s_date.at(row));
                QStandardItem *item6 = new QStandardItem(value6);
                m_model->setItem(row,column,item6);
            }
            if(column == 6)
            {
                QString value7 = QString("%1").arg(l_s_month.at(row));
                QStandardItem *item7 = new QStandardItem(value7);
                m_model->setItem(row,column,item7);
            }
            if(column == 7)
            {
                QString value8 = QString("%1").arg(l_s_year.at(row));
                QStandardItem *item8 = new QStandardItem(value8);
                m_model->setItem(row,column,item8);
            }
            if(column == 8)
            {
                QString value9 = QString("%1").arg(l_sevadate.at(row));
                QStandardItem *item9 = new QStandardItem(value9);
                m_model->setItem(row,column,item9);
            }
            if(column == 9)
            {
                QString value10 = QString("%1").arg(l_r_date.at(row));
                QStandardItem *item10 = new QStandardItem(value10);
                m_model->setItem(row,column,item10);
            }
            if(column == 10)
            {
                QString value11 = QString("%1").arg(l_r_month.at(row));
                QStandardItem *item11 = new QStandardItem(value11);
                m_model->setItem(row,column,item11);
            }
            if(column == 11)
            {
                QString value12 = QString("%1").arg(l_r_year.at(row));
                QStandardItem *item12 = new QStandardItem(value12);
                m_model->setItem(row,column,item12);
            }
            if(column == 12)
            {
                QString value13 = QString("%1").arg(l_receiptdate.at(row));
                QStandardItem *item13 = new QStandardItem(value13);
                m_model->setItem(row,column,item13);
            }
            if(column == 13)
            {
                QString value14 = QString("%1").arg(l_seva_cost.at(row));
                QStandardItem *item14 = new QStandardItem(value14);
                m_model->setItem(row,column,item14);
            }
            if(column == 14)
            {
                QString value15 = QString("%1").arg(l_add_cost.at(row));
                QStandardItem *item15 = new QStandardItem(value15);
                m_model->setItem(row,column,item15);
            }
            if(column == 15)
            {
                QString value16 = QString("%1").arg(l_total_cost.at(row));
                QStandardItem *item16 = new QStandardItem(value16);
                m_model->setItem(row,column,item16);
            }
            if(column == 16)
            {
                QString value17 = QString("%1").arg(l_note.at(row));
                QStandardItem *item17 = new QStandardItem(value17);
                m_model->setItem(row,column,item17);
            }
        }
    }
    this->show();
    connect(m_view, SIGNAL(clicked(const QModelIndex &)),this, SLOT(onTableClicked(const QModelIndex &)));
}
