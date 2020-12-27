#include <iostream>
#include "FruitSeller.h"
using namespace std;

void FruitSeller::InitMembers(int price, int num, int money)
{
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
}

int FruitSeller::SaleApples(int money)
{
    if(money < 0)
    {
        cout << "잘못된 값 입력됌" << endl;
        return;
    }
    
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller::ShowSalesResult() const
{
    cout << "남은 사과 : " << numOfApples << endl;
    cout << "판매 수익 : " << myMoney << endl << endl;
}