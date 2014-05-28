#include "sqlservermanage.h"
#include <QDebug>
#include <QStringList>

SqlServerManage::SqlServerManage(QObject *parent) :
    QObject(parent)
{
    view = new QTableView();
    model = new QSqlQueryModel;
    view->setWindowTitle(QString::fromUtf8("查询结果--作者：雨后星辰"));
    //view->setMinimumSize();
    view->setGeometry(50,50,500,600);
}

void SqlServerManage::OpenDatabase(QString ServerName, QString DataBaseName, QString UserName, QString Password)
{
    qDebug()<<QString::fromUtf8("处理数据库线程地址：")<<QThread::currentThread();
    qDebug()<<db.drivers();
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                   "SERVER=%1;" //服务器名称
                                   "DATABASE=%2;"//数据库名
                                   "UID=%3;"           //登录名
                                   "PWD=%4;"        //密码
                               ).arg(ServerName)
                       .arg(DataBaseName)
                       .arg(UserName)
                       .arg(Password)
                           );
    bool is = db.open();

    if(!is) emit OpenDatabaseError(QString::fromUtf8("打开数据库出错：")+db.lastError().text());
    else emit OpenDatabaseOk();
}

QString SqlServerManage::RunCode(QString str)
{
    if(str.indexOf("select",0,Qt::CaseInsensitive)>=0)
    {
        model->setQuery(str);//这里直接设置SQL语句，忽略最后一个参数

        view->setModel(model);
        view->show();

        return model->lastError().text();
    }else{
        query = db.exec(str);
        return query.lastError().text();
    }
}

QString SqlServerManage::openSQLITEdatabase()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MYDATABASE");
    bool is = db.open();

    if(!is) return QString::fromUtf8("打开数据库出错：")+db.lastError().text();
    else return "";
}
