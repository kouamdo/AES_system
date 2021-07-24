/********************************************************************************
** Form generated from reading UI file 'first.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_H
#define UI_FIRST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_First
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *First)
    {
        if (First->objectName().isEmpty())
            First->setObjectName(QString::fromUtf8("First"));
        First->resize(800, 600);
        menubar = new QMenuBar(First);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        First->setMenuBar(menubar);
        centralwidget = new QWidget(First);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        First->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(First);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        First->setStatusBar(statusbar);

        retranslateUi(First);

        QMetaObject::connectSlotsByName(First);
    } // setupUi

    void retranslateUi(QMainWindow *First)
    {
        First->setWindowTitle(QCoreApplication::translate("First", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class First: public Ui_First {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_H
