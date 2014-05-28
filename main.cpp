#include <QtGui/QApplication>
#include <QDebug>
#include <QtWebKit>
#include <QLibraryInfo>
#include <QTranslator>
#include "src/mainwindow.h"
#include "src/selectsql.h"
#include "src/login.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString locale = QLocale::system().name();
    QTranslator translator(0);
    if(translator.load("qt_"+locale, ":/i18n/"))
        a.installTranslator(&translator);
    else
        qDebug()<<"loading qm error";

    a.setApplicationName("MySqlServer");
    a.setApplicationVersion("1.0.0");
    a.setOrganizationName("Star");

    qDebug()<<QString::fromUtf8("主线程地址：")<<QThread::currentThread();

    MainWindow w;
    Login login(&w);
    SelectSql selectSql(&w,&login);

    QObject::connect(&w, SIGNAL(OpenDatabaseError(QString)), &login, SLOT(OpenDatabaseError(QString)));
    QObject::connect(&w, SIGNAL(OpenDatabaseOk()), &login, SLOT(OpenDatabaseOk()));

    selectSql.show();

    return a.exec();
}
