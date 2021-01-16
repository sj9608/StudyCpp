#include "header/BankingCommonDecl.h"
#include "header/Account.h"
#include "header/NormalAccount.h"
#include "header/HighCreditAccount.h"
#include "header/AccountHandler.h"

void AccountHandler::ShowMenu() const
{
    cout << "---- M E N U ----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
    int sel;
    cout << "[계좌 종류 선택]" << endl;
    cout << "1. 보통예금계좌" << endl;
    cout << "2. 신용신뢰계좌" << endl;
    cout << "선택 : "; cin >> sel;

    if(sel == NORMAL)
        MakeNormalAccount();
    else if(sel == CREDIT)
        MakeCreditAccount();
    else 
        cout << "잘못 입력하셨습니다." << endl;
}

void AccountHandler::MakeNormalAccount(void)
{
    int id;
    String name;
    int balance;
    int interRate;

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    cout << "이자율 : "; cin >> interRate;
    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
    int id;
    String name;
    int balance;
    int interRate;
    int special;

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    cout << "이자율 : "; cin >> interRate;
    cout << "신용등급 (1 to A, 2 to B, 3 to C) : "; cin >> special;
    cout << endl;

    switch (special)
    {
    case 1:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
        break;
    case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
        break;
    case 3:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
        break;
    default:
        cout << "신용등급이 잘못 입력되었습니다." << endl;
        break;
    }
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;
    cout << "[입 금]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "입금액 : "; cin >> money;

    for(int i = 0; i < accNum ; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입금 완료" << endl;
            return;
        }
        cout << "유효하지 않은 ID 입니다." << endl;
    }
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;

    cout << "[출 금]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "출금액 : "; cin >> money;

    for(int i = 0; i < accNum ; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            if(accArr[i]->Withdraw(money) == 0)
            cout << "잔액 부족" << endl;
            return;
        }
        cout << "출금 완료" << endl;
        return;
    }
    cout << "유효하지 않은 ID 입니다." << endl;
}

AccountHandler::AccountHandler() : accNum(0) { }

void AccountHandler::ShowAllAccInfo(void) const
{
    for(int i = 0; i < accNum ; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i< accNum ; i++)
    {
        delete accArr[i];
    }
}