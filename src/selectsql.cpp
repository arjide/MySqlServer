#include "selectsql.h"
#include "ui_selectsql.h"

SelectSql::SelectSql(MainWindow *w, Login *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectSql)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromUtf8("选择SQL--作者：雨后星辰"));
    setFixedSize(320,240);

    mainwindow = w;
    login = l;
}

SelectSql::~SelectSql()
{
    delete ui;
}

void SelectSql::on_pushButton_clicked()
{
    close();
    login->loginServer();
}

void SelectSql::on_pushButton_2_clicked()
{
    QString restr = mainwindow->openSQLITEdatabase();
    if(restr != "")
    {
        ui->label->setText(restr);
    }else{
        close();
        mainwindow->show();
    }
}
