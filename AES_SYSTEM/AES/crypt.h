#ifndef CRYPT_H
#define CRYPT_H

#include <QMainWindow>

namespace Ui {
class Crypt;
}

class Crypt : public QMainWindow
{
    Q_OBJECT

public:
    explicit Crypt(QWidget *parent = nullptr);
    ~Crypt();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Crypt *ui;
};

#endif // CRYPT_H
