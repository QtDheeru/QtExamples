#ifndef PRINTRECEIPT_H
#define PRINTRECEIPT_H

#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QDebug>
#include<QHeaderView>
#include <QRegularExpressionValidator>
#include<QTableView>
#include<QStandardItemModel>
#include<QGroupBox>
#include<QTableView>

#include"hedder_screen.h"
class printreceipt : public QWidget
{
    Q_OBJECT
public:
    explicit printreceipt(QWidget *parent = nullptr);
    QHBoxLayout *b_hbox1,*b_hbox2,*b_hbox3,*b_hbox4;
    QHBoxLayout *f_hbox1,*f_hbox2,*f_hbox3,*f_hbox4,*f_hbox5;
    QHBoxLayout *m_hbox1,*m_hbox2,*m_hbox3,*m_hbox4,*m_hbox5,*m_hbox6,*m_hbox7,*m_hbox8,*m_hbox9,*m_hbox10;
    QHBoxLayout *m1_hbox2,*m1_hbox3,*m1_hbox4,*m1_hbox5,*m1_hbox6,*m1_hbox7,*m1_hbox8,*m1_hbox9,*m1_hbox10,*m1_hbox11;

    QVBoxLayout *m_vbox1,*m_vbox2,*m_vbox3,*m_vbox4;
    QLabel *m_Name,*m_user_name,*m_Total,*m_Totalvalue,*m_r_no,*m_r_noprint,*m_date,*m_dateprint,*m_gotra,*m_gotraprint,*m_nakshatra,*m_nakshatraprint,*m_mobile,*m_mobileprint,*m_sevadate,*m_sevatime,*m_sevatimePrint,*m_sevadateprint,*m_Note,*m_Notedetails,*m_trustName,*m_totalInWords,*m_totalInWordslabel,*m_rulesImage;
    QTableView *p_view;
    QStandardItemModel *p_model;
    QGroupBox *box1,*box2;
    hedder_screen *head;
    ~printreceipt();
signals:

public slots:
    void clear();
    void display(QString , QString , QString , QString , QString , QString , QString , int , int , QString, QString, QString, int, QString, QString);
    QString NumberToWord(const unsigned int number);
private:
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QPixmap *m_rulesPixmap;
    QString Note;
//    QList<Print_Detail*> pd;
};

#endif // PRINTRECEIPT_H
