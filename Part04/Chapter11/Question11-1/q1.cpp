#include <iostream>
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
    Police pman2 = pman1;

    Police pman3(1, 4);
    pman3 = pman1;
    
    
    return 0;
}