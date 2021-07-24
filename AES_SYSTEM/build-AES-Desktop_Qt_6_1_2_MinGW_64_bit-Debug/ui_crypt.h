/********************************************************************************
** Form generated from reading UI file 'crypt.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRYPT_H
#define UI_CRYPT_H

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

class Ui_Crypt
{
public:
    QWidget *centralwidget;
    QLineEdit *key;
    QLineEdit *message;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Crypt)
    {
        if (Crypt->objectName().isEmpty())
            Crypt->setObjectName(QString::fromUtf8("Crypt"));
        Crypt->resize(800, 600);
        centralwidget = new QWidget(Crypt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        key = new QLineEdit(centralwidget);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(160, 250, 281, 21));
        message = new QLineEdit(centralwidget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(160, 350, 281, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(620, 280, 81, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ressources/img/icons8-lock-100.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        pushButton->setFlat(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 250, 75, 23));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(450, 350, 75, 23));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 250, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 180, 121, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, -18, 801, 601));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 53, 53);"));
        Crypt->setCentralWidget(centralwidget);
        label_2->raise();
        key->raise();
        message->raise();
        pushButton->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        label->raise();
        menubar = new QMenuBar(Crypt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Crypt->setMenuBar(menubar);
        statusbar = new QStatusBar(Crypt);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Crypt->setStatusBar(statusbar);

        retranslateUi(Crypt);

        QMetaObject::connectSlotsByName(Crypt);
    } // setupUi

    void retranslateUi(QMainWindow *Crypt)
    {
        Crypt->setWindowTitle(QCoreApplication::translate("Crypt", "MainWindow", nullptr));
        pushButton->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Crypt", "Import", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Crypt", "Import", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Crypt", "Generate Key", nullptr));
        label->setText(QCoreApplication::translate("Crypt", "<html><head/><body><p align=\"center\">CRYPTAGE</p></body></html>", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Crypt: public Ui_Crypt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRYPT_H
