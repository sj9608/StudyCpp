/* 숫자 하나를 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성 */
#include<iostream>

int main()
{
    int row = 0;

    std::cout << "출력하실 구구단은 몇 단인가요? : ";
    std::cin >> row;

    std::cout << "---------- " << row << " 단 ------------" << std::endl;
    for(int i = 1; i < 10 ; i++)
    {
        std::cout << row << '*' << i << '=' << row * i << std::endl;
    }

    return 0;
}