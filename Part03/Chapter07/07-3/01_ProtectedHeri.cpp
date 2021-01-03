#include <iostream>
using namespace std;

class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
    Base() : num1(1), num2(2), num3(3) { }
};

class Derived : protected Base
{
public:
    void ShowData()
    {
        cout << num2 << endl;
        cout << num3 << endl;
    }
};

int main(void)
{
    Derived drv;

    drv.ShowData();
    return 0;
}