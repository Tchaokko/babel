/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginscreenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *loginscreenClass)
    {
        if (loginscreenClass->objectName().isEmpty())
            loginscreenClass->setObjectName(QStringLiteral("loginscreenClass"));
        loginscreenClass->resize(600, 400);
        menuBar = new QMenuBar(loginscreenClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        loginscreenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(loginscreenClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        loginscreenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(loginscreenClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loginscreenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(loginscreenClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        loginscreenClass->setStatusBar(statusBar);

        retranslateUi(loginscreenClass);

        QMetaObject::connectSlotsByName(loginscreenClass);
    } // setupUi

    void retranslateUi(QMainWindow *loginscreenClass)
    {
        loginscreenClass->setWindowTitle(QApplication::translate("loginscreenClass", "loginscreen", 0));
    } // retranslateUi

};

namespace Ui {
    class loginscreenClass: public Ui_loginscreenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
