문제1
---
계산기 기능의 Calculator 클래스를 정의해 보자. 기본적으로 지니는 기능은 덧셈, 뺼셈, 곱셈, 나눗셈이며 연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록 되어야 한다.
아래의 main 함수와 실행의 예에 부합하는 Calculator 클래스를 정의하면 된다.
단 멤버변수는 private, 멤버함수는 public으로 선언하자.

```C++
int main(void)
{
    Calculator cal;
    cal.Init();

    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;

    cal.ShowOpCount();

    return 0;
}
```
실행의 예
``` bash
3.2 + 2.4 = 5.6
3.5 / 1.7 = 2.05882
2.2 - 1.5 = 0.7
4.9 / 1.2 = 4.08333
덧셈 : 1 뺄셈 : 1 곱셈 : 0 나눗셈 : 2
```

문제 2
---
문자열 정보를 내부에 저장하는 Printer 클래스를 디자인하자. 이 클래스는 다음의 기능 2가지를 한다.
* 문자열 저장
* 문자열 출력

아래의 main함수와 실행의 예에 부합하는 Printer 클래스를 정의하되, 이번에도 역시 멤버변수는 private, 멤버함수는 public으로 선언하자

``` C++
int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();

    return 0;
}
```
실행의 예
``` bash
Hello world!
I love C++
```