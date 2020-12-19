/* 이름, 전화번호를 문자열 형태로 입력 받고 데이터를 그대로 출력하는 프로그램 */
#include <iostream>

int main(void)
{
    char name[15];
    char number[15];

    std::cout << "이름을 입력하세요 : ";
    std::cin >> name;
    std::cout << "번호를 입력하세요 : ";
    std::cin >> number;

    std::cout << "입력하신 성함은 " << name << "이고 번호는 " << number << " 입니다." << std::endl;

    return 0;
}