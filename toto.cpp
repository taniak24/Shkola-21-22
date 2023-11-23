#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int fiche[6] = {1};
    int toto[6];
    int randNumb, r = -1;
    int counter = 0;
    bool flag = false;

    cout << "Enter six numbers: ";

    ///Input numbers

     for(int i = 0; i < 6; i++)
        {
            cin >> fiche[i];
            while(fiche[i] > 49 || fiche[i] < 1)
            {
                cout << "Input number from 1 to 49! ";
                cin >> fiche[i];
            }
        }


    ///Random Numbers

    /*
    while(r < 6)
    {
        r++;
        flag = false;
        randNumb = rand() % 49 + 1;
        for(int i = 0; i < 6; i++)
        {
            if(toto[i] == randNumb)
            {
                r--;
                flag = true;
                cout << endl;
                cout << "Repeated numbers: " << randNumb;
                break;
            }
        }
        if(flag == false && r <= 5)
        {
            toto[r] = randNumb;
        }
    } */

    ///second way

    for(int br = 0; br < 6; br++)
    {
        do
        {
            flag = false;
            randNumb = rand() % 49 + 1;
            for(int i = 0; i < br; i++)
            {
                if(randNumb == toto[i])
                {
                    flag = true;
                    break;
                }
            }
        }
        while(flag == true);
        toto[br] = randNumb;
    }

    cout << endl;

    for(int j = 0; j < 6; j++)
    {
        cout << toto[j] << " ";
    }

    for(int f = 0; f < 6; f++)
    {
        for(int t = 0; t < 6; t++)
        {
            if(fiche[f] == toto[t])
            {
                counter++;
            }
        }
    }

    switch(counter)
    {
    case 3:
        cout << "10 lv.";
        break;
    case 4:
        cout << "1000 lv.";
        break;
    case 5:
        cout << "100 000 lv.";
        break;
    case 6:
        cout << "1 000 000 lv.";
        break;

    default:
        cout << "No money";
    }

    return 0;
}
///da ne se vuvejdat chisla > 49 i < 1
