#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include "showranking.cpp"

using namespace std;

void square(string, int);
void menu(int , string *, int);
void switchItemLoadGame(string * ,int);
int getchLoadGame(void);

int MenuMoveLoadgame = 0;

int showLoadGameMenu(string *arr ,int size)
{
    MenuMoveLoadgame = 0;
    menu(0 , arr ,size);
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t\t";
    cout << "  ";
    cout << "-------------------------" << endl;
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t\t";
    cout << "          ";
    cout << "\x1B[93m" << "ESC: " << "\033[0m";
    cout << "\e[1m\e";
    cout << "\x1B[32m" << "BACK" << "\033[0m\t\t";
    cout << endl;
    switchItemLoadGame(arr ,size);
    return MenuMoveLoadgame;
}

void square(string name, int height)
{
    int size = name.length();
    cout <<  "\t\t\t\t\t\t\t\t\t";
    for (int i = 0; i < size + 4; i++)
    {
        if (i == 0)
        {
            cout << "\u2554";
        }
        else if (i == size + 3)
        {
            cout << "\u2557";
        }
        else
        {
            cout << "\u2550";
        }
    }
    
    cout << endl << "\t\t\t\t\t\t\t\t\t";
    bool flag = true;
    for (int j = 0; j < height - 2; j++)
    {
        for (int i = 0; i < size + 4; i++)
        {
            if (i == 0 || i == size + 1)
            {
                cout << "\u2551";
            }
            else
            {
                if (flag)
                {
                    cout << " " << name << " ";
                    flag = false;
                }
            }
        }
        cout << endl;
    }

    cout << "\t\t\t\t\t\t\t\t\t";
    for (int i = 0; i < size + 4; i++)
    {
        if (i == 0)
        {
            cout << "\u255A";
        }
        else if (i == size + 3)
        {
            cout << "\u255D";
        }
        else
        {
            cout << "\u2550";
        }
    }
}

void menu(int MenuMove1 ,string *arr ,int size)
{
    cout << "\n\n";
    for(int i = 0; i < size - 1; i++)
    {
        if (i == MenuMove1 and arr[i] != "")
        {
            square(arr[i], 3);
            cout << endl;
        }
        else if (arr[i] != "")
        {
            cout << "\e[1m\e" << endl;
            cout << "\t\t\t\t\t\t\t\t\t" << i + 1 << ".  "  << "\x1B[93m" << arr[i] << "\033[0m" << endl;
        }
    }
    cout << endl << endl;
}

void switchItemLoadGame(string *arr ,int size)
{
    int InputKey1;
    while (true)
    {
        InputKey1 = getchLoadGame();
        if (InputKey1 == 115)
        {
            if (MenuMoveLoadgame >= size - 2)
            {
                MenuMoveLoadgame = -1;
            }
            MenuMoveLoadgame++;
            system("clear");
            logo("     LOAD GAME     " , 8 , 2);
            menu(MenuMoveLoadgame ,arr ,size);
            cout << "\e[1m\e";
            cout << "\t\t\t\t\t\t\t\t";
            cout << "  ";
            cout << "-------------------------" << endl;
            cout << "\e[1m\e";
            cout << "\t\t\t\t\t\t\t\t";
            cout << "          ";
            cout << "\x1B[93m" << "ESC: " << "\033[0m";
            cout << "\e[1m\e";
            cout << "\x1B[32m" << "BACK" << "\033[0m\t\t";
        }
        else if (InputKey1 == 119)
        {
            MenuMoveLoadgame--;
            if (MenuMoveLoadgame < 0)
            {
                MenuMoveLoadgame = size - 2;
            }
            system("clear");
            logo("     LOAD GAME     " , 8 , 2);
            menu(MenuMoveLoadgame ,arr ,size);
            cout << "\e[1m\e";
            cout << "\t\t\t\t\t\t\t\t";
            cout << "  ";
            cout << "-------------------------" << endl;
            cout << "\e[1m\e";
            cout << "\t\t\t\t\t\t\t\t";
            cout << "          ";
            cout << "\x1B[93m" << "ESC: " << "\033[0m";
            cout << "\e[1m\e";
            cout << "\x1B[32m" << "BACK" << "\033[0m\t\t";
        }
        else if (InputKey1 == 10)
        {
            system("clear");
            break;
        } 
        else if (InputKey1 == 27)
        {
            MenuMoveLoadgame = -1;
            break; 
        }
    }  
}

int getchLoadGame(void)
{
   struct termios oldattr, newattr;
   int ch;
   tcgetattr(0, &oldattr);
   newattr=oldattr;
   newattr.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( 0, TCSANOW, &newattr);
   ch=getchar();
   tcsetattr(0, TCSANOW, &oldattr);
   return(ch);
}