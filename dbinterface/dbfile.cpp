﻿#include "dbfile.h"
dbfile *dbfile::init =nullptr;
static int BID;
static int SID;
static int RID;
static int SET ;
static int TID ;


dbfile::dbfile(QWidget *parent) : QWidget(parent)
{
    BID=0;
    TID=0;
    SID=0;
    RID=0;
    qDebug()<<Q_FUNC_INFO<<"****************"<<endl;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString currentPath=qApp->applicationDirPath()+"/nseva.db";
    db.setDatabaseName(currentPath);
    bool ok = db.open();
    QSqlQuery qry;
    if(ok)
    {
        qDebug()<<"Database is opened"<<endl;
    }else{
        qDebug()<<"Database is NOT opened"<<endl;
    }
    QString query = "CREATE TABLE seva("
                    "SNO,"
                    "SEVATYPE,"
                    "SEVACODE,"
                    "PERSON);";
    QString query1 = "CREATE TABLE sevaname("
                     "SNO,"
                     "SEVANAME,"
                     "SEVATYPE,"
                     "SEVACOST,"
                     "SEVADATE,"
                     "PERSON,"
                     "THEERTHAPRASADA,"
                     "POOJATIMEING,"
                     "SANKALAPAPOOJA);";
    QString query2 = "CREATE TABLE sevabooking("
                     "SNO,"
                     "PERSONID,"
                     "SEVATYPE,"
                     "SEVANAME,"
                     "QUANTITY,"
                     "S_DATE,"
                     "S_MONTH,"
                     "S_YEAR,"
                     "SEVA_DATE,"
                     "R_DATE,"
                     "R_MONTH,"
                     "R_YEAR,"
                     "RECEIPT_DATE,"
                     "SEVACOST,"
                     "ADDITIONALCOST,"
                     "SEVATOTALPRICE,"
                     "NOTE,"
                     "CASH,"
                     "BANK,"
                     "BANKDETAILS);";
    QString query3 = "CREATE TABLE persondetails("
                     "SNO,"
                     "PERSONNAME,"
                     "GOTHRA,"
                     "NAKSHATRA,"
                     "DATE,"
                     "MOBILE,"
                     "EMAIL);";
    QString query4 = "CREATE TABLE signindetails("
                     "SNO,"
                     "FIRSTNAME,"
                     "LASTNAME,"
                     "USERNAME,"
                     "PASSWORD,"
                     "DATE);";
    QString query5 = "CREATE TABLE mastersignin("
                     "SNO,"
                     "USERNAME,"
                     "PASSWORD,"
                     "DATE);";
//    QString query6 = "CREATE TABLE BankDetails("
//                     "BANK_NAME);";
    qry.prepare(query);
    qry.prepare(query1);
    qry.prepare(query2);
    qry.prepare(query3);
    qry.prepare(query4);
    qry.prepare(query5);
//    qry.prepare(query6);
    qry.exec();
}

void dbfile::add_seva_type(QString seva_type, int seva_code,QString seva_adder_name)
{
    QSqlQuery query_sevaID;
    query_sevaID.exec();
    BID = BID +1;
    QSqlQuery Squery;
    Squery.prepare("INSERT INTO seva(SNO,SEVATYPE,SEVACODE,PERSON)"
                   "VALUES (:sno, :seva_name, :seva_code, :person_name)");
    Squery.bindValue(":sno",BID);
    Squery.bindValue(":seva_name",seva_type);
    Squery.bindValue(":seva_code",seva_code );
    Squery.bindValue(":person_name",seva_adder_name);
    qDebug() << Q_FUNC_INFO <<BID;
    qDebug() << Q_FUNC_INFO <<seva_type;
    qDebug() << Q_FUNC_INFO <<seva_code;
    qDebug() << Q_FUNC_INFO <<seva_adder_name;
    Squery.exec();
}

dbfile* dbfile::getInstance()
{
    if (init == nullptr) {
        qDebug() << "Creating the DataBase Connection " << endl;
        init = new dbfile();
    }
    return init;
}

QList<QStringList> dbfile::printdata_db()
{
    
    //    QList<QStringList> data;
    QSqlQuery qry;
    //    qry.prepare("select SNO,SEVATYPE,SEVACODE from bookings where bid=:BID");
    qry.prepare("select SNO,SEVATYPE,SEVACODE from seva ");
    //    qry.bindValue(":BID",1);
    while(qry.next()){
        QString s_no=qry.value(0).toString();
        QString seva_name=qry.value(1).toString();
        QString seva_code=qry.value(2).toString();
        QString seva_adder_name=qry.value(3).toString();
        
        
        //        QStringList list;
        //        list<<s_no<<seva_name<<seva_code;
        //        data.append(list);
    }
    //    return data;
    qry.exec();
}

bool dbfile::chek_db(QString seva_type, int seva_code, QString sevatype_adder_name)
{
    QMessageBox msgbox;
    int seva_type_size =seva_type.size();
    
    if((seva_code<0)||(seva_type_size<2))
    {
        msgbox.setText(tr("PLEASE ENTER ALL FIELDS"));
        msgbox.exec();
    }
    if((seva_type!=nullptr)||(seva_code!=0))
    {
        bool found =false;
        QSqlQuery qry;
        qry.prepare("select SNO,SEVATYPE,SEVACODE from seva ");
        qry.exec();
        while(qry.next())
        {
            BID =qry.value(0).toInt();
            QString val1=qry.value(1).toString();
            int val2=qry.value(2).toInt();
            qDebug()<<Q_FUNC_INFO<<val1<<endl;
            qDebug()<<Q_FUNC_INFO<<val2<<endl;
            if((val1.compare(seva_type)==0)||(seva_code==val2))
            {
                found =true;
                break;
            }
        }
        if(!found)
        {
            this->add_seva_type(seva_type,seva_code,sevatype_adder_name);
            emit send_seva_details(seva_type,seva_code,sevatype_adder_name);
            emit s_type_sig(seva_type);
        }
        else
        {
            msgbox.setText(tr("SEVA TYPE IS ALREADY EXISTS"));
            msgbox.exec();
        }
    }
}

bool dbfile::chek_name_db(int sevatype, QString sevaName, int seva_cost, QString str_date, QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA from sevaname ");
    qry.exec();
    while(qry.next()){
        SID =qry.value(0).toInt();
        QString val1=qry.value(1).toString();
        int val2=qry.value(2).toInt();
        qDebug()<<Q_FUNC_INFO<<val1<<endl;
        qDebug()<<Q_FUNC_INFO<<val2<<endl;
        if((val1.compare(sevaName)==0)&&(sevatype==val2))
        {
            found =true;
            break;
        }
    }
    if(!found)
    {
        this->addsevaname(sevatype,sevaName,seva_cost,str_date,seva_adder_name,prasada,pooja_time,pooja);
    }
}

void dbfile::addsevaname(int sevatype, QString sevaName, int seva_cost, QString strold_date, QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    QSqlQuery query_sevaID;
    query_sevaID.exec();
    
    QDate Date1 = QDate::fromString(strold_date,"dd-MM-yyyy");
    QString str_date  = Date1.toString("dd-MM-yyyy");
    SID = SID +1;
    QSqlQuery Squery;
    Squery.prepare("INSERT INTO sevaname(SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA,POOJATIMEING,SANKALAPAPOOJA)"
                   "VALUES (:sno, :seva_name, :seva_type, :seva_cost, :seva_date, :seva_adder_name, :t_prasada, :pooja_time, :pooja  )");
    Squery.bindValue(":sno",SID);
    Squery.bindValue(":seva_name",sevaName);
    Squery.bindValue(":seva_type",sevatype );
    Squery.bindValue(":seva_cost",seva_cost );
    Squery.bindValue(":seva_date",str_date );
    Squery.bindValue(":seva_adder_name",seva_adder_name);
    Squery.bindValue(":t_prasada",prasada);
    Squery.bindValue(":pooja_time",pooja_time);
    Squery.bindValue(":pooja",pooja);
    
    
    qDebug() << Q_FUNC_INFO <<sevaName;
    qDebug() << Q_FUNC_INFO <<SID;
    qDebug() << Q_FUNC_INFO <<sevatype;
    qDebug() << Q_FUNC_INFO <<seva_cost;
    qDebug() << Q_FUNC_INFO <<str_date;
    qDebug() << Q_FUNC_INFO <<seva_adder_name;
    qDebug() << Q_FUNC_INFO <<prasada;
    qDebug() << Q_FUNC_INFO <<pooja_time;
    qDebug() << Q_FUNC_INFO <<pooja;
    Squery.exec();
    
}

void dbfile::modify_db_type(int r_s_no,QString r_seva_name,int r_seva_code,QString sevaadder_name,int m_s_no)
{
    qWarning()<<Q_FUNC_INFO<<r_s_no<<endl;
    QSqlQuery qry;
    qry.prepare("UPDATE seva SET SNO=:sno,SEVATYPE=:seva_type,SEVACODE=:seva_code,PERSON=:seva_adder_name WHERE SNO=:s_no");
    qry.bindValue(":s_no",m_s_no);
    qry.bindValue(":sno",r_s_no);
    qry.bindValue(":seva_type",r_seva_name);
    qry.bindValue(":seva_code",r_seva_code);
    qry.bindValue(":seva_adder_name",sevaadder_name);
    qry.exec();
}

void dbfile::modify_db_seva(int ser_no, QString r_seva_name, int r_seva_code, QString seva_type, QString dateold, QString sevaadder_name, int mod_theertha_prasada, QString modifaid_ptime, int modifaidpooja)
{
    
    QDate Date1 = QDate::fromString(dateold,"dd-MM-yyyy");
    QString date  = Date1.toString("dd-MM-yyyy");
    qWarning()<<Q_FUNC_INFO<<ser_no<<endl;
    QSqlQuery qry;
    qDebug()<<Q_FUNC_INFO<<ser_no<<endl;
    qDebug()<<Q_FUNC_INFO<<r_seva_name<<endl;
    qDebug()<<Q_FUNC_INFO<<r_seva_code<<endl;
    qDebug()<<Q_FUNC_INFO<<seva_type<<endl;
    qDebug()<<Q_FUNC_INFO<<date<<endl;
    
    
    qry.prepare("UPDATE sevaname SET SNO=:sno,SEVANAME=:seva_name,SEVATYPE=:seva_type,SEVACOST=:seva_cost,SEVADATE=:seva_date,PERSON=:seav_adder, THEERTHAPRASADA=:terthaprasada,POOJATIMEING=:poojatiming,SANKALAPAPOOJA=:pooja  WHERE SNO=:s_no");
    
    qry.bindValue(":s_no",ser_no);
    qry.bindValue(":sno",ser_no);
    qry.bindValue(":seva_name",r_seva_name);
    qry.bindValue(":seva_type",seva_type);
    qry.bindValue(":seva_cost",r_seva_code);
    qry.bindValue(":seva_date",date);
    qry.bindValue(":seav_adder",sevaadder_name);
    qry.bindValue(":terthaprasada",mod_theertha_prasada);
    qry.bindValue(":poojatiming",modifaid_ptime);
    qry.bindValue(":pooja",modifaidpooja);
    qry.exec();
}

void dbfile::delete_sevadb(QString old_seva_name,QString old_seva_type)
{
    qDebug()<<Q_FUNC_INFO<<old_seva_name<<endl;
    qDebug()<<Q_FUNC_INFO<<old_seva_type<<endl;
    int s_no;
    QString sevaname;
    QSqlQuery query;
    query.prepare("SELECT * FROM  sevaname");
    query.exec();
    while(query.next())
    {
        sevaname = query.value(1).toString();
        QString sevat = query.value(2).toString();
        if(old_seva_name==sevaname && sevat==old_seva_type)
        {
            s_no=query.value(0).toInt();
        }
    }
    QSqlQuery qry;
    qry.prepare("DELETE FROM sevaname WHERE SNO=:sno");
    qry.bindValue(":sno", s_no);
    qry.exec();
}

void dbfile::gotra_list()
{
    QList<QString> list_gotra;
    QSqlQuery qury;
    qury.prepare("select * from persondetails");
    qury.exec();
    while(qury.next())
    {
        QString Gotra=qury.value(2).toString();
        bool alreadyExist = list_gotra.contains(Gotra);
        if(alreadyExist==true)
        {
            continue;
        }
        if(alreadyExist==false)
        {
            list_gotra.append(Gotra);
        }
    }
    emit gotraList(list_gotra);
}

//QStringList dbfile::bank_list()
void dbfile::bank_list()
{
    qDebug()<<Q_FUNC_INFO<<" List of Banks: \n";
    QStringList list_bank;
    QSqlQuery query;
    query.prepare("select * from sevabooking");
    query.exec();
    while(query.next())
    {
        QString Banks=query.value(19).toString();

        bool alreadyExist = list_bank.contains(Banks);
        if(alreadyExist==true)
        {
            continue;
        }
        if(alreadyExist==false)
        {
            list_bank.append(Banks);
        }
    }

    qDebug()<< list_bank<<endl;
    emit bankList(list_bank);
    //return list_bank;
}

void dbfile::Checking_sevacharge(QString data)
{
    int sevaCharge;
    QSqlQuery qry;
    qry.prepare("select * from sevaname");
    qry.exec();
    while(qry.next())
    {
        sevaCharge=qry.value(3).toInt();
        QString sevaCharges=qry.value(3).toString();
        QString sevaName=qry.value(1).toString();
        if(data==sevaName){
            if(sevaCharge==0)
            {

                emit variable_sevacharge();
            }
            else {
                emit fixed_sevacharge(sevaCharge);
                emit  setting_fixed_seva_charge(sevaCharges);

            }
        }
    }
}

void dbfile::delete_db(int d_sno)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM seva WHERE SNO=:sno");
    qry.bindValue(":sno", d_sno);
    qry.exec();
}

void dbfile::sevabookingdb(QString devoteMobile, QString devoteName, QString devoteNakshatra, QString devoteGotra, QString devoteSevacharge, QString devoteAdditionalcharges, QString devoteCount, QString devotereceiptdate, QString devoteSevadate, QString devoteNote, QString devoteSevaName, int cost, int rspt_no, QString cash, QString bank_ref, QString bank_name)
{
    QSqlQuery qury;
    qury.prepare("select * from sevaname");
    QString devoteSevaType;
    qury.exec();
    while(qury.next())
    {
        RID=qury.value(0).toInt();
        QString val1=qury.value(1).toString();
        if(val1==devoteSevaName)
        {
            devoteSevaType=qury.value(2).toString();
        }
    }

    QSqlQuery qury_personId;
    qury.prepare("select * from persondetails");
    qury.exec();

    QDate sevaDate = QDate::fromString(devoteSevadate,"dd-MM-yyyy");
    int sdate = sevaDate.day();
    int smonth = sevaDate.month();
    int syear = sevaDate.year();

    QDate receiptDate = QDate::fromString(devotereceiptdate,"dd-MM-yyyy");
    int rdate = receiptDate.day();
    int rmonth = receiptDate.month();
    int ryear = receiptDate.year();
    QString Person_id;
    while(qury.next())
    {
        QString p_name=qury.value(1).toString();
        QString mobile_no=qury.value(5).toString();
        if(p_name==devoteName && devoteMobile==mobile_no)
        {
            Person_id =qury.value(0).toString();
        }
    }
    //    QSqlQuery qry;
    QSqlQuery qry;
    qry.prepare("INSERT INTO sevabooking(SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE, NOTE, CASH, BANK, BANKDETAILS)"
                "VALUES (:sno, :person_id, :sevatype, :sevaname, :quantity, :s_date, :s_month, :s_year, :seva_date, :r_date, :r_month,:r_year, :receipt_date, :seva_cost, :additionalcost, :sevatotalprice, :note, :cash, :bank, :bankdetails)");
    qry.bindValue(":sno",rspt_no);
    qry.bindValue(":person_id",Person_id);
    qry.bindValue(":sevatype",devoteSevaType );
    qry.bindValue(":sevaname",devoteSevaName);
    qry.bindValue(":quantity",devoteCount );
    qry.bindValue(":s_date",sdate);
    qry.bindValue(":s_month",smonth );
    qry.bindValue(":s_year",syear );
    qry.bindValue(":seva_date",devoteSevadate);
    qry.bindValue(":r_date",rdate);
    qry.bindValue(":r_month",rmonth );
    qry.bindValue(":r_year",ryear );
    qry.bindValue(":receipt_date",devotereceiptdate);
    qry.bindValue(":seva_cost",devoteSevacharge );
    qry.bindValue(":additionalcost",devoteAdditionalcharges);
    qry.bindValue(":sevatotalprice",cost);
    qry.bindValue(":note",devoteNote );
    qry.bindValue(":cash", cash);
    qry.bindValue(":bank",bank_ref);
    qry.bindValue(":bankdetails",bank_name);
    qry.exec();
}

void dbfile::topersondetailsdb(QString devoteMobile,QString devoteName,QString devoteNakshatra,QString devoteGotra,QString devoteSevacharge,QString devoteAdditionalcharges,QString devoteCount,QString devotereceiptdate,QString devoteSevadate,QString devoteNote)
{
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select * from persondetails");
    qry.exec();
    while(qry.next())
    {
        RID=qry.value(0).toInt();
        QString val1=qry.value(5).toString();
        if(val1==devoteMobile)
        {
            found =true;
            break;
        }
    }
    if(!found)
    {
        RID = RID +1;
        QSqlQuery qry;
        qry.prepare("INSERT INTO persondetails(SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE)"
                    "VALUES (:sno, :person_name, :gothra, :nakshatra, :date, :mobile)");
        qry.bindValue(":sno",RID);
        qry.bindValue(":person_name",devoteName);
        qry.bindValue(":gothra",devoteGotra );
        qry.bindValue(":nakshatra",devoteNakshatra );
        qry.bindValue(":date",devotereceiptdate );
        qry.bindValue(":mobile",devoteMobile);
        qDebug() << Q_FUNC_INFO <<devoteName;
        qDebug() << Q_FUNC_INFO <<devoteGotra;
        qDebug() << Q_FUNC_INFO <<devoteNakshatra;
        qDebug() << Q_FUNC_INFO <<devoteMobile;
        if( qry.exec()){
        };
    }
}

bool dbfile::chek_sevaname_allreadyexist(int sevatype, QString sevaName, int seva_cost, QString str_date, QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    QMessageBox msgbox;
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON from sevaname ");
    qry.exec();
    while(qry.next()){
        SID =qry.value(0).toInt();
        QString val1=qry.value(1).toString();
        int val2=qry.value(2).toInt();
        qDebug()<<Q_FUNC_INFO<<val1<<endl;
        qDebug()<<Q_FUNC_INFO<<val2<<endl;

        if((val1.compare(sevaName)==0)&&(sevatype==val2))
        {
            found =true;
            break;
        }
    }
    if(!found)
    {

        this->chek_name_db(sevatype,sevaName,seva_cost,str_date,seva_adder_name,prasada,pooja_time,pooja);
        emit seva_Name(sevatype,sevaName,seva_cost,str_date,seva_adder_name,prasada,pooja_time,pooja);
        msgbox.setText("SEVA NAME ADDED SUCCESSFULLY");
        msgbox.exec();
    }
    else
    {
        msgbox.setText("SEVA TYPE IS ALREADY EXISTS");
        msgbox.exec();
    }
}

void dbfile::seva_modification_testing(int sno, int new_sevarow, QString new_seva_nmae, int new_seva_cost, QString new_date, QString sevamodifairname, int mod_theertha_prasada, QString modifaid_ptime, int modifaidpooja, QString old_seva_name, QString old_seva_type)
{
    QString sevaname;
    int seva_type_size =new_seva_nmae.size();
    int s_no;
    QSqlQuery query_other;
    query_other.prepare("SELECT * FROM  sevaname");
    query_other.exec();
    while(query_other.next())
    {
        sevaname = query_other.value(1).toString();
        QString sevat = query_other.value(2).toString();
        if(old_seva_name==sevaname && sevat==old_seva_type)
        {
            s_no=query_other.value(0).toInt();
        }
    }
    QString s_seva_name=new_seva_nmae;
    int s_seva_cost=new_seva_cost;
    qDebug()<<Q_FUNC_INFO<<new_seva_nmae<<endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_cost<<endl;
    qDebug()<<Q_FUNC_INFO<<sno<<endl;
    QMessageBox msgbox;
    if((new_seva_cost<0)||(seva_type_size<2))
    {
        msgbox.setText(tr("PLZ ENTER THE ALL FIELD"));
        msgbox.exec();
        return;
    }
    emit modifying_seva(sno,new_sevarow,new_seva_nmae,new_seva_cost,new_date,sevamodifairname,mod_theertha_prasada,modifaid_ptime,modifaidpooja);
    this->modify_db_seva(s_no,s_seva_name,s_seva_cost,old_seva_type,new_date,sevamodifairname,mod_theertha_prasada,modifaid_ptime,modifaidpooja);
}

void dbfile::combobox_sevatype()
{
    //for booking report
    QList<QString> list_sevatype;

    list_sevatype.clear();
    QSqlQuery query_other;
    query_other.prepare("SELECT * FROM seva");
    query_other.exec();
    while(query_other.next())
    {
        QString str = query_other.value(1).toString();
        list_sevatype.append(str);
    }
    emit seva_type(list_sevatype);
}

void dbfile::getdata()
{
    QSqlQuery qry;
    qry.prepare("select SNO,SEVATYPE,SEVACODE,PERSON from seva ");
    qry.exec();
    while(qry.next()){
        QString s_no=qry.value(0).toString();
        QString seva_name=qry.value(1).toString();
        QString seva_code=qry.value(2).toString();
        QString seva_adder_name=qry.value(3).toString();
        qDebug()<<Q_FUNC_INFO<<s_no<<endl;
        qDebug()<<Q_FUNC_INFO<<seva_name<<endl;
        qDebug()<<Q_FUNC_INFO<<seva_code<<endl;
        qDebug()<<Q_FUNC_INFO<<seva_adder_name<<endl;
        emit get_data_db(s_no,seva_name,seva_code,seva_adder_name);
    }
}

void dbfile::dbtable_view()
{
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;

    l_sno.clear();

    l_sno.clear();
    l_person_id.clear();
    l_sevatype.clear();
    l_sevaname.clear();
    l_quantity.clear();
    l_s_date.clear();
    l_s_month.clear();
    l_s_year.clear();
    l_sevadate.clear();
    l_r_date.clear();
    l_r_month.clear();
    l_receiptdate.clear();
    l_seva_cost.clear();
    l_add_cost.clear();
    l_total_cost.clear();
    l_note.clear();
    QString devoteSevaType;
    QString str;
    str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    QSqlQuery query_other1;
    query_other1.prepare(str);
    query_other1.exec();
    while(query_other1.next())
    {
        QString sno = query_other1.value(0).toString();
        QString  person_id = query_other1.value(1).toString();
        QString sevatype =query_other1.value(2).toString();
        QString sevaname =query_other1.value(3).toString();
        QString quantity=query_other1.value(4).toString();
        QString s_date = query_other1.value(5).toString();
        QString  s_month = query_other1.value(6).toString();
        QString s_year =query_other1.value(7).toString();
        QString realformatsevadate =query_other1.value(8).toString();
        QDate sevadateDate = QDate::fromString(realformatsevadate,"dd-MM-yyyy");
        QString sevadate = sevadateDate.toString("dd-MM-yyyy");
        QString r_date = query_other1.value(9).toString();
        QString  r_month = query_other1.value(10).toString();
        QString r_year =query_other1.value(11).toString();
        QString realformatreceiptdate =query_other1.value(12).toString();
        QDate receiptdateDate = QDate::fromString(realformatreceiptdate,"dd-MM-yyyy");
        QString receiptdate = receiptdateDate.toString("dd-MM-yyyy");
        QString seva_cost =query_other1.value(13).toString();
        QString add_cost=query_other1.value(14).toString();
        QString total_cost=query_other1.value(15).toString();
        QString note=query_other1.value(16).toString();

        l_sno.append(sno);
        l_person_id.append(person_id);
        l_sevatype.append(sevatype);
        l_sevaname.append(sevaname);
        l_quantity.append(quantity);
        l_s_date.append(s_date);
        l_s_month.append(s_month);
        l_s_year.append(s_year);
        l_sevadate.append(sevadate);
        l_r_date.append(r_date);
        l_r_month.append(r_month);
        l_r_year.append(r_year);
        l_receiptdate.append(receiptdate);
        l_seva_cost.append(seva_cost);
        l_add_cost.append(add_cost);
        l_total_cost.append(total_cost);
        l_note.append(note);
    }
    emit forFUllDetails(l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note);
}

void dbfile::getpersondetails(QString person_id)
{

    QString id,person_name,gotra,nakshatra,date,mobile,email;
    QString newstr;
    newstr = ("select SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE,EMAIL from persondetails;" );
    QSqlQuery query;
    query.prepare(newstr);
    query.exec();
    while(query.next())
    {

        QString id = query.value(0).toString();
        if(id==person_id)
        {
            id = query.value(0).toString();
            person_name = query.value(1).toString();
            gotra =query.value(2).toString();
            nakshatra =query.value(3).toString();
            date=query.value(4).toString();
            mobile = query.value(5).toString();
            email = query.value(6).toString();
        }
    }
    emit persondetails(id,person_name,gotra,nakshatra,date,mobile,email);
}

void dbfile::getsevadetails(QString sevaname)
{
    QSqlQuery qry;
    qry.prepare("select * from sevaname");
    qry.exec();
    QString l_sevaname;
    int sevacost;
    while(qry.next())
    {
        l_sevaname=qry.value(1).toString();
        sevacost=qry.value(3).toInt();
        if(sevaname==l_sevaname)
        {
            emit sevadetails(l_sevaname,sevacost);
        }
    }
}


void dbfile::deletesevabookingentry(int s_no)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM sevabooking WHERE SNO=:sno");
    qry.bindValue(":sno", s_no);
    qry.exec();
}

void dbfile::getsevabookingmodifaing(int s_no,int count,int s_date,int s_month,int s_year, QString sevadate,int sevacharge,int addcharg,int total, QString note)
{
    QSqlQuery qry;
    qry.prepare("UPDATE sevabooking SET SNO=:s_no,QUANTITY=:count,S_DATE=:s_date,S_MONTH=:s_month,S_YEAR=:s_year,SEVA_DATE=:sevadate,SEVACOST=:seva_cost,ADDITIONALCOST=:add_cost,SEVATOTALPRICE =:total_price,NOTE=:note WHERE SNO=:sno;");
    qry.bindValue(":sno",s_no);
    qry.bindValue(":s_no",s_no);
    qry.bindValue(":count",count);
    qry.bindValue(":s_date",s_date);
    qry.bindValue(":s_month",s_month);
    qry.bindValue(":s_year",s_year);
    qry.bindValue(":sevadate",sevadate);
    qry.bindValue(":seva_cost",sevacharge);
    qry.bindValue(":add_cost",addcharg);
    qry.bindValue(":total_price",total);
    qry.bindValue(":note",note);
    qry.exec();
}

void dbfile::table_view_forlast_ten_tran()
{
    QList<QString> m_sno,m_person_id,m_sevatype,m_sevaname,m_quantity,m_s_date,m_s_month,m_s_year ,m_sevadate,m_r_date,m_r_month,m_r_year,m_receiptdate,m_seva_cost,m_add_cost,m_total_cost,m_note;

    m_sno.clear();
    m_sno.clear();
    m_person_id.clear();
    m_sevatype.clear();
    m_sevaname.clear();
    m_quantity.clear();
    m_s_date.clear();
    m_s_month.clear();
    m_s_year.clear();
    m_sevadate.clear();
    m_r_date.clear();
    m_r_month.clear();
    m_receiptdate.clear();
    m_seva_cost.clear();
    m_add_cost.clear();
    m_total_cost.clear();
    m_note.clear();
    QString str1;
    str1 = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    QSqlQuery query_other;

    query_other.prepare(str1);
    query_other.exec();
    while(query_other.next())
    {
        SET =query_other.value(0).toInt();
    }
    SET =SET-10;
    QString devoteSevaType;
    QString str;
    str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    QSqlQuery query_other1;
    query_other1.prepare(str);
    query_other1.exec();
    while(query_other1.next())
    {
        int s_num = query_other1.value(0).toInt();
        if(s_num>=SET)
        {
            QString sno = query_other1.value(0).toString();
            QString  person_id = query_other1.value(1).toString();
            QString sevatype =query_other1.value(2).toString();
            QString sevaname =query_other1.value(3).toString();
            QString quantity=query_other1.value(4).toString();
            QString s_date = query_other1.value(5).toString();
            QString  s_month = query_other1.value(6).toString();
            QString s_year =query_other1.value(7).toString();
            QString realformatsevadate =query_other1.value(8).toString();
            QDate sevadateDate = QDate::fromString(realformatsevadate,"dd-MM-yyyy");
            QString sevadate = sevadateDate.toString("dd-MM-yyyy");
            QString r_date = query_other1.value(9).toString();
            QString  r_month = query_other1.value(10).toString();
            QString r_year =query_other1.value(11).toString();
            QString realformatreceiptdate =query_other1.value(12).toString();
            QDate receiptdateDate = QDate::fromString(realformatreceiptdate,"dd-MM-yyyy");
            QString receiptdate = receiptdateDate.toString("dd-MM-yyyy");
            QString seva_cost =query_other1.value(13).toString();
            QString add_cost=query_other1.value(14).toString();
            QString total_cost=query_other1.value(15).toString();
            QString note=query_other1.value(16).toString();

            m_sno.append(sno);
            m_person_id.append(person_id);
            m_sevatype.append(sevatype);
            m_sevaname.append(sevaname);
            m_quantity.append(quantity);
            m_s_date.append(s_date);
            m_s_month.append(s_month);
            m_s_year.append(s_year);
            m_sevadate.append(sevadate);
            m_r_date.append(r_date);
            m_r_month.append(r_month);
            m_r_year.append(r_year);
            m_receiptdate.append(receiptdate);
            m_seva_cost.append(seva_cost);
            m_add_cost.append(add_cost);
            m_total_cost.append(total_cost);
            m_note.append(note);
        }
        emit forlasttenDetails(m_sno,m_person_id,m_sevatype,m_sevaname,m_quantity,m_s_date,m_s_month,m_s_year ,m_sevadate,m_r_date,m_r_month,m_r_year,m_receiptdate,m_seva_cost,m_add_cost,m_total_cost,m_note);

    }
}

void dbfile::print_data_db(int seva_Type)
{
    QList<QString> list_s_no,list_seva_name,list_seva_type,list_seva_cost,list_seva_date,list_seva_adder_name,list_prasada,list_pooja_time,list_pooja;
    qDebug()<<"cooooooooooooooooooooooooooooooooooooooooooooooooming"<<endl;
    list_s_no.clear();
    list_seva_name.clear();
    list_seva_type.clear();
    list_seva_cost.clear();
    list_seva_date.clear();
    list_seva_adder_name.clear();
    list_prasada.clear();
    list_pooja_time.clear();
    list_pooja.clear();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM sevaname");
    qry.exec();
    while(qry.next())
    {
        int val = qry.value(2).toInt();
        if(seva_Type == 0)//regular seva at 1st index in combo
        {
            qDebug()<<"comming"<<seva_Type<<endl;
            QString s_no=qry.value(0).toString();
            QString seva_name=qry.value(1).toString();
            QString seva_type=qry.value(2).toString();
            QString seva_cost=qry.value(3).toString();
            QString seva_date_real=qry.value(4).toString();
            QDate Dateseva_date = QDate::fromString(seva_date_real,"dd-MM-yyyy");
            QString seva_date = Dateseva_date.toString("dd-MM-yyyy");
            QString seva_adder_name=qry.value(5).toString();
            QString prasada=qry.value(6).toString();
            QString pooja_time=qry.value(7).toString();
            QString pooja=qry.value(8).toString();
            list_s_no.append(s_no);
            list_seva_name.append(seva_name);
            list_seva_type.append(seva_type);
            list_seva_cost.append(seva_cost);
            list_seva_date.append(seva_date);
            list_seva_adder_name.append(seva_adder_name);
            list_prasada.append(prasada);
            list_pooja_time.append(pooja_time);
            list_pooja.append(pooja);
        }

        if(val == seva_Type)//regular seva at 1st index in combo
        {
            qDebug()<<"comming"<<seva_Type<<endl;
            QString s_no=qry.value(0).toString();
            QString seva_name=qry.value(1).toString();
            QString seva_type=qry.value(2).toString();
            QString seva_cost=qry.value(3).toString();
            QString seva_date_real=qry.value(4).toString();
            QDate Dateseva_date = QDate::fromString(seva_date_real,"dd-MM-yyyy");
            QString seva_date = Dateseva_date.toString("dd-MM-yyyy");
            QString seva_adder_name=qry.value(5).toString();
            QString prasada=qry.value(6).toString();
            QString pooja_time=qry.value(7).toString();
            QString pooja=qry.value(8).toString();
            list_s_no.append(s_no);
            list_seva_name.append(seva_name);
            list_seva_type.append(seva_type);
            list_seva_cost.append(seva_cost);
            list_seva_date.append(seva_date);
            list_seva_adder_name.append(seva_adder_name);
            list_prasada.append(prasada);
            list_pooja_time.append(pooja_time);
            list_pooja.append(pooja);
        }
    }
    emit sevaname(list_s_no,list_seva_name,list_seva_type,list_seva_cost,list_seva_date,list_seva_adder_name,list_prasada,list_pooja_time,list_pooja);
}

void dbfile::seva_type_adding()
{
    QList<QString> list_sevatypes;
    //    list_sevatypes.append("ALL SEVA TYPE");
    QSqlQuery qry;
    qry.prepare("SELECT * FROM seva");
    qry.exec();
    while(qry.next())
    {
        QString sevaType = qry.value(1).toString();
        list_sevatypes.append(sevaType);
        qDebug()<<Q_FUNC_INFO<<sevaType;
    }
    emit seva_types_adding(list_sevatypes);

}

void dbfile::seva_name_adding(int sevaT)
{
    QList<QString> list_seva_name;
    list_seva_name.clear();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM sevaname");
    qry.exec();
    while(qry.next())
    {
        int sevaType = qry.value(2).toInt();
        if(sevaT==0)
        {
            list_seva_name.append("ALL SEVA NAME");
            break;
        }
        if(sevaT==sevaType)
        {
            QString sevaname = qry.value(1).toString();
            list_seva_name.append(sevaname);

        }
    }
    emit sevaName(list_seva_name);
}

void dbfile::mobileNumberSearching(QString mobile_num)
{
    qDebug()<<"mobile_number searching"<<  mobile_num<<endl;
    QSqlQuery qry;
    qry.prepare("select * from persondetails");
    qry.exec();
    while(qry.next())
    {
        RID =qry.value(0).toInt();
        QString d_Mobile= qry.value(5).toString();
        QString   d_Name =qry.value(1).toString();
        QString  d_Gotra = qry.value(2).toString();
        QString  d_Nakshatra =qry.value(3).toString();
        QString  d_receiptdate = qry.value(4).toString();
        if(mobile_num==d_Mobile)
        {
            emit mob_num_there(d_Mobile,d_Name,d_Nakshatra,d_Gotra);
            break;
        }
        else
        {
            emit mob_num_Not_there();

        }
    }
}

void dbfile::receipt_no_printing()
{
    int r_number;
    QSqlQuery qury_SNO;
    qury_SNO.prepare("select * from sevabooking");
    qury_SNO.exec();
    while(qury_SNO.next())
    {
        r_number=qury_SNO.value(0).toInt();
    }
    emit get_receiptnumber(r_number);
}

void dbfile::booking_report_cdate_function(QString formatchangedcalendar_str, QString SEVA, int TYPE)
{
    total_prasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QList<float> list_cost,list_total;
    QString calendar_str;

    QString que;
    if(TYPE==0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1';");
        que = que.arg(formatchangedcalendar_str);
    }
    else if (SEVA==ALLSEVANAME) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2'; ");
        que = que.arg(formatchangedcalendar_str).arg(TYPE);
    }
    else {

        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3'; ");
        que = que.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }

    qDebug() << " Query string =" << que << endl;
    QSqlQuery query_other1;
    query_other1.prepare(que);
    query_other1.exec();

    QSqlQuery query;
    while(query_other1.next())
    {
        personid = query_other1.value(0).toString();
        p_sevaname = query_other1.value(1).toString();
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == p_sevaname)//regular seva at 1st index in combo
            {
                prasada = query.value(6).toInt();
                list_prasada.append(prasada);
            }
        }
        prasada =prasada*quantity;
        sevadate =query_other1.value(3).toString();//cost
        list_sevadate.append(sevadate);
        note=query_other1.value(5).toString();//total
        list_note.append(note);
        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                p_name=query_other2.value(1).toString();
                p_gotra=query_other2.value(2).toString();
                p_nakshtra=query_other2.value(3).toString();
                p_mobile=query_other2.value(5).toString();
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }
        total_prasada=total_prasada+prasada;
        int size_list = list_sevaname.size();

    }
    emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);

}

void dbfile::booking_report_cmonth_function(QString SEVA,int TYPE,int month,int year)
{
    total_prasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR='%2' ; ");
        que = que.arg(month).arg(year);
    }
    else if (SEVA==ALLSEVANAME) {

        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' ; ");
        que = que.arg(month).arg(year).arg(TYPE);

    }
    else {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  ");
        qDebug() <<month<<year<<TYPE<<SEVA<<endl;
        que = que.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << que << endl;
    query_other1.prepare(que);
    query_other1.exec();
    QSqlQuery query;

    while(query_other1.next())
    {
        personid = query_other1.value(0).toString();
        p_sevaname = query_other1.value(1).toString();
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == p_sevaname)//regular seva at 1st index in combo
            {
                prasada = query.value(6).toInt();
                list_prasada.append(prasada);
            }
        }
        prasada =prasada*quantity;
        sevadate =query_other1.value(3).toString();//cost
        list_sevadate.append(sevadate);
        note=query_other1.value(5).toString();//total
        list_note.append(note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                p_name=query_other2.value(1).toString();
                p_gotra=query_other2.value(2).toString();
                p_nakshtra=query_other2.value(3).toString();
                p_mobile=query_other2.value(5).toString();
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }

        total_prasada=total_prasada+prasada;
    }

    emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);

}

void dbfile::booking_report_dataRange_function(QString SEVA,int TYPE,QString seva_Startdate,QString seva_Enddate)
{
    total_prasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString str;
    if(TYPE == 0)
    {
        qDebug() <<seva_Startdate<<seva_Enddate;

        str = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2';" );
        str  = str.arg(seva_Startdate).arg(seva_Enddate);

    }
    else if (SEVA==ALLSEVANAME) {
        str = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' ; " );
        str  = str.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);
    }
    else {
        str = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' ;" );
        str  = str.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << str << endl;
    query_other1.prepare(str);
    query_other1.exec();
    QSqlQuery query;
    while(query_other1.next())
    {
        personid = query_other1.value(0).toString();
        p_sevaname = query_other1.value(1).toString();
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == p_sevaname)//regular seva at 1st index in combo
            {
                prasada = query.value(6).toInt();
                list_prasada.append(prasada);
            }
        }
        prasada =prasada*quantity;
        sevadate =query_other1.value(3).toString();//cost
        list_sevadate.append(sevadate);
        note=query_other1.value(5).toString();//total
        list_note.append(note);
        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                p_name=query_other2.value(1).toString();
                p_gotra=query_other2.value(2).toString();
                p_nakshtra=query_other2.value(3).toString();
                p_mobile=query_other2.value(5).toString();
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }

        total_prasada=total_prasada+prasada;
        int size_list = list_sevaname.size();

    }
    emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);

}

dbfile::~dbfile()
{

}

void dbfile::account_report_cdate_function(QString SEVA,int TYPE,QString formatchangedcalendar_str)
{
    qDebug()<<formatchangedcalendar_str<<"^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString que1;

    if(TYPE==0) {
        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' Group by sevabooking.SEVANAME");
        que1 = que1.arg(formatchangedcalendar_str);

    }
    else if (SEVA==ALLSEVANAME) {
        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME; ");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE);
    }
    else {

        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME; ");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }

    qDebug() << " Query string =" << que1 << endl;
    query_other1.prepare(que1);
    query_other1.exec();

    while(query_other1.next())
    {
        QString b = query_other1.value(0).toString();
        int  c = query_other1.value(1).toInt();
        float d =query_other1.value(2).toFloat();//cost
        float e =query_other1.value(3).toFloat();//total
        list_name.append(b);
        list_ticket.append(c);
        list_cost.append(d);
        list_total.append(e);
    }

    int size_list = list_name.size();
    qDebug()<<"size of list="<<size_list<<endl;
    int sum=0;
    for(int i=0;i<size_list;i++)
    {
        sum= sum+list_total[i];
    }
    QString total_sum = QString::number(sum);

    qDebug()<<"size of list="<<sum<<endl;
    emit account_report(list_name,list_ticket,list_cost,list_total,total_sum);
}
void dbfile::account_report_cmonth_function(QString SEVA,int TYPE,int month,int year)
{
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    int sum=0;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR='%2' Group by sevabooking.SEVANAME; ");
        que = que.arg(month).arg(year);
    }
    else if (SEVA==ALLSEVANAME)
    {

        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVANAME; ");
        que = que.arg(month).arg(year).arg(TYPE);
        qDebug()<<"+_____________________________________++++++++++________________"<<month;

    }
    else {
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  Group by sevabooking.SEVANAME");
        qDebug() <<month<<"&&&&&&&&&&&"<<year<<"&&&&&&&&&&&&&&&&&&&"<<TYPE<<"&&&&&&&&&&&&&&&&&&&"<<SEVA<<endl;
        que = que.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << que << endl;
    query_other1.prepare(que);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug()<<year<<month<<"***--------------------------***"<<endl;
        QString b = query_other1.value(0).toString();
        int  c = query_other1.value(1).toInt();
        float d =query_other1.value(2).toFloat();//cost
        float e =query_other1.value(3).toFloat();//total
        list_name.append(b);
        list_ticket.append(c);
        list_cost.append(d);
        list_total.append(e);
    }

    int size_list = list_name.size();
    qDebug()<<"size of list="<<size_list<<endl;
    for(int i=0;i<size_list;i++)
    {
        sum= sum+list_total[i];
    }
    QString total_sum = QString::number(sum);
    emit account_report(list_name,list_ticket,list_cost,list_total,total_sum);

}

void dbfile::account_report_dataRange_function(QString SEVA,int TYPE ,QString seva_Startdate,QString seva_Enddate)
{
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' Group by sevabooking.SEVANAME;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate);
    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVANAME; " );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);
    }
    else {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.SEVANAME;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << readstr << endl;
    query_other1.prepare(readstr);
    query_other1.exec();

    while(query_other1.next())
    {
        QString b = query_other1.value(0).toString();
        int  c = query_other1.value(1).toInt();
        float d =query_other1.value(2).toFloat();//cost
        float e =query_other1.value(3).toFloat();//total
        list_name.append(b);
        list_ticket.append(c);
        list_cost.append(d);
        list_total.append(e);
    }

    int size_list = list_name.size();
    qDebug()<<"size of list="<<size_list<<endl;
    int sum=0;
    for(int i=0;i<size_list;i++)
    {
        sum= sum+list_total[i];
    }
    qDebug()<<"size of list="<<sum<<endl;
    QString total_sum = QString::number(sum);
    emit account_report(list_name,list_ticket,list_cost,list_total,total_sum);
}
void dbfile::signin_clicked(QString username,QString password,int type)
{
    bool found =false;
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE from signindetails");
    query_s_no.exec();
    while(query_s_no.next())
    {
        QString Last_name=query_s_no.value(2).toString();
        QString user_name=query_s_no.value(3).toString();
        QString pass_word=query_s_no.value(4).toString();

        if(username==user_name && password==pass_word)
        {
            if(type==1)
            {
                emit success();

            }
            else {
                emit correct_password(Last_name);
            }
            found =true;
            break;
        }
    }

    if(!found)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("YOU ENTERD THE WRONG PASSWORD"));
        msgBox.exec();
    }
}
void dbfile::old_password(QString l_userfirstname, QString l_userlastname)
{
    bool found =false;
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE from signindetails");
    query_s_no.exec();
    while(query_s_no.next())
    {
        QString f_First_name=query_s_no.value(1).toString();
        QString  l_last_name=query_s_no.value(2).toString();
        QString l_username=query_s_no.value(3).toString();
        QString l_password=query_s_no.value(4).toString();
        qDebug()<<l_userfirstname<<f_First_name <<l_userlastname<<l_last_name;
        if((l_userfirstname==f_First_name) && (l_userlastname==l_last_name))
        {
            emit show_username_password(l_username,l_password);
            found =true;
            break;
        }
    }

    if(!found)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("YOU ENTERD THE WRONG USERNAME OR PASSWORD"));
        msgBox.exec();
    }

}

void dbfile::add_new_signin_details(QString fname, QString lname, QString username, QString password,QString date)
{
    QSqlQuery query_s_no;
    QMessageBox msgbox;
    query_s_no.prepare("select SNO from signindetails");
    query_s_no.exec();
    while(query_s_no.next()){
        TID =query_s_no.value(0).toInt();
        qDebug()<<TID<<endl;
    }
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select SNO,FIRSTNAME,LASTNAME from signindetails");
    qry.exec();
    while(qry.next())
    {
        int s_num =qry.value(0).toInt();
        QString val1=qry.value(1).toString();
        int val2=qry.value(2).toInt();
        qDebug()<<Q_FUNC_INFO<<val1<<endl;
        qDebug()<<Q_FUNC_INFO<<val2<<endl;
        if((fname==val1)||(lname==val2))
        {
            found =true;
            msgbox.setText(tr("ITS ALLREADY EXIST"));
            msgbox.exec();
            return;
            break;
        }
    }
    if(!found)
    {

        QSqlQuery Squery;
        Squery.prepare("INSERT INTO signindetails(SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE)"
                       "VALUES (:sno, :first_name, :last_name, :user_name, :password, :date)");
        TID = TID +1;
        Squery.bindValue(":sno",TID);
        Squery.bindValue(":first_name",fname);
        Squery.bindValue(":last_name",lname );
        Squery.bindValue(":user_name",username);
        Squery.bindValue(":password",password);
        Squery.bindValue(":date",date);
        Squery.exec();
        emit sucessfully_added();
    }
}

QList<SigninDetails *> dbfile::geting_signInDetails()
{
    QList<SigninDetails *>  listOfSignin;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM signindetails");
    qry.exec();
    while(qry.next())
    {
        SigninDetails *signIn_Detail  = new SigninDetails;
        signIn_Detail->firstName=qry.value(1).toString();
        signIn_Detail->LastName=qry.value(2).toString();
        signIn_Detail->UserName=qry.value(3).toString();
        signIn_Detail->Password=qry.value(4).toString();
        listOfSignin.append(signIn_Detail);
    }
    return listOfSignin;
}

void dbfile::delete_selected_LoginDetails(QString Name)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM signindetails WHERE FIRSTNAME=:firstname");
    qry.bindValue(":firstname", Name);
    qry.exec();
}
void dbfile::modify_selected_LoginDetails(QString previous_name,QString first_name, QString last_name, QString user_name, QString password, QString date)
{
    QSqlQuery qry;
    qry.prepare("UPDATE signindetails SET  FIRSTNAME=:firstname,LASTNAME=:lastname,USERNAME=:username,PASSWORD=:password,DATE=:date WHERE FIRSTNAME=:previous");
    qry.bindValue(":previous",previous_name);
    qry.bindValue(":firstname",first_name);
    qry.bindValue(":lastname",last_name);
    qry.bindValue(":username",user_name);
    qry.bindValue(":password",password);
    qry.bindValue(":date",date);
    qry.exec();
}

QStringList dbfile::getMasterCredentials()
{
    QStringList listOfSignin;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM mastersignin");
    qry.exec();
    while(qry.next())
    {
        listOfSignin.append(qry.value(1).toString());
        listOfSignin.append(qry.value(2).toString());
    }
    return listOfSignin;
}

void dbfile::updateMasterCredentials(QString oldUserName,QString NewUsername,QString NewPassword,QString date)
{
    QSqlQuery qry;
    qry.prepare("UPDATE mastersignin SET USERNAME=:username,PASSWORD=:password,DATE=:date WHERE USERNAME=:old_username");
    qry.bindValue(":old_username",oldUserName);
    qry.bindValue(":username",NewUsername);
    qry.bindValue(":password",NewPassword);
    qry.bindValue(":date",date);
    qry.exec();
}

