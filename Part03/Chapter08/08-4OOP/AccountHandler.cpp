#include <iostream>
#include <cstring>
#include "header/AccountHandler.h"

using namespace std;
const int NAME_LEN = 20;

enum { NORMAL = 1, HIGHCREDIT = 2 };

enum {CREDIT_A = 7, CREDIT_B = 4, CREDIT_C = 2};

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
    int choice;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 ";
    cout << "2. 신용신뢰계좌 ";
    cout << " 선택 : ";
    cin >> choice;

    if(choice == NORMAL)
        MakeNormalAccount();
    else if(choice == HIGHCREDIT)
        MakeHighCreditAccount();
}
void AccountHandler::MakeNormalAccount()
{
    char name[NAME_LEN];
    int id;
    int balance;
    int ratio;

    cout << "[ 계 좌 개 설 ]" << endl << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    cout << "이자율 : "; cin >> ratio;

    accArr[accNum++] = new NormalAccount(name, id, balance, ratio);
}

void AccountHandler::MakeHighCreditAccount()
{
    char name[NAME_LEN];
    int id;
    int balance;
    int ratio;
    int credit;

    cout << "[ 계 좌 개 설 ]" << endl << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    cout << "이자율 : "; cin >> ratio;
    cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> credit;

    switch(credit)
    {
        case 1:
            accArr[accNum++] = new HighCreditAccount(name, id, balance, ratio, CREDIT_A);
            break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(name, id, balance, ratio, CREDIT_B);
            break;
        case 3:
            accArr[accNum++] = new HighCreditAccount(name, id, balance, ratio, CREDIT_C);
            break;
        default:
            cout << "잘못된 신용등급 입니다." << endl;
            break;
    }
    
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