#ifndef CURRENTREPORT_H
#define CURRENTREPORT_H

#include <QWidget>
#include <QPushButton>
#include <QCalendarWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QDebug>
#include <QStandardItemModel>
#include <QRadioButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGroupBox>
#include <QDateTime>
#include <QMessageBox>
#include <QThread>
#include <QScreen>

#include"dbfile.h"

#define ALLSEVANAME "All"


class CurrentReport : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentReport(QWidget *parent = 0);
    QStandardItemModel* createModel(QObject*,QList<QString>,QList<int>,QList<float>,QList<float>,QString);
    void cdate_function();
    void cmonth_function();
    void dataRange_function();
    void retriveSevabookingDetails(QString file_name);
    void openFile(QFile *file);
    void reportBetweenDates();
    void reportMonthly();
    void DatewiseReport();
~CurrentReport();

signals:

public slots:
    void combo_type(int type);
    void calendar_receive(QDate);
    void Rbutton_cdate();
    void Rbutton_cmonth();
    void Rbutton_Rangedate();
    void submit_funtion();
    void combo_seva(QString);
    void combo_function(QList<QString>);
    void addingSevaname(QList<QString>);
    void month_wise(QList<QString>,QList<int>,QList<float>,QList<float>,QString);
    void date_range(QList<QString>,QList<int>,QList<float>,QList<float>,QString);
    void date_wise(QList<QString>,QList<int>,QList<float>,QList<float>,QString);
    void export_creport_csv();
    void export_booking_csv();
    void export_report_date_wise();
    void export_report_range();
    void export_report_month_wise();

private:
    QString calendar_str,formatchangedcalendar_str;
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QString st,st1,SEVA;
    bool startdate;
    int TYPE;
    int i_radio ;
    QPushButton *B_submit,*B_Dreport,*B_Mreport;
    QCalendarWidget *calendar;
    QHBoxLayout *hlayout8a,*hlayout8b,*hlayout8c,*hlayout8d,*hlayout9, *hor_main,*bot_main,*hlayout8e,*hlayout8f,*m_hboxtype,*m_hboxname;
    QVBoxLayout *vlayout8a,*vlayout8b,*vlayout8c,*ver_part1 ,*ver_part2, *ver_main,*vlayout8e;
    QTableView *view;
    QStandardItemModel *model;
    QLabel *lab,*da,*da1,*lab1,*m_selectSevaType,*m_selectSevaName;
    QLineEdit *line;
    QGroupBox *gro_left,*gro_right;
    QDate dateCheck ;
    QRadioButton *R_cdate,*R_cmonth,*R_bdate,*R_bmonth,*m_DataRange;
    QLineEdit *m_cdate,*m_StartDate,*m_EndDate;
    QComboBox *C_cmonth,*C_type,*C_seva,*C_year;
    QFont font;
    QPushButton *Export_c_xl, *summary, *report_date_wise, *report_month_wise, *report_range;
    QString total_amt;
    QSqlDatabase db;

};

#endif // CURRENTREPORT_H
