#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
    int height;
    friend class Girl;
public:
    Boy(int len) : height(len) { }
    void ShowyourFriendInfo(Girl &frn);
};

class Girl
{
private:
    char phNum[20];
public:
    Girl(char * num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn);
    friend class Boy;
};

void Boy::ShowyourFriendInfo(Girl &frn)
{
    cout << "Her Phone Num is : " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
    cout << "His height is : " << frn.height << endl;
}

int main(void)
{
    Boy boy(170);
    Girl girl("010-1234-5678");

    boy.ShowyourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    
    return 0;
}