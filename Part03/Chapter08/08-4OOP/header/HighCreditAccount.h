#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int creditRate;
public:
    HighCreditAccount(char * name, int account, int money, int ratio, int credit);
    virtual void Deposit(int money);
};

#endif