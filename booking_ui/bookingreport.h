#ifndef BOOKINGREPORT_H
#define BOOKINGREPORT_H

#include <QWidget>
#include <QCalendarWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QDebug>
#include <QStandardItemModel>
#include <QRadioButton>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QDateTime>
#include <QMessageBox>
#include <QThread>
#include<QPixmap>
#include<QPushButton>
#include <QLabel>
#include<QProgressBar>

#include"mylabel.h"
#include"dbfile.h"
#define ALLSEVANAME "All"
class bookingReport : public QWidget
{
    Q_OBJECT
public:
    explicit bookingReport(QWidget *parent = nullptr);
    QPushButton *printbutton;
    QCalendarWidget *calendar;
    QHBoxLayout *hlayout8a,*hlayout8b,*hlayout8c,*hlayout8d,*hlayout9, *hor_main,*bot_main,*hlayout8e,*hlayout8f,*m_hboxtype,*m_hboxname;
    QVBoxLayout *vlayout8a,*vlayout8b,*vlayout8c,*ver_part1 ,*ver_part2, *ver_main,*vlayout8e;
    QTableView *view;//,*t_view,*s_view;
    QStandardItemModel *model;//,*s_model,*t_model;
    QLabel *lab,*da,*da1,*lab1,*m_selectSevaType,*m_selectSevaName,*totalprasadaprint;
    QGroupBox *gro_left,*gro_right;
    QDate dateCheck ;
    QRadioButton *R_cdate,*R_cmonth,*R_bdate,*R_bmonth,*m_DataRange;
    QLineEdit *m_cdate,*m_StartDate,*m_EndDate;
    QComboBox *C_cmonth,*C_type,*C_seva,*C_year;
//    QComboBox *report;
    QFont font;
    QPixmap *p_image;
    mylabel *mylab;
    QGroupBox *p_box;
//    QLabel *l1;
    QProgressBar *p_bar;
    void cdate_function();
    void cmonth_function();
    void dataRange_function();
    void retriveSevabookingDetails(QString file_name);
    ~bookingReport();
signals:

public slots:
    void combo_type(int);
    void calendar_receive(QDate);
    void Rbutton_cdate();
    void Rbutton_cmonth();
    void Rbutton_Rangedate();
    void submit_funtion();
    QStandardItemModel* createModel(QObject*,QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
//    QStandardItemModel *createModel2(QObject*,QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
//    QStandardItemModel *createModel3(QObject*,QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
    void combo_function(QList<QString>);
    void printreceipt();
    void printoption();
    void closeoption();
    void sevaList();
    void prasadaList();
    //void selectReport(int);
    void selectReport();
    void printReport();
//    void progressbarShow(int value, int rowvalue);
    void addingSevaname(QList<QString>);
    void date_wise(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
    void month_wise(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString> list_note, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
    void date_range(QList<QString>,QList<int>,QList<int>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void export_booking_csv();
    void export_booking_report_csv();

private:
    QPushButton *report;
    //QList<QString> listReport;
    QList<QString> list_sevaname,list_sevadate,list_note;
    //QList<QString> list_name;
    QList<QString> list_pname,list_gotra,list_nakshatra,list_mobile;
    QList<int> list_prasada,list_quantity,list_totalamount;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QString calendar_str,formatchangedcalendar_str;
    QString st,st1,SEVA;
    int i_radio,TYPE;
    bool startdate;
    int total_prasada;
    int type;
    QSqlDatabase db;
    QPushButton *get_report;
};

#endif // BOOKINGREPORT_H
