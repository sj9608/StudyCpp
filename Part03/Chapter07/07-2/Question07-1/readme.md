문제1
---
앞서 상속관계에 놓여있는 클래스의 생성자 정의 및 호출방식에 대해 설명하였다.
이 내용을 바탕으로 다음 클래스에 적절한 생성자를 삽입하고. 이를 확인하기 위한 main 함수를 적절히 정의해 보자.

``` C++
#include <iostream>
#include <cstring>

using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGague;
public:
    int GetElecGauge()
    {
        return electricGague;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    void ShowCurrentGague()
    {
        cout << "잔여 가솔린  : " << GetGasGauge() << endl;
        cout << "잔여 전기량  : " << GetElecGauge() << endl;
        cout << "잔여 워터량  : " << waterGauge << endl;
    }
};
```

문제 2
---
다음 두 클래스에 적절한 생성자와 소멸자를 정의해 보자. 그릭 이의 확인을 위한 main 함수를 정의해 보자.
``` C++
class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    void ShowMyFriendInfo() const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    void ShowMyFriendDetailInfo() const
    {
        ShowMyFriendInfo();
        cout << "주소 : " << addr << endl;
        cout << "번호 : " << phone << endl;
    }
};
```