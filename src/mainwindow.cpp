#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromUtf8("SQL命令执行器--作者：雨后星辰"));
    document = ui->textEdit->document();

    cursor = -1;
    CurrentCodePos = settings.value("CurrentCodePos",-1).toInt();
    recordSqlCode = settings.value("recordSqlCode", NULL).toStringList();

    if(CurrentCodePos > recordSqlCode.count()-1 ){
        CurrentCodePos = recordSqlCode.count()-1;
        settings.setValue("CurrentCodePos",CurrentCodePos);
    }
    //qDebug()<<CurrentCodePos<<recordSqlCode.count();
    if(!recordSqlCode.isEmpty())
        ui->textEdit->setHtml(recordSqlCode.at(CurrentCodePos>0 ? CurrentCodePos :0));
    else{
        ui->LastButton->setEnabled(false);
        ui->NextButton->setEnabled(false);
    }
    if(CurrentCodePos == 0) ui->LastButton->setEnabled(false);
    if(CurrentCodePos == recordSqlCode.count()-1) ui->NextButton->setEnabled(false);

    QString str = "add ,all ,alter ,and ,any ,as ,asc ,authorization ,backup ,begin ,between ,break ,browse ,bulk ,by ,cascade ,case ,check ,checkpoint ,close ,clustered ,coalesce ,collate ,column ,commit ,compute ,constraint ,contains ,containstable ,continue ,convert ,create ,cross ,current ,current_date ,current_time ,current_timestamp ,current_user ,cursor ,database ,dbcc ,deallocate ,declare ,default ,delete ,deny ,desc ,disk ,distinct ,distributed ,double ,drop ,dummy ,dump ,else ,end ,errlvl ,escape ,except ,exec ,execute ,exists ,exit ,external ,fetch ,file ,fillfactor ,for ,foreign ,freetext ,freetexttable ,from ,full ,function ,goto ,grant ,group ,having ,holdlock ,identity ,identity_insert ,identitycol ,if ,in ,index ,inner ,insert ,intersect ,into ,is ,join ,key ,kill ,left ,like ,linemo ,load ,nattonal ,nocheck ,nonclustered ,not ,null ,nullif ,of ,off ,offsets ,on ,open ,opendatasource ,openquery ,openrowset ,openxml ,option ,or ,order ,outer ,over ,percent ,pivot ,plan ,percision ,primary ,print ,proc ,procedure ,public ,raiserror ,read ,readtext ,reconfigure ,references ,replication ,restore ,restrict ,return ,revert ,revoke ,right ,rollback ,rowcount ,rowguidcol ,rule ,save ,schema ,select ,session_user ,set ,setuser ,shutdown ,some ,statistics ,system_user ,table ,tablesample ,textsize ,then ,to ,top ,tran ,transaction ,trigger ,truncate ,tsequal ,union ,unique ,unpivot ,update ,updatetext ,use ,user ,values ,varying ,view ,waitfor ,when ,where ,while ,with ,writetext";
    keyword = str.split(",");

    str = "Binary(,Varbinary(,Char(,Varchar(,Nchar(,Nvarchar(,Datetime(,Smalldatetime(,Decimal(,Numeric(,Float(,Real(,Int(,Smallint(,Tinyint(,Money(,Smallmoney(,Bit(,Cursor(,Sysname(,Timestamp(,Uniqueidentifier(,Text(,Image(,Ntext(,Binary),Varbinary),Char),Varchar),Nchar),Nvarchar),Datetime),Smalldatetime),Decimal),Numeric),Float),Real),Int),Smallint),Tinyint),Money),Smallmoney),Bit),Cursor),Sysname),Timestamp),Uniqueidentifier),Text),Image),Ntext),Binary ,Varbinary ,Char ,Varchar ,Nchar ,Nvarchar ,Datetime ,Smalldatetime ,Decimal ,Numeric ,Float ,Real ,Int ,Smallint ,Tinyint ,Money ,Smallmoney ,Bit ,Cursor ,Sysname ,Timestamp ,Uniqueidentifier ,Text ,Image ,Ntext ";
    dataKeyWord = str.split(",");

    mySqlServer.moveToThread(&mythread);

    connect(&mySqlServer , SIGNAL(OpenDatabaseError(QString)), SIGNAL(OpenDatabaseError(QString)));
    connect(&mySqlServer , SIGNAL(OpenDatabaseOk()), SIGNAL(OpenDatabaseOk()));
    connect(this, SIGNAL(OpenDatabase(QString,QString,QString,QString)), &mySqlServer, SLOT(OpenDatabase(QString,QString,QString,QString)));

    mythread.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginServer(QString ServerName, QString DataBaseName, QString UserName, QString Password)
{
    emit OpenDatabase(ServerName, DataBaseName, UserName, Password);
}

QString MainWindow::openSQLITEdatabase()
{
    return mySqlServer.openSQLITEdatabase();//打开sqlite数据库
}

void MainWindow::isDeleteText()
{
    QTextCharFormat fmt;
    fmt.setForeground( Qt::NoBrush );

    QTextCursor helper = ui->textEdit->textCursor();

    if(helper.charFormat().foreground() != Qt::black)
    {
        int begin = cursor ,end = cursor;
        for(; begin>0 ;--begin)
        {
            helper.setPosition(begin, QTextCursor::KeepAnchor);
            if(helper.charFormat().foreground() == Qt::NoBrush)
                break;
        }
        int temp = ui->textEdit->toPlainText().count()-1;
        for(; end<temp; ++end)
        {
            helper.setPosition(end, QTextCursor::KeepAnchor);
            if(helper.charFormat().foreground() == Qt::NoBrush)
                break;
        }
        //qDebug()<<"on delete"<<begin<<" "<<end;
        helper.setPosition(begin);
        helper.setPosition(end, QTextCursor::KeepAnchor);
        helper.setCharFormat(fmt);
    }
}

void MainWindow::isAddText()
{
    /*!qDebug()<<"on add";*/

    QTextCharFormat fmt;
    fmt.setForeground( Qt::blue );

    QString str = ui->textEdit->toPlainText();
    int temp_num = str.lastIndexOf(" ", cursor-2);

    str = str.mid(temp_num+1, str.count()-temp_num);
    qDebug()<<str;

    int begin = -1 ,length=0;

    foreach(QString temp , keyword)
    {
        begin = str.lastIndexOf(temp , str.count()-1 , Qt::CaseInsensitive);
        if(begin != -1){
            length = temp.count()-1;
            break;
        }
    }

    if(begin == -1)
    {
        foreach(QString temp , dataKeyWord)
        {
            begin = str.lastIndexOf(temp , str.count()-1 , Qt::CaseInsensitive);
            if(begin != -1){
                length = temp.count()-1;
                break;
            }
        }
        if( begin != -1) fmt.setForeground( Qt::red );
    }

    if( begin != -1 )
    {
        begin = begin + temp_num + 1;
        QTextCursor helper = ui->textEdit->textCursor();
        helper.setPosition( begin );

        helper.setPosition( begin+length , QTextCursor::KeepAnchor);
        helper.setCharFormat(fmt);
    }
}

void MainWindow::addRunRecord(QString str)
{
    qDebug()<<CurrentCodePos;
    recordSqlCode.append(str);

    CurrentCodePos = recordSqlCode.count()-1;
    ui->NextButton->setEnabled(false);

    settings.setValue("CurrentCodePos" ,CurrentCodePos);

    if(CurrentCodePos > 0)
        ui->LastButton->setEnabled(true);

    settings.setValue("recordSqlCode", recordSqlCode);
}

QString MainWindow::lastRunRecord()
{
    qDebug()<<CurrentCodePos;
    if(CurrentCodePos < 0){
        CurrentCodePos = 0;
        settings.setValue("CurrentCodePos" ,CurrentCodePos);
    }

    if(CurrentCodePos-1 == 0) ui->LastButton->setEnabled(false);
    if( CurrentCodePos-1 < recordSqlCode.count()-1 ) ui->NextButton->setEnabled(true);
    settings.setValue("CurrentCodePos" ,CurrentCodePos-1);
    return recordSqlCode.at(--CurrentCodePos);
}

QString MainWindow::nextRunRecord()
{
    qDebug()<<CurrentCodePos;
    if(CurrentCodePos > recordSqlCode.count()-1){
        CurrentCodePos = recordSqlCode.count()-1;
        settings.setValue("CurrentCodePos" ,CurrentCodePos);
    }

    if(CurrentCodePos+1 == recordSqlCode.count()-1) ui->NextButton->setEnabled(false);
    if( CurrentCodePos+1 > 0 ) ui->LastButton->setEnabled(true);
    settings.setValue("CurrentCodePos" ,CurrentCodePos+1);
    return recordSqlCode.at(++CurrentCodePos);
}

void MainWindow::on_runSqlCode_clicked()
{
    QString temp = mySqlServer.RunCode(ui->textEdit->toPlainText());
    if(temp == " ") temp = QString::fromUtf8("执行完成");
    ui->showMessage->setText(temp);

    if(recordSqlCode[recordSqlCode.count()-1] != ui->textEdit->toHtml())
        addRunRecord(ui->textEdit->toHtml());
}

void MainWindow::on_clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_textEdit_textChanged()
{
    int pos = ui->textEdit->textCursor().position();

    if(ui->textEdit->toPlainText() != "")
    {
        if(cursor != pos)
        {
            //qDebug()<<"pos:"<<pos<<" "<<cursor;
            ui->runSqlCode->setEnabled(true);
            ui->clear->setEnabled(true);

            if(pos > cursor)
            {
                cursor = pos;
                isAddText();
            }
            else{
                cursor = pos;
                isDeleteText();
            }
        }

    }else{
        cursor = -1;
        ui->runSqlCode->setEnabled(false);
        ui->clear->setEnabled(false);
    }
}

void MainWindow::on_LastButton_clicked()
{
    ui->textEdit->setHtml( lastRunRecord() );
}

void MainWindow::on_NextButton_clicked()
{
    ui->textEdit->setHtml( nextRunRecord() );
}
