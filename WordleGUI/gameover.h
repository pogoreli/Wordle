#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();
    void setCorrectWord(std::string Word);

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

private:
    Ui::GameOver *ui;
    std::string word;
};

#endif // GAMEOVER_H
