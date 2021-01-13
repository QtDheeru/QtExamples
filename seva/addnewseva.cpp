#include "addnewseva.h"
addnewseva::addnewseva(QWidget *parent) : QWidget(parent)
{
    hr1= new QHBoxLayout;
    hr2= new QHBoxLayout;
    hr3= new QHBoxLayout;
    hr4= new QHBoxLayout;
    hr5= new QHBoxLayout;
    hr6= new QHBoxLayout;
    hr7 =new QHBoxLayout;
    hr8 =new QHBoxLayout;
    hr9 =new QHBoxLayout;
    hr10 =new QHBoxLayout;
    vr1= new QVBoxLayout;
    image= new QPixmap("://cal1.png");
    calendar =new QCalendarWidget;
    p_name =new QLabel(tr("    * USER NAME"));
    p_name->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    m_prasadalabel =new QLabel(tr("    * THEERTHA PRASADA"));
    m_prasadalabel->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    m_prasadaedit =new QLineEdit;
    m_prasadaedit->setStyleSheet("QLineEdit {color:BLACK; font: 17pt Times New Roman}");
    m_prasadaedit->setText("0");
    p_sname =new QLineEdit;
    p_sname->setStyleSheet("QLineEdit {color:BLACK; font: 17pt Times New Roman}");
    head =new QLabel(tr("ADD NEW SEVA"));
    head->setStyleSheet("QLabel {color : '#fafafa' ;font: 22pt Times New Roman}");
    m_time =new QLabel(tr("    * POOJA TIME"));
    m_time->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    m_t_edit = new QTimeEdit(QTime::currentTime());
    m_t_edit->setMaximumWidth(310);
    m_t_edit->setMinimumHeight(30);
    m_t_edit->setStyleSheet("QTimeEdit {color : '#cc00ff' ;font: 17pt Times New Roman}");
    m_skp_pooja =new QLabel(tr("    * SANKALPA"));
    m_skp_pooja->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    m_avilable =new QCheckBox(tr("POOJA"));
    m_avilable->setStyleSheet("QCheckBox {color : 'White' ;font: 16pt Times New Roman}");
    m_notavilable=new QCheckBox(tr("NO POOJA"));
    m_notavilable->setStyleSheet("QCheckBox {color : 'White' ;font: 16pt Times New Roman}");
    type =new QLabel(tr("    * SEVA TYPE"));
    type->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    name =new QLabel(tr("    * SEVA NAME"));
    name->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    cost =new QLabel(tr("    * SEVA COST"));
    cost->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    date =new QLabel(tr("    *   DATE"));
    date->setStyleSheet("QLabel {color : '#fafafa' ;font: 17pt Times New Roman}");
    m_add_SEVA= new QPushButton(tr("ADD SEVA"));
    m_add_SEVA->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_modify_SEVA= new QPushButton(tr("MODIFY SEVA"));
    m_modify_SEVA->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_get_SEVA= new QPushButton(tr("GET SEVA"));
    m_get_SEVA->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_delete_SEVA = new QPushButton(tr("DELETE SEVA"));
    m_delete_SEVA->setStyleSheet("QPushButton {background-color : Gold;color:BLACK; font: 13pt Times New Roman}");
    m_cost= new QLineEdit;
    m_cost->setStyleSheet("QLineEdit {color:BLACK; font: 18pt Times New Roman}");

    type_seva =new QComboBox;
    type_seva->setStyleSheet("QComboBox {background-color : blue;color:BLACK; font: 16pt Times New Roman:}");
    m_name_seva= new QLineEdit;
    m_name_seva->setStyleSheet("QLineEdit {color:BLACK; font: 18pt Times New Roman}");
    box1= new QGroupBox;

    type_seva->clear();
    type_seva->addItem("ALLSEVATYPE");
    hr1->addWidget(head,0,Qt::AlignCenter);
    hr2->addWidget(type);
    hr2->setSpacing(180);
    hr2->addWidget(type_seva,0,Qt::AlignLeft);
    hr3->addWidget(name);
    hr3->setSpacing(180);
    hr3->addWidget(m_name_seva,0,Qt::AlignLeft);
    hr4->addWidget(cost);
    hr4->setSpacing(180);
    hr4->addWidget(m_cost,0,Qt::AlignLeft);
    hr5->addWidget(m_prasadalabel);
    hr5->setSpacing(180);
    hr5->addWidget(m_prasadaedit,0,Qt::AlignLeft);
    hr6->addWidget(p_name);
    hr6->setSpacing(180);
    hr6->addWidget(p_sname,0,Qt::AlignLeft);
    hr7->addWidget(m_skp_pooja);
    hr7->setSpacing(180);
    hr7->addWidget(m_avilable,0,Qt::AlignLeft);
    hr7->addWidget(m_notavilable,0,Qt::AlignRight);
    hr8->addWidget(m_time);
    hr8->addWidget(m_t_edit,0,Qt::AlignLeft);
    hr9->addWidget(m_add_SEVA);
    hr9->addWidget(m_modify_SEVA);
    hr9->addWidget(m_get_SEVA);
    hr9->addWidget(m_delete_SEVA);
    vr1->setSpacing(5);
    vr1->addLayout(hr1);
    vr1->addLayout(hr2);
    vr1->addLayout(hr3);
    vr1->addLayout(hr4);
    vr1->addLayout(hr5);
    vr1->addLayout(hr6);
    vr1->addLayout(hr7);
    vr1->addLayout(hr8);
    vr1->addLayout(hr9);
    box1->setLayout(vr1);
    hr10->addWidget(box1);
    this->setLayout(hr10);
    this->setMaximumSize(900,400);
    this->setMinimumSize(425,190);
    this->setLayout(vr1);
    QRegExp re1("^[a-zA-Z]+$");
    QRegExp re2("[0-9]{10}");
    m_cost->setValidator(new QRegExpValidator(re2));
    m_prasadaedit->setValidator(new QRegExpValidator(re2));
    connect(m_avilable,SIGNAL(stateChanged(int)),this,SLOT(checkboxpooja(int)));
    connect(m_notavilable,SIGNAL(stateChanged(int)),this,SLOT(checkboxNopooja(int)));
    connect(m_add_SEVA,SIGNAL(clicked()),this,SLOT(sevaAdding()));
    connect(type_seva,SIGNAL(highlighted(int)),this,SLOT(getdata_seva(int)));
    connect(m_modify_SEVA,SIGNAL(clicked()),this,SLOT(modified_seva()));
    connect(m_delete_SEVA,SIGNAL(clicked()),this,SLOT(delete_seva()));

}

void addnewseva::paintEvent(QPaintEvent *event)
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

void addnewseva::sevaAdding()
{
    bool sevaFound=false;
    str_date = calendar->selectedDate().toString("dd-MM-yyyy");
    int int_type = type_seva->currentIndex();
    QString sevaTypeName = type_seva->currentText();
    QString   seva_name = m_name_seva->text();
    QString seva_adder_name = p_sname->text();
    int  size_name = seva_name.size();
    int seva_cost =  m_cost->text().toInt();
    int prasada =m_prasadaedit->text().toInt();
    QMessageBox msgbox;
    if(size_name==0||m_cost->text().isEmpty()||str_date==0){
        qWarning() << Q_FUNC_INFO << " Seva Type not found... Serious!!" <<endl;
        msgbox.setText(tr("PLEASE ENTER ALL FIELDS "));
        msgbox.exec();
        return;
    }
    qDebug() << Q_FUNC_INFO << " Adding the new Seva Type under the SevaType =" << sevaTypeName<<endl;
    if(sevaTypeName=="ALLSEVATYPE")
    {
        sevaFound =true;
        msgbox.setText("PLEASE SELECT THE SEVA TYPE");
        msgbox.exec();
        return;
    }
    if((seva_name!=NULL)||(seva_cost!=0))
    {
        poojatime=m_t_edit->text();
        emit sevaName(int_type,seva_name,seva_cost,str_date,seva_adder_name,prasada,poojatime,pooja);
    }

    m_name_seva->clear();
    m_cost->clear();
    p_sname->clear();
}


void addnewseva::getdata_seva(int sevat)
{
    dbfile::getInstance()->print_data_db(sevat);
}
void addnewseva::modify_seva(int row, int s_no, QString seva_name, QString seva_type, QString seva_cost, QString seva_addeer_name)
{
    old_seva_name=seva_name;
    old_seva_cost=seva_cost;
    old_seva_type=seva_type;
    m_name_seva->setText(seva_name);
    m_cost->setText(seva_cost);
    p_sname->setText(seva_addeer_name);
    new_sevarow =row;
    seav_s_no =s_no;

}
void addnewseva::seva()
{
    dbfile::getInstance()->seva_type_adding();
}
void addnewseva::modified_seva()
{
    QString  new_seva_nmae=m_name_seva->text();
    int new_seva_cost = m_cost->text().toInt();
    QString new_date =calendar->selectedDate().toString("dd-MM-yyyy");
    int sno = seav_s_no;
    int modifaidpooja=pooja;
    int mod_theertha_prasada = m_prasadaedit->text().toInt();
    QString modifaid_ptime=m_t_edit->text();
    QString sevamodifairname=p_sname->text();
    dbfile::getInstance()->seva_modification_testing(sno,new_sevarow,new_seva_nmae,new_seva_cost,new_date,sevamodifairname,mod_theertha_prasada,modifaid_ptime,modifaidpooja,old_seva_name,old_seva_type);
}

void addnewseva::delete_seva()
{

    dbfile::getInstance()->delete_sevadb(old_seva_name,old_seva_type);
}

void addnewseva::sevaType(QString seva_t)
{
    type_seva->addItem(seva_t);
}


void addnewseva::user_name(QString username)
{
    p_sname->setText(username);
}

void addnewseva::checkboxpooja(int l_value)
{
    if(l_value==2)
    {
        m_notavilable->setCheckState(Qt::Unchecked);
        pooja=1;
        qDebug()<<l_value<<endl;
    }
}

void addnewseva::checkboxNopooja(int l_value)
{
    if(l_value==2)
    {
        m_avilable->setCheckState(Qt::Unchecked);
        pooja=0;
        qDebug()<<l_value<<endl;
    }
}

void addnewseva::collectingSeva(QList<QString> list_seva_name)
{
    int size=list_seva_name.size();
    type_seva->clear();
    type_seva->addItem("ALL SEVA TYPE");
    for(int i=0;i<size;i++)
    {
        type_seva->addItem(list_seva_name.at(i));
    }
}

addnewseva::~addnewseva()
{

}
