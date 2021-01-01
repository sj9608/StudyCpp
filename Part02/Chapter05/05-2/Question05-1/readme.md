문제 05-1 [복사 생성자의 정의]
---
문제 04-3의 문제 2를 통해서 NameCard 클래스를 정의하였다. 그런데 이 클래스도 생성자 내에서 메모리 공간을 동적 할당하기 때문에 복사 생성자가 필요한 클래스이다. 이에 복사 생성자를 적절히 정의해보고, 복사 이후에 문제가 발생하지 않음을 다음 main 함수를 통해서 확인하자.

[main 함수의 예]
``` C++
int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;

    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}
```