/********************************************************************************
** Form generated from reading UI file 'decrypt.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECRYPT_H
#define UI_DECRYPT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Decrypt
{
public:
    QWidget *centralwidget;
    QLineEdit *key_d;
    QLineEdit *message_c;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Decrypt)
    {
        if (Decrypt->objectName().isEmpty())
            Decrypt->setObjectName(QString::fromUtf8("Decrypt"));
        Decrypt->resize(800, 600);
        centralwidget = new QWidget(Decrypt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        key_d = new QLineEdit(centralwidget);
        key_d->setObjectName(QString::fromUtf8("key_d"));
        key_d->setGeometry(QRect(180, 200, 211, 20));
        message_c = new QLineEdit(centralwidget);
        message_c->setObjectName(QString::fromUtf8("message_c"));
        message_c->setGeometry(QRect(180, 290, 211, 20));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 200, 101, 91));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ressources/img/icons8-unlock-100.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_2->setFlat(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 290, 75, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 200, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -20, 801, 601));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 26, 26);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 130, 151, 16));
        Decrypt->setCentralWidget(centralwidget);
        label->raise();
        key_d->raise();
        message_c->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_3->raise();
        label_2->raise();
        menubar = new QMenuBar(Decrypt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Decrypt->setMenuBar(menubar);
        statusbar = new QStatusBar(Decrypt);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Decrypt->setStatusBar(statusbar);

        retranslateUi(Decrypt);

        QMetaObject::connectSlotsByName(Decrypt);
    } // setupUi

    void retranslateUi(QMainWindow *Decrypt)
    {
        Decrypt->setWindowTitle(QCoreApplication::translate("Decrypt", "MainWindow", nullptr));
        pushButton_2->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Decrypt", "Import", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Decrypt", "Import", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Decrypt", "<html><head/><body><p align=\"center\">DECRYPTAGE</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Decrypt: public Ui_Decrypt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECRYPT_H
