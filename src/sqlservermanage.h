#ifndef SQLSERVERMANAGE_H
#define SQLSERVERMANAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QThread>

class SqlServerManage : public QObject
{
    Q_OBJECT
private:
    QSqlQuery query;
    QTableView *view;
    QSqlQueryModel *model;
    QSqlDatabase db;
public:
    explicit SqlServerManage(QObject *parent = 0);

    QString RunCode(QString);

    QString openSQLITEdatabase();
signals:
    void OpenDatabaseError(QString errorString);
    void OpenDatabaseOk();
public slots:
    void OpenDatabase(QString ServerName, QString DataBaseName, QString UserName, QString Password);
};

#endif // SQLSERVERMANAGE_H
