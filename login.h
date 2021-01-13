#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include<QLineEdit>
#include<QPushButton>
#include<QCheckBox>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QColor>
#include<QLayout>
#include <QPixmap>
#include<QTextEdit>
#include<QGroupBox>
#include<QDebug>
#include"tempmange.h"
#include<QPalette>
#include"mylabel.h"
#include"common.h"
#include<dbfile.h>
#include<QCalendarWidget>
class login : public QWidget
{
    Q_OBJECT
public:
    explicit login(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~login();
    void master_login_clicked();
signals:
    void success();
    void masterCredentials(QString,QString);

public slots:
    void signin_clicked();
    void forgot_password();
    void show_old_password(QString,QString);
    void show_Password();
    void signinscreen();
    void calendar_popup();
    void calendar_hide();
    void userdetails();
    void onlylogin();
    void passwordverification();
    void to_temp_manage(QString);
    void added_successfully();
    void screenVisibleFalse();
    void masterLogin();
    void verifyMasterUsernameAndPassword();
    void chooseAddorDelete();
    void tableView_signInDetils();
    void onTableClicked(const QModelIndex &);
    void closeSigninDetailsScreen();
    void ModifySigninDetailsScreen();
    void DeleteSigninDetailsScreen();
    void modifyMasterPasswordAndUsername();
    void verifyPasswordAgain();
    void modifyingMasterCredentials();
    void  closeaddOrRemoveCredentialsWindow();
    void  closeMasterLoginWindow();
    void  closeAddCredentialsWindow();
    void closeTableView();

private :
    static int log_times;
    int type;
    QString l_userfirstname;
    QString l_userlastname;
    QString masterUserName;
    QString masterpassword;
    QString lineEditUsername;
    QString lineEditPassword;
    QWidget *m_masterwigdet,*m_addOrModSignDetails,*m_masterPasswordrecheck,*m_masterPasswordModify,*m_addRemoveCredentials,*m_signinscreen,*m_tableViewWidget;
    QLineEdit *m_username,*local2,*m_password,*p_firstname,*p_lastname,*p_usernameedit,*p_password,*p_dateedit, *m_re_checkPassword,*m_modifyedPassword,*m_modifyedUsername;
    QCheckBox *m_showcheckbox;
    QLabel *line1,*line2,*p_date,*m_firstNameLabel,*m_LastNameLabel,*m_UserNameLabel,*m_PasswordLabel;
    QPushButton *m_signin,*m_register,*m_forgotpassword;
    QHBoxLayout *m_horijontal1,*m_horijontal2,*m_horijontal3,*m_horijontal4,*m_horijontal5,*m_horijontal6,*m_horijontal7,*m_horijontal8,*m_horijontal9;
    QVBoxLayout *m_verticle;
    QBoxLayout *layout;
    QGroupBox *box,*p_box;
    Tempmange *temple;
    mylabel *date;
    QPixmap *image;
    QCalendarWidget *m_calendar;
    QTableView  *m_tableview;
    QStandardItemModel * m_model;
    QList<SigninDetails *> sinndetail;
    QLineEdit *l_lin1,*l_lin2,*m_masterusername,*m_masterpassword,*m_firstNameEdit,*m_LastNameEdit,*m_UserNameEdit,*m_PasswordEdit;
    QString selectedPeersonNameOfSignInDetails;

    QPushButton *l_masterButt, *l_closebut;
    QVBoxLayout *l_mastervbox;
    QHBoxLayout *l_masterhbox;
    QGroupBox *l_mastergbox;
    QScreen *displayscreensize;

};



#endif // LOGIN_H
