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

class Police
{
private:
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuffs)
        :handcuffs(bcuffs)
    {
        if(bnum > 0)
        {
            pistol = new Gun(bnum);
        }
        else
        {
            pistol = NULL;
        }
    }
    void Shot()
    {
        if(pistol== NULL)
        {
            cout << "총알 없다." << endl;
        }
        else pistol->Shot();
    }
    void PutHandcuff()
    {
        cout << "SNAP" << endl;
        handcuffs--;
    }
    ~Police()
    {
        if(pistol != NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();

    return 0;
}