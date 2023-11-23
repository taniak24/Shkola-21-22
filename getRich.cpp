#include <iostream>

using namespace std;

const int N = 4;
int counter = 0;
int money = 0;
///1st way: *a
///2nd way: []unsized array
///3rd way: [N]sized

bool correctAnswer(string q, string a[], char ca)
{
    char answer;


    cout << q << endl;
    for(int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    cout << "What's your answer?: ";
    cin >> answer;

        if(answer == ca)
        {
            cout << "It is correct!";
            cout << endl << endl;
            counter++;
            return true;
        }
        else
        {
            cout << "Wrong answer!";
            cout << endl << endl;
            return false;
        }

}

int main()
{
    string q1 = "What is the biggest animal in the world?";
    string a1[N] = {"a. elephant", "b. whale", "c. hippopotamus", "d. rhino"};
    char ca1 = 'b';

    string q2 = "What is the freezing point in Fahrenheit?";
    string a2[N] = {"a. 50", "b. 0", "c. 84", "d. 32"};
    char ca2 = 'd';

    string q3 = "What is the sacred animal of India?";
    string a3[N] = {"a. cow", "b. rabbit", "c. snake", "d. lion"};
    char ca3 = 'a';

    string q4 = "What is the fastest animal in the water?";
    string a4[N] = {"a. jaguar", "b. sailfish", "c. dolphin", "d. shark"};
    char ca4 = 'b';

    correctAnswer(q1, a1, ca1);
    correctAnswer(q2, a2, ca2);
    correctAnswer(q3, a3, ca3);
    correctAnswer(q4, a4, ca4);



    return 0;
}
