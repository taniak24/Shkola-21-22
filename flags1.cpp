#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int rows, cols;

    cout << "How many rows: ";
    cin >> rows;
    while(rows%3 != 0)
    {
        cout << "Input numbers divided by 3!: ";
        cin >> rows;
    }
    cout << "How many columns: ";
    cin >> cols;

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= cols; j++)
        {
            if(i <= rows/3)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " * ";
            }
            else if(i >= rows/3 && i <= rows - (rows/3))
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout << " $ ";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
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
