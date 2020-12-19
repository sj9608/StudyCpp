/* 사용자로부터 총 5개의 정수 입력받아 그 합을 출력하는 프로그램을 작성 */
#include <iostream>

int main(void)
{
    int num, result = 0;

    for(int i = 0; i < 5 ; i++)
    {
        std::cout << i+1 << "번 째 정수 입력: ";
        std::cin >> num;
        result += num;
    }
    std::cout << "합계: " << result << std::endl;
    return 0;
}