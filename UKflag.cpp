#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int n = 12;
    cout << "Input a number divided by 2 and higher than 14: ";
    cin >> n;
    while(n%2 == 1 || n < 14)
    {
        cout << "Input only numbers divided by 2 and higher than 14!: ";
        cin >> n;
    }

    ///i = 0 => -1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= n/2 - 1 && i <= n/2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << " * ";
            }
            else if(j >= n/2 - 1 && j <= n/2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << " * ";
            }
            else if(j > n/2 - 3 && j < n/2 - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(i > n/2 - 3 && i < n/2 - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(j < n/2 + 2 && j > n/2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(i < n/2 + 2 && i > n/2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(i == j)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << " * ";
            }
            else if((i + j) == n - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << " * ";
            }
            else if(i == j + 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(i == j - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(i + j == n)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else if(i + j == n - 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                cout << " # ";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << " + ";
            }
        }
        cout << endl;
    }

    return 0;
}
