#ifndef __FRUITBUYER_H__
#define __FRUITBUYER_H__
#include "FruitSeller.h"

class FruitBuyer
{
private:
    int myMoney;     
    int numOfApples; 

public:
    void InitMembers(int money);
    void BuyApples(FruitSeller &seller, int money);
    void ShowBuyResult();
};
#endif