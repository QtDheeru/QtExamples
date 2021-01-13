#include "table_view_seva.h"
static int BID;


table_view_seva::table_view_seva(QWidget *parent) : QWidget(parent)
{
    BID=0;
    s_h1 =new QHBoxLayout;
    s_view=new QTableView;
    s_view->horizontalHeader()->setStretchLastSection(true);
    s_model =new QStandardItemModel;
    s_view->setVisible(true);
    s_view->resize(400,700);
    s_h1->addWidget(s_view);
    s_model=new QStandardItemModel( 0,3 );
    s_model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("SEVA NAME"))<<(tr("SEVA TYPE"))<<(tr("SEVA COST"))<<(tr("SEVA DATE"))<<(tr("PERSON_NAME"))<<(tr("PRASADA"))<<(tr("POOJA TIME"))<<(tr("POOJA")));
    this->setMaximumSize(900,400);
    this->setMinimumSize(425,190);
    s_view->setModel(s_model);
    connect(s_view, SIGNAL(clicked(const QModelIndex &)),this, SLOT(onTableClicked(const QModelIndex &)));
    this->setLayout(s_h1);
}

void table_view_seva::paintEvent(QPaintEvent *event)
{
    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(QColor(5, 3, 13));
    painter.setPen(pen);
    painter.setBrush(QColor("#006699"));
    painter.drawRect(rect);
}

void table_view_seva::print_seva_data(int seva_type , QString seva_name, int seva_cost,QString seva_date,QString seva_adder_name,int prasada,QString pooja_timeint,int pooja)
{
    //qDebug()<<"###################&&&&&&&&&&&&&&&&&&&&####################"<<endl;

    s_model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("SEVA NAME"))<<(tr("SEVA TYPE"))<<(tr("SEVA COST"))<<(tr("SEVA DATE"))<<(tr("PERSON_NAME"))<<(tr("PRASADA"))<<(tr("POOJA TIME"))<<(tr("POOJA")));
    int rownum =s_model->rowCount();
    QString value = QString("%1").arg(rownum+1);
    QStandardItem *item = new QStandardItem(value);
    s_model->setItem(rownum, 0, item);
    QString value1 = QString("%1").arg(seva_name);
    QStandardItem *item1 = new QStandardItem(value1);
    s_model->setItem(rownum, 1, item1);
    QString value2 = QString("%1").arg(seva_type);
    QStandardItem *item2 = new QStandardItem(value2);
    s_model->setItem(rownum, 2, item2);
    QString value3 = QString("%1").arg(seva_cost);
    QStandardItem *item3 = new QStandardItem(value3);
    s_model->setItem(rownum, 3, item3);
    QString value4 = QString("%1").arg(seva_date);
    QStandardItem *item4 = new QStandardItem(value4);
    s_model->setItem(rownum, 4, item4);
    QString value5 = QString("%1").arg(seva_adder_name);
    QStandardItem *item5 = new QStandardItem(value5);
    s_model->setItem(rownum, 5, item5);
    QString value6 = QString("%1").arg(prasada);
    QStandardItem *item6 = new QStandardItem(value6);
    s_model->setItem(rownum, 6, item6);
    QString value7 = QString("%1").arg(pooja_timeint);
    QStandardItem *item7 = new QStandardItem(value7);
    s_model->setItem(rownum, 7, item7);
    QString value8 = QString("%1").arg(pooja);
    QStandardItem *item8 = new QStandardItem(value8);
    s_model->setItem(rownum,8, item8);
}

bool table_view_seva::chek_seva(int seva_type , QString seva_name, int seva_cost,QString seva_date,QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    QMessageBox msgbox;
    int rowcount = s_model->rowCount();
    bool found = false;
    for(int i=0;i<rowcount;i++)
    {
        QStandardItem *item1 = s_model->item(i,0) ;
        int s_s = item1->text().toInt();
        QStandardItem *item2 = s_model->item(i,1) ;
        QString s_n = item2->text();
        QStandardItem *item3 = s_model->item(i,3) ;
        int s_c = item3->text().toInt();
        if((s_n==seva_name)||(s_c==seva_type))
        {
            found =true;
            break;
        }
    }
    if(!found){
        this->print_seva_data(seva_type,seva_name,seva_cost,seva_date,seva_adder_name,prasada,pooja_time,pooja);
    }
}

bool table_view_seva::onTableClicked(const QModelIndex &index)
{
    int row = index.row();
    int s_no = index.sibling(row, 0).data().toInt();
    QString seva_name = index.sibling(row, 1).data().toString();
    QString seva_type = index.sibling(row, 2).data().toString();
    QString seva_cost = index.sibling(row, 3).data().toString();
    QString seva_adder_name = index.sibling(row, 5).data().toString();
    qDebug()<<Q_FUNC_INFO<<s_no<<endl;
    qDebug()<<Q_FUNC_INFO<<seva_name<<endl;
    qDebug()<<Q_FUNC_INFO<<seva_type<<endl;
    qDebug()<<Q_FUNC_INFO<<seva_cost<<endl;

    emit seva_resived(row,s_no,seva_name,seva_type,seva_cost,seva_adder_name);
}


void table_view_seva::modifaid_data_seva(int sno, int row, QString new_seva_name, int new_seva_cost, QString date,QString modi_sevaaddername,int prasada,QString pooja_time,int pooja)
{
    qDebug()<<Q_FUNC_INFO<<sno<<endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_name<<endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_cost<<endl;
    QString value0 = QString("%1").arg(sno);
    QStandardItem *item = new QStandardItem(value0);
    s_model->setItem(row, 0, item);
    QString value1 = QString("%1").arg(new_seva_name);
    QStandardItem *item1 = new QStandardItem(value1);
    s_model->setItem(row, 1, item1);
    QString value3 = QString("%1").arg(new_seva_cost);
    QStandardItem *item3 = new QStandardItem(value3);
    s_model->setItem(row, 3, item3);
    QString value4 = QString("%1").arg(date);
    QStandardItem *item4 = new QStandardItem(value4);
    s_model->setItem(row, 4, item4);
    QString value5 = QString("%1").arg(modi_sevaaddername);
    QStandardItem *item5 = new QStandardItem(value5);
    s_model->setItem(row, 5, item5);
    QString value6 = QString("%1").arg(prasada);
    QStandardItem *item6 = new QStandardItem(value6);
    s_model->setItem(row, 6, item6);
    QString value7 = QString("%1").arg(pooja_time);
    QStandardItem *item7 = new QStandardItem(value7);
    s_model->setItem(row, 7, item7);
    QString value8 = QString("%1").arg(pooja);
    QStandardItem *item8 = new QStandardItem(value8);
    s_model->setItem(row,8, item8);
}
void table_view_seva::print_data_db(QList<QString>  list_s_no ,QList<QString> list_seva_name, QList<QString> list_seva_type, QList<QString> list_seva_cost, QList<QString> list_seva_date, QList<QString> list_seva_adder_name, QList<QString> list_prasada, QList<QString> list_pooja_time, QList<QString> list_pooja)
{
    int row,column;
   s_model->clear();
    s_model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("SEVA NAME"))<<(tr("SEVA TYPE"))<<(tr("SEVA COST"))<<(tr("SEVA DATE"))<<(tr("PERSON_NAME"))<<(tr("PRASADA"))<<(tr("POOJA TIME"))<<(tr("POOJA")));

    int size_list= list_seva_name.size();
    for (row =0; row < size_list; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            if(column == 0)
            {
                QString value1 = QString("%1").arg(list_s_no.at(row));
                QStandardItem *item1 = new QStandardItem(value1);
                s_model->setItem(row,column,item1);
            }
            if(column == 1)
            {
                QString value2 = QString("%1").arg(list_seva_name.at(row));
                QStandardItem *item2 = new QStandardItem(value2);
                s_model->setItem(row,column,item2);
            }
            if(column == 2)
            {
                QString value3 = QString("%1").arg(list_seva_type.at(row));
                QStandardItem *item3 = new QStandardItem(value3);
                s_model->setItem(row,column,item3);
            }
            if(column == 3)
            {
                QString value4 = QString("%1").arg(list_seva_cost.at(row));
                QStandardItem *item4 = new QStandardItem(value4);
                s_model->setItem(row,column,item4);
            }
            if(column == 4)
            {
                QString value5 = QString("%1").arg(list_seva_date.at(row));
                QStandardItem *item5 = new QStandardItem(value5);
                s_model->setItem(row,column,item5);
            }
            if(column == 5)
            {
                QString value6 = QString("%1").arg(list_seva_adder_name.at(row));
                QStandardItem *item6 = new QStandardItem(value6);
                s_model->setItem(row,column,item6);
            }
            if(column == 6)
            {
                QString value7 = QString("%1").arg(list_prasada.at(row));
                QStandardItem *item7 = new QStandardItem(value7);
                s_model->setItem(row,column,item7);
            }
            if(column == 7)
            {
                QString value8 = QString("%1").arg(list_pooja_time.at(row));
                QStandardItem *item8 = new QStandardItem(value8);
                s_model->setItem(row,column,item8);
            }
            if(column == 8)
            {
                QString value9 = QString("%1").arg(list_pooja.at(row));
                QStandardItem *item9 = new QStandardItem(value9);
                s_model->setItem(row,column,item9);
            }

        }
    }
}

table_view_seva::~table_view_seva()
{

}
