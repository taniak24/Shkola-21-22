#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <ctime>

using namespace std;

const int ROWS = 24;
const int COLS = 24;

char mine_field[ROWS][COLS];

///actial field show
const int play_board_rows = ROWS;
const int play_board_cols = COLS;

///objects char
char bomb_ch = '#';
char pointer = ' ';
char flag_ch;

///check if there is mine
char corr_mine = '!';
char wr_mine = 'X';

///objects int
int mine = 20;

///mode
bool DEV = true;

///check die
bool EXPLODE = true;

int x = 0;
int y = 0;

enum COLORS{
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    LIGHT_GREY =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,

    GREY = 0 | FOREGROUND_INTENSITY,
    LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PINK = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHITE =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
};

/// declare new colour variable.GLOBAL
COLORS defaultColor = GREY;

/// drawing
HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screenBuf = {play_board_rows, play_board_cols};
CHAR_INFO blankScreen[(play_board_rows)*(play_board_cols)] = {0};

void drawChar(char ch, int y, int x, COLORS foregroundColor, COLORS backgroundColor){
    CHAR_INFO chInfo;
    chInfo.Char.AsciiChar = ch;
    chInfo.Attributes = foregroundColor | (backgroundColor<<4);
    COORD bufSize = {1,1};
    COORD bufCoord = {0,0};
     SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &chInfo, bufSize, bufCoord, &screen_pos);
}

void background(COLORS color)
{
    for(int i = 0; i < play_board_rows; i++)
    {
        for(int j = 0; j < play_board_cols; j++)
        {
            drawChar(' ', i, j, color, color);
        }
    }
}

void print_mines(int m)
{
    int counter = 0;
    int rand_r, rand_c;

    while(counter < m)
    {
        rand_r = rand() % ROWS;
        rand_c = rand() % COLS;

        if(mine_field[rand_r][rand_c] == ' ')
        {
            mine_field[rand_r][rand_c] = bomb_ch;
            counter++;
        }
    }

    return;
}

int t = 0;

void open_field(int r, int c)
{
    int counter = 0;

    for(int i = r-1; i <= r+1; i++)
    {
        for(int j = c-1; j <= c+1; j++)
        {
            counter+=(mine_field[i][j] == '#');
            counter+=(mine_field[i][j] == '*');
        }
    }

    ///convert
    mine_field[r][c] = '0' + counter;

    drawChar(mine_field[r][c], c, r, WHITE, GREEN);

    int min_r = max(1,r-1);
    int max_r = min(ROWS,r+1);
    int min_c = max(1,c-1);
    int max_c = min(COLS,c+1);

    for(int i = min_r; i <= max_r; i++)
    {
        for(int j = min_c; j <= max_c; j++)
        {
            if(mine_field[i][j] == ' ')
            {
                open_field(i, j);
            }
        }
    }
}

void move_pointer()
{
    int row = x;
    int col = y;

    if(GetAsyncKeyState('W'))
    {
        col--;
    }
    if(GetAsyncKeyState('S'))
    {
        col++;
    }
    if(GetAsyncKeyState('A'))
    {
        row--;
    }
    if(GetAsyncKeyState('D'))
    {
        row++;
    }


    if((row >= 0 && row < ROWS) && (col >= 0 && col < COLS))
    {
        //drawChar(' ', y, x, BLACK, GREEN);
        //mine_field[x][y] = ' ';

        ///TODO prev pointer delete
        drawChar(pointer, col, row, BLACK, CYAN);
        drawChar(pointer, y, x, BLACK, BLUE);

        if(GetAsyncKeyState('M'))
        {
            switch(mine_field[row][col])
            {
            case '#': mine_field[row][col] = '*'; flag_ch = 'F'; break;
            case ' ': mine_field[row][col] = 'X'; flag_ch = 'F'; break;
            case '*': mine_field[row][col] = '#'; flag_ch = ' '; break;
            case 'X': mine_field[row][col] = ' '; flag_ch = ' '; break;
            }
            drawChar(flag_ch, col, row, WHITE, BLUE);
        }

        if(GetAsyncKeyState(VK_RETURN))
        {
            if(mine_field[row][col] == bomb_ch)
            {
                EXPLODE = false;
                system("color 4F");
            }
            else
            {
                open_field(row, col);
            }
        }

        x = row;
        y = col;
    }

}

int main()
{
    srand(time(0));

    background(BLUE);

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            mine_field[i][j] = ' ';
        }
    }

    print_mines(mine);

    while(EXPLODE)
    {
        move_pointer();

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(DEV)
                {
                    if(mine_field[i][j] == bomb_ch)
                    {
                        drawChar(bomb_ch, j, i, RED, BLUE);
                    }
                }
                if(mine_field[i][j] == flag_ch)
                {
                    drawChar(flag_ch, j, i, WHITE, BLUE);
                }
                if(mine_field[i][j] == '*' || mine_field[i][j] == 'X')
                {
                    drawChar(flag_ch, j, i, WHITE, BLUE);
                }
            }
        }
       Sleep(200);
    }

    ///TODO check if you failed
    if(!EXPLODE)
    {
        system("cls");
        cout << "Sorry. YOU LOST! " << endl;
    }

    Sleep(3000);

    return 0;
}
