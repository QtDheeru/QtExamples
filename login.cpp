#include "login.h"
static int TID;
int login::log_times = 0;
login::login(QWidget *parent) : QWidget(parent)
{
    log_times++;
    this->setObjectName("Login_object_"+QString::number(log_times));
    qDebug()<<"\n--------Object of login created-------"<<this->objectName();
    TID=0;
    temple =new Tempmange;
    type=0;
    line1 =new QLabel(tr("\n        SRIMAN MADHVA SANGHA\n\nRELIGIOUS AND CHARITABLE TRUST\n"));
    line1->setStyleSheet("QLabel {color : '#cc00cc' ;font: 15pt Times New Roman;}");
    //    line2 =new QLabel(tr(""));
    //    line2->setStyleSheet("QLabel {color : '#cc00cc' ;font: 15pt Times New Roman;}");
    m_username =new QLineEdit;
    m_username->setMinimumHeight(45);
    m_username->setStyleSheet("QLabel {color : '#fafafa' ;font: 15pt Times New Roman;border-style:outset;border-width:2p}");
    m_password =new QLineEdit;
    m_password->setMinimumHeight(45);
    m_password->setEchoMode(QLineEdit::Password);
    m_showcheckbox =new QCheckBox(tr("  SHOW PASSWORD"));
    m_signin =new QPushButton(tr("LOG IN"));
    m_register=new QPushButton(tr("SIGN UP/CREATE ACCOUNT"));
    m_forgotpassword =new QPushButton(tr("FORGOT PASSWORD"));
    m_signin->setMinimumHeight(45);
    m_register->setMinimumHeight(45);
    m_forgotpassword->setMinimumHeight(45);
    m_addOrModSignDetails =new QWidget;
    m_masterPasswordrecheck =new QWidget;
    m_masterPasswordModify =new QWidget;
    m_addRemoveCredentials =new QWidget;
    m_masterwigdet = new QWidget;
    m_signinscreen = new QWidget;
    m_tableViewWidget =new QWidget;

    qDebug()<<"\n--------Table View Object of login created-------"<<this->objectName();

    box = new QGroupBox;
    m_horijontal1 =new QHBoxLayout;
    m_horijontal2 =new QHBoxLayout;
    m_horijontal3 =new QHBoxLayout;
    m_horijontal4 =new QHBoxLayout;
    m_horijontal5 =new QHBoxLayout;
    m_horijontal6 =new QHBoxLayout;
    m_horijontal7 =new QHBoxLayout;
    m_horijontal8 =new QHBoxLayout;
    m_horijontal9 =new QHBoxLayout;
    m_verticle =new QVBoxLayout();

    m_horijontal1->addWidget(line1,0,Qt::AlignCenter);
    //m_horijontal2->addWidget(line2,0,Qt::AlignCenter);
    m_horijontal3->addWidget(m_username);
    m_username->setStyleSheet("background-color: #ffffff;border-style:outset;border-width:2px");
    m_username->setPlaceholderText("User Name");
    m_username->setFont(QFont("Times New Roman",m_username->height() * 0.05));
    m_password->setPlaceholderText("Password");
    m_password->setStyleSheet("background-color:#fffafa;border-style:outset;border-width:2px");
    m_horijontal4->addWidget(m_password);
    m_password->setFont(QFont("Times NEw Roman",m_password->height() * 0.05));
    m_horijontal5->addWidget(m_showcheckbox,0,Qt::AlignCenter);
    m_showcheckbox->setStyleSheet("QCheckBox::indicator { width:20px; height: 20px;} QCheckBox::indicator::checked /*{image: url(/home/jvdglind/Downloads/280px-PNG_transparency_demonstration_2.png);}*/");
    m_showcheckbox->setFont(QFont("Times NEw Roman",m_showcheckbox->height() * 0.03));
    m_horijontal6->addWidget(m_signin);
    m_signin->setFont(QFont("Times NEw Roman",m_signin->height() * 0.04));
    m_signin->setStyleSheet("background-color:#33cc33;border-width:4px");
    m_horijontal7->addWidget(m_register);
    m_register->setFont(QFont("Times NEw Roman",m_register->height() * 0.04));
    m_register->setStyleSheet("background-color:#cc33ff");

    m_horijontal8->addWidget(m_forgotpassword);
    m_forgotpassword->setStyleSheet("background-color:#ff0000");

    m_forgotpassword->setFont(QFont("Times NEw Roman",m_forgotpassword->height() * 0.04));
    m_horijontal8->setSpacing(5);
    m_verticle->addLayout(m_horijontal1);
    m_verticle->setSpacing(40);
    //m_verticle->addLayout(m_horijontal2);
    m_verticle->addLayout(m_horijontal3);
    m_verticle->addLayout(m_horijontal4);
    m_verticle->addLayout(m_horijontal5);
    m_verticle->addLayout(m_horijontal6);
    m_verticle->addLayout(m_horijontal7);
    m_verticle->addLayout(m_horijontal8);


    box->setMaximumSize(500,700);
    box->setStyleSheet("QGroupBox {border-radius:20px;background-color:'#66ffff';border-style:outset;border-width:3px}");
    box->setLayout(m_verticle);
    m_horijontal9->addWidget(box);
    this->setLayout(m_horijontal9);

    qDebug()<<"\n--------Object of login created before l_masterCredentials after box-------"<<this->objectName();


    QStringList l_masterCredentials = dbfile::getInstance()->getMasterCredentials();

    qDebug()<<"\n--------Object of login created clicked after mcred getMasterCredentials-------"<<this->objectName();

    qDebug()<<"\n--------Object of login created clicked after lmcred-------"<<this->objectName()<<"\n--------Object of login created just before signin clicked -------"<<this->objectName();

    connect(m_signin,SIGNAL(clicked()),this,SLOT(signin_clicked()));
    qDebug()<<"\n--------Object of login created after signin clicked-------"<<this->objectName();


    connect(m_forgotpassword,SIGNAL(clicked()),this,SLOT(forgot_password()));
    connect(m_showcheckbox,SIGNAL(clicked()),this,SLOT(show_Password()));

    qDebug()<<"\n--------Object of login created after show password clicked-------"<<this->objectName();

    masterUserName = l_masterCredentials[0];
    masterpassword =l_masterCredentials[1];

    m_masterusername= new QLineEdit;
    m_masterpassword= new QLineEdit;

    l_masterButt = new QPushButton("Login");
    l_closebut = new QPushButton("Close");
    m_masterusername->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;font-weight: bold;}");
    m_masterpassword->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;font-weight: bold;}");
    l_masterButt->setMaximumSize(480,40);
    l_masterButt->setStyleSheet("QPushButton {background-color : LIGHTBLUE;color:BLACK; font: 20pt Times New Roman;font-weight: bold;}");
    l_closebut->setMaximumSize(480,40);
    l_closebut->setStyleSheet("QPushButton {background-color : LIGHTBLUE;color:BLACK; font: 20pt Times New Roman;font-weight: bold;}");
    m_masterusername->setPlaceholderText(tr("Master User Name"));
    m_masterpassword->setPlaceholderText(tr("Master Password"));
    m_masterpassword->setEchoMode(QLineEdit::Password);
    l_mastervbox = new QVBoxLayout;
    l_masterhbox = new QHBoxLayout;
    l_mastergbox = new QGroupBox;
    l_mastergbox->setStyleSheet("QGroupBox {border-radius:10px;background-color:'#66ff66';border-style:outset;border-width:3px}");
    //qDebug()<<"###############"<<endl;

    master_login_clicked();

    qDebug()<<"\n--------Object of login created after l_masterCredentials clicked-------"<<this->objectName();

}

void login::master_login_clicked()
{
    l_mastervbox->addWidget(m_masterusername);
    l_mastervbox->addWidget(m_masterpassword);
    l_mastervbox->addWidget(l_masterButt);
    l_mastervbox->addWidget(l_closebut);
    l_mastergbox->setLayout(l_mastervbox);
    l_masterhbox->addWidget(l_mastergbox);
    l_mastergbox->setFixedSize(500,500);
    m_masterwigdet->setLayout(l_masterhbox);

    displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    m_masterwigdet->resize(width,height);

    connect(m_register,SIGNAL(clicked()),this,SLOT(masterLogin()));
}


void login::signin_clicked()
{
    qDebug()<<"\n--------Object of login created inside signin clicked-------"<<this->objectName();

    QString username= m_username->text();
    QString password= m_password->text();

    qDebug()<<"\n--------Object of login created inside signin after musr mpswd-------"<<this->objectName();

    dbfile::getInstance()->signin_clicked(username,password,type);

    qDebug()<<"\n--------Object of login created inside signin after db-------"<<this->objectName();

    m_username->clear();
    m_password->clear();
}

void login::forgot_password()
{
    QWidget *local =new QWidget;
    QHBoxLayout *l_h1,*l_h2,*l_h3;
    QVBoxLayout *l_v1;
    QLabel *l_label1 =new QLabel(tr("ENTER YOUR FIRST NAME"));
    l_label1->setStyleSheet("QLabel {color : '#e600ac' ;font: 20pt Times New Roman}");
    QLabel *l_label2 =new QLabel(tr("ENTER YOUR LAST NAME "));
    l_label2->setStyleSheet("QLabel {color : '#e600ac' ;font: 20pt Times New Roman}");
    l_h1=new QHBoxLayout;
    l_h2=new QHBoxLayout;
    l_h3=new QHBoxLayout;
    QPushButton *local3 =new QPushButton(tr("press"));
    local3->setFont(QFont("Times NEw Roman",local3->height() * 0.04));
    local3->setStyleSheet("background-color: #6600cc ;border-width:4px");
    l_h3=new QHBoxLayout;

    l_v1=new QVBoxLayout;
    l_lin1 =new QLineEdit;
    l_lin2 =new QLineEdit;

    l_lin1->setStyleSheet("QLineEdit {color : '#fafafa' ;font: 25pt Times New Roman;border-style:outset;border-width:2p}");
    l_lin1->setPlaceholderText("FIRST NAME");
    l_lin1->setFont(QFont("Times NEw Roman",l_lin1->height() * 0.05));
    l_lin2->setStyleSheet("QLineEdit {color : '#fafafa' ;font: 25pt Times New Roman;border-style:outset;border-width:2p}");
    l_lin2->setPlaceholderText("LAST NAME");
    l_lin2->setFont(QFont("Times NEw Roman",l_lin2->height() * 0.05));
    l_lin1->setStyleSheet("background-color:white");
    l_lin2->setStyleSheet("background-color:white");
    l_h1->addWidget(l_label1);
    l_h1->addWidget(l_lin1);
    l_h2->addWidget(l_label2);
    l_h2->addWidget(l_lin2);
    l_h3->addWidget(local3);
    l_v1->addLayout(l_h1);
    l_v1->addLayout(l_h2);
    l_v1->addLayout(l_h3);
    l_h1->setSpacing(5);
    local->setLayout(l_v1);
    local->show();
    local->setWindowTitle("FORGOT PASSWORD");
    connect(local3,SIGNAL(clicked()),this,SLOT(passwordverification()));

}


void login::show_old_password(QString l_username, QString l_password)
{
    QWidget *l_wid =new QWidget;
    QLabel *l_label1 =new QLabel(tr("USERNAME   :  "));
    l_label1->setStyleSheet("QLabel {color : '#ff0080' ;font: 20pt Times New Roman}");
    QLabel *l_label2 =new QLabel("");
    l_label2->setStyleSheet("QLabel {color : '#527a7a' ;font: 20pt Times New Roman}");
    QLabel *l_label3 =new QLabel(tr("PASSWORD    :   "));
    l_label3->setStyleSheet("QLabel {color : '#ff0080' ;font: 19.8pt Times New Roman}");
    QLabel *l_label4 =new QLabel("");
    l_label4->setStyleSheet("QLabel {color : '#527a7a' ;font: 20pt Times New Roman}");

    QHBoxLayout *l_hbox1,*l_hbox2;
    QVBoxLayout *l_vbox1;
    l_label2->setText(l_username);
    l_label4->setText(l_password);
    l_hbox1 =new QHBoxLayout;
    l_hbox2 =new QHBoxLayout;
    l_vbox1 =new QVBoxLayout;
    l_hbox1->addWidget(l_label1);
    l_hbox1->addWidget(l_label2);
    l_hbox2->addWidget(l_label3);
    l_hbox2->addWidget(l_label4);
    l_vbox1->addLayout(l_hbox1);
    l_vbox1->addLayout(l_hbox2);
    l_wid->setLayout(l_vbox1);
    l_wid->show();

}


void login::show_Password()
{

    if(m_showcheckbox->isChecked())
    {
        m_password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        m_password->setEchoMode(QLineEdit::Password);
    }
    qDebug()<<Q_FUNC_INFO<<"show password"<<endl;
}

void login::signinscreen()
{
    this->setDisabled(true);
    m_calendar =new QCalendarWidget;
    m_calendar->setMaximumSize(500,400);
    image = new QPixmap("cal1.png");
    date = new mylabel(this);
    date->setPixmap(image->scaled(50,50));
    date->setVisible(true);
    //    date->setMaximumSize(50,50);
    QPushButton *p_getstarted=new QPushButton(tr("GET STARTED"));
    QPushButton *p_close=new QPushButton(tr("Close"));
    p_close->setStyleSheet("QPushButton {background-color : BLUE;color:BLACK; font: 18pt Times New Roman;}");

    QHBoxLayout *p_horijontal1,*p_horijontal2,*p_horijontal3,*p_horijontal4,*p_horijontal5,*p_horijontal6,*p_horijontal7;
    QVBoxLayout *p_verticle;
    QString p_passwordstring;

    p_date =new QLabel(tr("Date"));
    p_date->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");

    p_firstname =new QLineEdit;
    p_lastname =new QLineEdit;
    p_usernameedit =new QLineEdit;
    p_password =new QLineEdit;
    p_dateedit =new QLineEdit;

    p_firstname->setPlaceholderText(tr("FIRST NAME"));
    p_firstname->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;}");
    p_lastname->setPlaceholderText(tr("LAST NAME"));
    p_lastname->setStyleSheet("QLineEdit {color : '#0080ff';font: 20pt Times New Roman;}");
    p_usernameedit->setPlaceholderText(tr("USER NAME"));
    p_usernameedit->setStyleSheet("QLineEdit {color : '#cc66ff';font: 20pt Times New Roman;}");
    p_password->setPlaceholderText(tr("PASS WORD"));
    p_password->setStyleSheet("QLineEdit {color : '#ff0000';font: 20pt Times New Roman;}");
    p_getstarted->setMaximumSize(480,50);
    p_getstarted->setStyleSheet("QPushButton {background-color : BLUE;color:BLACK; font: 13pt Times New Roman;}");
    p_dateedit->setText(m_calendar->selectedDate().toString("dd-MM-yyyy"));
    p_dateedit->setStyleSheet("QLineEdit {color : '#000000' ;font: 15pt Times New Roman}");
    p_box = new QGroupBox;
    p_horijontal1 =new QHBoxLayout;
    p_horijontal2 =new QHBoxLayout;
    p_horijontal3 =new QHBoxLayout;
    p_horijontal4 =new QHBoxLayout;
    p_horijontal5 =new QHBoxLayout;
    p_horijontal6 =new QHBoxLayout;
    p_horijontal7 =new QHBoxLayout;

    p_verticle =new QVBoxLayout();
    p_horijontal1->addWidget(p_firstname);
    p_horijontal2->addWidget(p_lastname);
    p_horijontal3->addWidget(p_usernameedit);
    p_horijontal4->addWidget(p_password);
    p_horijontal5->addWidget(p_date,0,Qt::AlignLeft);
    p_horijontal5->addWidget(p_dateedit,0,Qt::AlignRight);
    p_horijontal5->addWidget(date,0,Qt::AlignRight);

    p_horijontal6->addWidget(p_getstarted);
    p_horijontal6->addWidget(p_close);
    p_verticle->addLayout(p_horijontal1);
    p_verticle->setSpacing(25);
    p_verticle->addLayout(p_horijontal2);
    p_verticle->addLayout(p_horijontal3);
    p_verticle->addLayout(p_horijontal4);
    p_verticle->addLayout(p_horijontal5);
    p_verticle->addLayout(p_horijontal6);
    p_box->setStyleSheet("QGroupBox {border-radius:10px;background-color:'#66ff66';border-style:outset;border-width:3px}");
    p_box->setLayout(p_verticle);
    p_box->setFixedSize(450,500);
    p_horijontal7->addWidget(p_box);
    m_signinscreen->setLayout(p_horijontal7);
    QScreen *displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    m_signinscreen->resize(width,height);
    m_signinscreen->show();
    connect(date,SIGNAL(mylabelclicked()),this,SLOT(calendar_popup()));
    connect(m_calendar,SIGNAL(clicked(QDate)),this,SLOT(calendar_hide()));
    connect(p_getstarted,SIGNAL(clicked()),this,SLOT(userdetails()));
    connect(p_close,SIGNAL(clicked()),this,SLOT(closeAddCredentialsWindow()));

    this->setDisabled(false);

}


void login::paintEvent(QPaintEvent *event)
{
    //qDebug()<<Q_FUNC_INFO<<event<<endl;
    //    pen.setWidth(10);//    QRect rect = this->rect();
    //    QPainter painter(this);
    //    QPen pen;
    //        pen.setColor(QColor(5, 3, 13));
    //    painter.setPen(pen);
    //    painter.setBrush(QColor("#66b3ff"));
    //    painter.drawRect(rect);
}
void login::calendar_popup()
{
    m_calendar->setVisible(true);
    m_calendar->setGeometry(600,500,500,400);
    m_calendar->show();
    //qDebug()<<"---------------"<<endl;
}
void login::calendar_hide()
{
    QString seva_d =m_calendar->selectedDate().toString("dd-MM-yyyy");
    p_dateedit->setText(seva_d);
    m_calendar->hide();
}

void login::userdetails()
{
    QString fname=p_firstname->text();
    int size_fname=fname.size();
    QString lname=p_lastname->text();
    int size_lname=lname.size();
    QString username=p_usernameedit->text();
    int size_username=username.size();
    QString password=p_password->text();
    int size_password=password.size();
    QString date=p_dateedit->text();
    int size_date= date.size();
    QMessageBox msgbox;
    if(size_fname==0||size_lname==0||size_username==0||size_password==0||size_date==0){
        qWarning() << Q_FUNC_INFO << " Seva Type not found... Serious" <<endl;
        msgbox.setText(tr("PLEASE ENTER THE ALL FIELDS"));
        msgbox.exec();
        return;
    }
    qDebug()<<fname<<lname<<username<<password<<date;
    dbfile::getInstance()->add_new_signin_details(fname,lname,username,password,date);
}

void login::onlylogin()
{
    qDebug()<<Q_FUNC_INFO<<"++++++++++++++++++Login object name inside onlylogin(): "<<this->objectName()<<"+++++++++++\n";
    m_username->clear();
    m_password->clear();
    m_register->setVisible(false);
    type=1;
    this->show();
    this->setGeometry(0,40,this->width(),this->height()-40);
    this->setWindowTitle("LOGIN");
}

void login::passwordverification()
{
    l_userfirstname = l_lin1->text();
    l_userlastname = l_lin2->text();
    dbfile::getInstance()->old_password(l_userfirstname,l_userlastname);
}

void login::to_temp_manage(QString Last_name)
{
    temple->t_mange(Last_name);
}

void login::added_successfully()
{
    QMessageBox msgbox;
    msgbox.setText(tr("Person details added successfully "));
    msgbox.exec();
    p_box->close();
    this->setDisabled(false);
    return;
}

void login::screenVisibleFalse()
{
    qDebug()<<Q_FUNC_INFO<<"............. Login object name is:.............. "<<this->objectName()<<endl;
    this->setVisible(false);
}

void login::masterLogin()
{
    qDebug()<<"\n\n!@#$%^&*------Login Object------in master--------!@#$%^&*\n\n"<<this->objectName()<<endl;
    m_masterwigdet->show();
    connect(l_masterButt,SIGNAL(clicked()),this,SLOT(verifyMasterUsernameAndPassword()), Qt::UniqueConnection);
    connect(l_closebut,SIGNAL(clicked()),this,SLOT(closeMasterLoginWindow()), Qt::UniqueConnection);

}

void login::verifyMasterUsernameAndPassword()
{
    lineEditUsername=m_masterusername->text();
    lineEditPassword=m_masterpassword->text();
    if(lineEditUsername==masterUserName && lineEditPassword==masterpassword)
    {
        qDebug()<<"Entered User name: "<<lineEditUsername<<",actual User name: "<<masterUserName<<endl;
        qDebug()<<"Entered Password: "<<lineEditPassword<<",actual Psswd: "<<masterpassword<<endl;

        m_masterwigdet->setVisible(false);
        m_masterusername->clear();
        m_masterpassword->clear();

        this->chooseAddorDelete();
    }
    else
    {
        qDebug()<<"Entered User name: "<<lineEditUsername<<",actual User name: "<<masterUserName<<endl;
        qDebug()<<"Entered Password: "<<lineEditPassword<<",actual Psswd: "<<masterpassword<<endl;        QMessageBox msgBox;
        msgBox.setText(tr("Please enter a valid User Name And Password"));
        msgBox.setWindowTitle("Error");
        m_masterusername->clear();
        m_masterpassword->clear();
        msgBox.exec();
        m_masterwigdet->close();
        return;
    }
}

void login::chooseAddorDelete()
{

    QPushButton *l_addButt =new QPushButton("Add");
    l_addButt->setMaximumSize(510,50);
    l_addButt->setStyleSheet("QPushButton {background-color : LIGHTGREEN;color:BLACK; font: 18pt Times New Roman;font-weight: bold;}");
    QPushButton *l_deleteButt =new QPushButton("Delete/Modify");
    l_deleteButt->setMaximumSize(510,50);
    l_deleteButt->setStyleSheet("QPushButton {background-color : LIGHTGREEN;color:BLACK; font: 18pt Times New Roman;font-weight: bold;}");
    QPushButton *l_ModifyMasterUserNamePassword =new QPushButton("Modify Master Username And Password");
    l_ModifyMasterUserNamePassword->setMaximumSize(510,50);
    l_ModifyMasterUserNamePassword->setStyleSheet("QPushButton {background-color : LIGHTGREEN;color:BLACK; font: 18pt Times New Roman;font-weight: bold;}");
    QPushButton *l_modbutclose =new QPushButton("Close");
    l_modbutclose->setMaximumSize(510,50);
    l_modbutclose->setStyleSheet("QPushButton {background-color : LIGHTGREEN;color:BLACK; font: 18pt Times New Roman;font-weight: bold;}");
    QVBoxLayout *l_vbox=new QVBoxLayout;
    QGroupBox *l_gbox=new QGroupBox;
    QHBoxLayout *l_hbox=new QHBoxLayout;

    l_vbox->addWidget(l_addButt);
    l_vbox->addWidget(l_deleteButt);
    l_vbox->addWidget(l_ModifyMasterUserNamePassword);
    l_vbox->addWidget(l_modbutclose);
    l_gbox->setLayout(l_vbox);
    l_hbox->addWidget(l_gbox);
    m_addRemoveCredentials->setLayout(l_hbox);
    l_gbox->setFixedSize(550,500);
    l_gbox->setStyleSheet("QGroupBox {border-radius:10px;border-style:outset;border-width:3px;background-color : LIGHTPINK;}");

    QScreen *displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    m_addRemoveCredentials->resize(width,height);
    m_addRemoveCredentials->show();
    connect(l_addButt,SIGNAL(clicked()),this,SLOT(signinscreen()));
    connect(l_deleteButt,SIGNAL(clicked()),this,SLOT(tableView_signInDetils()));
    connect(l_ModifyMasterUserNamePassword,SIGNAL(clicked()),this,SLOT(modifyMasterPasswordAndUsername()));
    connect(l_modbutclose,SIGNAL(clicked()),this,SLOT(closeaddOrRemoveCredentialsWindow()));

}

void login::tableView_signInDetils()
{
    m_tableview =new QTableView;
    m_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_tableview->horizontalHeader()->setStretchLastSection(true);
    m_model=new QStandardItemModel;
    m_tableview->setModel(m_model);
    sinndetail = dbfile::getInstance()->geting_signInDetails();
    QGroupBox *gbox= new QGroupBox;
    QVBoxLayout *lvox1= new QVBoxLayout;
    QHBoxLayout *hbox2= new QHBoxLayout;
    QPushButton *l_closebut =new QPushButton("Close");
    l_closebut->setStyleSheet("QPushButton {background-color : BLUE;color:BLACK; font: 18pt Times New Roman;}");
    m_model->clear();
    m_model->setHorizontalHeaderLabels(QStringList()<<(tr(" Assets Name "))<<(tr(" Application Name for win "))<<(tr(" Application Name for mac ")));
    for(int i=0;i<sinndetail.size();i++)
    {
        int rownum =m_model->rowCount();
        QString value1 = QString("%1").arg(sinndetail[i]->firstName);
        QStandardItem *item1 = new QStandardItem(value1);
        item1->setFlags(item1->flags() &  ~Qt::ItemIsEditable);
        m_model->setItem(rownum, 0, item1);
        QString value2 = QString("%1").arg(sinndetail[i]->LastName);
        QStandardItem *item2 = new QStandardItem(value2);
        item2->setFlags(item2->flags() &  ~Qt::ItemIsEnabled);

        m_model->setItem(rownum, 1, item2);
        QString value3 = QString("%1").arg(sinndetail[i]->UserName);
        QStandardItem *item3 = new QStandardItem(value3);
        item3->setFlags(item3->flags() &  ~Qt::ItemIsEnabled);

        m_model->setItem(rownum, 2, item3);
        QString value4 = QString("%1").arg(sinndetail[i]->Password);
        QStandardItem *item4 = new QStandardItem(value4);
        m_model->setItem(rownum, 3, item4);
        item4->setFlags(item4->flags() &  ~Qt::ItemIsEnabled);

    }
    lvox1->addWidget(m_tableview);
    lvox1->addWidget(l_closebut);
    gbox->setLayout(lvox1);
    hbox2->addWidget(gbox);
    gbox->setFixedSize(700,700);
    QScreen *displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    m_tableViewWidget->resize(width,height);
    m_tableViewWidget->setLayout(hbox2);
    m_tableViewWidget->show();
    connect(m_tableview, SIGNAL(clicked(const QModelIndex &)),this, SLOT(onTableClicked(const QModelIndex &)));
    connect(l_closebut,SIGNAL(clicked()),this,SLOT(closeTableView()));


}

void login::onTableClicked(const QModelIndex &index)
{
    m_tableview->setEnabled(true);
    QString data =index.data().toString();
    QPushButton *l_modbutclose =new QPushButton("Close");
    l_modbutclose->setStyleSheet("QPushButton {color : '#ff6699';font: 20pt Times New Roman;}");
    QPushButton *l_modbutModify =new QPushButton("Modify");
    l_modbutModify->setStyleSheet("QPushButton {color : '#ff6699';font: 20pt Times New Roman;}");
    QPushButton *l_modbutDelete =new QPushButton("Delete");
    l_modbutDelete->setStyleSheet("QPushButton {color : '#ff6699';font: 20pt Times New Roman;}");

    for(int i=0;i<sinndetail.size();i++)
    {
        if(data==sinndetail[i]->firstName)
        {
            selectedPeersonNameOfSignInDetails=sinndetail[i]->firstName;
            m_firstNameLabel = new QLabel("First Name");
            m_firstNameLabel->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");
            m_LastNameLabel = new QLabel("Last Name");
            m_LastNameLabel->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");
            m_UserNameLabel = new QLabel("User Name");
            m_UserNameLabel->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");
            m_PasswordLabel = new QLabel("Password");
            m_PasswordLabel->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");


            m_firstNameEdit = new QLineEdit;
            m_firstNameEdit->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;}");
            m_firstNameEdit->setMaximumWidth(250);
            m_LastNameEdit = new QLineEdit;
            m_LastNameEdit->setMaximumWidth(250);
            m_LastNameEdit->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;}");
            m_UserNameEdit = new QLineEdit;
            m_UserNameEdit->setMaximumWidth(250);
            m_UserNameEdit->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;}");
            m_PasswordEdit = new QLineEdit;
            m_PasswordEdit->setMaximumWidth(250);
            m_PasswordEdit->setStyleSheet("QLineEdit {color : '#ff6699';font: 20pt Times New Roman;}");


            m_firstNameEdit->setText(sinndetail[i]->firstName);
            m_LastNameEdit->setText(sinndetail[i]->LastName);
            m_UserNameEdit->setText(sinndetail[i]->UserName);
            m_PasswordEdit->setText(sinndetail[i]->Password);
            QHBoxLayout *l_modhbox1 =new QHBoxLayout;
            QHBoxLayout *l_modhbox2 =new QHBoxLayout;
            QHBoxLayout *l_modhbox3 =new QHBoxLayout;
            QHBoxLayout *l_modhbox4 =new QHBoxLayout;
            QHBoxLayout *l_modhbox5 =new QHBoxLayout;
            QHBoxLayout *l_modhbox6 =new QHBoxLayout;
            QGroupBox *l_modhgox5 =new QGroupBox;


            QVBoxLayout *l_modvbox =new QVBoxLayout;
            l_modhbox1->addWidget(m_firstNameLabel);
            l_modhbox1->addWidget(m_firstNameEdit,Qt::AlignRight);
            l_modhbox2->addWidget(m_LastNameLabel);
            l_modhbox2->addWidget(m_LastNameEdit,Qt::AlignRight);
            l_modhbox3->addWidget(m_UserNameLabel);
            l_modhbox3->addWidget(m_UserNameEdit,Qt::AlignRight);
            l_modhbox4->addWidget(m_PasswordLabel);
            l_modhbox4->addWidget(m_PasswordEdit,Qt::AlignRight);
            l_modhbox5->addWidget(l_modbutDelete);
            l_modhbox5->addWidget(l_modbutModify);
            l_modhbox5->addWidget(l_modbutclose);
            l_modvbox->addLayout(l_modhbox1);
            l_modvbox->addLayout(l_modhbox2);
            l_modvbox->addLayout(l_modhbox3);
            l_modvbox->addLayout(l_modhbox4);
            l_modvbox->addLayout(l_modhbox5);

            l_modhgox5->setLayout(l_modvbox);
            l_modhgox5->setFixedSize(600,500);
            l_modhgox5->setStyleSheet("QGroupBox {border-radius:20px;background-color:'#66ffff';border-style:outset;border-width:3px}");

            l_modhbox6->addWidget(l_modhgox5);
            m_addOrModSignDetails->setLayout(l_modhbox6);

        }
    }
    m_tableview->setDisabled(true);
    QScreen *displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    m_addOrModSignDetails->resize(width,height);
    m_addOrModSignDetails->show();
    connect(l_modbutclose,SIGNAL(clicked()),this,SLOT(closeSigninDetailsScreen()));
    connect(l_modbutModify,SIGNAL(clicked()),this,SLOT(ModifySigninDetailsScreen()));
    connect(l_modbutDelete,SIGNAL(clicked()),this,SLOT(DeleteSigninDetailsScreen()));

}

void login::closeSigninDetailsScreen()
{
    m_tableview->setEnabled(true);
    this->m_addOrModSignDetails->close();
}

void login::ModifySigninDetailsScreen()
{
    QString l_FirstName =m_firstNameEdit->text();
    QString l_LastName=m_LastNameEdit->text();
    QString l_UserName=m_UserNameEdit->text();
    QString l_Password=m_PasswordEdit->text();
    QString date = QDate::currentDate().toString("dd-MM-yyyy");
    dbfile::getInstance()->modify_selected_LoginDetails(selectedPeersonNameOfSignInDetails,l_FirstName,l_LastName,l_UserName,l_Password,date);
    this-> tableView_signInDetils();
    m_tableview->setEnabled(true);
    this->closeSigninDetailsScreen();
    m_addOrModSignDetails->setVisible(false);
}

void login::DeleteSigninDetailsScreen()
{
    dbfile::getInstance()->delete_selected_LoginDetails(selectedPeersonNameOfSignInDetails);
    this-> tableView_signInDetils();
    m_tableview->setEnabled(true);
    m_addOrModSignDetails->setVisible(false);

}

void login::modifyMasterPasswordAndUsername()
{
    QMessageBox *l_mbox =new QMessageBox();
    l_mbox->setStandardButtons(QMessageBox::Yes);
    l_mbox->addButton(QMessageBox::Close);
    m_re_checkPassword=new QLineEdit;
    l_mbox->setText(tr("Aare you sure you want change the username and password"));
    l_mbox->show();
    int ret = l_mbox->exec();
    switch (ret) {
    case QMessageBox::Yes:
    {
        QLabel *l_label=new QLabel("Please re-enter the Password");
        l_label->setStyleSheet("QLabel {color : '#cc0066' ;font: 25pt Times New Roman;border-style:outset;border-width:2p}");

        QPushButton *l_pbtn =new QPushButton("OK");
        l_pbtn->setStyleSheet("QPushButton {background-color : BLUE;color:BLACK; font: 25pt Times New Roman;}");
        m_re_checkPassword->setStyleSheet("QLineEdit {color : '#cc0066' ;font: 25pt Times New Roman;border-style:outset;border-width:2p}");

        QVBoxLayout *lvbx =new QVBoxLayout;
        QHBoxLayout *lhbx =new QHBoxLayout;
        QGroupBox *lgbx =new QGroupBox;

        lvbx->addWidget(l_label,0,Qt::AlignCenter);
        lvbx->addWidget(m_re_checkPassword);
        lvbx->addWidget(l_pbtn);
        lvbx->setSpacing(15);
        lgbx->setLayout(lvbx);
        lhbx->addWidget(lgbx);
        lgbx->setStyleSheet("QGroupBox {border-radius:20px;background-color:'#66ffff';border-style:outset;border-width:3px}");
        m_masterPasswordrecheck->setLayout(lhbx);
        lgbx->setFixedSize(500,250);
        QScreen *displayscreensize = QGuiApplication::primaryScreen();
        QRect  screenGeometry = displayscreensize->geometry();
        int height = screenGeometry.height();
        int width = screenGeometry.width();
        m_masterPasswordrecheck->resize(width,height);
        m_masterPasswordrecheck->show();
        connect(l_pbtn,SIGNAL(clicked()),this,SLOT(verifyPasswordAgain()));

    }
        break;
    case QMessageBox::Close:
        exit;
        break;
    default:
        break;
    }

}

void login::verifyPasswordAgain()
{
    m_modifyedUsername=new QLineEdit;
    m_modifyedPassword=new QLineEdit;
    m_masterPasswordrecheck->setVisible(false);
    if(m_re_checkPassword->text()==masterpassword)
    {
        QLabel *l_label1=new QLabel("Master UserName");
        l_label1->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");

        QLabel *l_label2=new QLabel("Master Password");
        l_label2->setStyleSheet("QLabel {color : '#cc00cc' ;font: 20pt Times New Roman}");

        m_modifyedUsername->setText(masterUserName);
        m_modifyedUsername->setStyleSheet("QLineEdit {color : '#cc00cc' ;font: 20pt Times New Roman}");

        m_modifyedPassword->setText(masterpassword);
        m_modifyedPassword->setStyleSheet("QLineEdit {color : '#cc00cc' ;font: 20pt Times New Roman}");

        QPushButton *l_pbtn1 =new QPushButton("Modify");
        l_pbtn1->setStyleSheet("QPushButton {background-color : BLUE;color:BLACK; font: 25pt Times New Roman;}");

        QHBoxLayout *lhbx1 =new QHBoxLayout;
        QHBoxLayout *lhbx2 =new QHBoxLayout;
        QHBoxLayout *lhbx3 =new QHBoxLayout;
        QHBoxLayout *lhbx4 =new QHBoxLayout;
        QGroupBox *lgbx =new QGroupBox;

        QVBoxLayout *lvbx =new QVBoxLayout;

        lhbx1->addWidget(l_label1);
        lhbx1->addWidget(m_modifyedUsername);
        lhbx2->addWidget(l_label2);
        lhbx2->addWidget(m_modifyedPassword);
        lhbx3->addWidget(l_pbtn1);
        lvbx->addLayout(lhbx1);
        lvbx->addLayout(lhbx2);
        lvbx->addLayout(lhbx3);
        lgbx->setLayout(lvbx);
        lhbx4->addWidget(lgbx);
        lgbx->setFixedSize(500,500);
        lgbx->setStyleSheet("QGroupBox {border-radius:20px;background-color:'#8cff66';border-style:outset;border-width:3px}");


        QScreen *displayscreensize = QGuiApplication::primaryScreen();
        QRect  screenGeometry = displayscreensize->geometry();
        int height = screenGeometry.height();
        int width = screenGeometry.width();
        m_masterPasswordModify->resize(width,height);
        m_masterPasswordModify->setLayout(lhbx4);
        m_masterPasswordModify->show();
        connect(l_pbtn1,SIGNAL(clicked()),this,SLOT(modifyingMasterCredentials()));

    }
}

void login::modifyingMasterCredentials()
{
    QString date = QDate::currentDate().toString("dd-MM-yyyy");
    dbfile::getInstance()->updateMasterCredentials(masterUserName,m_modifyedUsername->text(),m_modifyedPassword->text(),date);
    m_masterPasswordModify->setVisible(false);
}

void login::closeaddOrRemoveCredentialsWindow()
{
    m_addRemoveCredentials->close();
}
void login::closeMasterLoginWindow()
{
    m_masterwigdet->close();
}

void login::closeAddCredentialsWindow()
{
    m_signinscreen->close();
}

void login::closeTableView()
{
    m_tableViewWidget->close();
}

login::~login()
{
    qDebug()<<"xxxxxxxxxxxxxxxLogin object destroyedxxxxxxxxxxxxxxxx "<<log_times--<<endl;
}

