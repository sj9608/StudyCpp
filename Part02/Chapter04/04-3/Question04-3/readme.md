문제 1
---
앞서 제시한 문제 04-2에 Point, Circle, Ring 클래스의 객체의 초기화에 생성자를 정의해보자.

문제 2
---
이 문제는 05-1에 다시 사용됨
명함을 의미하는 NameCard 클래스를 정의해보자. 이클래스에는 다음의 정보가 저장되어야 한다.
* 성명
* 회사이름
* 전화번호
* 직급

단, 직급 정보를 제외한 나머지는 문자열의 형태로 저장을 하되, 길이에 딱 맞는 메모리 공간을 할당 받는 형태로 정의하자(동적할당 하라는 의미).
그리고 직급정보는 int형 멤버 변수를 선언해서 저장을 하되 아래의 enum 선언을 활용해야 한다.
``` C++
enum {CLERK, SENIOR, ASSIST, MANAGER}
```

위의 enum 선언에 정의된 상수는 순서대로 사원, 주임, 대리, 과장 을 뜻한다. 그럼 main 함수와 실행의 예를 참조하여, 이문제에서 원하는 형태대로 NameCard 클래스를 완성해보자.
``` C++
int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}
```

[실행의 예]
``` bash
이름 : Lee
회사 : ABCEng
전화번호 : 010-1111-2222
직급 : 사원

이름 : Hong
회사 : OrangeEng
전화번호 :010-3333-4444
직급 : 주임

이름 : Kim
회사 : SoGoodComp
전화번호 : 010-5555-6666
직급 : 대리 
```