#ifndef WORDLELIBRARY_H
#define WORDLELIBRARY_H
#include <string>
#include <array>
#include "dictionaryuploader.h"
#include <iostream>

class WordleLibrary
{
public:
    WordleLibrary();
    void startGame(); //Choosing a random word to start the game
    bool submitWord(std::string word); //Returns true if the word exists and 5 letters long
    bool win();//returns true if win
    std::array<int, 5> errorsReturn();
    bool  isGameOver();
    std::string word();

private:
    std::array<int, 5> errors;// 0- no error, 1- letter exists in the word, but in other place, 2- there is no such letter in the word
    bool winRound;
    std::string gameWord;
    DictionaryUploader words;
    bool wordExists(std::string word);
    int gameRounds;
    bool gameOver;
    std::array<int, 5> compareWord(std::string originalWord, std::string userInput);

};

#endif // WORDLELIBRARY_H
