#include <iostream>
#include <string>

using namespace std;

// This function draws square.
void drawSquare(int height, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            cout << "\u2554";
        }
        else if (i == length - 1)
        {
            cout << "\u2557";
        }
        else
        {
            cout << "\u2550";
        }
    }
    
    cout << endl;
    for (int j = 0; j < height - 2; j++)
    {
        for (int i = 0; i < length; i++)
        {
            if (i == 0 || i == length - 1)
            {
                cout << "\u2551";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            cout << "\u255A";
        }
        else if (i == length - 1)
        {
            cout << "\u255D";
        }
        else
        {
            cout << "\u2550";
        }
    }
}


// This function draws a square around the menu items.
void drawSquare(string name, int height)
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
                    cout <<" "<<name <<" ";
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