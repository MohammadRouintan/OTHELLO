#include <iostream>

using namespace std;

void showSquare(string name, int height)
{
    int size = name.length();
    cout << "\t\t\t\t\t\t\t\t\t";
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


void drawTable(int size, int x, int y , string array[12][12])
{
    cout << "\n\n";
    int m = 0, n = 0;
    for (int i = 0; i < 2 * size + 1; i++)
    {
        switch (size)
        {
            case 4:
                cout << "\t\t\t\t\t\t\t\t";
                cout << "    ";
                break;
            case 6:
                cout << "\t\t\t\t\t\t\t";
                cout << "        ";
                break;
            case 8:
                cout << "\t\t\t\t\t\t\t";
                cout << "    ";
                break;
            case 10:
                cout << "\t\t\t\t\t\t\t";
                break;
            case 12:
                cout << "\t\t\t\t\t\t";
                cout << "    ";
                break; 
            default:
                break;       
        }
        for (int j = 0; j < 4 * size + 1; j++)
        {
            if (i == x * 2 and j == y * 4)
                cout << "\u2554";
            else if (i == 0 and j == 4 * size)
            {   if (i == x * 2 and j == (y + 1) * 4)
                    cout << "\u2557";
                else 
                    cout << "\u2510";
            }
            else if (i == x * 2 and j % 4 == 0)
            {
                if (j == (y + 1) * 4)
                    cout << "\u2557";
                else if (i == 0 and j == 0)
                    cout << "\u250C";
                else if (i == 0)
                    cout << "\u252C";
                else if (i == 2 * size)
                    cout << "\u2534";
                else if (j == 0)
                    cout << "\u251C";
                else if (j == 4 * size)
                    cout << "\u2524";
                else
                    cout << "\u253C";
            }
            else if (i == x * 2 and j % 4 != 0)
            {
                if (j < (y + 1) * 4 and j > y * 4)
                    cout << "\u2550";
                else
                    cout << "\u2500";
            }
            else if (i == 2 * size and j == 0)
            {
                if (i == (x + 1) * 2 and j == y * 4)
                    cout << "\u255A";
                else
                    cout << "\u2514";
            }
            else if (i == 2 * size and j == 4 * size)
            {
                if (i == (x + 1) * 2 and j == (y + 1) * 4)
                    cout << "\u255D";
                else
                    cout << "\u2518";
            }    
            else if (i == 2 * size and j % 4 == 0)
            {
                if (i == (x + 1) * 2 and j == y * 4)
                    cout << "\u255A";
                else if (i == (x + 1) * 2 and j == (y + 1) * 4)
                    cout << "\u255D";
                else    
                    cout << "\u2534";
            }
            else if (i == 2 * size and j % 4 != 0)
            {
                if (i == (x + 1) * 2 and j > y * 4 and j < (y + 1) * 4)
                    cout << "\u2550";
                else    
                    cout << "\u2500";
            }
            else if (i % 2 != 0 and j % 4 == 0)
            {
                if (i > x * 2 and i < (x + 1) * 2 and j <= (y + 1) * 4 and j >= y * 4)
                    cout << "\u2551";
                else
                    cout << "\u2502";
            }
            else if (i % 2 != 0 and j % 4 != 0)
            {
                if (i % 2 != 0 and j % 2 == 0 and j % 4 != 0)
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << array[m][n] << "\033[0m";
                    n++;
                }    
                else
                    cout << " ";
            }    
            else if (i % 2 == 0 and j == y * 4)
            {
                if (i == (x + 1) * 2)
                    cout << "\u255A";
                else if (i == 0 and j == 0)
                    cout << "\u250C";
                else if (i == 0)
                    cout << "\u252C";
                else if (i == 2 * size)
                    cout << "\u2534";
                else if (j == 0)
                    cout << "\u251C";
                else
                    cout << "\u253C";
            }
            else if (i % 2 == 0 and j % 4 != 0)
            {
                if (i == (x + 1) * 2 and j < (y + 1) * 4 and j > y * 4)
                    cout << "\u2550";
                else
                    cout << "\u2500";
            }
            else if (i % 2 == 0 and j % 4 == 0)
            {
                if (i == (x + 1) * 2 and j == (y + 1) * 4)
                    cout << "\u255D";
                else if (i == 0 and j == 4 * size)
                    cout << "\u2514";
                else if (i == 0 and j == 0)
                    cout << "\u250C";
                else if (i == 2 * size and j == 0)
                    cout << "\u2510";
                else if (i == 2 * size and j == 4 * size)
                    cout << "\u2518";
                else if (i == 0)
                    cout << "\u252C";
                else if (i == 2 * size)
                    cout << "\u2533";
                else if (j == 0)
                    cout << "\u251C";
                else if (j == 4 * size)
                    cout << "\u2524";
                else
                    cout << "\u253C";
            }
        }
        n = 0;
        if (i % 2 != 0)
            m++;
        cout << endl;
    }

    cout << "\n\n";
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t";
    cout << "  ----------------------------------------------------" << endl;
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t";
    cout << "   ";
    cout << "\x1B[93m" << "W:" << "\033[0m";
    cout << "UP  ";
    cout << "\e[1m\e";
    cout << "\x1B[93m" << "A:" << "\033[0m";
    cout << "LEFT  ";
    cout << "\e[1m\e";
    cout << "\x1B[93m" << "S:" << "\033[0m";
    cout << "DOWN  ";
    cout << "\e[1m\e";
    cout << "\x1B[93m" << "D:" << "\033[0m";
    cout << "RIGHT  ";
    cout << "\e[1m\e";
    cout << "\x1B[93m" << "SPACE:" << "\033[0m";
    cout << "PUT  ";
    cout << "\e[1m\e";
    cout << "\x1B[93m" << "ESC:" << "\033[0m";
    cout << "EXIT  ";

    cout << endl;
}

/* This function takes the string from the input 
and prints it as a logo with the desired tab size and spacing */
void logo(string show ,int tab ,int space)
{
    cout << "\n\n";
    int len = show.size();
    bool flag = true;
    len += 4;
    for(int i=0; i < 7; i++)
    {
        for(int k=0; k < tab; k++)
        {
            cout << "\t";
        }
        for(int l=0; l < space; l++)
        {
            cout << " ";
        }

        for(int j=0; j < len; j++)
        {
            if((j == 0 and i == 0) || (i == 1 and j == 1))
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
            else if((i == 0 and j == len - 1 )|| (i == 1 and j == len - 2))
            {
                if (i == 1 and j == len - 2)
                {
                    cout << "\e[1m\e";
                    cout << "\u2557";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2557" << "\033[0m";
                }
            }
            else if((i == 6 and j == 0) || (i == 5 and j == 1))
            {
                if(i == 5 and j == 1)
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
            else if((i == 6 and j == len - 1) || (i == 5 and j == len - 2))
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
            else if((i == 1 and j == 0) || ( i == 1 and j == len -1 ) || ( i == 5 and j == 0) || ( i == 5 and j == len -1))
            {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2551" << "\033[0m";
            }
            else if(i == 0 || i == 6 || i == 1 || i == 5)
            {
                if(i == 1 || i == 5)
                {
                    cout << "\e[1m\e";
                    cout << "\u2550";
                }else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2550" << "\033[0m";
                }
            }
            else if(i == 3)
            {
                if(j == 0 || j == len-1 || j == 1 || j == len-2)
                {
                    if(j == 1 || j == len-2)
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
                else if(flag)
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << show << "\033[0m";
                    flag = false;
                }

            }
            else if((j == 0 || j == len-1 || j == 1 || j == len-2))
            {
                if(j == 1 || j == len-2)
                {
                    cout << "\e[1m\e";
                    cout << "\u2551";
                }
                else
                {
                    cout << "\e[1m\e";
                    cout << "\x1B[93m" << "\u2551" << "\033[0m";
                }
            }else
            {
                if(j != len - 3)
                    cout <<" ";
                else
                    cout << "  ";
            }
        }

        cout << "\n";

    }
}