#include "seva_type.h"
static int SID;
static int BID;

seva_type::seva_type(QWidget *parent)
    : QWidget(parent)
{
    m_mainh1 = new QHBoxLayout;
    m_headlebal =new QLabel(tr("ADD SEVA TYPE"));
    m_headlebal->setStyleSheet("QLabel {/*background-color : silver*/;color : '#fafafa' ;font: 25pt Times New Roman}");

    m_sevatypelabel=new QLabel(tr("     *  SEVA TYPE"));
    m_sevatypelabel->setStyleSheet("QLabel {color:'#fafafa'; font: 18pt Times New Roman}");

    m_sevatypeline=new QLineEdit;
    m_sevatypeline->setStyleSheet("QLineEdit {font: 20pt Times New Roman}");

    s_addername=new QLabel(tr("     * USER NAME  "));
    s_addername->setStyleSheet("QLabel {color:'#fafafa'; font: 18pt Times New Roman}");

    m_sevatypeaddername=new QLineEdit;
    m_sevatypeaddername->setStyleSheet("QLineEdit {font:20pt Times New Roman}");

    m_sevacodelabel=new QLabel(tr("     *  SEVA CODE"));
    m_sevacodelabel->setStyleSheet("QLabel {color:'#fafafa'; font: 18pt Times New Roman}");

    //    m_sevatypeline->setStyleSheet("QLineEdit{ "
    //                                            "background-color:rgb(202, 255, 227);"
    //                                            "border: 2px solid gray;"
    //                                            "border-radius: 10px;"
    //                                            "padding: 0 10px;"
    //                                            "selection-background-color: darkgray;"
    //                                            "font-size: 16px;}"
    //                                            "QLineEdit:focus { "
    //                                            "background-color:rgb(192, 192, 255);}"
    //                                            );
    //    m_sevatypeline->setReadOnly(true);
    m_sevacodeline=new QLineEdit;
    m_sevacodeline->setStyleSheet("QLineEdit {font: 20pt Times New Roman}");

    m_add= new QPushButton(tr("ADD SEVA TYPE"));
    m_add->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_modify= new QPushButton(tr("   MODIFY   "));
    m_modify->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_getdata= new QPushButton(tr("   GETDATA   "));
    m_getdata->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_delete = new QPushButton(tr("DELETE SEVA TYPE"));
    m_delete->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 11pt Times New Roman}");
    m_h1 =new QHBoxLayout;
    m_h2 =new QHBoxLayout;
    m_h3 =new QHBoxLayout;
    m_h4 =new QHBoxLayout;
    m_h5 =new QHBoxLayout;
    m_h6 =new QHBoxLayout;

    m_v1 =new QVBoxLayout;
    m_h5->setSpacing(10);
    m_h1->addWidget(m_headlebal,25,Qt::AlignHCenter);
    m_h2->setSpacing(170);
    m_h2->addWidget(m_sevatypelabel);
    m_h2->addWidget(m_sevatypeline,0,Qt::AlignLeft);
    m_h3->addWidget(m_sevacodelabel);
    m_h3->setSpacing(170);
    m_h3->addWidget(m_sevacodeline,0,Qt::AlignLeft);
    m_h4->addWidget(s_addername);
    m_h4->setSpacing(170);
    m_h4->addWidget(m_sevatypeaddername,0,Qt::AlignLeft);
    m_h5->addWidget(m_add);
    m_h5->addWidget(m_modify);
    m_h5->addWidget(m_getdata);
    m_h5->addWidget(m_delete);
    m_v1->setSpacing(15);
    m_v1->addLayout(m_h1);
    m_v1->addLayout(m_h2,20);
    m_v1->addLayout(m_h3,1);
    m_v1->addLayout(m_h4,3);
    m_v1->addLayout(m_h5,5);
    box1= new QGroupBox;
    box1->setLayout(m_v1);
    m_h6->addWidget(box1);
    this->setMaximumSize(900,400);
    this->setMinimumSize(425,190);

    this->setLayout(m_h6);
//    QRegExp re1("^[a-zA-Z]+$");
//    m_sevatypeline->setValidator(new QRegExpValidator(re1));
    QRegExp re2("[0-9]{5}");
    m_sevacodeline->setValidator(new QRegExpValidator(re2));
    connect(m_add,SIGNAL(clicked()),this,SLOT(exceptdata()));
    connect(m_modify,SIGNAL(clicked()),this,SLOT(getModifiedData()));
    connect(m_getdata,SIGNAL(clicked()),this,SLOT(gettingSevaType()));
    connect(m_delete,SIGNAL(clicked()),this,SLOT(delete_data()));

}

void seva_type::paintEvent(QPaintEvent *event)
{
    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(QColor(0, 0, 0));
    painter.setPen(pen);
    painter.setBrush(QColor("#006699"));
    painter.drawRect(rect);
}



void seva_type::exceptdata()
{
    //qDebug()<<Q_FUNC_INFO<<endl;
    QString seva_type=m_sevatypeline->text();
    int seva_code = m_sevacodeline->text().toInt();
    QString sevatype_adder_name=m_sevatypeaddername->text();
    dbfile::getInstance()->chek_db(seva_type,seva_code,sevatype_adder_name);
    dbfile::getInstance()->getdata();
    m_sevatypeline->clear();
    m_sevacodeline->clear();

}
void seva_type::modifydata(int s_no,int row,QString seva_type,QString seva_code,QString seva_adder_name)
{
    old_seva_type=seva_type;
    old_seva_code=seva_code;
    m_sevatypeline->setText(seva_type);
    m_sevacodeline->setText(seva_code);
    m_sevatypeaddername->setText(seva_adder_name);
    new_row =row;
    m_s_no =s_no;
    dbfile::getInstance()->getdata();
    m_sevatypeline->clear();
    m_sevacodeline->clear();
}

void seva_type::getModifiedData()
{
    QString  new_seva_type=m_sevatypeline->text();
    int new_seva_code = m_sevacodeline->text().toInt();
    QString sevaadder_name =m_sevatypeaddername->text();
    int seva_type_size =new_seva_type.size();
    int sno = m_s_no;
    qDebug()<<Q_FUNC_INFO<<new_seva_type<<endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_code<<endl;
    qDebug()<<Q_FUNC_INFO<<sno<<endl;
    int r_s_no=sno;
    QString r_seva_name=new_seva_type;
    int r_seva_code=new_seva_code;
    QMessageBox msgbox;
    if((new_seva_code<0)||(seva_type_size<2))
    {
        msgbox.setText(tr("Please enter all fields"));
        msgbox.exec();
        return;
    }
    emit Modify_db(r_s_no,r_seva_name,r_seva_code,sevaadder_name,m_s_no,old_seva_type,old_seva_code);
    emit modified(sno,new_row,new_seva_type,new_seva_code,sevaadder_name);
}

void seva_type::delete_data()
{
    emit deletedata( m_s_no);
    dbfile::getInstance()->getdata();
    m_sevatypeline->clear();
    m_sevacodeline->clear();

}

void seva_type::user_name(QString username)
{
    m_sevatypeaddername->setText(username);
}

void seva_type::gettingSevaType()
{
    dbfile::getInstance()->getdata();
}

//void seva_type::addingseva() //remove this
//{
//       add->sevaAdding();
//}

seva_type::~seva_type()
{

}
