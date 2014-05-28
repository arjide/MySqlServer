#ifndef SELECTSQL_H
#define SELECTSQL_H

#include <QWidget>
#include "login.h"
#include "mainwindow.h"

namespace Ui {
class SelectSql;
}

class SelectSql : public QWidget
{
    Q_OBJECT
    
public:
    explicit SelectSql(MainWindow *w, Login *l, QWidget *parent = 0);
    ~SelectSql();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SelectSql *ui;

    MainWindow *mainwindow;
    Login *login;
};

#endif // SELECTSQL_H
