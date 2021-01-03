#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum)
        : bullet(bnum)
    { }
    void Shot()
    {
        cout << "BBANG" << endl;
        bullet--;
    }
};

class Police : public Gun
{
private:
    int handcuffs;
public:
    Police(int bnum, int bcuffs)
        : Gun(bnum), handcuffs(bcuffs)
    { }
    void PutHandcuff()
    {
        cout << "SNAP" << endl;
        handcuffs--;
    }
};

int main(void)
{
    Police p1(5, 3);
    p1.Shot();
    p1.PutHandcuff();
    
    return 0;
}