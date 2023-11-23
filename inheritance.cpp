#include<iostream>

using namespace std;

class Base{
protected:
    int i;

public:
    Base(int x)
    {
        i = x;
        cout << "Constructing Base \n";
    }
};

class Inherited:public Base{
public:
    int j;
    Inherited(int x, int y):Base(y){
    j = x;
    cout << "Constructing Inherited \n";
    }

    void show()

int main()
{
    Inherited obj(3, 4);

    obj.show();

    return 0;
}
