#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

const int N = 100;

char field[N] = {};

char worm = '~';
char apple = '@';
char stones = '&';
char boosts = '*';
char poison = 'a';
char health = '+';
char dragon = 'D';
char sword = '>';
char portal = 'O';
char elephant = 'E';

int appleCount = 4;
int stonesCount = 7;
int boostCount = 4;
int poisonCount = 1;
int healthCount = 5;
int dragonCount = 2;
int position = 0;
int swordCount = 1;
int portalCount = 2;
int elephantCount = 1;

bool portalFlag = false;

void placeObstacle(char obstacle, int obstacleCount, char arr[])
{
    int br = 0;
    int randN;
    while(br < obstacleCount)
    {
        randN = rand() % N;
        if(arr[randN] == ' ')
        {
            arr[randN] = obstacle;
            br++;
        }
    }
}

///second level

const int N2 = 30;
char field2[N2] = {};

char megaDragon = 'G';
char goldenApple = '$';

int megaDragonCount = 1;
int goldenAppleCount = 1;


int main()
{
    srand(time(0));

    int eatenApples = 0;
    int lives = 3;
    int boostTotal = 0;
    int swordsTotal = 0;

    /// level 1
    for(int br = 0; br < N; br++)
    {
        field[br] = ' ';
    }

    /// 1. position worm
    field[0] = worm;

    placeObstacle(apple, appleCount, field);
    placeObstacle(stones, stonesCount, field);
    placeObstacle(boosts, boostCount, field);
    placeObstacle(poison, poisonCount, field);
    placeObstacle(health, healthCount, field);
    placeObstacle(dragon, dragonCount, field);
    placeObstacle(sword, swordCount, field);
    placeObstacle(portal, portalCount, field);
    placeObstacle(elephant, elephantCount, field);

    while(true)
    {
        field[position] = ' ';

        if(swordsTotal > 0)
        {
            field[position + 1 % N] = ' ';
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            if(position == N - 1)
            {
                position = -1;
            }
            position++;
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            if(position == 0)
            {
                position = N + 1;
            }
            position--;
        }

        if(field[position] == apple || field[position + 1] == apple && swordsTotal > 0)
        {
            eatenApples++;
        }
        if(field[position] == boosts || field[position + 1] == boosts && swordsTotal > 0)
        {
            boostTotal++;
        }
        /// stone takes -1 boost or -1 life
        if(field[position] == stones && boostTotal > 0)
        {
            boostTotal--;
        }
        else if(field[position] == stones && boostTotal == 0)
        {
            lives--;
        }

        /// poison takes -1 life
        if(field[position] == poison || field[position + 1] == poison && swordsTotal > 0)
        {
            lives--;
        }
        if(field[position] == health || field[position + 1] == health && swordsTotal > 0)
        {
            lives++;
        }
        /// dragon moves +3 position and kill dragon with sword
        if(field[position] == dragon || field[position + 1] == dragon)
        {
            if(swordsTotal > 0)
            {
                dragonCount--;
                swordsTotal--;

                field[position + 1 % N] = ' ';
            }
            else
            {
                position = (position + 3) % N;
            }
        }

        /// collected swords
        if(field[position] == sword)
        {
            swordsTotal++;
        }

        /// animal of luck, teleport to the nearest apple
        if(field[position] == elephant)
        {
            field[position] = ' ';
            for(int i = position + 1; i < N; i++)
            {
                if(field[i] == apple && field[i - 1] == ' ')
                {
                    position = i - 1;
                    break;
                }
            }
        }

        /// portal homework, teleport after touching the portal
        if(field[position] == portal)
        {
            for(int i = position + 1; i < N; i++)
            {
                if(field[i] == portal)
                {
                    position = i + 1;
                    portalFlag = true;
                    break;
                }
            }
        }

        if(portalFlag == false)
        {
            for(int i = 0; i < position; i++)
            {
                if(field[i] == portal)
                {
                    position = i - 1;
                    break;
                }
            }
        }

        /// after poison remove lives with over time
        /*
        while(poison == 1)
        {
            lives--;
            if(health == 1)
            {
                break;
            }
        }
        */


        field[position] = worm;
        if(swordsTotal > 0)
        {
            field[position + 1 % N] = sword;
        }

        /// 2. print array in console
        for(int br = 0; br < N; br++)
        {
            cout << field[br];
        }

        cout << endl;
        /// 3. add = below the array

        for(int br = 0; br < N; br++)
        {
            cout<< "=";
        }

        cout << endl;
        cout << "Apples: " << eatenApples << endl;
        cout << "Lives: " << lives << endl;
        cout << "Boosts: " << boostTotal << endl;
        cout << "Swords: " << swordsTotal << endl;

        Sleep(100);
        system("cls");
    }
         /////second level
        // exit and loose the game

        if(lives == 0)
        {
            cout << "YOU LOST!";
            Sleep(10000);
            return 0;
        }
        //TODO uncomment //if(eatenApples == appleCount)
        if(eatenApples == appleCount)
        {
            /*
            cout << "YOU WON!";
            Sleep(10000);
            return 0;*/

            for(int br = 0; br < N2; br++)
            {
                field2[br] = ' ';
            }

            position = 0;
            field2[0] = worm;
            int colectedApple = 0;

            placeObstacle(megaDragon, megaDragonCount, field2);
            placeObstacle(goldenApple, goldenAppleCount, field2);

            while(true)
            {
                field2[position] = ' ';
                if(GetAsyncKeyState(VK_RIGHT))
                {
                    if(position == N2 - 1)
                    {
                        position = -1;
                    }
                    position++;
                }
                if(GetAsyncKeyState(VK_LEFT))
                {
                    if(position == 0)
                    {
                        position = N2 + 1;
                    }
                    position--;
                }

                if(field2[position] == goldenApple)
                {
                    colectedApple++;
                }

                field2[position] = worm;

                /// print array in the console
                for(int counter =  0; counter < N2; counter++)
                {
                    cout << field2[counter];
                }

                cout << endl;

                /// print the field
                for(int counter = 0; counter < N2; counter++)
                {
                    cout << "=";
                }

                Sleep(100);
                system("cls");
            }
        }

    /*
    if(lives > 0)
    {
        cout << "YOU WON!";
        Sleep(10000);
    }
    else
    {
        cout << "YOU LOST!";
    }
    Sleep(5000);
    */


    return 0;
}
