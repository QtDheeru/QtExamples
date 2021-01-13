#ifndef seva_type_H
#define seva_type_H

#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QRegularExpressionValidator>
#include <QTableView>
#include <QGroupBox>
#include <QStandardItemModel>
#include <QComboBox>
#include <QMessageBox>

#include "table_view_type.h"
#include"dbfile.h"
class seva_type : public QWidget
{
    Q_OBJECT

public:
    seva_type(QWidget *parent = 0);
    QHBoxLayout *m_mainh1,*m_mainh2;
    QLabel *m_headlebal,*m_sevatypelabel,*m_sevacodelabel,*s_addername;
    QLineEdit *m_sevatypeline,*m_sevacodeline,*m_sevatypeaddername;
    QPushButton *m_add,*m_modify,*m_getdata,*m_delete;
    QHBoxLayout *m_h1,*m_h2,*m_h3,*m_h4,*m_h5,*m_h6;
    QVBoxLayout *m_v1;
    QGroupBox *box1;
    void paintEvent(QPaintEvent *event)override;
   ~seva_type();
protected:
    int new_row;
    int m_s_no;
    QString SEVATYPE;
    int type = 1;
    QString old_seva_type;
    QString old_seva_code;
signals:
    void modified(int,int,QString,int,QString);
    void send_new_seva(int,QString,QString,float,int);
    void Modify_db(int,QString,int,QString,int,QString,QString);
    void deletedata(int);

public slots:
    void exceptdata();
    void modifydata(int,int, QString, QString,QString);
    void getModifiedData();
    void delete_data();
//    void addingseva(); //remove this
    void user_name(QString);
    void gettingSevaType();

};

#endif // seva_type_H
