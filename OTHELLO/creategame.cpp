/*
Functions from drawgame.cpp => showSquare, drawTable, logo.
Functions from findvalue.cpp => findUsername1, findSymbol2, findSize and ...
findvalue.cpp find a value from data.txt
Functions from showmessage.cpp => defaultMessage, errorMessage.
logic.cpp checks and performs all logical operations of the game.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include <termios.h>
#include <unistd.h>
#include "logic.cpp"
#include "loadgame.cpp"
#include "findvalue.cpp"
#include "showmessage.cpp"

using namespace std;

int getchTable(void);
void showMenu(int, int, string []);
void switchItem(string, int&, int, string []);
void inputUserValue(bool);
void showValue();
int gameRender(bool, bool, bool);
int switchTable(bool, bool);
void defaultTableInfo();
void resize(string *&, int &);
int createMenuLoadGame();
void fillData(string);
void saveGame(bool);
void defaultStruct();

int counterX = 0;
int counterY = 0;


int tempsize = 0;
const int numberUser = 2;
bool checkEnter = false;
string winner = "0";

// Menu one to select the game
int menuMove1 = 0;
const int menuSize1 = 3;
string menuItem1[menuSize1] = {"Two Players" ,"Play With PC" ,"Back"};

// Menu one to saving the game
int menuMove2 = 0;
const int menuSize2 = 3;
string menuItem2[menuSize2] = {"YES" ,"NO" ,"Back"};

string tableInfo[12][12];
struct Users
{
    string savegamename;
    string name;
    string symbol;
    int sizeTable;
    int Turn;
    int picees;
    int rank;
};

Users usersValue[numberUser];
int sizeOfLoadGameMenu = 1;
string *itemLoadGameMeue = new string[sizeOfLoadGameMenu];

// return 123 => Return to the previous menu
int newGame()
{
    defaultStruct();
    counterX = 0;
    counterY = 0;
    menuMove1 = 0;
    menuMove2 = 0;
    defaultTableInfo();
    /* This function takes the string from the input 
    and prints it as a logo with the desired tab size and spacing */
    logo("     SELECT GAME     " ,8 , 3);
    showMenu(0, menuSize1, menuItem1);
    switchItem("     SELECT GAME     " , menuMove1, menuSize1, menuItem1);

    if (menuMove1 == 2)
    {
        menuMove1 = 0;
        return 123;
    }
    else if (menuMove1 == 0)
    {
        int temp = gameRender(false, false, false);
        if (temp == 123)
        {
            system("clear");
            return 123;
        }
    }
    else if (menuMove1 == 1)
    {
        system("clear");
        int temp = gameRender(true, false, false);
        if (temp == 123)
        {
            system("clear");
            return 123;
        }
    }
    return 0;
}

int loadGame()
{
    defaultStruct();
    menuMove2 = 0;
    counterX = 0;
    counterY = 0;
    logo("     LOAD GAME     " , 8 , 2);

    int numberMenuLoadGame = createMenuLoadGame();
    if (numberMenuLoadGame == -1)
    {
        system("clear");
        return 123;
    }
    fillData(itemLoadGameMeue[numberMenuLoadGame]);
    system("clear");
    showValue();
    drawTable(usersValue[0].sizeTable ,counterX ,counterY, tableInfo);

    if (usersValue[1].name == "Computer")
    {
        gameRender(true, true, true);
    }
    else
    {
        gameRender(false, true, true);
    }
    system("clear");
    return 123;
}

// This function reads information from the file and save it in the structure
void fillData(string savegamename)
{
    for (int i = 0; i < numberUser; i++)
    {
        usersValue[i].savegamename = get_NameSaveGame(savegamename);
        if (i == 0)
        {
            usersValue[i].name = findUsername1(savegamename);
            usersValue[i].symbol= findSymbol1(savegamename);
            usersValue[i].Turn = findTurn1(savegamename);
            usersValue[i].picees = findPieces1(savegamename);
            usersValue[i].sizeTable = findSize(savegamename);
        }
        else
        {
            usersValue[i].name = findUsername2(savegamename);
            usersValue[i].symbol= findSymbol2(savegamename);
            usersValue[i].Turn = findTurn2(savegamename);
            usersValue[i].picees = findPieces2(savegamename);
            usersValue[i].sizeTable = findSize(savegamename);
        }
    }
    /* from findvalue.cpp
       This function reads array information from a file and save it in the input array. 
    */
    get_Table(savegamename ,tableInfo);
}


int createMenuLoadGame()
{
    fstream data("data.txt", ios :: in);
    if (!data)
    {
        cout << "File could not be opened\n";
        return -1;
    }

    string dataInfo ,temp;
    data >> temp;
    while (!data.eof())
    {
        dataInfo += " " + temp;
        data >> temp;
    }

    int find1 = 0;
    int find2 = 0;
    int counter = 0;
    sizeOfLoadGameMenu = 1;
    while (true)
    {
        find1 = dataInfo.find("NAME: " ,find1);
        find2 = dataInfo.find("username1:" ,find2);
        find1 += 5;
        find2 -= 1;
        if(find1 == 4) break;

        string contaner =  dataInfo.substr(find1 + 1 ,find2 - find1);
        itemLoadGameMeue[counter] = contaner;
        
        resize(itemLoadGameMeue ,sizeOfLoadGameMenu);
        counter++;
        find2 += 10;
    }
    int enteredMenu = showLoadGameMenu(itemLoadGameMeue ,sizeOfLoadGameMenu);

    data.close();
    return enteredMenu;
}


void showMenu(int menuMove1, int menuSize1, string menuItem[])
{
    cout << "\n\n";
    for (int i = 0; i < menuSize1; i++)
    {
        if (i == menuMove1)
        {
            showSquare(menuItem[i], 3);
            cout << endl;
        }
        else
        {
            cout << "\e[1m\e" << endl;
            cout << "\t\t\t\t\t\t\t\t\t" << i + 1 << ".  " << "\x1B[93m" << menuItem[i] << "\033[0m" << endl;
        }
    }
    cout << endl << endl;
}

// This function switches on menu items.
void switchItem(string text, int &menuMove, int menuSize, string MenuItem[])
{
    int InputKey1;
    while (true)
    {
        InputKey1 = getchTable();
        if (InputKey1 == 115)
        {
            if (menuMove >= menuSize - 1)
            {
                menuMove = -1;
            }
            menuMove++;
            system("clear");
            logo(text, 8, 3);
            showMenu(menuMove, menuSize, MenuItem);
        }
        else if (InputKey1 == 119)
        {
            menuMove--;
            if (menuMove < 0)
            {
                menuMove = menuSize - 1;
            }
            system("clear");
            logo(text, 8, 3);
            showMenu(menuMove, menuSize, MenuItem);
        }
        else if (InputKey1 == 10)
        {
            system("clear");
            break;
        } 
    }  
}

// This function receives player information in each game mode and save it in the structure. 
void inputUserValue(bool playWithPC)
{
    if(!playWithPC)
    {
        system("clear");
        logo("            INFO            " ,7 , 8);
        cout << "\n\n";
        for (int i = 0; i < numberUser; i++)
        {
            cout <<"\e[1m\e" <<  "\t\t\t\t\t\t\t\t";
            cout << "\x1B[93m"<<"Player " << i + 1 << " => " << "Name:(without space) "  << "\033[0m";

            cin >> (usersValue[i].name);
            while (usersValue[0].name == usersValue[1].name)
            {
                errorMessage("Please enter diffrent name(without space) :  ");
                cin >> usersValue[1].name;
            }
    
            cout <<"\e[1m\e";
            cout <<"\t\t\t\t\t\t\t\t";
            cout << "\x1B[93m"<<"Player " << i + 1 << " => " << "Symbol: "<< "\033[0m";

            cin >> usersValue[i].symbol;
            while (usersValue[0].symbol == usersValue[1].symbol)
            {
                errorMessage("Please enter diffrent symbol :  ");
                cin >> usersValue[1].symbol;
            }

            string temp = usersValue[i].symbol;
            while (temp.length() > 1)
            {
                errorMessage("Your symbol is more than one character." );
                cout << endl;
                defaultMessage("Please enter again a symbol:");
        
                cin >> usersValue[i].symbol;
                temp = usersValue[i].symbol;
            }
            cout << endl;
        }     
    }
    else
    {
        usersValue[1].name = "Computer";
        usersValue[1].symbol= "o";
        system("clear");
        logo("            INFO            " ,7 , 8);

        cout << "\n\n";
        defaultMessage("Player => Name:(without space) ");
        cin >> (usersValue[0].name);
        while (usersValue[0].name == usersValue[1].name)
        {
            errorMessage("Please enter diffrent name(without space):  ");
            cin >> usersValue[0].name;
        }

        defaultMessage("Player => Symbol: ");
        cin >> usersValue[0].symbol;
        while (usersValue[0].symbol == usersValue[1].symbol)
        {
            errorMessage("Your symbol can not < o > : ");
            cin >> usersValue[1].symbol;
        }

        string temp = usersValue[0].symbol;
        while (temp.length() > 1)
        {
            errorMessage("Your symbol is more than one character.");
            cout << endl;
            defaultMessage("Please enter again a symbol: ");

            cin >> usersValue[0].symbol;
            temp = usersValue[0].symbol;
        }
        cout << endl;
    }

    defaultMessage("Enter size of table: ");
    string integer;
    cin >> integer;

    int number = atoi(integer.c_str());
    bool checkLoop = false;
    int length = integer.length();
    for (int i = 0; i < length; i++)
    {
        if (isalpha(integer[i]))
        {
            checkLoop = true;
            break;
        }
    }
    while(checkLoop)
    {
        errorMessage("Please enter again a size: ");
        cin >> integer;
        length = integer.length();
        for (int i = 0; i < length; i++)
        {
            if (isalpha(integer[i]))
            {
                checkLoop = false;
                break;
            }
        }
        if (!checkLoop)
        {
            checkLoop = true;
            continue;
        }
        number = atoi(integer.c_str());
        if (number > 3)
        {
            break;
        }
    }
    usersValue[0].sizeTable = number;

    tempsize = usersValue[0].sizeTable;
    while (tempsize % 2 != 0)
    {
        errorMessage("Size of your table cannot an odd number.");
        cout << endl;
        defaultMessage("Please enter again a size: ");

        cin >> usersValue[0].sizeTable;
        tempsize = usersValue[0].sizeTable;
        while (tempsize > 12)
        {
            errorMessage("Size of your table cannot bigger than 12.");
            cout << endl;
            defaultMessage("Please enter again a size: ");

            cin >> usersValue[0].sizeTable;
            tempsize = usersValue[0].sizeTable;
        }
    }
    usersValue[1].sizeTable = tempsize;
    defaultTableInfo();
}

// This function displays player information.
void showValue()
{
    system("clear");
    logo("                   OTHELLO                   " ,6 ,4);
    cout << "\n\n";
    for (int i = 0; i < numberUser; i++)
    {
        cout << "\e[1m\e";
        cout << "\t\t\t\t\t\t";
        cout << "\x1B[93m" << "    Player " << i + 1 << ": " << "\033[0m";
        cout << left << setw(10) << usersValue[i].name; 
        cout << "\e[1m\e";
        cout << setw(10) << "\x1B[93m" << "Symbol: " << "\033[0m";
        cout << usersValue[i].symbol;
        cout << "\e[1m\e";
        cout << setw(10) << "\x1B[93m" << "Pieces: " << "\033[0m";
        cout << usersValue[i].picees;
        cout << endl;
    }
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t";
    cout << "    ------------------------------------------------" << endl;

    if (usersValue[0].Turn == 0)
    {
        cout << "\t\t\t\t\t\t\t\t\t";
        cout << "\x1B[93m" << "Turn: " << "\033[0m";
        cout << usersValue[0].name << endl;
    }
    else 
    {
        cout << "\t\t\t\t\t\t\t\t\t";
        cout << "\x1B[93m" << "Turn: " << "\033[0m";
        cout << usersValue[1].name << endl;
    }
}

int gameRender(bool playWithPcNewGame ,bool checkLoadGame, bool deleteInfo)
{
    /*
    default flag = -1
    if push esc switchTable return 1 and flag = 1 and show savemenu.
    if the game is over switchTable return 0 and flag = 0 and break while loop and show winner.
    */
    int flag = -1;
    if (!checkLoadGame)
        inputUserValue(playWithPcNewGame);
    
    while (flag == -1)
    { 
        flag = switchTable(playWithPcNewGame, deleteInfo); 
        if (flag == 1)
        {
            system("clear");
            cout <<"\e[1m\e" << endl;
            logo("     SAVING     ", 8, 3);
            cout << "\n\n";
            showMenu(0, menuSize2, menuItem2);
            switchItem("     SAVING     ", menuMove2, menuSize2, menuItem2);
            if (menuMove2 == 0)
            {
                if(checkLoadGame)
                {
                    saveGame(true);
                }
                else
                {
                    saveGame(false);
                }
                fstream data("data.txt", ios::in);
                if (!data)
                {
                    return 123;
                }
                data.close();
                flag = 1;
            }
            else if (menuMove2 == 1)
            {
                flag = 1;
            }
            else if (menuMove2 == 2)
            {
                flag = -1;
                showValue();
                drawTable(usersValue[0].sizeTable ,counterX ,counterY , tableInfo);
                continue;
            }
        }
    }

    if (winner != "0")
    {
        if (winner == "equal")
        {
            cout << endl << endl;
            defaultMessage("    The game equalized");
            cout << endl;
        }
        else
        {
            fstream out("ranking.txt", ios::app);
            if (!out)
            {
                cout << "File could not be opened\n";
                return 123;
            }

            if (userExist(winner))
            {
                updateRanking(winner);
            }
            else
            {
                out << "RANK: ";
                out << "username: ";
                out << winner;
                out << " ";
                out << "wins: ";
                out << "1  ";
                out << "END ";
            }
            out.close();
            cout << endl << endl;
            cout <<"\e[1m\e";
            cout << "\t\t\t\t\t\t\t\t\t";
            cout << "\x1B[93mwinner: \033[0m";
            cout <<"\e[1m\e";
            cout << "\x1B[32m" << winner << "\033[0m\t\t";
            cout << endl;
        }
        usleep(3000000);   
    }
    return 123;   
}

int switchTable(bool playWithPC, bool checkLoadGame)
{
    int flag = 0;
    int inputKey;
    int checkInput;

    while (true)
    {
        if (playWithPC and usersValue[0].Turn == 0)
            inputKey = getchTable();
        if (!playWithPC)
            inputKey = getchTable();
        switch (inputKey)
        {
            case 119:
                counterX--;
                if(counterX < 0){
                    counterX = usersValue[0].sizeTable - 1;
                }
                break;
            case 115:
                counterX++;
                if(counterX > usersValue[0].sizeTable - 1){
                    counterX = 0;
                }
                break;
            case 100:
                counterY++;
                if(counterY > usersValue[0].sizeTable - 1){
                    counterY = 0;
                }
                break;
            case 97:
                counterY--;
                if(counterY < 0){
                    counterY = usersValue[0].sizeTable - 1;
                }
                break;
            case 32:
                checkEnter = true;
                break;
            case 27:
                flag = 1;
                break;
            default:
                break;
        }
        if (flag == 1)
        {
            break;
        } 
        /*
        if userValue[0].Turn = 0 then it is the turn of the first player.
        if userValue[1].Turn = 1 then it is the turn of the second player.
        */

        if (!playWithPC)
        {
            if (checkEnter and usersValue[0].Turn == 0)
            {
                checkInput = Logic(counterX, counterY, tableInfo, usersValue[0].symbol, usersValue[1].symbol, usersValue[0].sizeTable, usersValue[0].Turn ,usersValue[0].picees ,usersValue[1].picees);
                if(checkInput == 0)
                {
                    tableInfo[counterX][counterY] = usersValue[0].symbol;
                    usersValue[0].Turn = -1;
                    usersValue[1].Turn = 1;
                    checkEnter = false;

                }
                else
                {
                    checkEnter = false;
                    continue;
                }

            }
            else if (checkEnter and usersValue[1].Turn == 1)
            {
                checkInput = Logic(counterX, counterY, tableInfo, usersValue[0].symbol, usersValue[1].symbol, usersValue[0].sizeTable, usersValue[1].Turn ,usersValue[0].picees ,usersValue[1].picees);
                if(checkInput == 0)
                {
                    tableInfo[counterX][counterY] = usersValue[1].symbol;
                    usersValue[1].Turn = -1;
                    usersValue[0].Turn = 0;
                    checkEnter = false;
                }
                else 
                {
                    checkEnter = false;
                    continue;
                }
            }

            if (usersValue[0].Turn == 0)
            {
                int temp = checkChangeTurn(tableInfo ,usersValue[0].sizeTable ,usersValue[0].Turn, usersValue[0].symbol ,usersValue[1].symbol);
                if (temp == -1)
                {
                    usersValue[0].Turn = -1;
                    usersValue[1].Turn = 1; 
                }
            }
            else if (usersValue[1].Turn == 1)
            {
                int temp = checkChangeTurn(tableInfo ,usersValue[0].sizeTable ,usersValue[1].Turn, usersValue[0].symbol ,usersValue[1].symbol);
                if (temp == -1)
                {
                    usersValue[1].Turn = -1;
                    usersValue[0].Turn = 0;
                }
            }
        }
        else
        { 
            if (checkEnter and usersValue[0].Turn == 0)
            {
                checkInput = Logic(counterX, counterY, tableInfo, usersValue[0].symbol, usersValue[1].symbol, usersValue[0].sizeTable, usersValue[0].Turn ,usersValue[0].picees ,usersValue[1].picees);
                if (checkInput == 0)
                {
                    tableInfo[counterX][counterY] = usersValue[0].symbol;
                    usersValue[0].Turn = -1;
                    usersValue[1].Turn = 1;
                }
                else
                {
                    int temp = checkChangeTurn(tableInfo ,usersValue[0].sizeTable ,usersValue[0].Turn, usersValue[0].symbol ,usersValue[1].symbol);
                    if (temp == -1)
                    {
                        usersValue[0].Turn = -1;
                        usersValue[1].Turn = 1; 
                    }
                }
                checkEnter = false;
            }
            else if (usersValue[1].Turn == 1)
            {
                checkEnter = false;
                while(true)
                {
                    int b = usersValue[0].sizeTable - 1,a = 0;

                    counterX = rand()%(b-a+1)+a;
                    counterY = rand()%(b-a+1)+a;
                    checkInput = Logic(counterX, counterY, tableInfo, usersValue[0].symbol, usersValue[1].symbol, usersValue[0].sizeTable, usersValue[1].Turn ,usersValue[0].picees ,usersValue[1].picees);
                    if(checkInput == 0)
                    {
                        usleep(500000);
                        tableInfo[counterX][counterY] = usersValue[1].symbol;
                        usersValue[1].Turn = -1;
                        usersValue[0].Turn = 0;
                        break;
                    }
                    else
                    {
                        int temp = checkChangeTurn(tableInfo ,usersValue[0].sizeTable ,usersValue[1].Turn, usersValue[0].symbol ,usersValue[1].symbol);
                        if (temp == -1)
                        {
                            usersValue[1].Turn = -1;
                            usersValue[0].Turn = 0;
                            break;
                        }
                    }
                }   
            }
        }

        int turn;
        if (usersValue[1].Turn == 1)
        {
            turn = usersValue[1].Turn;
        }
        else if (usersValue[0].Turn == 0)
        {
            turn = usersValue[0].Turn;
        }

        winner = checkWinner(turn, usersValue[0].picees, usersValue[1].picees, usersValue[0].sizeTable, usersValue[0].name, usersValue[1].name, tableInfo, usersValue[0].symbol, usersValue[1].symbol);
        system("clear");
        showValue();
        drawTable(usersValue[0].sizeTable ,counterX ,counterY, tableInfo);

        if (winner != "0")
        {
            if (checkLoadGame)
            {
                deleteGame(usersValue[0].savegamename);
            }
            flag = 0;
            break;
        }
    }
    return flag;
}
    

void saveGame(bool saveAgain)
{
    if (menuMove2 == 0)
    {
        system("clear");
        if (!saveAgain)
        {
            logo("     SAVE GAME     " ,8 ,4);
            cout << "\n";
            cout << "\e[1m\e";
            cout << "\t\t\t\t\t\t\t\t";
            cout << "----------------------------------";
            cout << endl;
            defaultMessage("Enter Game Name: ");
            getline(cin ,usersValue[0].savegamename);
            while (true)
            {
                if (findGame(usersValue[0].savegamename) == -1)
                    break;
                else
                {
                    errorMessage("This name is exist.");
                    cout << endl;
                    defaultMessage("Please enter diffrent name: ");
                    getline(cin ,usersValue[0].savegamename);
                }
            }
            usersValue[1].savegamename = usersValue[0].savegamename;
        }

        if (saveAgain)
        {
            deleteGame(usersValue[0].savegamename);
        }

        fstream data("data.txt", ios::app);
        if (!data)
        {
            cout << "File could not be opened\n";
        }

        data << "NAME: ";
        data << usersValue[0].savegamename;
        data << " ";
        data << "username1: ";
        data << usersValue[0].name;
        data << " ";
        data << "symbol1: ";
        data << usersValue[0].symbol;
        data << " ";
        data << "picees1: ";
        data << usersValue[0].picees;
        data << " ";
        data << "turn1: ";
        data << usersValue[0].Turn;
        data << " ";
        data << "username2: ";
        data << usersValue[1].name;
        data << " ";
        data << "symbol2: ";
        data << usersValue[1].symbol;
        data << " ";
        data << "picees2: ";
        data << usersValue[1].picees;
        data << " ";
        data << "turn2: ";
        data << usersValue[1].Turn;
        data << " ";
        data << "size: ";
        data << usersValue[0].sizeTable;
        data << " ";
        data << "table: ";

        for (int i=0; i < usersValue[0].sizeTable; i++)
        {
            for (int j=0; j < usersValue[0].sizeTable; j++)
            {
                if (tableInfo[i][j] == " ")
                    data << 0;
                else
                    data << tableInfo[i][j];
            }
        }
        data << " ";
        data.close();
    }
}

// tempsize save size of tableInfo.
void defaultTableInfo()
{
    for(int i=0; i < tempsize; i++){
        for(int j=0; j < tempsize; j++){
            if(i == tempsize/2 -1 and j == tempsize/2 -1){
                tableInfo[i][j] = usersValue[1].symbol; 
            }else if(i == tempsize/2 -1 and j == tempsize/2){
                tableInfo[i][j] = usersValue[0].symbol; 
            }else if(i == tempsize/2 and j == tempsize/2 - 1){
                tableInfo[i][j] = usersValue[0].symbol;
            }else if(i == tempsize/2 and j == tempsize/2){
                tableInfo[i][j] = usersValue[1].symbol; 
            }else{
                tableInfo[i][j] = " ";
            }
        }
    }
}


void defaultStruct()
{
    for (int i = 0; i < numberUser; i++)
    {
        usersValue[i].Turn = i; 
        usersValue[i].picees = 2;
        usersValue[i].savegamename = "";
        usersValue[i].name = "";
        usersValue[i].symbol = "";
        usersValue[i].sizeTable = 0;
        usersValue[i].rank = 0;
    }
}


int getchTable(void)
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


void resize(string *&dynamicArray, int &capacity)
{
    string *arr = new string[capacity + 1];

    for(int i=0; i < capacity; i++){
        arr[i] = dynamicArray[i];
    }

    capacity += 1;

    delete[] dynamicArray;
    dynamicArray = nullptr;

    dynamicArray = arr;
}