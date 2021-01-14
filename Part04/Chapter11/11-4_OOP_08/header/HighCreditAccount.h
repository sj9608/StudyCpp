#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;
public:
    HighCreditAccount(int ID, int money, char* name, int rate, int special)
        : NormalAccount(ID, money, name, rate), specialRate(special)
    { }
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money); // 원금 + 이자
        Account::Deposit(money * (specialRate * 0.01)); // 특별이자
    }
};
#endif