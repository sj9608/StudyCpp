#include <iostream>
using namespace std;

class First
{
private:
    int num1, num2;
public:
    First(int n1=0, int n2=0) : num1(n1), num2(n2)
    { }
    void ShowData() const
    {
        cout << num1 << ", " << num2 << endl;
    }

    First& operator=(const First& ref)
    {
        cout << "First& operator=()" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second : public First
{
private:
    int num3, num4;
public:
    Second(int n1=0, int n2=0,int n3=0, int n4=0) 
        : First(n1, n2), num3(n3), num4(n4)
    { } 
    void ShowData() const
    {
        First::ShowData();
        cout << num3 << ", " << num4 << endl;
    }
    
    Second& operator=(const Second& ref)
    {
        cout << "Second& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    } 
};

int main(void)
{
    Second ssrc(111, 222, 333, 444);
    Second scpy;

    scpy = ssrc;
    scpy.ShowData();

    return 0;
}