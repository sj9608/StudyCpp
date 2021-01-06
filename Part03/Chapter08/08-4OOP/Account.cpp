#include <iostream>
#include <cstring>
#include "header/Account.h"
using namespace std;

Account::Account(char *name, int account, int money)
    : accID(account), balance(money)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref)
    : accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccId() const
{
    return accID;
}

void Account::Deposit(int money)
{
    balance += money;
}

bool Account::Withdraw(int money)
{
    if (balance < money)
        return false;

    balance -= money;
    return true;
}

void Account::ShowAccInfo() const
{
    cout << "계좌 ID : " << accID << endl;
    cout << "이 름 : " << cusName << endl;
    cout << "잔 액 : " << balance << endl;
}

Account::~Account()
{
    delete[] cusName;
}
/*
Account(char * name, int account, int money);
Account(const Account &copy);
int GetAccId() const;
void Deposit(int money);
int Withdraw(int money);
void ShowAccInfo() const;
~Account();
 */