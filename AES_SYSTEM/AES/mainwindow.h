#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crypt.h"
#include "decrypt.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_push1_clicked();

private:
    Ui::MainWindow *ui;
     Crypt *crypt;
     Decrypt *decrypt;
};
#endif // MAINWINDOW_H
