#ifndef SEVA_RECEIPT_H
#define SEVA_RECEIPT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QListView>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColor>
#include <QLayout>
#include <QPixmap>
#include <QString>
#include <QTextEdit>
#include <QDebug>
#include <QStringListModel>
#include <QGroupBox>
#include <QStyledItemDelegate>

#include"dbfile.h"
#include"seva_booking_receipt.h"
class seva_receipt : public QWidget
{
    Q_OBJECT
public:
    explicit seva_receipt(QWidget *parent = nullptr);
    QLabel *sevatype,*sevaname;
    QComboBox *seva_type;
    QListView *seva_name;
    QHBoxLayout *hor1,*hor2,*hor3,*hor4;
    QGroupBox *box1,*box2;
    QVBoxLayout *mainver1,*ver1;
    QStringListModel *model;
    ~seva_receipt();
signals:
    void devotes_seva_details(QString);

public slots:
    void seva_name_adding(QList<QString> list_sevaType);
    void currentSelected(const QModelIndex &current);
    void sevatype_adding(QList<QString>);
    void sevanamegetting(int sevaT);

private:
    QStringList list;

};

#endif // SEVA_RECEIPT_H
