#include <iostream>
#include <cstring>

using namespace std;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
    char name[20];
    int accountNum;
    int balance;
}Account;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void InquireAllInfo();

Account accArr[100];
int accNum = 0;

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "메뉴를 선택해 주세요 : ";
        cin >> choice;

        switch(choice)
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
                InquireAllInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selection..." << endl;
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
    Account acc1;

    cout << "[ 계 좌 개 설 ]" << endl;
    cout << "계좌 ID : ";
    cin >> acc1.accountNum;
    cout << "이름 : ";
    cin >> acc1.name;
    cout << "입금액 : ";
    cin >> acc1.balance;

    accArr[accNum].accountNum = acc1.accountNum;
    accArr[accNum].balance = acc1.balance;
    strcpy(accArr[accNum].name, acc1.name);
    accNum+=1;
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
        if(accArr[i].accountNum == accountNum)
        {
            accArr[i].balance += money;
            cout << "입금 완료" <<endl;
        }
    }
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
        if(accArr[i].accountNum == accountNum)
        {
            accArr[i].balance -= money;
            cout << "출금 완료" << endl;
        }
    }
}

void InquireAllInfo()
{
    for(int i = 0; i < accNum; i++)
    {
        cout << "계좌 ID : " << accArr[i].accountNum << endl;
        cout << "이 름 : " << accArr[i].name << endl;
        cout << "잔 액 : " << accArr[i].balance << endl;
    }
}