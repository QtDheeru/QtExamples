#ifndef TABLE_VIEW_SEVA_H
#define TABLE_VIEW_SEVA_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpressionValidator>
#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QHeaderView>
#include <QDate>
#include <QPaintEvent>
class table_view_seva : public QWidget
{
    Q_OBJECT
public:
    explicit table_view_seva(QWidget *parent = nullptr);
    QHBoxLayout *s_h1;
    QTableView *s_view;
    QStandardItemModel *s_model;
    void paintEvent(QPaintEvent *event)override;
~table_view_seva();
signals:
    void seva_resived(int,int,QString,QString,QString,QString);
public slots:
    void print_seva_data(int, QString, int, QString, QString, int,QString, int);
    bool chek_seva(int, QString, int, QString, QString, int,QString, int );
    bool onTableClicked(const QModelIndex &index);
    void modifaid_data_seva(int,int,QString,int,QString,QString,int,QString,int);
    void print_data_db( QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
private:
    int seva_num;
};

#endif // TABLE_VIEW_SEVA_H
