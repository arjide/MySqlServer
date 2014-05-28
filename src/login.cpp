#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(MainWindow *w, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    mainWindow = w;
    ui->setupUi(this);

    ui->Password->setEchoMode(QLineEdit::Password);


    setWindowTitle(QString::fromUtf8("登录SQL服务器--作者：雨后星辰"));
    setFixedSize(508,387);

    ui->ServerName->setText( settings.value("ServerName", "").toString() );
    ui->DataBaseName->setText( settings.value("DataBaseName", "").toString() );
    ui->UserName->setText( settings.value("UserName" ,"").toString() );

    ui->RememberPassword->setChecked(settings.value("RememberPassword",false).toBool());
    ui->AutoLogin->setChecked(settings.value("AutoLogin",false).toBool());

    if(ui->RememberPassword->isChecked())
        ui->Password->setText( settings.value("Password").toString() );

    updataButtonOrCheckEnable();
}

void Login::updataButtonOrCheckEnable()
{
    /*bool is = !(ui->ServerName->text()==""||ui->DataBaseName->text()==""||ui->UserName->text()==""||ui->Password->text()=="");
    ui->AutoLogin->setEnabled(is);
    ui->RememberPassword->setEnabled(is);
    ui->LoginButton->setEnabled(is);*/
}

Login::~Login()
{
    delete ui;
}

void Login::loginServer()
{
    if(ui->AutoLogin->isChecked())
    {
        mainWindow->loginServer(ui->ServerName->text(),ui->DataBaseName->text(),ui->UserName->text(),ui->Password->text());
    }else show();
}

void Login::on_AutoLogin_toggled(bool checked)
{
    if(checked)
        ui->RememberPassword->setChecked( checked );
}

void Login::on_RememberPassword_toggled(bool checked)
{
    settings.setValue("RememberPassword", checked);
    ui->AutoLogin->setChecked(checked&&ui->AutoLogin->isChecked());
}

void Login::on_ServerName_textChanged(const QString &arg1)
{
    //qDebug()<<arg1;
    settings.setValue("ServerName", arg1);
    //qDebug()<<settings.value("ServerName","no").toString();
    updataButtonOrCheckEnable();
}

void Login::on_DataBaseName_textChanged(const QString &arg1)
{
    settings.setValue("DataBaseName", arg1);
    updataButtonOrCheckEnable();
}

void Login::on_UserName_textChanged(const QString &arg1)
{
    settings.setValue("UserName", arg1);
    updataButtonOrCheckEnable();
}

void Login::on_Password_textChanged(const QString &arg1)
{
    settings.setValue("Password", arg1);
    updataButtonOrCheckEnable();
}

void Login::on_LoginButton_clicked()
{
    bool is = false;
    ui->AutoLogin->setEnabled(is);
    ui->RememberPassword->setEnabled(is);
    ui->ServerName->setEnabled(is);
    ui->DataBaseName->setEnabled(is);
    ui->UserName->setEnabled(is);
    ui->Password->setEnabled(is);
    ui->LoginButton->setEnabled(is);
    ui->showMessage->setText(QString::fromUtf8("登陆中......"));
    mainWindow->loginServer(ui->ServerName->text(),ui->DataBaseName->text(),ui->UserName->text(),ui->Password->text());
}

void Login::OpenDatabaseError(QString errorString)
{
    settings.setValue("AutoLogin", false);
    ui->showMessage->setText(errorString);

    bool is = true;
    ui->AutoLogin->setEnabled(is);
    ui->RememberPassword->setEnabled(is);
    ui->ServerName->setEnabled(is);
    ui->DataBaseName->setEnabled(is);
    ui->UserName->setEnabled(is);
    ui->Password->setEnabled(is);
    ui->LoginButton->setEnabled(is);
}

void Login::OpenDatabaseOk()
{
    settings.setValue("AutoLogin", ui->AutoLogin->isChecked());
    close();
    mainWindow->show();
}
