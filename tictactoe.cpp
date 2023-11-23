#include <iostream>
#include <windows.h>

using namespace std;

char field[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int check;
int counter = 0;

void board()
{
    system("cls");
    cout << "Tic Tac Toe: " << endl << endl;
    cout << "Player 1(X) - Player 2(O)" << endl << endl;
    cout << "   " << field[1] << " | " << field[2] << " | " << field[3] << endl;
    cout << "   " << field[4] << " | " << field[5] << " | " << field[6] << endl;
    cout << "   " << field[7] << " | " << field[8] << " | " << field[9] << endl;
    cout << endl;
}

int checkResult()
{
    if(field[1] == field[2] && field[2] == field[3])
    {
        return 1;
    }
    else if(field[4] == field[5] && field[5] == field[6])
    {
        return 1;
    }
    else if(field[7] == field[8] && field[8] == field[9])
    {
        return 1;
    }
    else if(field[1] == field[4] && field[4] == field[7])
    {
        return 1;
    }
    else if(field[2] == field[5] && field[5] == field[8])
    {
        return 1;
    }
    else if(field[3] == field[6] && field[6] == field[9])
    {
        return 1;
    }
    else if(field[1] == field[5] && field[5] == field[9])
    {
        return 1;
    }
    else if(field[3] == field[5] && field[5] == field[7])
    {
        return 1;
    }
    else if(field[1] != '1' && field[2] != '2' && field[3] != '3' && field[4] != '4' && field[5] != '5' && field[6] != '6' && field[7] != '7' && field[8] != '8' && field[9] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }

}

int main()
{
    int player = 1, n;
    char mark;

    do{
        board();
        /*
        cout << "Player " << player << " enter a number: " << endl;
        cin >> n;

        if(player == 1)
        {
            mark = 'X';
            player = 2;
        }
        else
        {
            mark = '0';
            player == 1;
        }
        cout << "Mark: " << mark << endl;*/

        ///second way for switching players. Ternary Operator

        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << " enter a number: " << endl;
        cin >> n;

        while(n < 1 || n > 9)
        {
            cout << "Enter a number between 1 and 9!: ";
            cin >> n;
        }
        while(field[n] == 'X' || field[n] == '0')
        {
            cout << "This field is used. Try again: ";
            cin >> n;
        }

        mark = (player == 1) ? 'X' : 'O';
        cout << "Mark: " << mark << endl << endl;
        field[n] = mark;
        player++;

        check = checkResult();


    } while(check == -1); ///TODO add logic to stop the game
    if(check == 0)
    {
        cout << "DRAW!";
    }
    if(check == 1)
    {
        player--;
        cout << "Player " << player << " wins!";
    }

    return 0;
}
