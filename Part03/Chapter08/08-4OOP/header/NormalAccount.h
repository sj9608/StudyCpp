#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account
{
private:
    int interRate;
public:
    NormalAccount(char * name, int account, int money, int ratio);
    virtual void Deposit(int money);
};
#endif