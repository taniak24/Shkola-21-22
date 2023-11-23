#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    srand(time(0));
    //system("color ??");

    int rand_numb;
    int rand_letter;
    char r_lett;

    string rand_num_str;
    string letter_str;

    while(true)
    {
        rand_numb = rand()%10;
        rand_letter = rand()%6;

        if(GetAsyncKeyState(VK_SPACE))
        {
            switch(rand_letter)
            {
            case 0:
                r_lett = 'A';
                break;
            case 1:
                r_lett = 'B';
                break;
            case 2:
                r_lett = 'C';
                break;
            case 3:
                r_lett = 'D';
                break;
            case 4:
                r_lett = 'E';
                break;
            case 5:
                r_lett = 'F';
                break;
            }

            rand_num_str = to_string(rand_numb);
            letter_str = "";
            letter_str += r_lett;

            //cout << "Rand N: " << rand_numb << endl;
            //cout << "Rand L: " << r_lett << endl;
            //cout << "Rand Num Str: " << rand_num_str << endl;
            //cout << "Rand L string: " << letter_str << endl;

            cout << "Hello Tania!" << endl;

            system(("color " + rand_num_str + letter_str).c_str());

            Sleep(100);
        }
        //system("cls");
    }

    return 0;
}
