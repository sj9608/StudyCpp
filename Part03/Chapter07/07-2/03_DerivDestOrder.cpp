#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;
public:
    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase()"<< baseNum << endl;
    }
    ~SoBase()
    {
        cout << "~SoBase()" << baseNum << endl;
    }
};

class SoDerived : public SoBase
{
private:
    int derivNum;
public:
    SoDerived(int n) : SoBase(n), derivNum(n)
    {
        cout << "SoDerived(int n)" << derivNum << endl;
    }
    ~SoDerived()
    {
        cout << "~SoDerived()" << derivNum << endl;
    }
};

int main(void)
{
    SoDerived dr1(15);
    SoDerived dr2(27);

    return 0;
}