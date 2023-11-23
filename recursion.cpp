#include <iostream>

using namespace std;

int num_print(int n)
{
    if(n <= 50)
    {
        cout << n << " ";
        num_print(n + 1);
    }

}

int main()
{
    ///print all numbers to 50 using recursion
    ///in here - call the function the first time and then it calls itself

    int n = 1;
    num_print(n);

    return 0;
}
