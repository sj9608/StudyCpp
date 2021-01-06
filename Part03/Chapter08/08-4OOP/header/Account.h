#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    char * cusName;
    int accID;
    int balance;
public:
    Account(char * name, int account, int money);
    Account(const Account &copy);
    int GetAccId() const;
    virtual void Deposit(int money);
    bool Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};
#endif