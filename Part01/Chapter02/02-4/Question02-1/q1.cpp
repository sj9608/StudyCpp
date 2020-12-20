#include<iostream>
using namespace std;
void PlusNum(int &ref1);
void ReverseNum(int &ref1);

int main(void)
{
    int num = 2;

    PlusNum(num);
    cout << num << endl;

    ReverseNum(num);
    cout << num << endl;

    return 0;
}

void PlusNum(int &ref1)
{
    ref1++;
}

void ReverseNum(int &ref2)
{
    ref2 *= -1;
}