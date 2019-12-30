/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowTTT
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowTTT)
    {
        if (MainWindowTTT->objectName().isEmpty())
            MainWindowTTT->setObjectName(QStringLiteral("MainWindowTTT"));
        MainWindowTTT->resize(800, 600);
        menubar = new QMenuBar(MainWindowTTT);
        menubar->setObjectName(QStringLiteral("menubar"));
        MainWindowTTT->setMenuBar(menubar);
        centralwidget = new QWidget(MainWindowTTT);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindowTTT->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindowTTT);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowTTT->setStatusBar(statusbar);

        retranslateUi(MainWindowTTT);

        QMetaObject::connectSlotsByName(MainWindowTTT);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowTTT)
    {
        MainWindowTTT->setWindowTitle(QApplication::translate("MainWindowTTT", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTTT: public Ui_MainWindowTTT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
