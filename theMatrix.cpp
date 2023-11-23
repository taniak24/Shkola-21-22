#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int width = 83;
    char txt[] = {"123456789qwertiopasdgJHDояоняТХМBdkuelmDSHDUHwjndwljK49geoba%#@kdwhHudjeJ@#$*2fje@()ансгзьмГДЖФвопувем;+&^5^%fne$#%=+!$t"};

    int length = 0;
    int index = 0, flip = 5;

    while(txt[length++] != '\0');
    cout << "length: " << length;

    bool swithes[length] = {};

    while(true)
    {
        for(int i = 0; i < flip; i++)
        {
            index = rand()%length;
            swithes[index] = !swithes[index];
        }

        for(int i = 0; i < width; i ++)
        {
            if(swithes[i])
            {
                cout << txt[rand()%length] << " ";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        Sleep(30);
    }

    return 0;
}
