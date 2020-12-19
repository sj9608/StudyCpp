/* 인라인 함수와 템플릿 변수 (매크로 함수를 사용하기 좋게) */
#include <iostream>

template <typename T>

inline T SQUARE(T x)
{
    return x * x;
}

int main(void)
{
    std::cout << SQUARE(5.5) << std::endl;
    std::cout << SQUARE(12) << std::endl;
    return 0;
}

/* 후반부에 더 자세하게 다룰 예정 */