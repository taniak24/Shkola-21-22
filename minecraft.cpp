#include <windows.h>
#include <iostream>
#include <winuser.h>
#include <ctime>

using namespace std;

const int ROWS = 64;
const int COLS = 64;
const int GAP = 16;

///array for game
char play_board[ROWS][COLS];
const char border = '*';

char steve = 'S';
char tree = 'T';
char rock = 'R';
char zombie = '#';
char lives = 'L';
char sword = '!';

///coor steve
int x = 0, y = 0;

///coor zombie
int x_zombie = 0;
int y_zombie = 0;

///coor rock
int x_rock = 0;
int y_rock = 0;

///coor tree
int x_tree = 0;
int y_tree = 0;

///coor sword
int x_sword = 0;
int y_sword = 0;

/*
int x_prev = 0, y_prev = 0;
int x_prev2 = 0, y_prev2 = 0;*/

char count_tr = '0',count_rk = '0', count_lv = '0', count_sw = '0';

///INVENTORY
int tree_num = 5;
int rock_num = 5;
int zombie_num = 10;
int durability_sw = 1;

///calculator in inventory
int tree_counter = 0;
int rock_counter = 0;
int live_counter = 8;
int sword_counter = 0;

///actual field show
const int play_board_rows = ROWS;
const int play_board_cols = COLS + GAP;

///placeable
const int placbl_rows = ROWS - 2;
const int placbl_cols = COLS - 2;

enum COLORS {
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
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            drawChar(' ', i, j, color, color);
            if(i == 0 || i == ROWS - 1)
            {
                drawChar(border, i, j, WHITE, color);
            }
            if(j == 0 || j == COLS - 1)
            {
                drawChar(border, i, j, WHITE, color);
            }
        }
    }
}

void add_trees()
{
    for(int i = 0; i < tree_num; i++)
    {
        x_tree = rand() % placbl_rows + 1;
        y_tree = rand() % placbl_cols + 1;
        if(play_board[x_tree][y_tree] == '\0')
        {
            play_board[x_tree][y_tree] = tree;
            drawChar(tree, y_tree, x_tree, BLACK, BROWN);
        }
        else
        {
            i--;
        }
    }
}

void add_rocks()
{
    for(int i = 0; i < rock_num; i++)
    {
        x_rock = rand() % placbl_rows + 1;
        y_rock = rand() % placbl_cols + 1;
        if(play_board[x_rock][y_rock] == '\0')
        {
            play_board[x_rock][y_rock] = rock;
            drawChar(rock, y_rock, x_rock, BLACK, GREY);
        }
        else
        {
            i--;
        }
    }
}

void add_zombies()
{
    for(int i = 0; i < zombie_num; i++)
    {
        x_zombie = rand() % placbl_rows + 1;
        y_zombie = rand() % placbl_cols + 1;

        if(play_board[x_zombie][y_zombie] == '\0')
        {
            play_board[x_zombie][y_zombie] = zombie;
            drawChar(zombie, y_zombie, x_zombie, BLACK, RED);
        }
        else
        {
            i--;
        }
    }
}

void inventory()
{
    int x_inventory = ROWS + 2;
    int y_inventory_tree = COLS - 63;
    int y_inventory_rock = COLS - 62;
    int y_inventory_live = COLS - 61;
    int y_inventory_sword = COLS - 60;

    count_tr = '0' + tree_counter;
    count_rk = '0' + rock_counter;
    count_lv = '0' + live_counter;
    count_sw = '0' + sword_counter;

    drawChar(tree, y_inventory_tree, x_inventory, BLACK, LIGHT_GREEN);
    drawChar(':', y_inventory_tree, x_inventory + 1, BLACK, LIGHT_GREEN);
    drawChar(count_tr, y_inventory_tree, x_inventory + 2, BLACK, LIGHT_GREEN);

    drawChar(rock, y_inventory_rock, x_inventory, BLACK, LIGHT_GREEN);
    drawChar(':', y_inventory_rock, x_inventory + 1, BLACK, LIGHT_GREEN);
    drawChar(count_rk, y_inventory_rock, x_inventory + 2, BLACK, LIGHT_GREEN);

    drawChar(lives, y_inventory_live, x_inventory, BLACK, LIGHT_GREEN);
    drawChar(':', y_inventory_live, x_inventory + 1, BLACK, LIGHT_GREEN);
    drawChar(count_lv, y_inventory_live, x_inventory + 2, BLACK, LIGHT_GREEN);

    drawChar('S', y_inventory_sword, x_inventory, BLACK, LIGHT_GREEN);
    drawChar(':', y_inventory_sword, x_inventory + 1, BLACK, LIGHT_GREEN);
    drawChar(count_sw, y_inventory_sword, x_inventory + 2, BLACK, LIGHT_GREEN);
}

void init()
{
    srand(time(0));
    ///assign rand values
    x = rand() % placbl_rows + 1;
    y = rand() % placbl_cols + 1;
    ///array assign
    play_board[x][y] = steve;
    ///draw char
    drawChar(steve, y, x, BLACK, LIGHT_GREEN);
    ///add objects
    add_trees();
    add_rocks();
    add_zombies();
    inventory();
}

bool goRight = false;
bool goLeft = false;
bool goUp = false;
bool goDown = false;

void move_Steve()
{
    int row = x;
    int col = y;

    ///goUp
    if(GetAsyncKeyState('W'))
    {
        col--;
    }
    ///goDown
    if(GetAsyncKeyState('S'))
    {
        col++;
    }
    ///goLeft
    if(GetAsyncKeyState('A'))
    {
        row--;
    }
    ///goRight
    if(GetAsyncKeyState('D'))
    {
        row++;
    }

    ///add objects in inventory
    if(play_board[row][col] == tree)
    {
        tree_counter++;
        play_board[row][col] = '\0';
        inventory();
    }
    if(play_board[row][col] == rock)
    {
        rock_counter++;
        play_board[row][col] = '\0';
        inventory();
    }
    if(play_board[row][col] == zombie)
    {
        if(sword_counter > 0)
        {
            durability_sw--;
            sword_counter--;
            inventory();
        }
        else
        {
            live_counter--;
            inventory();
        }
    }
    if(rock_counter >= 2 && tree_counter >=1)
    {
        sword_counter++;
        rock_counter -= 2;
        tree_counter --;
        inventory();

    }

    if((row > 0 && row < 63) && (col > 0 && col < 63))
    {
        drawChar(' ', y, x, BLACK, GREEN);
        play_board[x][y] = '\0';

        drawChar(steve, col, row, BLACK, CYAN);
        play_board[row][col] = steve;

        x = row;
        y = col;
    }
}

void move_zombie(int x_zomb_coor, int y_zomb_coor)
{
    int rand_way = rand() % 4;

    int r = x_zomb_coor;
    int c = y_zomb_coor;

    switch(rand_way)
    {
    case 0: ///up
        c--;
        break;
    case 1: ///down
        c++;
        break;
    case 2: ///right
        r++;
        break;
    case 3: ///left
        r--;
        break;
    }

    ///make the coordinates(r, c) to be in the limit from 1 to 62
    if((r > 0 && r < 63) && (c > 0 && c < 63))
    {
        if(play_board[r][c] == '\0' && play_board[r][c] != steve)
        {
            drawChar(zombie, c, r, BLACK, RED);
            play_board[r][c] = zombie;

            drawChar(' ', y_zomb_coor, x_zomb_coor, BLACK, GREEN);
            play_board[x_zomb_coor][y_zomb_coor] = '\0';

            x_zomb_coor = r;
            y_zomb_coor = c;
        }
    }
}
void move_all_mobs()
{
    for(int i = 0; i <= placbl_rows; i++)
    {
        for(int j = 0; j <= placbl_cols; j++)
        {
            if(play_board[i][j] == zombie)
            {
                move_zombie(i, j);
            }
        }
    }
}

int main()
{
    background(GREEN);
    init();

    while(true)
    {
        move_Steve();
        move_all_mobs();
        Sleep(200);
        if(live_counter == 0)
        {
            cout << "YOU DIED!" << endl;
            Sleep(1000);
            break;
        }
    }

    return 0;
}
