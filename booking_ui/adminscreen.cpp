#include "adminscreen.h"

adminScreen::adminScreen(QWidget *parent) : QWidget(parent)
{
    qDebug() << Q_FUNC_INFO << "SANjAy admin here" << endl;
    full = new fullSevaTransactionDetails;
    seva_booking = new seva_booking_receipt;
    qDebug() << Q_FUNC_INFO << "SANjAy admin after seva booking recpt object" << endl;
    seva =new seva_receipt;
    qDebug() << Q_FUNC_INFO << "SANjAy admin after seva recpt object" << endl;

    db = dbfile::getInstance();

    qDebug() << Q_FUNC_INFO << "SANjAy admin after db object" << endl;

    log =new login;

    qDebug() << Q_FUNC_INFO << "SANjAy admin after login object" << endl;

//    log->setObjectName("Login screen of admin");
    g_box =new QGroupBox;
    g_box1 =new QGroupBox;
    g_box2 =new QGroupBox;
//    g_box->setMaximumSize(1600,80);
//    g_box1->setMaximumSize(1600,1500);
    creport =new CurrentReport;
    breport =new bookingReport;
    w1 =new QWidget;
    alltype = new QComboBox;
    but1 = new QPushButton;
    but1->setIcon(QIcon("://Settings.png"));
    but1->setIconSize(QSize(50, 30));
    line1 =new QLabel(tr("SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST                                                                                                            "));
    line1->setStyleSheet("QLabel {color : '#f906bc' ;font: 20pt Times New Roman}");

    qDebug() << Q_FUNC_INFO << "SANjAy admin olage" << endl;

    list<<"SEVA BOOKING"<<"ADMIN"<<"ACCOUNT DETAILS"<<"BOOKING REPORT"<<"CLOSE PROJECT";
    alltype->addItems(list);
    alltype->setVisible(false);
    h1 =new QHBoxLayout;
    h2 =new QHBoxLayout;
    h3 =new QHBoxLayout;
    h4 =new QHBoxLayout;
    hbox1 =new QHBoxLayout;
    v1 =new QVBoxLayout;
    log->setVisible(false);
    creport->setVisible(false);
    breport->setVisible(false);
    h1->addWidget(but1,0,Qt::AlignLeft);
    h1->addWidget(alltype,Qt::AlignLeft);
    h1->addWidget(line1);
    g_box->setLayout(h1);
    h4->addWidget(g_box,0,Qt::AlignTop);
    hbox1->addWidget(seva);
    hbox1->addWidget(seva_booking);
    g_box2->setLayout(hbox1);
    h2->addWidget(g_box2);

    h2->addWidget(log);
    h2->addWidget(creport);
    h2->addWidget(breport);
    //    v1->addLayout(h4);
    v1->addLayout(h2);
    g_box1->setLayout(v1);
    h3->addWidget(g_box1);
    this->setLayout(h3);
    connect(but1,SIGNAL(clicked()),this,SLOT(buttonClicked()));
    connect(alltype,SIGNAL(currentIndexChanged(int)),this,SLOT(displaying_type(int)));
    connect(seva,SIGNAL(devotes_seva_details(QString)),seva_booking,SLOT(gettingdevotes_seva_details(QString)));
    connect(db,SIGNAL(gotraList(QList<QString>)),seva_booking,SLOT(addGotraList(QList<QString>)));

    connect(db,SIGNAL(bankList(QList<QString>)),seva_booking,SLOT(addBankList(QList<QString>)));

    connect(db,SIGNAL(seva_types_adding(QList<QString>)),seva,SLOT(sevatype_adding(QList<QString>)));
    connect(db,SIGNAL(sevaName(QList<QString>)),seva,SLOT(seva_name_adding(QList<QString>)));
    connect(db,SIGNAL(mob_num_there(QString,QString,QString,QString)),seva_booking,SLOT(mobile_num_there(QString,QString,QString,QString)));
    connect(db,SIGNAL(mob_num_Not_there()),seva_booking,SLOT(mobile_num_notthere()));
    connect(db,SIGNAL(fixed_sevacharge(int)),seva_booking,SLOT(fixed_sevacharge(int)));
    connect(db,SIGNAL(variable_sevacharge()),seva_booking,SLOT(variable_sevacharge()));
    connect(db,SIGNAL(setting_fixed_seva_charge(QString)),seva_booking,SLOT(set_fixed_sevacharges(QString)));
    connect(db,SIGNAL(variable_sevacharge()),seva_booking,SLOT(set_variable_sevacharges()));
    connect(db,SIGNAL(get_receiptnumber(int)),seva_booking,SLOT(set_receipt_num(int)));
    connect(db,SIGNAL(forlasttenDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>)),full,SLOT(table_viewlastten(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>)));
    connect(db,SIGNAL(forFUllDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>)),full,SLOT(table_view(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>)));
    connect(db,SIGNAL(persondetails(QString,QString,QString,QString,QString,QString,QString)),full,SLOT(getpersondetails(QString,QString,QString,QString,QString,QString,QString)));
    connect(db,SIGNAL(sevadetails(QString,int)),full,SLOT(getsevadetails(QString,int)));
    connect(db,SIGNAL(seva_types_adding(QList<QString>)),breport,SLOT(combo_function(QList<QString>)));
    connect(db,SIGNAL(sevaName(QList<QString>)),breport,SLOT(addingSevaname(QList<QString>)));
    connect(db,SIGNAL(seva_types_adding(QList<QString>)),creport,SLOT(combo_function(QList<QString>)));
    connect(db,SIGNAL(sevaName(QList<QString>)),creport,SLOT(addingSevaname(QList<QString>)));
    connect(db,SIGNAL(booking_report(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)),breport,SLOT(date_wise(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)));
    connect(db,SIGNAL(booking_report(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)),breport,SLOT(month_wise(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)));
    connect(db,SIGNAL(booking_report(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)),breport,SLOT(date_range(QList<QString>, QList<int>, QList<int>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)));
    connect(db,SIGNAL(account_report(QList<QString>,QList<int>,QList<float>,QList<float>,QString)),creport,SLOT(date_wise(QList<QString>,QList<int>,QList<float>,QList<float>,QString)));
    connect(db,SIGNAL(account_report(QList<QString>,QList<int>,QList<float>,QList<float>,QString)),creport,SLOT(month_wise(QList<QString>,QList<int>,QList<float>,QList<float>,QString)));
    connect(db,SIGNAL(account_report(QList<QString>,QList<int>,QList<float>,QList<float>,QString)),creport,SLOT(date_range(QList<QString>,QList<int>,QList<float>,QList<float>,QString)));
    connect(db,SIGNAL(correct_password(QString)),log,SLOT(to_temp_manage(QString)));
    connect(db,SIGNAL(show_username_password(QString,QString)),log,SLOT(show_old_password(QString,QString)));
    connect(db,SIGNAL(sucessfully_added()),log,SLOT(added_successfully()));

    qDebug() << Q_FUNC_INFO << "SANjAy admin last" << endl;
}

void adminScreen::buttonClicked()
{
    alltype->setVisible(true);
}

void adminScreen::displaying_type(int data)
{
    qDebug()<<data<<endl;
    enum print_receipt{SEVA_BOOKING=0,ACCOUNT_DETAILS,BOOKING_REPORT,ADMIN,CLOSE_PROJECT};

    switch (data)
    {
    case SEVA_BOOKING:
        g_box2->setVisible(true);
        log->setVisible(false);
        creport->setVisible(false);
        breport->setVisible(false);
        this->setWindowTitle("Seva Booking");
        this->show();
        break;
    case ACCOUNT_DETAILS:
        g_box2->setVisible(false);
        log->setVisible(false);
        creport->setVisible(true);
        breport->setVisible(false);
        this->setWindowTitle("Account Details");
        this->show();
        break;
    case BOOKING_REPORT:
        g_box2->setVisible(false);
        log->setVisible(false);
        creport->setVisible(false);
        breport->setVisible(true);
        this->setWindowTitle("Booking Report");
        this->show();
        break;

    case ADMIN:
        g_box2->setVisible(false);
        log->setVisible(true);
        creport->setVisible(false);
        this->setWindowTitle("Admin");
        breport->setVisible(false);
        this->show();

        break;
    case CLOSE_PROJECT:
        this->closingProgram();
        break;
    }
}

void adminScreen::closingProgram()
{
    QFont font;
    font.setPointSize(font.pointSize() + 7);
    QPalette palette;
    palette.setColor(QPalette::Background, (QColor("#ff66cc")));
    QMessageBox messageBox(QMessageBox::Question,tr("Are you sure? Do you want to close the project"),tr("Sure to quit?"),QMessageBox::Yes | QMessageBox::No,this);
    messageBox.setFont(font);
    messageBox.setButtonText(QMessageBox::Yes, tr("Yes"));
    messageBox.setButtonText(QMessageBox::No, tr("No"));
    messageBox.setText(tr("Are you sure? Do you want to close the project"));
    int ret = messageBox.exec();
    switch (ret) {
    case QMessageBox::No:
        // Save was clicked
        break;
    case QMessageBox::Yes:
        QApplication::quit();
        break;
    }
}

//void adminScreen::alldisplay()
//{
//    this->show();
//}

adminScreen::~adminScreen()
{

}
