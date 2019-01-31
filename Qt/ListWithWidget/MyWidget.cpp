#include "MyWidget.h"
#include "ui_MyWidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    for(int i=0;i<10;i++){
        qDebug() << Q_FUNC_INFO << endl;
        QListWidgetItem *item = new QListWidgetItem;
        item->setData(Qt::UserRole+1,i);
        QPushButton *b = new QPushButton(QString::number(i));
        b->setProperty("myrow",i);
        connect(b,SIGNAL(clicked(bool)),this,SLOT(callMe()));
        ui->listWidget->insertItem(i,item);
        ui->listWidget->setItemWidget(item,b);
    }
}

void MyWidget::callMe() {
   QPushButton *b = qobject_cast<QPushButton*>(this->sender());
   qDebug() << b->text() <<b->property("myrow") << endl;
   int r = b->property("myrow").toInt();
   qDebug() << r << endl;
   QListWidgetItem *it = ui->listWidget->item(r);
   qDebug() << " My Role =" << it->data(Qt::UserRole+1) << endl;
}

MyWidget::~MyWidget()
{
    delete ui;
}
