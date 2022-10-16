#ifndef WORDLEGUI_H
#define WORDLEGUI_H
#include <../WordleLibrary/wordlelibrary.h>
#include <array>
#include <string>
#include <incorrect.h>
#include <won.h>
#include <gameover.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WordleGUI; }
QT_END_NAMESPACE

class WordleGUI : public QMainWindow
{
    Q_OBJECT

public:
    WordleGUI(QWidget *parent = nullptr);
    ~WordleGUI();

private slots:
    void on_l11_cursorPositionChanged(int arg1, int arg2);
    void on_l12_cursorPositionChanged(int arg1, int arg2);
    void on_l13_cursorPositionChanged(int arg1, int arg2);
    void on_l14_cursorPositionChanged(int arg1, int arg2);

    void on_l21_cursorPositionChanged(int arg1, int arg2);
    void on_l22_cursorPositionChanged(int arg1, int arg2);
    void on_l23_cursorPositionChanged(int arg1, int arg2);
    void on_l24_cursorPositionChanged(int arg1, int arg2);

    void on_l31_cursorPositionChanged(int arg1, int arg2);
    void on_l32_cursorPositionChanged(int arg1, int arg2);
    void on_l33_cursorPositionChanged(int arg1, int arg2);
    void on_l34_cursorPositionChanged(int arg1, int arg2);

    void on_l41_cursorPositionChanged(int arg1, int arg2);
    void on_l42_cursorPositionChanged(int arg1, int arg2);
    void on_l43_cursorPositionChanged(int arg1, int arg2);
    void on_l44_cursorPositionChanged(int arg1, int arg2);

    void on_l51_cursorPositionChanged(int arg1, int arg2);
    void on_l52_cursorPositionChanged(int arg1, int arg2);
    void on_l53_cursorPositionChanged(int arg1, int arg2);
    void on_l54_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_pressed();

private:
    Ui::WordleGUI *ui;

    WordleLibrary api;

    int round = 1;
    void nextRound();

    void clearAll();

    void round1();
    void round2();
    void round3();
    void round4();
    void round5();
    void round6();

//    void editFirstLine();
//    void editSecondLine();
//    void editThirdLine();
//    void editForthLine();
//    void editFifthLine();
};
#endif // WORDLEGUI_H
