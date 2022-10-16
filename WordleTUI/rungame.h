#ifndef RUNGAME_H
#define RUNGAME_H
#include <../WordleLibrary/wordlelibrary.h>
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>


class RunGame
{
public:
    RunGame();
    void play();
private:
    WordleLibrary api;
    void printWord(std::string word, std::array<int, 5> colors);
    void printRedLetter(char letter);
    void printGreenLetter(char letter);
    void printYellowLetter(char letter);
    void clearScreen();
};

#endif // RUNGAME_H
