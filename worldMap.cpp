#include <iostream>
#include <windows.h>

using namespace std;

const int rows = 50;
const int cols = 90;
char water = '~';
char border = '*';

char world[rows][cols] = {};

char person = 002;
bool hasChange = true;
int randR = 0;
int randC = 0;

int maxpplAfrica = 15;
int pplAfrica = 0;

int maxpplEurope = 35;
int pplEurope = 0;

int maxpplAntarctica = 3;
int pplAntarctica = 0;

int maxpplNA = 12;
int pplNA = 0;

int maxpplSA = 15;
int pplSA = 0;

int maxpplAustralia = 12;
int pplAustralia = 0;


void Antarctica()
{
    int startC = cols/18;
    int startC1 = cols/10;

    for(int i = 0; i < 2; i++)
    {
        if(rows == 1)
        {
            for(int j = startC1; j < cols - startC1; j++)
            {
                world[i][j] = 'Q';
            }
        }

    else
    {
        for(int j = startC; j < cols - startC; j++)
        {
            world[i][j] = 'Q';
        }
    }
    }
}

void Australia()
{
    int startR = rows / 10;
    int endR = startR + (rows / 8);
    int startC= cols - (cols / 4);
    int endC = startC + cols / 5;
    for(int i = startR; i < endR; i++)
    {
        for(int j = startC; j < endC; j++)

        {
            world[i][j] = 'X';
        }
    }
}

void NorthAmerica()
{
    int startR = rows - ((rows / 3) - 3); /// 36 row
    int endR = rows - ((rows / 5) - 3); /// 43 row
    int startC = cols / cols + 2; /// 3 col
    int endC = cols / 4; ///15.5

    int startProw = rows - ((rows / 3) - 2); /// 36 row
    int endProw = rows - ((rows / 2) - 3); /// 28 row
    int startPcol = (cols / 15) + 10; /// 13?
    int endPcol = startPcol + cols / 4;

    ///square
    for(int i = startR; i < endR; i++)
    {
        for(int j = startC; j < endC; j++)
        {
            world[i][j] = 'w';
        }
    }

    ///pyramid
    for(int i = startProw; i >= endProw; i--)
    {
        for(int j = startProw - i; j > endProw; j--)
        {
            world[i][j] = '~';
        }
        for(int k = i; k > endProw; k--)
        {
            world[i][k] = 'w';
        }
    }
}

void NA()
{
    int startR = rows - (rows / 15); /// 47
    int endR = rows - (rows / 3); /// 33
    int startC = 3;
    int endC = cols / 4; ///22
    int rightGap = 0;
    int rightGapStart = (startR - endR) / 3; /// 5
    int leftGap = startC + 3; /// 6
    int leftGapStart = (startR - endR) / 3; ///5

    for(int i = startR; i > endR; i--)
    {
        for(int j = startC; j < endC; j++)
        {
            if(rightGap <= j)
            {
                world[i][j - rightGap]= 'w';
            }
        }
        if(i < startR - rightGapStart)
        {
            rightGap++;
        }
    }

    for(int i = startR; i > endR; i--)
    {
        for(int j = startC; j < endC; j++)
        {
            if(leftGap > 0)
            {
                world[i][leftGap - j] = '~';
            }
        }
        if(i < startR - leftGapStart)
        {
            leftGap++;
        }
    }

}

void Europe()
{
    ///startR = 29;
    ///endR = 45
    ///startC = 38
    ///endC = 55

    int startR = rows - 21; ///29
    int endR = rows - 5; ///45
    int startC = (cols / 2); ///38
    int endC = cols -8; ///82

    for(int i = startR; i < endR; i++)
    {
        for(int j = startC; j < endC; j++)
        {
            world[i][j] = '#';
        }
    }
}


void SA()
{
    int startR = rows/7;
    int endR = rows/2;
    int startC = cols/13;
    int endC = cols / 4;
    int rightGap = 0;
    int rightGapStart = (startR - endR) / 2;

    for(int i = startR; i < endR; i++)
    {
        for(int j = startC; j < endC; j++)
        {

                if(i < startR + rows / 3)
                {
                    world[i][j]='&';
                }
                else{
                    world[i][j - 2]='&';
                }
        }
    }



    for(int i = startR; i < endR; i++)
    {
        for(int j = startC; j < endC; j++)
        {
            if(rightGap <= j)
            {
                world[i][j + rightGap] = '~';
            }

        }
        if(i <startR-rightGapStart)
        {
            rightGap++;
        }
    }
}


void Africa()
{
    int startC = (cols/3) + 2;
    int startR = (rows/2) - 3;
    int endR = rows/20;
    int endC = startC*2;

    for(int i = startR; i > endR; i--)
    {
        for(int j = startC; j < endC; j++)
        {
            world[i][j] = 'A';
        }
        startC++;
        endC--;
    }

}

void England()
{
    int startR = rows - 13; ///37
    int endR = rows - 7; ///43
    int startC = (cols / 3) + 2; ///32
    int endC = (cols / 2) - 2; ///43

    for(int i = startR; i < endR; i++)
    {
        for(int j = startC; j < endC; j++)
        {
            world[i][j] = 'E';
        }
    }
}

void printArray()
{
    for(int i = 0; i < cols + 2; i++)
    {
        cout << border;
    }
    cout << endl;

    for(int i = rows - 1; i >= 0; i--)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0)
            {
                cout << border;
            }
            cout << world[i][j];
            if(j == cols - 1)
            {
                cout << border;
            }
            while(world[randR][randC] != 'A')
            {
                randR = rand() % rows;
                randC = rand() % cols;
            }
        }
         cout << endl;
    }

     for(int i = 0; i < cols  + 2; i++)
    {
        cout << border;
    }
}

void isFull()
{
    if(pplAntarctica == maxpplAntarctica)
    {
        cout << "Antarctica is full";
        cout << endl;
    }

    if(pplAfrica == maxpplAfrica)
    {
        cout << "Africa is full";
        cout << endl;
    }

    if(pplEurope == maxpplEurope)
    {
        cout << "Europe is full";
        cout << endl;
    }

    if(pplAustralia == maxpplAustralia)
    {
        cout << "Australia is full";
        cout << endl;
    }

    if(pplNA == maxpplNA)
    {
        cout << "North America is full";
        cout << endl;
    }

    if(pplSA == maxpplSA)
    {
        cout << "South America is full";
        cout << endl;
    }

}

void addPopulation()
{
        ///in Africa
        ///max 15

        if(GetAsyncKeyState('A'))
        {
            if(pplAfrica < maxpplAfrica)
            {
                while(world[randR][randC] != 'A')
                {
                    randR = rand() % rows;
                    randC = rand() % cols;
                }
                pplAfrica++;
                world[randR][randC] = person;
                hasChange = true;
            }

        }

        ///in Europe
        ///max 35

        if(GetAsyncKeyState('H'))
        {
            if(pplEurope < maxpplEurope)
            {
                while(world[randR][randC] != '#')
                {
                    randR = rand() % rows;
                    randC = rand() % cols;
                }
                pplEurope++;
                world[randR][randC] = person;
                hasChange = true;
            }
        }

        ///in Australia
        ///max 12

        if(GetAsyncKeyState('X'))
        {
            if(pplAustralia < maxpplAustralia)
            {
                while(world[randR][randC] != 'X')
                {
                    randR = rand() % rows;
                    randC = rand() % cols;
                }
                pplAustralia++;
                world[randR][randC] = person;
                hasChange = true;
            }
        }

        ///in North America
        ///max 12

        if(GetAsyncKeyState('N'))
        {
            if(pplNA < maxpplNA)
            {
                while(world[randR][randC] != 'w')
                {
                    randR = rand() % rows;
                    randC = rand() % cols;
                }
                pplNA++;
                world[randR][randC] = person;
                hasChange = true;
            }
        }

        ///in South America
        ///max 15

        if(GetAsyncKeyState('S'))
        {
            if(pplSA < maxpplSA)
            {
                while(world[randR][randC] != '&')
                {
                    randR = rand() % rows;
                    randC = rand() % cols;
                }
                pplSA++;
                world[randR][randC] = person;
                hasChange = true;
            }
        }


        ///in Antarctica
        ///max 9

        if(GetAsyncKeyState('I'))
        {
            if(pplAntarctica < maxpplAntarctica)
            {
                while(world[randR][randC] != 'Q')
                {
                    randR = rand() % rows;
                    randC = rand() % cols;
                }
                pplAntarctica++;
                world[randR][randC] = person;
                hasChange = true;
            }
        }

}

int main()
{

    /// fill world
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            world[i][j] = water;
        }
    }

    /// continents
    Antarctica();
    Australia();
    NA();
    Europe();
    SA();
    Africa();

    ///print world

    while(true)
    {
        ///add people
        addPopulation();

        ///print array
        if(hasChange)
        {
            system("cls");
            isFull();
            printArray();
            hasChange = false;
        }
    }


    return 0;
}
