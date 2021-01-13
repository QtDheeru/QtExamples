#ifndef ADDNEWSEVA_H
#define ADDNEWSEVA_H
#include<QPainter>
#include<QPaintEvent>
#include <QObject>
#include <QWidget>
#include<QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpressionValidator>
#include <QGroupBox>
#include <QMessageBox>
#include <QCalendarWidget>
#include <QPixmap>
#include<QComboBox>
#include<QTimeEdit>
#include<QCheckBox>

#include"dbfile.h"
class addnewseva : public QWidget
{
    Q_OBJECT
public:
    explicit addnewseva(QWidget *parent = nullptr);
    QComboBox *type_seva;
    QHBoxLayout *hr1,*hr2,*hr3,*hr4,*hr5,*hr6,*hr7,*hr8,*hr9,*hr10;
    QVBoxLayout *vr1;
    QPushButton *m_add_SEVA,*m_modify_SEVA,*m_get_SEVA,*m_delete_SEVA;
    QLabel *head,*type,*name,*cost,*date,*p_name,*m_prasadalabel,*m_time,*m_skp_pooja;
    QLineEdit *m_name_seva,*m_cost,*p_sname,*m_prasadaedit;
    QPixmap *image;
    QCalendarWidget *calendar;
    QGroupBox *box1;
    QCheckBox *m_avilable,*m_notavilable;
    QTimeEdit *m_t_edit;
    void seva();
    void paintEvent(QPaintEvent *event)override;
    ~addnewseva();
signals:
    void get_data_db(QString,QString,QString,QString);
    void seva_add_db(int,QString,QString,int);
    void sevaName(int,QString,int,QString,QString,int,QString,int);

public slots:
    void sevaAdding();
    void sevaType(QString);
    void getdata_seva(int);
    void modify_seva(int,int,QString,QString,QString,QString);
    void modified_seva();
    void delete_seva();
    void user_name(QString);
    void checkboxpooja(int);
    void checkboxNopooja(int);
    void collectingSeva(QList<QString>);
private:
    int pooja=0;
    QString m_date;
    QString old_seva_type;
    QString str_date;
    QString poojatime;
    QString old_seva_name;
    QString old_seva_cost;
    int val;
    int new_sevarow;
    int seav_s_no;
};

#endif // ADDNEWSEVA_H
