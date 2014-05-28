#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBlock>
#include <QTextDocument>
#include <QTextFragment>
#include <QTextCursor>
#include <QStringList>
#include <QThread>
#include <QSettings>
#include "sqlservermanage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loginServer(QString ServerName, QString DataBaseName, QString UserName, QString Password);

    QString openSQLITEdatabase();
signals:
    void OpenDatabaseError(QString errorString);
    void OpenDatabaseOk();

    void OpenDatabase(QString ServerName, QString DataBaseName, QString UserName, QString Password);
public slots:

private:
    QTextDocument *document;
    void isDeleteText();
    void isAddText();
    int cursor;

    QSettings settings;

    QStringList keyword , dataKeyWord , recordSqlCode;//recordSqlCode用了记录执行过的代码
    int CurrentCodePos;//记录当前显示的代码是第几次执行的

    SqlServerManage mySqlServer;
    QThread mythread;

    void addRunRecord(QString str);
    QString lastRunRecord();
    QString nextRunRecord();
private slots:
    void on_runSqlCode_clicked();

    void on_clear_clicked();

    void on_textEdit_textChanged();

    void on_LastButton_clicked();

    void on_NextButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
