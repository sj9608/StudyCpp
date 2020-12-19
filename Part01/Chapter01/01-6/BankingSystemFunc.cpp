#include "BankingSystem.h"

Account accArr[100]; // 저장된 계좌들 (최대 100개 까지 생성가능)
int accNum = 0; // 증설된 계좌 수

void ShowMenu(void)
{
    /* 메뉴 출력 */
    cout << "--------- M E N U --------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입   금" << endl;
    cout << "3. 출   금" << endl;
    cout << "4. 전체고객 잔액조회" << endl;
    cout << "5. 프로그램 종료. " << endl;
}

void MakeAccount(void)
{
    int id;
    int balance;
    char name[NAME_LEN];

    cout << "[계좌개설]" << endl;
    cout << "계좌 ID : ";    cin >> id;
    cout << "이 름 : ";    cin >> name;
    cout << "입금액 : ";    cin >> balance;
    cout << endl;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);

    accNum++;

}

void DepositMoney(void)
{
    int id;
    int balance;

    cout << "[입  금]" << endl;
    cout << "계좌 ID : ";    cin >> id;
    cout << "입금액 : ";    cin >> balance;

    for(int i = 0 ; i < 100 ; i++)
    {
        if(accArr[i].accID == id)
        {
            accArr[i].balance += balance;
            cout << "입금 완료";
            return;
        }        
    }
    cout << "유효하지 않은 id 입니다." << endl;
}

void WithdrawMoney(void)
{

}

void ShowAllAccInfo(void)
{

}