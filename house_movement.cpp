#include <windows.h>
#include <winuser.h>

using namespace std;

const int POLE_ROWS = 100;
const int POLE_COLS = 100;

enum COLORS
{
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

HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screen_buf = {POLE_ROWS, POLE_COLS};
CHAR_INFO blank_screen[(POLE_ROWS) * (POLE_COLS)] = {0};

void draw_char(char ch, int y, int x, COLORS foreground_color, COLORS background_color)
{
    CHAR_INFO ch_info;
    ch_info.Char.AsciiChar = ch;
    ch_info.Attributes = foreground_color | (background_color << 4);

    COORD buf_size = {1, 1};
    COORD buf_coord = {0, 0};
    SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);

}

void clean_screen()
{
    COORD buf_coord = {0, 0};
    SMALL_RECT screen_pos = {0, 0, screen_buf.X, screen_buf.Y};
    ::WriteConsoleOutput(hConsoleOutput, blank_screen, screen_buf, buf_coord, &screen_pos);

}

int main()
{

    SMALL_RECT rect = {0, 0, screen_buf.X, screen_buf.Y};

    ::SetConsoleScreenBufferSize(hConsoleOutput, screen_buf);
    ::SetConsoleWindowInfo(hConsoleOutput, TRUE, &rect);
    // show them this example
    ::SetConsoleTitle("House");


    int h_rows = 10;
    int h_cols = 10;
    int c = 0;
    int r = 0;
    bool moved = true;

    char house[h_rows][h_cols]=
    {
        "  ______   ",
        " /  O   \\ ",
        "/________\\",
        "|   |    |",
        "|___|____|",
        "|___+____|",
        "|   |    |",
        "|___|____|",
        "**      **",
        "**      **"
    };

    while(true)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            moved = true;
            r--;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moved = true;
            r++;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            moved = true;
            c--;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moved = true;
            c++;
        }
        // show when moved without blinking

        if(moved == true)
        {
            clean_screen();
            for(int i = 0; i < h_rows; i++)
            {
                for(int y = 0; y < h_cols; y++)
                {
                    draw_char(house[y][i],y + r, c + i, PINK, WHITE);
                }
            }
            moved = false;
        }

        /// to move smoothly
        Sleep(20);

    }

    return 0;
}

