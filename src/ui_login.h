/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Sat May 24 21:57:37 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QPushButton *LoginButton;
    QLabel *showMessage;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ServerName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *DataBaseName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *UserName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *AutoLogin;
    QCheckBox *RememberPassword;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(508, 387);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LoginButton = new QPushButton(centralwidget);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setEnabled(true);
        LoginButton->setGeometry(QRect(190, 340, 131, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy1);
        showMessage = new QLabel(centralwidget);
        showMessage->setObjectName(QString::fromUtf8("showMessage"));
        showMessage->setGeometry(QRect(8, 10, 491, 71));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(showMessage->sizePolicy().hasHeightForWidth());
        showMessage->setSizePolicy(sizePolicy2);
        showMessage->setAlignment(Qt::AlignCenter);
        showMessage->setWordWrap(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 90, 387, 251));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ServerName = new QLineEdit(widget);
        ServerName->setObjectName(QString::fromUtf8("ServerName"));

        horizontalLayout->addWidget(ServerName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        DataBaseName = new QLineEdit(widget);
        DataBaseName->setObjectName(QString::fromUtf8("DataBaseName"));

        horizontalLayout_2->addWidget(DataBaseName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        UserName = new QLineEdit(widget);
        UserName->setObjectName(QString::fromUtf8("UserName"));

        horizontalLayout_3->addWidget(UserName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        Password = new QLineEdit(widget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_4->addWidget(Password);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(120);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(68, -1, -1, -1);
        AutoLogin = new QCheckBox(widget);
        AutoLogin->setObjectName(QString::fromUtf8("AutoLogin"));
        AutoLogin->setEnabled(true);
        AutoLogin->setAcceptDrops(false);
        AutoLogin->setLayoutDirection(Qt::LeftToRight);
        AutoLogin->setAutoFillBackground(false);
        AutoLogin->setChecked(false);
        AutoLogin->setTristate(false);

        horizontalLayout_5->addWidget(AutoLogin);

        RememberPassword = new QCheckBox(widget);
        RememberPassword->setObjectName(QString::fromUtf8("RememberPassword"));
        RememberPassword->setEnabled(true);
        sizePolicy.setHeightForWidth(RememberPassword->sizePolicy().hasHeightForWidth());
        RememberPassword->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(RememberPassword);


        verticalLayout->addLayout(horizontalLayout_5);

        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "MainWindow", 0, QApplication::UnicodeUTF8));
        LoginButton->setText(QApplication::translate("Login", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        showMessage->setText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Login", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login", "\347\224\250 \346\210\267 \345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Login", "\345\257\206    \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        AutoLogin->setText(QApplication::translate("Login", "\344\270\213\346\254\241\350\207\252\345\212\250\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        RememberPassword->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
