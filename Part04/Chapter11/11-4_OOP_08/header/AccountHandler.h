#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    BoundCheckAccountPtrArray accArr;
    int accNum;
public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};
#endif