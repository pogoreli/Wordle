#ifndef WON_H
#define WON_H

#include <QDialog>

namespace Ui {
class Won;
}

class Won : public QDialog
{
    Q_OBJECT

public:
    explicit Won(QWidget *parent = nullptr);
    ~Won();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_pressed();

private:
    Ui::Won *ui;
};

#endif // WON_H
