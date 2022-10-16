#include "rungame.h"

RunGame::RunGame()
{

}

void RunGame::play()
{
    clearScreen();

    api.startGame();

    std::array<int, 5> arr; //for debugging only

    bool wonRound = false;

    for(int i = 0; i < 5; i++)
    {
        std::cout << "Enter your word. Attempt " << i+1 << " out of 5" << std::endl;
        std::string in;
        getline(std::cin, in);

        bool correct = api.submitWord(in);

        if(correct)
        {
        arr = api.errorsReturn();
        printWord(in, arr);
        }else
        {
            std::cout << "This word is not on the list" << std::endl;
        }

        wonRound = api.win();
        if(wonRound)
        {
            std::cout << "Your word is correct!" << std::endl;
            std::cout << "Press enter to continue the game" << std::endl;
            std::string in;
            getline(std::cin, in);
            break;
        }
    }
    if(!wonRound)
    {
        std::cout << "Game over! The correct word is: " << api.word() << std::endl;
        std::cout << "Press enter to start a new game" << std::endl;
        std::string in;
        getline(std::cin, in);
    }
}

void RunGame::printWord(std::string word, std::array<int, 5> colors) //0- green, 1- yellow, 2- red
{
    for(int i = 0; i < 5; i++)
    {
        if(colors[i]==0)
        {
            printGreenLetter(word[i]);
        }else if(colors[i]==1)
        {
            printYellowLetter(word[i]);
        }else if(colors[i]==2)
        {
            printRedLetter(word[i]);
        }else
        {
            std::cerr << "Invalid argument" << '\n';
        }

    }
    printf("\n");
}

void RunGame::printRedLetter(char letter)
{
    printf("\x1B[31m%c\033[0m", letter); //red
}

void RunGame::printGreenLetter(char letter)
{
    printf("\x1B[32m%c\033[0m", letter);
}

void RunGame::printYellowLetter(char letter)
{
    printf("\x1B[33m%c\033[0m", letter);
}

void RunGame::clearScreen()
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

