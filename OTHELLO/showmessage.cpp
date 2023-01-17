#include <iostream>

using namespace std;

void defaultMessage(string message)
{
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t\t";
    cout << "\x1B[93m" << message << "\033[0m";
}

void errorMessage(string message)
{
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t\t";
    cout << "\x1B[31m" << "Error : " << message << "\033[0m";
}