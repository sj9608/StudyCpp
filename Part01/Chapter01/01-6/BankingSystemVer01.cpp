#include "BankingSystem.h"

int main(void)
{
    int choice;

    while (1)
    {
        ShowMenu();
        cout << "선택 : " << endl;
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
            ShowAllAccInfo();
            break;

        case EXIT:
            return 0;
        default:
            break;
        }
    }
    return 0;
}