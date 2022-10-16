#include "wordlegui.h"
#include "ui_wordlegui.h"

WordleGUI::WordleGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WordleGUI)
{
    ui->setupUi(this);
    round1();
}

WordleGUI::~WordleGUI()
{
    delete ui;
}

void WordleGUI::nextRound()
{
    round++;

    if(round > 6)
    {
        round = 1;
    }

    if(round == 1)
    {
        round1();
    }else if(round == 2)
    {
        round2();
    }else if(round == 3)
    {
        round3();
    }else if(round == 4)
    {
        round4();
    }else if(round == 5)
    {
        round5();
    }else if(round == 6)
    {
        round6();
    }
}

void WordleGUI::round1()
{


        clearAll();
        api.startGame();

        ui -> debug ->setText(QString::fromStdString(api.word()));

        ui->l11->setFocus();

        ui->l11->setReadOnly(false);
        ui->l12->setReadOnly(false);
        ui->l13->setReadOnly(false);
        ui->l14->setReadOnly(false);
        ui->l15->setReadOnly(false);
        ui->l11->setStyleSheet("background:#FFFFFF");
        ui->l12->setStyleSheet("background:#FFFFFF");
        ui->l13->setStyleSheet("background:#FFFFFF");
        ui->l14->setStyleSheet("background:#FFFFFF");
        ui->l15->setStyleSheet("background:#FFFFFF");

        ui->l21->setReadOnly(true);
        ui->l22->setReadOnly(true);
        ui->l23->setReadOnly(true);
        ui->l24->setReadOnly(true);
        ui->l25->setReadOnly(true);
        ui->l21->setStyleSheet("background:#ADCCC9");
        ui->l22->setStyleSheet("background:#ADCCC9");
        ui->l23->setStyleSheet("background:#ADCCC9");
        ui->l24->setStyleSheet("background:#ADCCC9");
        ui->l25->setStyleSheet("background:#ADCCC9");

        ui->l31->setReadOnly(true);
        ui->l32->setReadOnly(true);
        ui->l33->setReadOnly(true);
        ui->l34->setReadOnly(true);
        ui->l35->setReadOnly(true);
        ui->l31->setStyleSheet("background:#ADCCC9");
        ui->l32->setStyleSheet("background:#ADCCC9");
        ui->l33->setStyleSheet("background:#ADCCC9");
        ui->l34->setStyleSheet("background:#ADCCC9");
        ui->l35->setStyleSheet("background:#ADCCC9");

        ui->l41->setReadOnly(true);
        ui->l42->setReadOnly(true);
        ui->l43->setReadOnly(true);
        ui->l44->setReadOnly(true);
        ui->l45->setReadOnly(true);
        ui->l41->setStyleSheet("background:#ADCCC9");
        ui->l42->setStyleSheet("background:#ADCCC9");
        ui->l43->setStyleSheet("background:#ADCCC9");
        ui->l44->setStyleSheet("background:#ADCCC9");
        ui->l45->setStyleSheet("background:#ADCCC9");

        ui->l51->setReadOnly(true);
        ui->l52->setReadOnly(true);
        ui->l53->setReadOnly(true);
        ui->l54->setReadOnly(true);
        ui->l55->setReadOnly(true);
        ui->l51->setStyleSheet("background:#ADCCC9");
        ui->l52->setStyleSheet("background:#ADCCC9");
        ui->l53->setStyleSheet("background:#ADCCC9");
        ui->l54->setStyleSheet("background:#ADCCC9");
        ui->l55->setStyleSheet("background:#ADCCC9");
}

void WordleGUI::round2()
{
    std::array<std::string, 5> letters;
    letters[0] = ui->l11->text().toStdString();
    letters[1] = ui->l12->text().toStdString();
    letters[2] = ui->l13->text().toStdString();
    letters[3] = ui->l14->text().toStdString();
    letters[4] = ui->l15->text().toStdString();

    std::string word;

    for(unsigned long i = 0; i < letters.size(); i++)
    {
        word = word + letters[i];
    }

    bool correct = api.submitWord(word);

    if(!correct)
    {
        Incorrect incorrect;
        incorrect.setModal(true);
        incorrect.exec();
    }

    std::array<int, 5> errors = api.errorsReturn();

    //0- green, 1- yellow, 2- red

    if(errors[0] == 0)
    {
        ui->l11->setStyleSheet("background:#56E86C");
    }else if(errors[0] == 1)
    {
        ui->l11->setStyleSheet("background:#E9F542");
    }else if(errors[0] == 2)
    {
        ui->l11->setStyleSheet("background:#F56042");
    }

    if(errors[1] == 0)
    {
        ui->l12->setStyleSheet("background:#56E86C");
    }else if(errors[1] == 1)
    {
        ui->l12->setStyleSheet("background:#E9F542");
    }else if(errors[1] == 2)
    {
        ui->l12->setStyleSheet("background:#F56042");
    }

    if(errors[2] == 0)
    {
        ui->l13->setStyleSheet("background:#56E86C");
    }else if(errors[2] == 1)
    {
        ui->l13->setStyleSheet("background:#E9F542");
    }else if(errors[2] == 2)
    {
        ui->l13->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l14->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l14->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l14->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l14->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l14->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l14->setStyleSheet("background:#F56042");
    }

    if(errors[4] == 0)
    {
        ui->l15->setStyleSheet("background:#56E86C");
    }else if(errors[4] == 1)
    {
        ui->l15->setStyleSheet("background:#E9F542");
    }else if(errors[4] == 2)
    {
        ui->l15->setStyleSheet("background:#F56042");
    }

    bool won = api.win();

    if(won)
    {
        Won winWindow;
        winWindow.setModal(true);
        winWindow.exec();

        round = 1;
        round1();
        return;
    }


    ui->l21->setFocus();

    ui->l11->setReadOnly(true);
    ui->l12->setReadOnly(true);
    ui->l13->setReadOnly(true);
    ui->l14->setReadOnly(true);
    ui->l15->setReadOnly(true);

    ui->l21->setReadOnly(false);
    ui->l22->setReadOnly(false);
    ui->l23->setReadOnly(false);
    ui->l24->setReadOnly(false);
    ui->l25->setReadOnly(false);
    ui->l21->setStyleSheet("background:#FFFFFF");
    ui->l22->setStyleSheet("background:#FFFFFF");
    ui->l23->setStyleSheet("background:#FFFFFF");
    ui->l24->setStyleSheet("background:#FFFFFF");
    ui->l25->setStyleSheet("background:#FFFFFF");

    ui->l31->setReadOnly(true);
    ui->l32->setReadOnly(true);
    ui->l33->setReadOnly(true);
    ui->l34->setReadOnly(true);
    ui->l35->setReadOnly(true);
    ui->l31->setStyleSheet("background:#ADCCC9");
    ui->l32->setStyleSheet("background:#ADCCC9");
    ui->l33->setStyleSheet("background:#ADCCC9");
    ui->l34->setStyleSheet("background:#ADCCC9");
    ui->l35->setStyleSheet("background:#ADCCC9");

    ui->l41->setReadOnly(true);
    ui->l42->setReadOnly(true);
    ui->l43->setReadOnly(true);
    ui->l44->setReadOnly(true);
    ui->l45->setReadOnly(true);
    ui->l41->setStyleSheet("background:#ADCCC9");
    ui->l42->setStyleSheet("background:#ADCCC9");
    ui->l43->setStyleSheet("background:#ADCCC9");
    ui->l44->setStyleSheet("background:#ADCCC9");
    ui->l45->setStyleSheet("background:#ADCCC9");

    ui->l51->setReadOnly(true);
    ui->l52->setReadOnly(true);
    ui->l53->setReadOnly(true);
    ui->l54->setReadOnly(true);
    ui->l55->setReadOnly(true);
    ui->l51->setStyleSheet("background:#ADCCC9");
    ui->l52->setStyleSheet("background:#ADCCC9");
    ui->l53->setStyleSheet("background:#ADCCC9");
    ui->l54->setStyleSheet("background:#ADCCC9");
    ui->l55->setStyleSheet("background:#ADCCC9");
}

void WordleGUI::round3()
{
    std::array<std::string, 5> letters;
    letters[0] = ui->l21->text().toStdString();
    letters[1] = ui->l22->text().toStdString();
    letters[2] = ui->l23->text().toStdString();
    letters[3] = ui->l24->text().toStdString();
    letters[4] = ui->l25->text().toStdString();

    std::string word;

    for(unsigned long i = 0; i < letters.size(); i++)
    {
        word = word + letters[i];
    }

    bool correct = api.submitWord(word);

    if(!correct)
    {
        Incorrect incorrect;
        incorrect.setModal(true);
        incorrect.exec();
    }

    std::array<int, 5> errors = api.errorsReturn();

    //0- green, 1- yellow, 2- red

    if(errors[0] == 0)
    {
        ui->l21->setStyleSheet("background:#56E86C");
    }else if(errors[0] == 1)
    {
        ui->l21->setStyleSheet("background:#E9F542");
    }else if(errors[0] == 2)
    {
        ui->l21->setStyleSheet("background:#F56042");
    }

    if(errors[1] == 0)
    {
        ui->l22->setStyleSheet("background:#56E86C");
    }else if(errors[1] == 1)
    {
        ui->l22->setStyleSheet("background:#E9F542");
    }else if(errors[1] == 2)
    {
        ui->l22->setStyleSheet("background:#F56042");
    }

    if(errors[2] == 0)
    {
        ui->l23->setStyleSheet("background:#56E86C");
    }else if(errors[2] == 1)
    {
        ui->l23->setStyleSheet("background:#E9F542");
    }else if(errors[2] == 2)
    {
        ui->l23->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l24->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l24->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l24->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l24->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l24->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l24->setStyleSheet("background:#F56042");
    }

    if(errors[4] == 0)
    {
        ui->l25->setStyleSheet("background:#56E86C");
    }else if(errors[4] == 1)
    {
        ui->l25->setStyleSheet("background:#E9F542");
    }else if(errors[4] == 2)
    {
        ui->l25->setStyleSheet("background:#F56042");
    }

    bool won = api.win();

    if(won)
    {
        Won winWindow;
        winWindow.setModal(true);
        winWindow.exec();

        round = 1;
        round1();
        return;
    }



    ui->l31->setFocus();

    ui->l11->setReadOnly(true);
    ui->l12->setReadOnly(true);
    ui->l13->setReadOnly(true);
    ui->l14->setReadOnly(true);
    ui->l15->setReadOnly(true);

    ui->l21->setReadOnly(true);
    ui->l22->setReadOnly(true);
    ui->l23->setReadOnly(true);
    ui->l24->setReadOnly(true);
    ui->l25->setReadOnly(true);


    ui->l31->setReadOnly(false);
    ui->l32->setReadOnly(false);
    ui->l33->setReadOnly(false);
    ui->l34->setReadOnly(false);
    ui->l35->setReadOnly(false);
    ui->l31->setStyleSheet("background:#FFFFFF");
    ui->l32->setStyleSheet("background:#FFFFFF");
    ui->l33->setStyleSheet("background:#FFFFFF");
    ui->l34->setStyleSheet("background:#FFFFFF");
    ui->l35->setStyleSheet("background:#FFFFFF");

    ui->l41->setReadOnly(true);
    ui->l42->setReadOnly(true);
    ui->l43->setReadOnly(true);
    ui->l44->setReadOnly(true);
    ui->l45->setReadOnly(true);
    ui->l41->setStyleSheet("background:#ADCCC9");
    ui->l42->setStyleSheet("background:#ADCCC9");
    ui->l43->setStyleSheet("background:#ADCCC9");
    ui->l44->setStyleSheet("background:#ADCCC9");
    ui->l45->setStyleSheet("background:#ADCCC9");

    ui->l51->setReadOnly(true);
    ui->l52->setReadOnly(true);
    ui->l53->setReadOnly(true);
    ui->l54->setReadOnly(true);
    ui->l55->setReadOnly(true);
    ui->l51->setStyleSheet("background:#ADCCC9");
    ui->l52->setStyleSheet("background:#ADCCC9");
    ui->l53->setStyleSheet("background:#ADCCC9");
    ui->l54->setStyleSheet("background:#ADCCC9");
    ui->l55->setStyleSheet("background:#ADCCC9");
}

void WordleGUI::round4()
{
    std::array<std::string, 5> letters;
    letters[0] = ui->l31->text().toStdString();
    letters[1] = ui->l32->text().toStdString();
    letters[2] = ui->l33->text().toStdString();
    letters[3] = ui->l34->text().toStdString();
    letters[4] = ui->l35->text().toStdString();

    std::string word;

    for(unsigned long i = 0; i < letters.size(); i++)
    {
        word = word + letters[i];
    }

    bool correct = api.submitWord(word);

    if(!correct)
    {
        Incorrect incorrect;
        incorrect.setModal(true);
        incorrect.exec();
    }

    std::array<int, 5> errors = api.errorsReturn();

    //0- green, 1- yellow, 2- red

    if(errors[0] == 0)
    {
        ui->l31->setStyleSheet("background:#56E86C");
    }else if(errors[0] == 1)
    {
        ui->l31->setStyleSheet("background:#E9F542");
    }else if(errors[0] == 2)
    {
        ui->l31->setStyleSheet("background:#F56042");
    }

    if(errors[1] == 0)
    {
        ui->l32->setStyleSheet("background:#56E86C");
    }else if(errors[1] == 1)
    {
        ui->l32->setStyleSheet("background:#E9F542");
    }else if(errors[1] == 2)
    {
        ui->l32->setStyleSheet("background:#F56042");
    }

    if(errors[2] == 0)
    {
        ui->l33->setStyleSheet("background:#56E86C");
    }else if(errors[2] == 1)
    {
        ui->l33->setStyleSheet("background:#E9F542");
    }else if(errors[2] == 2)
    {
        ui->l33->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l34->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l34->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l34->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l34->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l34->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l34->setStyleSheet("background:#F56042");
    }

    if(errors[4] == 0)
    {
        ui->l35->setStyleSheet("background:#56E86C");
    }else if(errors[4] == 1)
    {
        ui->l35->setStyleSheet("background:#E9F542");
    }else if(errors[4] == 2)
    {
        ui->l35->setStyleSheet("background:#F56042");
    }

    bool won = api.win();

    if(won)
    {
        Won winWindow;
        winWindow.setModal(true);
        winWindow.exec();

        round = 1;
        round1();
        return;
    }


    ui->l41->setFocus();

    ui->l11->setReadOnly(true);
    ui->l12->setReadOnly(true);
    ui->l13->setReadOnly(true);
    ui->l14->setReadOnly(true);
    ui->l15->setReadOnly(true);

    ui->l21->setReadOnly(true);
    ui->l22->setReadOnly(true);
    ui->l23->setReadOnly(true);
    ui->l24->setReadOnly(true);
    ui->l25->setReadOnly(true);


    ui->l31->setReadOnly(true);
    ui->l32->setReadOnly(true);
    ui->l33->setReadOnly(true);
    ui->l34->setReadOnly(true);
    ui->l35->setReadOnly(true);


    ui->l41->setReadOnly(false);
    ui->l42->setReadOnly(false);
    ui->l43->setReadOnly(false);
    ui->l44->setReadOnly(false);
    ui->l45->setReadOnly(false);
    ui->l41->setStyleSheet("background:#FFFFFF");
    ui->l42->setStyleSheet("background:#FFFFFF");
    ui->l43->setStyleSheet("background:#FFFFFF");
    ui->l44->setStyleSheet("background:#FFFFFF");
    ui->l45->setStyleSheet("background:#FFFFFF");

    ui->l51->setReadOnly(true);
    ui->l52->setReadOnly(true);
    ui->l53->setReadOnly(true);
    ui->l54->setReadOnly(true);
    ui->l55->setReadOnly(true);
    ui->l51->setStyleSheet("background:#ADCCC9");
    ui->l52->setStyleSheet("background:#ADCCC9");
    ui->l53->setStyleSheet("background:#ADCCC9");
    ui->l54->setStyleSheet("background:#ADCCC9");
    ui->l55->setStyleSheet("background:#ADCCC9");
}

void WordleGUI::round5()
{
    std::array<std::string, 5> letters;
    letters[0] = ui->l41->text().toStdString();
    letters[1] = ui->l42->text().toStdString();
    letters[2] = ui->l43->text().toStdString();
    letters[3] = ui->l44->text().toStdString();
    letters[4] = ui->l45->text().toStdString();

    std::string word;

    for(unsigned long i = 0; i < letters.size(); i++)
    {
        word = word + letters[i];
    }

    bool correct = api.submitWord(word);

    if(!correct)
    {
        Incorrect incorrect;
        incorrect.setModal(true);
        incorrect.exec();
    }

    std::array<int, 5> errors = api.errorsReturn();

    //0- green, 1- yellow, 2- red

    if(errors[0] == 0)
    {
        ui->l41->setStyleSheet("background:#56E86C");
    }else if(errors[0] == 1)
    {
        ui->l41->setStyleSheet("background:#E9F542");
    }else if(errors[0] == 2)
    {
        ui->l41->setStyleSheet("background:#F56042");
    }

    if(errors[1] == 0)
    {
        ui->l42->setStyleSheet("background:#56E86C");
    }else if(errors[1] == 1)
    {
        ui->l42->setStyleSheet("background:#E9F542");
    }else if(errors[1] == 2)
    {
        ui->l42->setStyleSheet("background:#F56042");
    }

    if(errors[2] == 0)
    {
        ui->l43->setStyleSheet("background:#56E86C");
    }else if(errors[2] == 1)
    {
        ui->l43->setStyleSheet("background:#E9F542");
    }else if(errors[2] == 2)
    {
        ui->l43->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l44->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l44->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l44->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l44->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l44->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l44->setStyleSheet("background:#F56042");
    }

    if(errors[4] == 0)
    {
        ui->l45->setStyleSheet("background:#56E86C");
    }else if(errors[4] == 1)
    {
        ui->l45->setStyleSheet("background:#E9F542");
    }else if(errors[4] == 2)
    {
        ui->l45->setStyleSheet("background:#F56042");
    }

    bool won = api.win();

    if(won)
    {
        Won winWindow;
        winWindow.setModal(true);
        winWindow.exec();

        round = 1;
        round1();
        return;
    }


    ui->l51->setFocus();

    ui->l11->setReadOnly(true);
    ui->l12->setReadOnly(true);
    ui->l13->setReadOnly(true);
    ui->l14->setReadOnly(true);
    ui->l15->setReadOnly(true);

    ui->l21->setReadOnly(true);
    ui->l22->setReadOnly(true);
    ui->l23->setReadOnly(true);
    ui->l24->setReadOnly(true);
    ui->l25->setReadOnly(true);


    ui->l31->setReadOnly(true);
    ui->l32->setReadOnly(true);
    ui->l33->setReadOnly(true);
    ui->l34->setReadOnly(true);
    ui->l35->setReadOnly(true);


    ui->l41->setReadOnly(true);
    ui->l42->setReadOnly(true);
    ui->l43->setReadOnly(true);
    ui->l44->setReadOnly(true);
    ui->l45->setReadOnly(true);


    ui->l51->setReadOnly(false);
    ui->l52->setReadOnly(false);
    ui->l53->setReadOnly(false);
    ui->l54->setReadOnly(false);
    ui->l55->setReadOnly(false);
    ui->l51->setStyleSheet("background:#FFFFFF");
    ui->l52->setStyleSheet("background:#FFFFFF");
    ui->l53->setStyleSheet("background:#FFFFFF");
    ui->l54->setStyleSheet("background:#FFFFFF");
    ui->l55->setStyleSheet("background:#FFFFFF");
}

void WordleGUI::round6()
{
    std::array<std::string, 5> letters;
    letters[0] = ui->l51->text().toStdString();
    letters[1] = ui->l52->text().toStdString();
    letters[2] = ui->l53->text().toStdString();
    letters[3] = ui->l54->text().toStdString();
    letters[4] = ui->l55->text().toStdString();

    std::string word;

    for(unsigned long i = 0; i < letters.size(); i++)
    {
        word = word + letters[i];
    }

    bool correct = api.submitWord(word);

    if(!correct)
    {
        Incorrect incorrect;
        incorrect.setModal(true);
        incorrect.exec();
    }

    std::array<int, 5> errors = api.errorsReturn();

    //0- green, 1- yellow, 2- red

    if(errors[0] == 0)
    {
        ui->l51->setStyleSheet("background:#56E86C");
    }else if(errors[0] == 1)
    {
        ui->l51->setStyleSheet("background:#E9F542");
    }else if(errors[0] == 2)
    {
        ui->l51->setStyleSheet("background:#F56042");
    }

    if(errors[1] == 0)
    {
        ui->l52->setStyleSheet("background:#56E86C");
    }else if(errors[1] == 1)
    {
        ui->l52->setStyleSheet("background:#E9F542");
    }else if(errors[1] == 2)
    {
        ui->l52->setStyleSheet("background:#F56042");
    }

    if(errors[2] == 0)
    {
        ui->l53->setStyleSheet("background:#56E86C");
    }else if(errors[2] == 1)
    {
        ui->l53->setStyleSheet("background:#E9F542");
    }else if(errors[2] == 2)
    {
        ui->l53->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l54->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l54->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l54->setStyleSheet("background:#F56042");
    }

    if(errors[3] == 0)
    {
        ui->l54->setStyleSheet("background:#56E86C");
    }else if(errors[3] == 1)
    {
        ui->l54->setStyleSheet("background:#E9F542");
    }else if(errors[3] == 2)
    {
        ui->l54->setStyleSheet("background:#F56042");
    }

    if(errors[4] == 0)
    {
        ui->l55->setStyleSheet("background:#56E86C");
    }else if(errors[4] == 1)
    {
        ui->l55->setStyleSheet("background:#E9F542");
    }else if(errors[4] == 2)
    {
        ui->l55->setStyleSheet("background:#F56042");
    }

    bool won = api.win();

    if(won)
    {
        Won winWindow;
        winWindow.setModal(true);
        winWindow.exec();

        round = 1;
        round1();
        return;
    }else
    {
        GameOver gameover;
        gameover.setCorrectWord(api.word());
        gameover.setModal(true);
        gameover.exec();
        round = 1;
        round1();
        return;
    }
}









void WordleGUI::clearAll()
{
    ui->l11->clear();
    ui->l12->clear();
    ui->l13->clear();
    ui->l14->clear();
    ui->l15->clear();
    ui->l21->clear();
    ui->l22->clear();
    ui->l23->clear();
    ui->l24->clear();
    ui->l25->clear();
    ui->l31->clear();
    ui->l32->clear();
    ui->l33->clear();
    ui->l34->clear();
    ui->l35->clear();
    ui->l41->clear();
    ui->l42->clear();
    ui->l43->clear();
    ui->l44->clear();
    ui->l45->clear();
    ui->l51->clear();
    ui->l52->clear();
    ui->l53->clear();
    ui->l54->clear();
    ui->l55->clear();
}

void WordleGUI::on_l11_cursorPositionChanged(int arg1, int arg2)
{
    ui->l12->setFocus();
}


void WordleGUI::on_l12_cursorPositionChanged(int arg1, int arg2)
{
    ui->l13->setFocus();
}

void WordleGUI::on_l13_cursorPositionChanged(int arg1, int arg2)
{
    ui->l14->setFocus();
}

void WordleGUI::on_l14_cursorPositionChanged(int arg1, int arg2)
{
    ui->l15->setFocus();
}


void WordleGUI::on_l21_cursorPositionChanged(int arg1, int arg2)
{
    ui->l22->setFocus();
}


void WordleGUI::on_l22_cursorPositionChanged(int arg1, int arg2)
{
    ui->l23->setFocus();
}

void WordleGUI::on_l23_cursorPositionChanged(int arg1, int arg2)
{
    ui->l24->setFocus();
}

void WordleGUI::on_l24_cursorPositionChanged(int arg1, int arg2)
{
    ui->l25->setFocus();
}


void WordleGUI::on_l31_cursorPositionChanged(int arg1, int arg2)
{
    ui->l32->setFocus();
}


void WordleGUI::on_l32_cursorPositionChanged(int arg1, int arg2)
{
    ui->l33->setFocus();
}

void WordleGUI::on_l33_cursorPositionChanged(int arg1, int arg2)
{
    ui->l34->setFocus();
}

void WordleGUI::on_l34_cursorPositionChanged(int arg1, int arg2)
{
    ui->l35->setFocus();
}


void WordleGUI::on_l41_cursorPositionChanged(int arg1, int arg2)
{
    ui->l42->setFocus();
}


void WordleGUI::on_l42_cursorPositionChanged(int arg1, int arg2)
{
    ui->l43->setFocus();
}

void WordleGUI::on_l43_cursorPositionChanged(int arg1, int arg2)
{
    ui->l44->setFocus();
}

void WordleGUI::on_l44_cursorPositionChanged(int arg1, int arg2)
{
    ui->l45->setFocus();
}


void WordleGUI::on_l51_cursorPositionChanged(int arg1, int arg2)
{
    ui->l52->setFocus();
}


void WordleGUI::on_l52_cursorPositionChanged(int arg1, int arg2)
{
    ui->l53->setFocus();
}

void WordleGUI::on_l53_cursorPositionChanged(int arg1, int arg2)
{
    ui->l54->setFocus();
}

void WordleGUI::on_l54_cursorPositionChanged(int arg1, int arg2)
{
    ui->l55->setFocus();
}


void WordleGUI::on_pushButton_pressed()
{
    nextRound();
}

