#ifndef INCORRECT_H
#define INCORRECT_H

#include <QDialog>

namespace Ui {
class Incorrect;
}

class Incorrect : public QDialog
{
    Q_OBJECT

public:
    explicit Incorrect(QWidget *parent = nullptr);
    ~Incorrect();

private slots:
    void on_pushButton_pressed();

private:
    Ui::Incorrect *ui;
};

#endif // INCORRECT_H
