#ifndef FULLSEVATRANSACTIONDETAILS_H
#define FULLSEVATRANSACTIONDETAILS_H

#include <QObject>
#include <QWidget>
#include<QScreen>
#include <QTableView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
#include <mylabel.h>
#include <QGroupBox>
#include <QPushButton>
#include <QMessageBox>
#include"dbfile.h"
class fullSevaTransactionDetails : public QWidget
{
    Q_OBJECT
public:
    explicit fullSevaTransactionDetails(QWidget *parent = nullptr);
    QTableView *m_view;
    QHBoxLayout *hbox1,*hbox2,*hbox3,*hbox4,*hbox5,*hbox6,*hbox7,*hbox8,*hbox9,*hbox10,*hbox11,*hbox12,*hbox13,*hbox14,*hbox15;
    QVBoxLayout *vbox1,*vbox2,*vbox3;
    QLabel *m_mobilelabel,*m_namelabel,*m_sevachargeslabel,*m_additionalchargelabel,*m_countlabel,*m_naksathralabel,*m_gothralabel,*r_datelabel,*s_datelabel,*notelabel,*receiptnolabel,*m_typelabel,*m_type_user,*r_no,*seva_charge_label;
    QLineEdit *m_mobileedit,*m_nameedit,*m_sevachargesedit,*m_additionalchargeedit,*m_countedit,*r_dateedit,*s_dateedit,*noteedit;
    QStandardItemModel *m_model;
    QComboBox *m_nakshatracom,*m_gothracom;
    QCalendarWidget *calendarSeva,*calendarreceipt;
    QPushButton *m_delete,*m_modify,*m_back;
    QHBoxLayout *m_hbox;
    QPixmap *image,*image1;
    mylabel *s_date,*r_date;
    QGroupBox *box1,*box2;
    QWidget *w1,*w2;
    int row ;
    QSqlQueryModel *model_query;
    QTableView *view;
    ~fullSevaTransactionDetails();
signals:
    
public slots:
    
    void table_view(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    bool onTableClicked(const QModelIndex &index);
    void deletedata();
    void modifydata();
    void getpersondetails(QString,QString,QString,QString,QString,QString,QString);
    void backtoscreen();
    void delete_ofter();
    void getsevadetails(QString,int);
    void table_viewlastten(QList<QString> l_sno, QList<QString> l_person_id, QList<QString> l_sevatype, QList<QString> l_sevaname, QList<QString> l_quantity, QList<QString> l_s_date, QList<QString> l_s_month, QList<QString> l_s_year, QList<QString> l_sevadate, QList<QString> l_r_date, QList<QString> l_r_month, QList<QString> l_r_year, QList<QString> l_receiptdate, QList<QString> l_seva_cost, QList<QString> l_add_cost, QList<QString> l_total_cost, QList<QString> l_note);
private:
    QString m_id,m_person_name,m_gotra,m_nakshatra,m_date,m_mobile,m_email;
    QString m_sevaname;
    int m_sevacost;
    int sevacharge;
    QList<QString> list_nakshatra;
};

#endif // FULLSEVATRANSACTIONDETAILS_H
