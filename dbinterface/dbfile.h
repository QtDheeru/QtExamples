#ifndef DBFILE_H
#define DBFILE_H
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include<QtSql>
#include<QList>
#include<QStringList>
#include<QMessageBox>
#include<QApplication>
#include"common.h"
#define ALLSEVANAME "All"
class dbfile : public QWidget
{
    Q_OBJECT
public:
    static dbfile* init;
    static dbfile* getInstance();
    QList<QStringList> printdata_db();
    QSqlDatabase db;
    ~ dbfile();

signals:
    void send_seva_details(QString,int);
    void seva_Name(int,QString,int,QString,QString,int,QString,int);
    void modifying_seva(int,int,QString,int,QString,QString,int,QString,int);
    void seva_type(QList<QString>);
    void send_seva_details(QString,int,QString);
    void s_type_sig(QString);
    void get_data_db(QString,QString,QString,QString);
    void forFUllDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void forlasttenDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void persondetails(QString,QString,QString,QString,QString,QString,QString);
    void sevadetails(QString,int);
    void seva_types_adding(QList<QString>);
    void sevaName(QList<QString>);
    void sevaname( QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
    void mob_num_there(QString,QString,QString,QString);
    void mob_num_Not_there();
    void gotraList(QList<QString>);
    void bankList(QList<QString>);
    void variable_sevacharge();
    void fixed_sevacharge(int);
    void  setting_fixed_seva_charge(QString);
    void get_receiptnumber(int);
    void booking_report(QList<QString>,QList<int>,QList<int>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void account_report(QList<QString>,QList<int>,QList<float>,QList<float>,QString);
    void correct_password(QString);
    void success();
    void show_username_password(QString,QString);
    void sucessfully_added();

public slots:
    void add_seva_type(QString seva_type, int seva_code, QString seva_adder_name);
    void modify_db_type(int,QString,int,QString,int);
    void delete_db(int);
    void modify_db_seva(int,QString,int,QString,QString,QString,int,QString,int);
    void delete_sevadb(QString, QString);
    void sevabookingdb(QString , QString , QString , QString , QString , QString , QString , QString , QString , QString , QString , int, int , QString , QString , QString);
    bool chek_name_db(int,QString,int,QString,QString,int,QString,int);
    bool chek_db(QString, int, QString seva_adder_name);
    void addsevaname(int, QString, int, QString, QString, int , QString,int );
    void topersondetailsdb(QString , QString , QString , QString , QString , QString , QString , QString , QString , QString );
    bool chek_sevaname_allreadyexist(int , QString , int , QString , QString , int , QString , int );
    void seva_modification_testing(int, int, QString, int, QString, QString, int, QString, int, QString, QString );
    void combobox_sevatype();
    void getdata();
    void dbtable_view();
    void getpersondetails(QString);
    void getsevadetails(QString);
    void deletesevabookingentry(int);
    void getsevabookingmodifaing(int,int,int,int,int, QString,int,int ,int , QString);
    void table_view_forlast_ten_tran();
    void print_data_db(int seva_Type);
    void seva_type_adding();
    void seva_name_adding(int sevaT);
    void mobileNumberSearching(QString);
    void gotra_list();
    void Checking_sevacharge(QString);
    void receipt_no_printing();
    void booking_report_cdate_function(QString,QString,int);
    void booking_report_cmonth_function(QString,int,int,int);
    void booking_report_dataRange_function(QString,int,QString,QString);
    void account_report_cdate_function(QString, int, QString);
    void account_report_dataRange_function(QString,int,QString,QString);
    void account_report_cmonth_function(QString ,int ,int ,int );
    void signin_clicked(QString, QString, int);
    void old_password(QString l_userfirstname, QString l_userlastname);
    void add_new_signin_details(QString, QString, QString, QString, QString);
    QList<SigninDetails*> geting_signInDetails();
    void delete_selected_LoginDetails(QString);
    void modify_selected_LoginDetails(QString,QString,QString, QString, QString, QString);
    QStringList getMasterCredentials();
    void updateMasterCredentials(QString,QString,QString,QString);
//    QStringList bank_list();
    void bank_list();

private:
    explicit dbfile(QWidget *parent = nullptr);
    int val;
    int last_s_no;
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QString p_name,p_gotra, p_nakshtra, p_mobile,personid,p_sevaname,sevadate,note,que;
    int  quantity,prasada;
    int total_prasada=0;

};

#endif // DBFILE_H
