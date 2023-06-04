#include "networkapiclass.h"
#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    register_ptr = new RegisterPage();
    ui->usrname_warning_lbl->clear();
    ui->password_warning_lbl->clear();

}

LoginPage::~LoginPage()
{
    delete ui;
}



void LoginPage::on_Register_pbn_clicked()
{
    this->hide();
    register_ptr->show();
    register_ptr->exec();
    this->show();
}


void LoginPage::on_login_pbn_clicked()
{
    checkInput();
}

int LoginPage::checkInput()
{
    int loginGateUser = 0,loginGatePass = 0;
    ui->usrname_warning_lbl->clear();
    ui->password_warning_lbl->clear();
    QString user_name = ui->username_led->text();
    QString pass_word = ui->password_led->text();
    if(user_name.isEmpty())
    {
        ui->usrname_warning_lbl->setText("<!> Username box is Empty");
        loginGateUser = 1;
    }
    if(pass_word.isEmpty())
    {
        ui->password_warning_lbl->setText("<!> Password box is Empty");
        loginGatePass = 1;
    }
    if(!loginGateUser && !loginGatePass){
        QThread* threadSignIn = new networkApiClass(user_name,pass_word,"login");
        threadSignIn->start();
    }
    // ANGOOLAK ENTERED
}

