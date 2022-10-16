#ifndef DICTIONARYUPLOADER_H
#define DICTIONARYUPLOADER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>


class DictionaryUploader
{
public:
    DictionaryUploader();
    DictionaryUploader(std::string path);
    std::vector<std::string> words;
    void listWords();


private:
    void upload();
    std::string filePath;
    std::string toLowerCase(std::string word);


};

#endif // DICTIONARYUPLOADER_H
