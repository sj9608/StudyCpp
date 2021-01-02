#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

class Account
{
private:
    int accID;
    int balance;
    char *cusName;

public:
    Account(int acc, int money, char *name)
        : accID(acc), balance(money)
    {
        cusName = new char[strlen(name) + 1];
        strcpy(cusName, name);
    }
    Account(const Account &copy)
        : accID(copy.accID), balance(copy.balance)
    {
        cusName = new char[strlen(copy.cusName) + 1];
        strcpy(cusName, copy.cusName);
    }

    int GetAccId()
    {
        return accID;
    }

    void Deposit(int money)
    {
        balance += money;
    }

    int Withdraw(int money)
    {
        if(balance < money)
            return 0;
        
        balance -= money;
        return money;
    }

    void ShowAccInfo()
    {
        cout << "계좌 ID : " << accID << endl;
        cout << "이 름 : " << cusName << endl;
        cout << "잔 액 : " << balance << endl;
    }

    ~Account()
    {
        delete[] cusName;
    }
};

Account * accArr[100];
int accNum = 0;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void InquireAllAccInfo();

int main(void)
{
    int choice;
    while (1)
    {
        ShowMenu();
        cin >> choice;
        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            InquireAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal Selection . . ." << endl;
            break;
        }
    }

    return 0;
}

void ShowMenu()
{
    cout << endl;
    cout << "------ M e n u -----" << endl;
    cout << "1. 계좌개설 " << endl;
    cout << "2. 입 금 " << endl;
    cout << "3. 출 금 " << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << endl;
}

void MakeAccount()
{
    char name[NAME_LEN];
    int accountNum;
    int money;

    cout << "[ 계 좌 개 설 ]" << endl;
    cout << "계좌 ID : ";
    cin >> accountNum;
    cout << "이름 : ";
    cin >> name;
    cout << "입금액 : ";
    cin >> money;

    accArr[accNum] = new Account(accountNum, money, name);
    accNum ++;
}

void DepositMoney()
{
    int accountNum;
    int money;

    cout << "[ 입 금 ]" << endl;
    cout << "계좌 ID : ";
    cin >> accountNum;
    cout << "입금액 : ";
    cin >> money;

    for(int i=0; i<accNum ; i++)
    {
        if(accArr[i]->GetAccId() == accountNum)
        {
            accArr[i]->Deposit(money);
            cout << "입금 완료" <<endl;
            return;
        }
    }
    cout << "계좌번호를 찾을 수 없습니다." << endl;
}

void WithdrawMoney()
{
    int accountNum;
    int money;

    cout << "[ 출 금 ]" << endl;
    cout << "계좌 ID : ";
    cin >> accountNum;
    cout << "입금액 : ";
    cin >> money;

    for(int i = 0; i< accNum; i++)
    {
        if(accArr[i]->GetAccId() == accountNum)
        {
            if(accArr[i]->Withdraw(money) == 0)
            {
                cout << "잔액이 부족합니다. " << endl;
            }
            else cout << "출금 완료" << endl;
        }
    }
}

void InquireAllAccInfo()
{
    for(int i = 0; i < accNum; i++)
    {
        cout << "-----고객정보-----" << endl;
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}