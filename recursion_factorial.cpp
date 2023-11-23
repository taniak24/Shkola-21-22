#include <iostream>

using namespace std;

int print_factorial(int n)
{
    if(n <= 1)
    {
        return n;
    }
    cout << "N: " << n << endl;
    return n * print_factorial(n - 1);
}

int main()
{
    int n;

    cout << "Input a number: ";
    cin >> n;

    cout << "The result is: " << print_factorial(n);

    return 0;
}
