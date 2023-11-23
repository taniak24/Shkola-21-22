#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    string words[] = {"programming", "discord", "tiger", "computer", "purple", "keyboard", "research", "painting", "dog", "green", "jacket", "pocket", "rocket", "rectangular", "jewelry"};
    int wordCount = sizeof(words) / sizeof(words[0]);
    ///int wordCount2 = *(&words+1) - words;
    /// (&words + 1) point to the memory address right after the array
    /// *(&words + 1) cast the address to 'int'

    int randWord = rand() % wordCount;
    string rWord = words[randWord];

    bool guessWord[rWord.length()] = {false};
    int rightLetter = 0;
    char letter;
    int lives = 7;
    bool check = false;

    ///cout << rWord << endl;

    guessWord[0] = true; ///first letter

    while(lives >= 0 || rightLetter == rWord.length())
    {
        check = false;
        cout << "Guess the word:" << endl;
        for(int i = 0; i < rWord.length(); i++)
        {
            if(guessWord[i] == false)
            {
                cout << "_ ";
            }
            else
            {
                cout << rWord[i];
            }
        }

        cout << endl << endl;
        cin >> letter;

        for(int i = 0; i < rWord.length(); i++)
        {
            if(rWord[i] == letter)
            {
                guessWord[i] = true;
                rightLetter++;
                check = true;
            }
        }

        if(check == false)
        {
            lives--;
        }
        cout << "lives: " << lives << endl;

        if(lives == 6)
        {
            cout << "___________" << endl << endl;
        }
        else if(lives == 5)
        {
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "___________" << endl << endl;
        }
        else if(lives == 4)
        {
            cout << " ______    " << endl;
            cout << "|     |    " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "___________" << endl << endl;
        }
        else if(lives == 3)
        {
            cout << " ______    " << endl;
            cout << "|     |    " << endl;
            cout << "|     O    " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "|          " << endl;
            cout << "___________" << endl << endl;
        }
        else if(lives == 2)
        {
            cout << " ______    " << endl;
            cout << "|     |    " << endl;
            cout << "|     O    " << endl;
            cout << "|     |    " << endl;
            cout << "|     |    " << endl;
            cout << "|          " << endl;
            cout << "___________" << endl << endl;
        }
        else if(lives == 1)
        {
            cout << " ______    " << endl;
            cout << "|     |    " << endl;
            cout << "|     O    " << endl;
            cout << "|    /|\\  " << endl;
            cout << "|     |    " << endl;
            cout << "|          " << endl;
            cout << "___________" << endl << endl;
        }
        else if(lives == 0)
        {
            cout << " ______    " << endl;
            cout << "|     |    " << endl;
            cout << "|     O    " << endl;
            cout << "|    /|\\  " << endl;
            cout << "|     |    " << endl;
            cout << "|    / \\  " << endl;
            cout << "___________" << endl;
            cout << "YOU LOST!  " << endl;
        }

    }


    return 0;
}
