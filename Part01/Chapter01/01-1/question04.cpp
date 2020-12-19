/* 판매원들의 급여 계산 프로그램 */
#include <iostream>

int main()
{
    int salesAmt = 0;

    while (true)
    {
        std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
        std::cin >> salesAmt;
        if (salesAmt == -1)
            break;
        else
            std::cout << "이번 달 급여 : " << 50 + salesAmt * 0.12 << " 만원" << std::endl;
    }

    std::cout << "프로그램을 종료합니다." << std::endl;

    return 0;
}