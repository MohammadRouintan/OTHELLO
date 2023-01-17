#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string get_file();
string findUsername1(string nameSaveGame);
string findUsername2(string nameSaveGame);
string findSymbol1(string nameSaveGame);
string findSymbol2(string nameSaveGame);
int findGame(string nameSaveGame);
int findvalue(string value);
int findPieces2(string nameSaveGame);
int findPieces1(string nameSaveGame);
int findTurn1(string nameSaveGame);
int findTurn2(string nameSaveGame);
int findSize(string nameSaveGame);
void get_Table(string nameSaveGame ,string *arr);


int findGame(string nameSaveGame)
{
    string temp = get_file();
    return temp.find(nameSaveGame);
}

int findvalue(string value)
{
    return findGame(value);
}

string get_NameSaveGame(string nameSaveGame)
{
    string file = get_file();
    int begin = findvalue(nameSaveGame);
    int end = file.find("username1" , begin);
    end -=1;

    return file.substr(begin ,end - begin);
}

string findUsername1(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginUsername =  file.find("username1: " , temp);
    beginUsername += 11;
    int endUsername =  file.find(" ", beginUsername);

    return file.substr(beginUsername, endUsername - beginUsername);
}

string findUsername2(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginUsername =  file.find("username2: " , temp);
    beginUsername += 11;
    int endUsername =  file.find(" ", beginUsername);

    return file.substr(beginUsername, endUsername - beginUsername);
}

string findSymbol1(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int Symbol =  file.find("symbol1: " , temp);
    Symbol += 9;

    return file.substr(Symbol ,1);
}

string findSymbol2(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int Symbol =  file.find("symbol2: " , temp);
    Symbol += 9;

    return file.substr(Symbol ,1);
}

int findPieces1(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginPieces =  file.find("picees1: " , temp);
    beginPieces += 9;
    int endPieces =  file.find(" ", beginPieces);

    string outPut = file.substr(beginPieces ,endPieces - beginPieces);
    int number = atoi(outPut.c_str());

    return number;
}

int findPieces2(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginPieces =  file.find("picees2: " , temp);
    beginPieces += 9;
    int endPieces =  file.find(" ", beginPieces);

    string outPut = file.substr(beginPieces ,endPieces - beginPieces);
    int number = atoi(outPut.c_str());

    return number;
}

int findTurn1(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginTrun =  file.find("turn1: " , temp);
    beginTrun += 7;
    int endTurn =  file.find(" ", beginTrun);

    string outPut = file.substr(beginTrun ,endTurn - beginTrun);
    int number = atoi(outPut.c_str());

    return number;
}

int findTurn2(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginTrun =  file.find("turn2: " , temp);
    beginTrun += 7;
    int endTurn =  file.find(" ", beginTrun);

    string outPut = file.substr(beginTrun ,endTurn - beginTrun);
    int number = atoi(outPut.c_str());

    return number;
}

int findSize(string nameSaveGame)
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginSize =  file.find("size: " , temp);
    beginSize += 6;
    int endSize = file.find(" ",beginSize);

    string outPut = file.substr(beginSize ,endSize - beginSize);
    int number = atoi(outPut.c_str());

    return number;
}

void get_Table(string nameSaveGame ,string arr[][12])
{
    string file = get_file();
    int temp = findvalue(nameSaveGame);
    int beginTable =  file.find("table: " , temp);
    beginTable += 7;
    int size = findSize(nameSaveGame);

    for (int i=0; i < size;i++)
    {
        for (int j=0; j < size;j++)
        {
            string element = file.substr(beginTable , 1);
            if (element == "0")
                arr[i][j] =  " ";
            else
                arr[i][j] = element;
            beginTable++;
        }
    }
}

void deleteGame(string nameSaveGame)
{
    string file = get_file();
    int begin = findGame(nameSaveGame);
    int end = file.find("NAME: " ,begin);
    end -=2;
    begin -=6; 
    file.erase(begin ,end - begin);

    ofstream data("data.txt");
    if (!data)
    {
        cout << "File could not be opened\n";
    }
    data << file;
    data.close();
}

int numberOfGames()
{
    string file = get_file();
    int counter = 0;
    int find = 0;
    while (find != -1)
    {
        find = file.find("NAME: ", find);
        counter++;
    }

    return counter;
}


string get_file()
{
    fstream data("data.txt" ,ios::in);
    if (!data)
    {
        fstream Data("data.txt", ios::app);
        Data.close();
    }

    string temp, dataInfo;
    while (!data.eof())
    {
        data >> temp;
        dataInfo += " " + temp;
    }
    data.close();
    return dataInfo;
}

