#ifndef DECRYPT_H
#define DECRYPT_H

#include <QMainWindow>

namespace Ui {
class Decrypt;
}

class Decrypt : public QMainWindow
{
    Q_OBJECT

public:
    explicit Decrypt(QWidget *parent = nullptr);
    ~Decrypt();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Decrypt *ui;
};

#endif // DECRYPT_H
