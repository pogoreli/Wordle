
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../WordleLibrary/wordlelibrary.h>
#include <string>
#include <iostream>

using namespace testing;

WordleLibrary api;

TEST(WordleTest, GameStarts)
{
    api.startGame();
    ASSERT_TRUE(!api.isGameOver());
}


TEST(WordleTest, GameOver)
{
    api.startGame();
    api.submitWord("abcde");
    api.submitWord("abcde");
    api.submitWord("abcde");
    api.submitWord("abcde");
    api.submitWord("abcde");
    api.submitWord("abcde");
    ASSERT_TRUE(api.isGameOver());
}

TEST(WordleTest, incorrectWord)
{
    api.startGame();
    std::string correctWord = api.word();
    if(correctWord!="apple")
    {
        api.submitWord("apple");
    }else
    {
        api.submitWord("agent");
    }

    ASSERT_TRUE(!api.win());
}

TEST(WordleTest, correctWord)
{
    api.startGame();
    std::string correctWord = api.word();
    api.submitWord(correctWord);

    ASSERT_TRUE(api.win());
}

TEST(WordleTest, wordExists)
{
    api.startGame();

    ASSERT_TRUE(api.submitWord("apple"));
}

TEST(WordleTest, wordDoesNotExist)
{
    api.startGame();

    ASSERT_TRUE(!api.submitWord("abcde"));
}

