#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include "drawmenu.cpp"

using namespace std;

void ShowMenu(int);
void SwitchItem();
int getchMenu(void);
void Logo(string);

const int MenuSize = 5;
const string MenuItem[MenuSize] = {"New Game", "Load Game", "Ranking", "About", "Exit"};
int MenuMove = 0;

// This function includes other functions and performs all operations on the menu.
int Menu()
{
    MenuMove = 0;
    Logo("       OTHELLO       ");
    ShowMenu(0);
    cout << endl;
    SwitchItem();
    return MenuMove;
}

// This function organizes the menu shape and displays it.
void ShowMenu(int MenuMove)
{
    cout << "\n\n";
    for (int i = 0; i < MenuSize; i++)
    {
        if (i == MenuMove)
        {
            drawSquare(MenuItem[i], 3);
            cout << endl;
        }
        else
        { 
            cout << "\e[1m\e" << endl;
            cout << "\t\t\t\t\t\t\t\t\t" << i + 1 << ".  "  << "\x1B[93m" << MenuItem[i] << "\033[0m" << endl;
        }
    }
    cout << endl << endl;
}

// This function moves on menu items.
void SwitchItem()
{
    int InputKey;
    while(true)
    {
        InputKey = getchMenu();
        if(InputKey == 115)
        {
            if(MenuMove >= MenuSize - 1)
            {
                MenuMove = -1;
            }
            MenuMove++;
            system("clear");
            Logo("       OTHELLO       ");
            ShowMenu(MenuMove);
        }
        else if(InputKey == 119)
        {
            MenuMove--;
            if(MenuMove < 0)
            {
                MenuMove = MenuSize - 1;
            }
            system("clear");
            Logo("       OTHELLO       ");
            ShowMenu(MenuMove);
        }
        else if(InputKey == 10)
        {
            system("clear");
            break;
        } 
    }  
}

int getchMenu(void)
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

void Logo(string show)
{
    cout << "\n\n";
    int len = show.size();
    bool flag = true;
    len += 4;
    for (int i=0; i < 7; i++)
    {
        cout << "\t\t\t\t\t\t\t";
        cout << "          ";
        for (int j=0; j < len; j++)
        {

            if ((j == 0 and i == 0) || (i == 1 and j == 1))
            {
                if(i == 1 and j == 1)
                {
                    cout << "\e[1m\e";
                    cout << "\u2554";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2554" << "\033[0m";
                }
            }
            else if ((i == 0 and j == len - 1 )|| (i == 1 and j == len - 2))
            {
                if(i == 1 and j == len - 2)
                {
                    cout <<"\e[1m\e";
                    cout << "\u2557";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2557" << "\033[0m";
                }
            }
            else if ((i == 6 and j == 0) || (i == 5 and j == 1))
            {
                if (i == 5 and j == 1)
                {
                    cout << "\e[1m\e";
                    cout << "\u255A";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u255A" << "\033[0m";
                }
            }
            else if ((i == 6 and j == len - 1) || (i == 5 and j == len - 2))
            {
                if (i == 5 and j == len - 2)
                {
                    cout << "\e[1m\e";
                    cout << "\u255D";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u255D" << "\033[0m";
                }
            }
            else if ((i == 1 and j == 0) || ( i == 1 and j == len -1 ) || ( i == 5 and j == 0) || ( i == 5 and j == len -1))
            {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2551" << "\033[0m";
            }
            else if (i == 0 || i == 6 || i == 1 || i == 5)
            {
                if (i == 1 || i == 5)
                {
                    cout << "\e[1m\e";
                    cout << "\u2550";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2550" << "\033[0m";
                }
            }
            else if (i == 3)
            {
                if (j == 0 || j == len-1 || j == 1 || j == len-2)
                {
                    if (j == 1 || j == len-2)
                    {
                        cout << "\e[1m\e";
                        cout << "\u2551";
                    }
                    else
                    {
                        cout << "\e[1m\e";
                        cout << "\x1B[93m" << "\u2551" << "\033[0m";
                    }
                }
                else if (flag)
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << show << "\033[0m";
                    flag = false;
                }
            }
            else if ((j == 0 || j == len-1 || j == 1 || j == len-2))
            {
                if (j == 1 || j == len-2)
                {
                    cout << "\e[1m\e";
                    cout << "\u2551";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2551" << "\033[0m";
                }
            }
            else
            {
                if (j != len - 3)
                    cout <<" ";
                else
                    cout << "  ";
            }
        }
        cout << "\n";
    }
}