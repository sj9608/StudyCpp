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

    Police(const Police& ref)
        : handcuffs(ref.handcuffs)
    {
        if(pistol != NULL)
            pistol = new Gun(*ref.pistol);
        else
            pistol = NULL;
    }

    Police& operator=(const Police& ref)
    {
        if(pistol != NULL)
            delete pistol;
        if(ref.pistol != NULL)    
            pistol = new Gun(*ref.pistol);
        else 
            pistol = NULL;
            
        handcuffs = ref.handcuffs;
        return *this;
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

    pman2.PutHandcuff();
    pman2.PutHandcuff();

    Police pman3(1, 4);
    pman3 = pman1;
    
    pman3.Shot();
    pman3.Shot();
    pman3.Shot();
    
    return 0;
}