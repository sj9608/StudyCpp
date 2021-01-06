#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

class AccountHandler
{
private:
    Account * accArr[50];
    int accNum;
public:
    AccountHandler();
    void ShowMenu() const;
    void MakeNormalAccount();
    void MakeHighCreditAccount();
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccInfo() const;
    ~AccountHandler();
};
#endif