#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/ressources/img/photo_2021-07-24_09-28-08.jpg");
    ui->label->setPixmap(pix.scaled(650,800,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//cry
{
    hide();
    crypt = new Crypt(this);
    crypt->show();
}


void MainWindow::on_push1_clicked()//dec
{
    hide();
    decrypt = new Decrypt(this);
    decrypt->show();
}

