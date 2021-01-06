#include "header/HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(char *name, int account, int money, int ratio, int credit)
    : NormalAccount(name, account, money, ratio), creditRate(credit)
{ }

void HighCreditAccount::Deposit(int money)
{
    NormalAccount::Deposit(money);
    Account::Deposit(money * (creditRate * 0.01));
}