#include "dictionaryuploader.h"

DictionaryUploader::DictionaryUploader()
{
    filePath = "/home/pogoreli/Lab_4_5/Wordle/WordleLibrary/words.txt";
    //filePath = "/../WordleLibrary/words.txt";
    upload();
}

/**
 * Constructor for the class
 */
DictionaryUploader::DictionaryUploader(std::string path)
{
    filePath = path;
    upload();
}

/**
 * Uploads words from a file to a vector
 */
void DictionaryUploader::upload()
{
    std::ifstream myFile (filePath);
    std::string word;

    while(myFile >> word)
       {
           words.push_back(toLowerCase(word));
       }
}

std::string DictionaryUploader::toLowerCase(std::string word)
{
    std::string returnWord = word;

    for(unsigned long i = 0; i < word.length(); i++)
    {
        returnWord[i] = std::tolower(word[i]);
    }

    return returnWord;
}

/**
 * Debugging only. Prints all words to the console
 */
void DictionaryUploader::listWords()
{
    for(unsigned long i = 0; i < words.size(); i++)
    {
        std::cout << words[i] << std::endl;
    }
}
