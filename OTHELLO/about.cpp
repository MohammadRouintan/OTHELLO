# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <termios.h>

using namespace std;

int getchAbout(void)
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

int about()
{
    string about = "          \t\t\t\t\tCreated by Mohammad Rouintan and Reza Mosavi in 2022/1/21\n          \t\t\t\t\tThis project is related to the first semester of 1400\n          \t\t\t\t\tCollege of Computer Science of Shahid Beheshti University\n          \t\t\t\t\tDr.kheradpisheh\n";
    cout << "\n\n";
    cout << "\e[1m\e" << "\x1B[93m" << about << "\033[0m";
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t";
    cout << "---------------------------------------------------------" << endl;
    cout << "\e[1m\e";
    cout << "\t\t\t\t\t\t\t";
    cout << "               ";
    cout << "\x1B[93m" << "ESC: " << "\033[0m";
    cout << "\e[1m\e";
    cout << "\x1B[32m" << "BACK" << "\033[0m\t\t";
    cout << endl; 

    while (true)
    {
        int temp = getchAbout();
        if (temp == 27)
        {
            system("clear");
            return 123;
        }
    }
    return 0;    
}