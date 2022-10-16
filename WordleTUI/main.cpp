#include <iostream>
//#include <../WordleLibrary/wordlelibrary.h>
#include <bits/stdc++.h>
#include <rungame.h>

using namespace std;

int main()
{
    RunGame rg;

    std::cout << "Press enter to start a new game" << std::endl;
    std::string in;
    getline(cin, in);

    while(true)
    {
        rg.play();
    }

    return 0;
}
