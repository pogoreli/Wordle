#include "wordlelibrary.h"

WordleLibrary::WordleLibrary()
{
    DictionaryUploader fiveLetterWords;
    words = fiveLetterWords;
}

void WordleLibrary::startGame() //Choosing a random word to start the game
{
    unsigned long wordsNumber = words.words.size();
    srand(time(NULL));
    unsigned long randomNumber = rand() % wordsNumber;
    gameWord = words.words[randomNumber];
    winRound = false;
    errors = {2, 2, 2, 2, 2};
    gameRounds = 0;
    gameOver = false;
    //std::cout << gameWord << std::endl; //debugging only
}

bool WordleLibrary::submitWord(std::string word) //Returns true if the word exists and 5 letters long
{
    gameRounds++;
    //check whether word exists
    if(gameRounds > 5)
    {
        gameOver = true;
        return false;
    }else
    {
        if(word.length() == 5)
        {
             if(wordExists(word))
             {
                 errors  = compareWord(gameWord,word);
                 bool won = true;
                 for(int i = 0; i < 5; i++)
                 {
                     if(errors[i] != 0)
                     {
                         won = false;
                         break;
                     }
                 }
                 if(won)
                 {
                     winRound = true;

                 }else
                 {
                     winRound = false;
                 }

                 return true;
             }else
             {
                 return false;
             }
        }else
        {
            return false;
        }
    }
}

bool WordleLibrary::isGameOver()
{
    return gameOver;
}

bool WordleLibrary::win()//returns true if win
{
    return winRound;
}

std::array<int, 5> WordleLibrary::errorsReturn()// 0- no error, 1- letter exists in the word, but in other place, 2- there is no such letter in the word
{
    return errors;
}

bool WordleLibrary::wordExists(std::string word)
{
    bool exists = false;
    std::vector<std::string> wordsVector = words.words;

    for(unsigned long i = 0; i < wordsVector.size(); i++)
    {
        if(word==wordsVector[i])
        {
            exists = true;
            break;
        }
    }

    return exists;
}

std::array<int, 5> WordleLibrary::compareWord(std::string originalWord, std::string userInput)
{
    std::array<int, 5> output;

    for(unsigned long i = 0; i < originalWord.length(); i++)
    {
        if(toupper(originalWord[i]) == toupper(userInput[i]))
        {
            output[i] = 0;
        }else
        {
            bool letterExists = false;
            char currentLetter = userInput[i];
            for(unsigned long j = 0; j < originalWord.length(); j++)
            {
                if(toupper(currentLetter) == toupper(originalWord[j]))
                {
                    letterExists = true;
                    break;
                }
            }
            if(letterExists)
            {
                output[i] = 1;
            }else
            {
                output[i] = 2;
            }
        }
    }
    return output;
}

std::string WordleLibrary::word()
{
    return gameWord;
}
