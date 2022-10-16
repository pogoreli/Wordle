#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);


}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_pressed()
{
    hide();
}


void GameOver::on_pushButton_2_pressed()
{
    std::exit(1);
}

void GameOver::setCorrectWord(std::string Word)
{
    word = Word;
    std::string text = "the correct word is: " + word;
    ui->cv->setText(QString::fromStdString(text));
}

