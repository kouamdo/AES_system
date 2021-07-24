#include "first.h"
#include "ui_first.h"

First::First(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::First)
{
    ui->setupUi(this);
}

First::~First()
{
    delete ui;
}
