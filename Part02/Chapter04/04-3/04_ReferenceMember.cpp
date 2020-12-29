#include <iostream>
using namespace std;

class AAA
{
public:
    AAA()
    {
        cout << "empty object" << endl;
    }
    void ShowYourName() const
    {
        cout << "I'm class AAA" << endl;
    }
};

class BBB
{
private:
    AAA &ref;
    const int &num;
public:
    BBB(AAA &r, const int &n)
        : ref(r), num(n)
    {

    }
    void ShowYourName() const
    {
        cout << "I'm Class BBB" << endl;
        cout << "and I ref num : " << num << endl;
    }
};

int main(void)
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}