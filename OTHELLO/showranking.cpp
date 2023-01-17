#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <ctype.h>
#include <termios.h>
#include "saveranking.cpp"
#include "drawgame.cpp"

using namespace std;

void resizeArr(int *&dynamicArray, int &capacity);
void BubbleSort(int *arr, int n);

int size = 1;
int *rankigList = new int[size];

int getchRanking(void)
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

int show()
{
    if (get_file_ranking() == "123")
    {
        return 123;
    }
    logo("        RANKING        " ,8 ,0);
    cout << "\n\n";
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t\t";
    cout << "   ";
    cout << "\x1B[93m" << "NAME              WINS" << "\033[0m";
    cout << endl;
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t\t";
    cout << "   ";
    cout << "----------------------";
    cout << endl;
    string file =  get_file_ranking();
    int counter = rankingNumber();
    int find = 0;
    string temp ,username;

    for(int i = 0; i < counter; i++)
    {
        username = get_username(find);
        rankigList[i] = get_rank_number(username);
        if (i != counter - 1)
            resizeArr(rankigList ,size);
    }

    BubbleSort(rankigList ,size);

    string a =  get_file_ranking();

    find = 0;
    for (int i=0; i < counter; i++)
    {
        int temp = rankigList[i];
        int check = 0;
        while (true)
        {
            username = get_username(find);           
            check = get_rank_number(username);
            if(check == temp)
            {
                break;
            }
        }
        cout << "\e[1m\e";
        cout << "\t\t\t\t\t\t\t\t";
        cout << "   ";
        cout << left << "\x1B[93m" << setw(20) << username << "\033[0m" << temp << endl;
        cout << "\e[1m\e";
        cout << "\t\t\t\t\t\t\t\t";
        cout << "   ";
        if (i != counter - 1)
            cout << "----------------------";
        cout << endl;
    }
    size = 1;
    return 0;
}

int ranking()
{
    while(true)
    {
        system("clear");
        int back = show();
        if (back == 123)
        {
            return 123;
        }
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
        int temp = getchRanking();
        if (temp == 27)
        {
            system("clear");
            return 123;
        }
    }
}

void resizeArr(int *&dynamicArray, int &capacity)
{
    int *arr = new int[capacity + 1];

    for(int i=0; i < capacity; i++){
        arr[i] = dynamicArray[i];
    }

    capacity += 1;

    delete[] dynamicArray;
    dynamicArray = nullptr;

    dynamicArray = arr;
}

void BubbleSort(int *arr, int n)
{ 
    int temp; 
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n - 1; j++){ 
            if (arr[j] < arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
}