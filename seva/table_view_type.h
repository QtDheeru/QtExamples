#ifndef table_view_type_H
#define table_view_type_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpressionValidator>
#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QHeaderView>
class table_view_type : public QWidget
{
    Q_OBJECT
public:
    explicit table_view_type(QWidget *parent = nullptr);
    QHBoxLayout *m_h1;
    QTableView *m_view;
    QStandardItemModel *model;
    void paintEvent(QPaintEvent *event)override;
    ~table_view_type();

signals:
    void resivedata(int,int,QString,QString,QString);
public slots:
    void print_data(QString, int,QString);
    bool chek(QString seva_type, int seva_code,QString);
    bool onTableClicked(const QModelIndex &index);
    void modifaid_data(int,int, QString, int,QString);
    void print_data_db(QString, QString, QString,QString);
};

#endif // table_view_type_H
