#include "decrypt.h"
#include "ui_decrypt.h"
#include "aes_main.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QLineEdit>

Decrypt::Decrypt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Decrypt)
{
    ui->setupUi(this);
}

Decrypt::~Decrypt()
{
    delete ui;
}

void Decrypt::on_pushButton_3_clicked()
{
    static QString file_name = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath());

   ui->key_d->setText(file_name) ;
}


void Decrypt::on_pushButton_4_clicked()
{
    static QString file_name = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath());

   ui->message_c->setText(file_name) ;
}


void Decrypt::on_pushButton_2_clicked()
{
    AES_main aes ;

    aes.Initialiser();
    aes.ImporterClef(ui->key_d->text().toLocal8Bit().data()) ;
    aes.Dechiffrer(ui->message_c->text().toLocal8Bit().data() ,ui->message_c->text().toLocal8Bit().data());
    aes.Nettoyer();
}

