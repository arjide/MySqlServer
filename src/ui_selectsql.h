/********************************************************************************
** Form generated from reading UI file 'selectsql.ui'
**
** Created: Sun May 25 22:43:24 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSQL_H
#define UI_SELECTSQL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectSql
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *SelectSql)
    {
        if (SelectSql->objectName().isEmpty())
            SelectSql->setObjectName(QString::fromUtf8("SelectSql"));
        SelectSql->resize(320, 240);
        verticalLayoutWidget = new QWidget(SelectSql);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 80, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        label = new QLabel(SelectSql);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(17, 20, 281, 51));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(SelectSql);

        QMetaObject::connectSlotsByName(SelectSql);
    } // setupUi

    void retranslateUi(QWidget *SelectSql)
    {
        SelectSql->setWindowTitle(QApplication::translate("SelectSql", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SelectSql", "Sql Server", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SelectSql", "SQLITE", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SelectSql", "\350\257\267\351\200\211\346\213\251\344\275\240\344\275\277\347\224\250\347\232\204\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectSql: public Ui_SelectSql {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSQL_H
