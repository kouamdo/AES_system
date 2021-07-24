#include "crypt.h"
#include "ui_crypt.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aes_main.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QLineEdit>

Crypt::Crypt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Crypt)
{
    ui->setupUi(this);
}

Crypt::~Crypt()
{
    delete ui;
}

void Crypt::on_pushButton_clicked()
{

        AES_main aes ;

        aes.Initialiser();
        aes.ImporterClef(ui->key->text().toLocal8Bit().data()) ;
        aes.Chiffrer(ui->message->text().toLocal8Bit().data() ,ui->message->text().toLocal8Bit().data()) ;
        aes.Nettoyer();

}


void Crypt::on_pushButton_3_clicked()
{
    static QString file_name = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath());

   ui->key->setText(file_name) ;
}


void Crypt::on_pushButton_4_clicked()
{
    static QString file_name = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath());

   ui->message->setText(file_name) ;
}


void Crypt::on_pushButton_5_clicked()
{
    AES_main aes ;

    aes.Initialiser();

    aes.GenererClef();

    aes.ExporterClef(ui->key->text().toLocal8Bit().data());

    aes.Nettoyer();
}

void Crypt::on_pushButton_2_clicked()
{

}

