// 기본자료형 bool도 마찬가지로 다른 기본자료형과 동일한 방식으로 사용 할 수 있음.

#include <iostream>
using namespace std;

bool IsPositive(int num)
{
    if (num <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(void)
{
    bool isPos;
    int num;

    cout << "Input number: ";
    cin >> num;

    isPos = IsPositive(num);
    if(isPos)
    {
        cout<< "Positive number" << endl;
    }
    else
    {
        cout << "Negative number" << endl;
    }
    
    return 0;
}