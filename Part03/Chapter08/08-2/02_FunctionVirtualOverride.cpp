#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() { cout << "First" << endl; }
};

class Second : public First
{
public:
    virtual void MyFunc() { cout << "Second" << endl; }
};

class Third : public Second
{
public:
    virtual void MyFunc() { cout << "Third" << endl; }
};

int main(void)
{
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();

    delete tptr;
    return 0;
}