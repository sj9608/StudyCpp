#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    FruitSeller(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money)
    {
        int num = money/APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void ShowSalesResult() const
    {
        cout << "남은 사과 : " << numOfApples << endl;
        cout << "판매 수익 : " << myMoney << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    FruitBuyer(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "현재 잔액 : " << myMoney << endl;
        cout << "사과 개수 : " << numOfApples << endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);

    buyer.BuyApples(seller, 3000);

    cout << "과일 판매자" << endl; 
    seller.ShowSalesResult();

    cout << "과일 구매자" << endl;
    buyer.ShowBuyResult();
    
    return 0;
}