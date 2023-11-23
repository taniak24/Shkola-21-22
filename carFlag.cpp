#include <iostream>
#include <windows.h>

using namespace std;

///country central african republic flag
///HW: UK flag

int main()
{
    int rows, cols;

    cout << "Input rows(number divided by 4): ";
    cin >> rows;
    while(rows%4 != 0)
    {
        cout << "Input numbers divided by 4!: ";
        cin >> rows;
    }

    cout << "Input columns(even number): ";
    cin >> cols;
    while(cols%2 == 1)
    {
        cout << "Input only even numbers: ";
        cin >> cols;
    }

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= cols; j++)
        {
            if(i <= rows/4)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);

                if(j >= cols/2 && j <= cols - (cols/2))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

                }
                if(i == 2 && j == 2)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);

                }
                cout << " * ";
            }
            else if(i >= rows/4 && i <= rows - (rows/4) - (rows/4))
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                if(j >= cols/2 && j <= cols - (cols/2))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                }
                cout << " # ";
            }
            else if(i >= rows - (rows/4) - (rows/4) && i <= rows -(rows/4))
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                if(j >= cols/2 && j <= cols - (cols/2))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                }
                cout << " $ ";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                if(j >= cols/2 && j <= cols - (cols/2))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                }
                cout << " + ";
            }
        }
        cout << endl;
    }

    for(int r = 1; r <= rows/2; r++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        cout << "|" << endl;
    }

    return 0;
}
