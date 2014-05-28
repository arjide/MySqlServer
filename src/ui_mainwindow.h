/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat May 24 22:32:12 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *clear;
    QPushButton *runSqlCode;
    QLabel *showMessage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *LastButton;
    QPushButton *NextButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(520, 357);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAcceptDrops(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(20);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setPointSize(12);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setEnabled(false);

        horizontalLayout->addWidget(clear);

        runSqlCode = new QPushButton(centralWidget);
        runSqlCode->setObjectName(QString::fromUtf8("runSqlCode"));
        runSqlCode->setEnabled(false);

        horizontalLayout->addWidget(runSqlCode);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 1);

        showMessage = new QLabel(centralWidget);
        showMessage->setObjectName(QString::fromUtf8("showMessage"));
        showMessage->setLayoutDirection(Qt::LeftToRight);
        showMessage->setAlignment(Qt::AlignCenter);
        showMessage->setWordWrap(true);

        gridLayout->addWidget(showMessage, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(100);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, -1, 50, -1);
        LastButton = new QPushButton(centralWidget);
        LastButton->setObjectName(QString::fromUtf8("LastButton"));

        horizontalLayout_2->addWidget(LastButton);

        NextButton = new QPushButton(centralWidget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));

        horizontalLayout_2->addWidget(NextButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        runSqlCode->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", 0, QApplication::UnicodeUTF8));
        showMessage->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250", 0, QApplication::UnicodeUTF8));
        LastButton->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\346\235\241", 0, QApplication::UnicodeUTF8));
        NextButton->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\235\241", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
