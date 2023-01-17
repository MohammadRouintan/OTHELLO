#include <iostream>
#include <string>
#include "menu.cpp"
#include "creategame.cpp"
#include "about.cpp"

using namespace std;

// return 123 => Return to the previous menu
int main()
{
    fstream Data("data.txt", ios::app);
    Data.close();
    system("clear");
    while (true)
    {
        int outPutNumber = Menu();
        if (outPutNumber == 0)
        {
            int checkNewGameNumber = newGame();
            if(checkNewGameNumber == 123)
            {
                continue;
            }
            else
            {
                break;
            }

        }
        else if (outPutNumber == 1)
        {
            int checkLoadGameNumber = loadGame();
            if (checkLoadGameNumber == 123)
            {
                continue;
            }
            else
            {  
                break;
            }
        }
        else if(outPutNumber == 2)
        {
            int checkRankingNumber = ranking();
            if (checkRankingNumber == 123)
            {
                continue;
            }
            else
            {  
                break;
            }
        }
        else if (outPutNumber == 3)
        {
            int checkAboutNumber = about();
            if (checkAboutNumber == 123)
                continue;
        }
        else if (outPutNumber == 4)
        {
            break;
        }
    }

    delete[] itemLoadGameMeue;
    itemLoadGameMeue  = nullptr;
    delete[] rankigList;
    rankigList = nullptr;

    return 0;
}
