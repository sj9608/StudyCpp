/* 문제 2 다음과 같은 형태로의 함수 오버로딩은 문제가 있다. 어떤 문제가 있는지 설명해보자. */
#include <iostream>

int SimpleFunc(int a = 10)
{
    return a + 1;

}

int SimpleFunc(void)
{
    return 10;
}

/* asnwer */
 
 // 함수인자를 전달하지 않았을 경우 전달형이 없는 void와 
 // 인자가 없을 경우 디폴트값 10을 전달하는 함수가 서로 겹치기 때문에
