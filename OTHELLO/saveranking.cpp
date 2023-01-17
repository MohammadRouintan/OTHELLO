#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

bool userExist(string);
int get_rank_number(string);
void updateRanking(string);
int rankingNumber();
int numberOfDigits(int);
int get_file_size();
string get_username(int &);
string get_file_ranking();

bool userExist(string username)
{
    string file = get_file_ranking();
    int temp = file.find(username);
    if (temp != -1)
        return true;

    return false;
}

int get_rank_number(string username)
{
    string file = get_file_ranking();
    int findBegin = file.find(username);
    findBegin = file.find("wins: ",findBegin);
    findBegin += 6;
    int findEnd = file.find("END ", findBegin);
    findEnd -= 1;

    string outPut = file.substr(findBegin ,findEnd - findBegin);
    int number = atoi(outPut.c_str());

    return number;
}

void updateRanking(string username)
{
    int rank = get_rank_number(username);
    int len = numberOfDigits(rank);
    rank++;

    string output = to_string(rank);
    string file = get_file_ranking();
    int find = file.find(username);
    find = file.find("wins: ",find);
    find += 6;

    file = file.erase(find,len);
    file = file.insert(find,output);
    fstream ranking("ranking.txt", ios::out);
    if (!ranking)
    {
        cout << "File could not be opened\n";
        exit(1);
    }
    ranking << file;
    ranking.close();
}

string get_file_ranking()
{
    fstream ranking("ranking.txt" ,ios::in);
    if (!ranking)
    {
        return "123";
    }
    string temp, rankingInfo;
    while (!ranking.eof())
    {
        ranking >> temp;
        rankingInfo += " " + temp;
    }
    return rankingInfo;
}

int rankingNumber()
{
    string file = get_file_ranking();
    int find = 0;
    int counter = 0;

    while (true)
    {
        find = file.find("RANK: ", find + 1);
        if (find == -1)
        {
            break;
        }
        counter++;
    }

    return counter;
}

string get_username(int &find)
{
    string file = get_file_ranking();
    int begin = file.find("username: ",find);
    if (begin == -1)
    {
        find = 0;
        begin = file.find("username: ", find);
    }
    int end = file.find("wins: ",begin);
    if (end == -1)
    {
        find = 0;
        end = file.find("username: ", find);
    }
    begin += 10;
    end -= 1;
    find = file.find("wins: ", find + 1);

    return file.substr(begin , end - begin);
}

int numberOfDigits(int number)
{
    int answer = 0;
    while (number != 0)
    {
        int digit = number % 10;
        answer++;
        number /= 10;
    }
    
    return answer;
}

int get_file_size()
{
    string file = get_file_ranking();
    return file.size();
}