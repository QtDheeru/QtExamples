#include "seva_receipt.h"

seva_receipt::seva_receipt(QWidget *parent) : QWidget(parent)
{
    box1 = new  QGroupBox;
    box2 = new  QGroupBox;
    model = new QStringListModel();
    sevatype = new QLabel(tr("SEVATYPE"));
    sevatype->setStyleSheet("QLabel {color : '#0066ff' ;font: 25pt Times New Roman}");
    sevaname = new QLabel(tr("SEVANAME"));
    sevaname->setStyleSheet("QLabel {color : '#0066ff' ;font: 25pt Times New Roman}");
    seva_type = new QComboBox();
    seva_type->addItem("ALLSEVATYPE");
    QFont font;
    font.setPointSize(font.pointSize() + 5);
    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    seva_type->setItemDelegate(itemDelegate);
    seva_type->setFont(font);
    seva_type->setStyleSheet("QComboBox {color : '#cc00ff' ;font: 18pt Times New Roman ;selection-background-color:  #0066ff;selection-color: WHITE;}");
    seva_name = new QListView;
    seva_name->setStyleSheet("QListView {color : '#c613e4' ;font: 15pt Times New Roman;background:#ffffff;border-style:outset;border-width:2px}");
    seva_name->setFont(font);
    seva_name->setMaximumSize(300,600);
    //    QPixmap bkgnd("/home/avinash/Downloads/2.jpg");
    //    bkgnd = bkgnd.scaled(this->window()->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    //    palette.setBrush(QPalette::Window, bkgnd);
    //    QPalette pal = seva_type->view()->palette();
    //    pal.setBrush(QPalette::Base, Qt::transparent);
    //    seva_type->view()->setPalette(pal);
    //    if (seva_type->view()->parentWidget())
    //        seva_type->view()->setWindowOpacity(0);

    hor1 =new QHBoxLayout;
    hor2 =new QHBoxLayout;
    hor3 =new QHBoxLayout;
    hor4 =new QHBoxLayout;

    mainver1 = new QVBoxLayout;
    ver1 = new QVBoxLayout;
    //    this->setPalette(palette);
    hor1->addWidget(seva_type);
    hor2->addWidget(seva_name);
    ver1->addLayout(hor1);
    ver1->addLayout(hor2);
    hor3->addLayout(ver1);
    this->setLayout(hor3);
    connect(seva_type,SIGNAL(highlighted(int)),this,SLOT(sevanamegetting(int)));
    connect(seva_name, SIGNAL(clicked(const QModelIndex&)),this, SLOT(currentSelected(const QModelIndex &)));
}

void seva_receipt::sevatype_adding(QList<QString> list_sevaType)
{
    int size=list_sevaType.size();
    seva_type->clear();
    seva_type->addItem("--SELECT A SEVA--");

    for(int i=0;i<size;i++)
    {
        seva_type->addItem(list_sevaType.at(i));
    }
}

void seva_receipt::sevanamegetting(int sevaT)
{
    dbfile::getInstance()->seva_name_adding(sevaT);
}


void seva_receipt::seva_name_adding(QList<QString> list_sevaname)
{
    int size=list_sevaname.size();
    list.clear();
    for(int i=0;i<size;i++)
    {
        list.append(list_sevaname.at(i));
        model->setStringList(list);
        seva_name->setModel(model);
    }
}
void seva_receipt::currentSelected(const QModelIndex &current)
{
    QString data =(current.data().toString());
    emit devotes_seva_details(data);
}

seva_receipt::~seva_receipt()
{

}
