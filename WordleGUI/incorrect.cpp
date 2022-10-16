#include "incorrect.h"
#include "ui_incorrect.h"

Incorrect::Incorrect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Incorrect)
{
    ui->setupUi(this);
}

Incorrect::~Incorrect()
{
    delete ui;
}

void Incorrect::on_pushButton_pressed()
{
    hide();
}

