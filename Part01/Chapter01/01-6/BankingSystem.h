#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

typedef struct
{
    int accID;
    int balance;
    char cusName[NAME_LEN];

} Account;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

#endif