#include "table_view_type.h"

table_view_type::table_view_type(QWidget *parent) : QWidget(parent)
{
    m_h1 =new QHBoxLayout;
    m_view=new QTableView;
    m_view->horizontalHeader()->setStretchLastSection(true);
    m_view->resizeColumnsToContents();
    m_view->setVisible(true);
    m_view->resize(400,700);
    model=new QStandardItemModel( 0,3 );
    model->setHorizontalHeaderLabels(QStringList()<<(tr("S NO"))<<(tr("SEVA TYPE"))<<(tr("SEVA CODE"))<<(tr("PERSON NAME")));
    m_view->setModel(model);    
    m_h1->addWidget(m_view);
    this->setMaximumSize(900,400);
    this->setMinimumSize(425,190);

    this->setLayout(m_h1);
    connect(m_view, SIGNAL(clicked(const QModelIndex &)),this, SLOT(onTableClicked(const QModelIndex &)));
}

void table_view_type::print_data(QString seva_type, int seva_code, QString seva_adder_name)
{
    int rownum =model->rowCount();
    QString value = QString("%1").arg(rownum);
    QStandardItem *item = new QStandardItem(value);
    model->setItem(rownum, 0, item);
    QString value1 = QString("%1").arg(seva_type);
    QStandardItem *item1 = new QStandardItem(value1);
    model->setItem(rownum, 1, item1);
    QString value2 = QString("%1").arg(seva_code);
    QStandardItem *item2 = new QStandardItem(value2);
    model->setItem(rownum, 2, item2);
    QString value3 = QString("%1").arg(seva_adder_name);
    QStandardItem *item3 = new QStandardItem(value3);
    model->setItem(rownum, 3, item3);
}

bool table_view_type::chek(QString seva_type, int seva_code, QString seva_adder_name)
{
    int rowcount = model->rowCount();
    bool found = false;
    for(int i=0;i<rowcount;i++)
    {
        QStandardItem *item1 = model->item(i,0) ;
        int s_s = item1->text().toInt();
        //qDebug()<<Q_FUNC_INFO<<"*******"<<i<<"*********"<<endl;
        QStandardItem *item2 = model->item(i,1) ;
        QString s_t = item2->text();

        QStandardItem *item3 = model->item(i,2) ;
        int s_c = item3->text().toInt();

        if((s_t==seva_type)||(s_c==seva_code))
        {
            found =true;
            break;
        }
    }

    if(!found){
        this->print_data(seva_type,seva_code,seva_adder_name);
    }
}

bool table_view_type::onTableClicked(const QModelIndex &index)
{
    int row = index.row();
    int s_no = index.sibling(row, 0).data().toInt();
    QString seva_type = index.sibling(row, 1).data().toString();
    QString seva_code = index.sibling(row, 2).data().toString();
    QString seva_adder_name = index.sibling(row, 3).data().toString();
    qDebug()<<Q_FUNC_INFO<<s_no<<endl;
    qDebug()<<Q_FUNC_INFO<<seva_type<<endl;
    qDebug()<<Q_FUNC_INFO<<seva_code<<endl;
    emit resivedata(s_no,row,seva_type,seva_code,seva_adder_name);
}

void table_view_type::modifaid_data(int sno,int row,QString new_seva_type,int new_seva_code,QString new_seva_adder_name)
{
    qDebug()<<Q_FUNC_INFO<<sno<<endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_type<<endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_code<<endl;

    QString value = QString("%1").arg(sno);
    QStandardItem *item = new QStandardItem(value);
    model->setItem(row, 0, item);
    QString value1 = QString("%1").arg(new_seva_type);
    QStandardItem *item1 = new QStandardItem(value1);
    model->setItem(row, 1, item1);
    QString value2 = QString("%1").arg(new_seva_code);
    QStandardItem *item2 = new QStandardItem(value2);
    model->setItem(row, 2, item2);
    QString value3 = QString("%1").arg(new_seva_adder_name);
    QStandardItem *item3 = new QStandardItem(value3);
    model->setItem(row, 3, item3);
}
void table_view_type::print_data_db(QString s_no, QString seva_type, QString seva_code, QString seva_adder_name)
{
    qDebug()<<Q_FUNC_INFO<<"*******"<<seva_adder_name<<"*********"<<endl;

    int rowcount = model->rowCount();
    bool found = false;
    for(int i=0;i<rowcount;i++)
    {
        QStandardItem *item2 = model->item(i,1) ;
        QString s_t = item2->text();
        QStandardItem *item3 = model->item(i,2) ;
        int s_c = item3->text().toInt();
        if((s_t==seva_type)||(s_c==seva_code))
        {
            found =true;
            break;
        }
    }
    if(!found){
        QStandardItem *item = new QStandardItem(s_no);
        model->setItem(rowcount, 0, item);
        QStandardItem *item1 = new QStandardItem(seva_type);
        model->setItem(rowcount, 1, item1);
        QStandardItem *item2 = new QStandardItem(seva_code);
        model->setItem(rowcount, 2, item2);
        QStandardItem *item3 = new QStandardItem(seva_adder_name);
        model->setItem(rowcount, 3, item3);
    }
}

void table_view_type::paintEvent(QPaintEvent *event)
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
table_view_type::~table_view_type()
{

}
