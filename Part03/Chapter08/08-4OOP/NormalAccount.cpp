#include "header/NormalAccount.h"

NormalAccount::NormalAccount(char * name, int account, int money, int ratio)
        : Account(name, account, money), interRate(ratio)
    { }

void NormalAccount::Deposit(int money)
{
    Account::Deposit(money);
    Account::Deposit(money * (interRate * 0.01));
}