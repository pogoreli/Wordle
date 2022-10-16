#include "won.h"
#include "ui_won.h"

Won::Won(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Won)
{
    ui->setupUi(this);
}

Won::~Won()
{
    delete ui;
}

void Won::on_pushButton_2_pressed()
{
    std::exit(1);
}


void Won::on_pushButton_pressed()
{
    hide();
}

