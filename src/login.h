#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSettings>
#include <QFuture>
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Login(MainWindow *w,  QWidget *parent = 0);
    ~Login();

    void loginServer();
    
private slots:
    void on_AutoLogin_toggled(bool checked);

    void on_RememberPassword_toggled(bool checked);

    void on_ServerName_textChanged(const QString &arg1);

    void on_DataBaseName_textChanged(const QString &arg1);

    void on_UserName_textChanged(const QString &arg1);

    void on_Password_textChanged(const QString &arg1);

    void on_LoginButton_clicked();

public slots:
    void OpenDatabaseError(QString errorString);
    void OpenDatabaseOk();

signals:

private:
    MainWindow *mainWindow;
    QSettings settings;
    Ui::Login *ui;

    void updataButtonOrCheckEnable();
};

#endif // LOGIN_H
