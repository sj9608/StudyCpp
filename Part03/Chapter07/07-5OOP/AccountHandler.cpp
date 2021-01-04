#include <iostream>
#include <cstring>
#include "Account.h"
#include "AccountHandler.h"

using namespace std;
const int NAME_LEN = 20;

AccountHandler::AccountHandler()
    : accNum(0)
{
}

void AccountHandler::ShowMenu() const
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

void AccountHandler::MakeAccount()
{
    char name[NAME_LEN];
    int id;
    int balance;

    cout << "[ 계 좌 개 설 ]" << endl
         << endl;
    cout << "계좌 ID : ";
    cin >> id;
    cout << "이 름 : ";
    cin >> name;
    cout << "입금액 : ";
    cin >> balance;

    accArr[accNum++] = new Account(name, id, balance);
}

void AccountHandler::DepositMoney()
{
    int id;
    int money;

    cout << "[ 입 금 ]" << endl
         << endl;
    cout << "계좌 ID : ";
    cin >> id;
    cout << "입금액 : ";
    cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccId() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입 금 완 료" << endl;
            return;
        }
    }
    cout << "일치하는 계좌 id가 없습니다." << endl;
}

void AccountHandler::WithdrawMoney()
{
    int id;
    int money;

    cout << "[ 출 금 ]" << endl;
    cout << "계좌 ID : ";
    cin >> id;
    cout << "출금액 : ";
    cin >> money;

    for(int i = 0; i < accNum; i++)
    {
        if(accArr[i]->GetAccId() == id)
        {
            if(!accArr[i]->Withdraw(money))
            {
                cout << "잔고가 부족합니다." << endl;
                return;
            }
            cout << "출금 완료" << endl;
        }
    }
}

void AccountHandler::ShowAllAccInfo() const
{
    for(int i = 0 ; i < accNum ; i++)
    {
        cout << "---- 고 객 정 보 ----" << endl;
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i < accNum; i++)
    {
        delete accArr[i];
    }    
}

/*
void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();
*/