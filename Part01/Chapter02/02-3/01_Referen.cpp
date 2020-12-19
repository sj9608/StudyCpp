#include<iostream>
using namespace std;

int main(void)
{
    int num1 = 2010;
    int &num2 = num1; // num1에 대한 참조자 num2를 선언 이후로 num1, num2 가 동일한 메모리 공간을 참조하게 된다.

    num2 = 3047;
    cout << "VAL : " << num1 << endl; // VAL : 3047
    cout << "REF : " << num2 << endl; // REF : 3047

    cout << "VAL : " << &num1 << endl; // VAL : 0x7ffeea01e7f8
    cout << "REF : " << &num2 << endl; // REF : 0x7ffeea01e7f8

    return 0;
}