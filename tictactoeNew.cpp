#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

class Game{
    enum class Player{
        none = '-',
        human = 'X',
        computer = 'O'
    };

    struct Move{
        int x;
        int y;
    };

    const int size = 3;
    Player board[3][3];

public:
    Game()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                board[i][j] = Player::none;
            }
        }
    }

    void printBoard()
    {
        for(int i = 0; i < size; i++)
        {
            cout << endl;
            for(int j = 0; j < size; j++)
            {
                cout << setw(3) << static_cast<char>(board[i][j]) << setw(3) << " |";
            }
        }
    }

    void humanMove()
    {
        bool fail = true;
        int x, y;
        char a;

        do{
        cout << "Human move: ";
        cin >> a;

        ///cout << "A: " << a << endl;

        x = a-'0';

        cin >> a;
        y = a-'0';

        fail = board[x][y] != Player::none;

        cin.clear();
        cout << a << endl;
        cout << x << endl;

        }
        while(fail);
        {
            board[x][y] = Player::human;
        }
    }

    Move minimax()
    {
        ///if X wins the score increase by 10
        ///if 0 wins the score decrease by 10
        ///if draw - not changing

        int score = numeric_limits<int>::max();
        Move moves;

        ///cout << "score: " << score << endl;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(board[i][j] == Player::none)
                {
                    board[i][j] == Player::computer;

                    int temp = maxSearch();

                    if(temp < score)
                    {
                        score = temp;
                        moves.x = i;
                        moves.y = j;
                    }
                    board[i][j] = Player::none;
                }
            }
        }
        return moves;
    }

    int maxSearch()
    {
        if(checkWin(Player::human))
        {
            return 10;
        }
        else if(checkWin(Player::computer))
        {
            return -10;
        }
        else if(isTie())
        {
            return 0;
        }

        int score = numeric_limits<int>::min();

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(board[i][j] == Player::none)
                {
                    board[i][j] = Player::human;
                    ///higher result better for human
                    score = max(score, minSearch());
                    board[i][j] = Player::none;
                }
            }
        }
        return score;
    }

    int minSearch()
    {
        if(checkWin(Player::human))
        {
            return 10;
        }
        else if(checkWin(Player::computer))
        {
            return - 10;
        }
        else if(isTie())
        {
            return 0;
        }

        int score = numeric_limits<int>::max();

        for(unsigned int i = 0; i < size; i++)
        {
            for(unsigned int j = 0; j < size; j++)
            {
                if(board[i][j] == Player::none)
                {
                    board[i][j] = Player::computer;
                    ///lower result better for computer
                    score = min(score, maxSearch());
                    board[i][j] = Player::none;
                }
            }
        }
        return score;
    }

    void play()
    {
        int turn = 0;
        bool exit = false;
        printBoard();

        cout << "Enter your move in coordinates: " << endl;

        do
        {
            if(turn == 0)
            {
                humanMove();
                if(checkWin(Player::human))
                {
                    printBoard();
                    cout << "Human win!" << endl;
                    system("Color 0a");
                }

                ///add logic for human win
            }
            else{
                cout << "Computer move: " << endl;
                ///computer move

                Move aimove = minimax();

                cout << aimove.x << " " << aimove.y << endl;

                board[aimove.x][aimove.y] = Player::computer;

                ///TODO computer wins
            }

            ///logic tie
            if(isTie())
            {
                cout << "Tie: " << endl;\
                exit = true;
            }

            turn ^= 1;
            printBoard();

        }while(!exit);
    }

    bool checkWin(Player player)
    {
        int counterDiagonal = 0;
        int counterDiagonal2 = 0;

        for(int i = 0; i < size; i ++)
        {

            if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                ///check horizontals
                return true;
            }
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            {
                ///check verticals
                return true;
            }
            ///check diagonals
            for(int j = 0; j < size; j++)
            {
                ///first
                if(i == j && board[i][j] == player)
                {
                    counterDiagonal++;
                }
                ///second
                if((i + j) == size - 1 && board[i][j] == player)
                {
                    counterDiagonal2++;
                }
            }
        }
        if(counterDiagonal == 3)
        {
            return true;
        }
        if(counterDiagonal2 == 3)
        {
            return true;
        }
    }

    bool isTie()
    {
        for (int i = 0; i < size; i ++)
        {
            if(board[i][0] == Player::none || board[i][1] == Player::none || board[i][2] == Player::none)
            {
                return false;
            }
        }
        return true;
    }

};

int main()
{
    Game tictactoe;
    tictactoe.play();

    return 0;
}
