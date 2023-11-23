#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

class Game
{
public:
    int mode;
    int rounds;
    int resultPlayer1;
    int resultPlayer2;
    int resultTie;

    string choices[4] = {"empty", "Rock", "Paper", "Scissors"};
    string players[2] = {};

    Game(int m, int r)
    {
        mode = m;
        rounds = r;
        resultPlayer1 = 0;
        resultPlayer2 = 0;
        resultTie = 0;
    }

    int checkWin(int player1, int player2)
    {
        ///return 1 if player 1 wins
        ///return 2 if player 2 wins
        ///2 of 3 rounds - win

        if(player1 == 1 && player2 == 2)
        {
            resultPlayer2++;
            cout<< players[1] << " wins" << endl << endl;
            return 2;
        }
        else if(player1 == 2 && player2 == 3)
        {
            resultPlayer2++;
            cout<< players[1] << " wins" << endl << endl;
            return 2;
        }
        else if(player1 == 3 && player2 == 1)
        {
            resultPlayer2++;
            cout<< players[1] << " wins" << endl << endl;
            return 2;
        }
        else if(player1 == 2 && player2 == 1)
        {
            resultPlayer1++;
            cout<< players[0] << " wins" << endl << endl;
            return 1;
        }
        else if(player1 == 1 && player2 == 3)
        {
            resultPlayer1++;
            cout<< players[0] << " wins" << endl << endl;
            return 1;
        }
        else if(player1 == 3 && player2 == 2)
        {
            resultPlayer1++;
            cout<< players[0] << " wins" << endl << endl;
            return 1;
        }
        else{
            resultTie++;
            cout<<"Tie" << endl;
            return 0;
        }
    }


    void play()
    {
        int player1, player2;
        int roundsToWin = rounds/2+1;

        string name;
        string name2;

         if(mode==1) ///human VS computer
        {
            cout << "Player 1, enter your name: ";
            cin >> name;

            players[0] = name;
            players[1] = "Computer";

            for(int i=0; i<rounds;i++)
            {
                cout<< endl << "Enter 1)rock, 2) for paper or 3) for scissors: ";
                cin >> player1;

                cout<<"Computer's choice...";
                Sleep(2000);

                player2 = rand()%3+1;
                cout<<" is: "<<player2 << endl;

                checkWin(player1, player2);
                if(resultPlayer1 == roundsToWin)
                {
                    cout << endl << players[0] << " wins the GAME!" << endl;
                    break;
                }
                if(resultPlayer2 == roundsToWin)
                {
                    cout << endl << players[1] << " wins the GAME!" << endl;
                    break;
                }
                if(resultTie > 0)
                {
                    i--;
                }
            }
        }

        else if(mode == 2) ///human VS human
        {
            cout << "Player 1, enter your name: ";
            cin >> name;
            players[0] = name;

            cout << "Player 2, enter your name: ";
            cin >> name2;
            players[1] = name2;

            for(int i = 0; i < rounds; i++)
            {
                cout<< endl << "Enter 1)for rock, 2) for paper or 3) for scissors: ";
                cin >> player1;

                cout<< endl << "Enter 1)rock, 2) for paper or 3) for scissors: ";
                cin >> player2;

                checkWin(player1, player2);

                if(resultPlayer1 == roundsToWin)
                {
                    cout << endl << players[0] << " wins the GAME!" << endl;
                    break;
                }
                if(resultPlayer2 == roundsToWin)
                {
                    cout << endl << players[1] << " wins the GAME!" << endl;
                    break;
                }
                if(resultTie > 0)
                {
                    i--;
                }
            }
        }

        else if(mode == 3)
        {
            players[0] = "Computer 1";
            players[1] = "Computer 2";

            for(int i = 0; i < rounds; i++)
            {
                cout<<"1)for rock, 2) for paper or 3) for scissors: " << endl;

                cout << "Computer 1's choice...";
                Sleep(2000);
                player1 = rand()%3+1;
                cout << "is: " << player1 << endl;

                cout << "Computer 2's choice...";
                Sleep(2000);
                player2 = rand()%3+1;
                cout << "is: " << player2 << endl;

                checkWin(player1, player2);

                if(resultPlayer1 == roundsToWin)
                {
                    cout << endl << players[0] << " wins the GAME!" << endl;
                    break;
                }
                if(resultPlayer2 == roundsToWin)
                {
                    cout << endl << players[1] << " wins the GAME!" << endl;
                    break;
                }
                if(resultTie > 0)
                {
                    i--;
                }
            }
        }
    }
};

void print()
{
    cout << "*******Rock, Paper, Scissors!*******" << endl << endl;
    cout << "[1st mode]-Human VS Computer; [2nd mode]-Human VS Human; [3rd mode]- Computer VS Computer" << endl;
}

int main()
{
    int mode;
    int rounds;

    print();

    cout << "Enter the mode you want: ";
    cin >> mode;
    cout << "How many rounds do you want? - [3], [5], [7], [9]: ";
    cin >> rounds;

    if(rounds == 3)
    {
        cout << "First to win 2 rounds wins the game!" << endl << endl;
    }
    else if (rounds == 5)
    {
        cout << "First to win 3 rounds wins the game!" << endl << endl;
    }
    else if (rounds == 7)
    {
        cout << "First to win 4 rounds wins the game!" << endl << endl;
    }
    else if (rounds == 9)
    {
        cout << "First to win 5 rounds wins the game!" << endl << endl;
    }

    while(rounds%2 == 0 || rounds > 9 || rounds < 3)
    {
        cout << "Input only valid numbers: ";
        cin >> rounds;
    }

    srand(time(0));
    ///system("cls");


    Game obj(mode, rounds);
    obj.play();

    return 0;
}

