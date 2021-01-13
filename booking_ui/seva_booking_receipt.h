#ifndef SEVA_BOOKING_RECEIPT_H
#define SEVA_BOOKING_RECEIPT_H

#include <QWidget>
#include<QComboBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QModelIndex>
#include<QPushButton>
#include<QLineEdit>
#include<QDialog>
#include<QRegularExpressionValidator>
#include<QDebug>
#include<QLabel>
#include<QGroupBox>
#include<QCalendarWidget>
#include<QString>
#include <QMessageBox>
#include<QToolTip>
#include<QTimeEdit>
#include<QStringListModel>
#include <QCheckBox>

#include "common.h"
#include "dbfile.h"
#include"mylabel.h"
#include"printreceipt.h"
#include "print_file.h"
#include"fullsevatransactiondetails.h"
class seva_booking_receipt : public QWidget
{
    Q_OBJECT
public:
    explicit seva_booking_receipt(QWidget *parent = nullptr);
    QHBoxLayout *hbox1,*hbox2,*hbox3,*hbox4,*hbox5,*hbox6,*hbox7,*hbox8,*hbox9,*hbox10,*hbox11,*hbox12,*hbox13,*hbox14,*hbox15,*hbox16,*hbox17;
    QVBoxLayout *vbox1,*vbox2,*vbox3,*vbox4,*vbox5;
    QLineEdit *mobileedit,*nameedit,*sevachargesedit,*additionalchargeedit,*countedit,*r_dateedit,*s_dateedit,*noteedit;
    QLabel *mobilelabel,*namelabel,*sevachargeslabel,*additionalchargelabel,*countlabel,*naksathralabel,*gothralabel,*r_datelabel,*s_datelabel,*notelabel,*receiptnolabel,*typelabel,*type_user,*r_no,*m_time;
    QComboBox *nakshatracom,*gothracom,*bank_combo;
    QPushButton *m_submit,*m_clear,*m_next,*m_print,*m_addmore,*m_alldata,*m_delete,*m_modify,*m_lasttransaction,*m_submitaddmore;
    QPixmap *image,*image1,*p_image;
    QCalendarWidget *calendarSeva,*calendarreceipt;
    QGroupBox *box1,*box2,*box3;
    QTimeEdit *m_timeEdit;
    QLabel *seva_charge_label;

    QCheckBox *cheque_box, *cash_box;
    QLineEdit *cheque_line, *cash_line;

    mylabel *s_date,*r_date,*n_date,*s_type;
    print_file *RS_listPrint,*RS_single_print;
    printreceipt *print_res;
    //for summary
    QGroupBox *p_box;
    fullSevaTransactionDetails *full;
    ~seva_booking_receipt();

    QString NumberToWord(const unsigned int number);

signals:

public slots:
    void addBankList(QList<QString> Banks);
    void calendarSeva_popup();
    void calendarSeva_hide(QDate);
    void calendarreceipt_popup();
    void calendarreceipt_hide();
    void gettingdevotes_seva_details(QString);
    bool chek_persondetails_db_submit();
    void search(QString);
    void home();
    void addmore();
    void alldata();
    void printintdata();
    void printoption();
    void closeoption();
    void lasttransaction();
    void nextoption();
    void addmoresubmitted();
    void print_receipt();
    void addGotraList(QList<QString>);
    void mobile_num_there(QString,QString,QString,QString);
    void mobile_num_notthere();
    bool chek_persondetails_db_addmore();
    void fixed_sevacharge(int);
    void variable_sevacharge();
    void set_fixed_sevacharges(QString);
    void set_variable_sevacharges();
    void set_receipt_num(int);
    void change_state_box();
    void combo_state_changed();

private:
    int count;
    QString seva_name ;
    QString devoteSevacharge;
    int rspt_no;
    QList<QString> list_nakshatra;
    QString totalcost;
    QList<Print_Detail> *pd;
    Print_Detail seva_struct;

};
#endif // SEVA_BOOKING_receipt_H
