10-4 cout, cin 그리고 endl 의 정체
---
**cout과 endl 이해하기**
다음은 C++의 콘솔 입출력에 사용되는 cout과 endl의 이해를 돕기 위한 예제이다.
이 예제에서는 cout과 endl을 아주 조금 흉내내서 이 둘에 대한 이해를 돕고있다.
> 01_ConsoleOutput.cpp 예제 확인

``` C++
#include <iostream>
namespace mystd
{
    using namespace std;

    class ostream
    {
    public:
        void operator<<(char * str)
        {
            printf("%s", str);
        }
        void operator<< (char str)
        {
            printf("%c", str);
        }
        void operator<< (int num)
        {
            printf("%d", num);
        }
        void operator<< (double e)
        {
            printf("%g", e);
        }
        void operator<< (ostream& (*fp)(ostream &ostm))
        {
            fp(*this);
        }
    };

    ostream& endl(ostream &ostm)
    {
        ostm<< '\n';
        fflush(stdout);
        return ostm;
    }

    ostream cout;
}

int main(void)
{
    using mystd::cout;
    using mystd::endl;

    cout <<(char *)"Simple String";
    cout << endl;
    cout << 3.14;
    cout << endl;
    cout << 123;
    endl(cout);

    return 0;
}
```
위 예제를 디버깅 해본뒤 순서를 분석해보자.

main 함수의 
``` C++
cout << "Simple String";
cout << 3.14; 
cout << 123;
```
위 구문은 다음과 같이 해석된다.

``` C++
cout.operator << ("Simple String");
cout.operator << (3.14);
cout.operator << (123);
```
이 때 사용된 cout은 namespace mystd 내에 선언된 cout 이다. 그리고 
``` C++
cout << endl;
```
위 구문은 다음과 같이 해석된다.

``` C++
cout.operator << (endl);
```

위 구문은 다음의 구문을 호출한다.
``` C++
void operator << (ostream& (*fp)(ostream &ostm))
{
    fp(*this);
}
```

---
위 예제는 한가지 문제점을 가지고 있다. 다음형태의 문장은 컴파일 에러를 일으킨다. 어디를 어떻게 변경해야 다음 문장을 실행할 수 있을까? 예제 02를 작성하자.

> 02_ItreateConsoleOutput.cpp

예제 01과 02의 내용으로 알 수 있는 사실은 다음과 같다.
* cout은 객체의 이름이며. 이 객체 내에서는 다양한 기본자료형 데이터를 대상으로 << 연산자를 오버로딩 했다는 것.
* endl은 함수의형태를 하고있다는 것.

**<<, >> 연산자 오버로딩**
cout, endl의 이해를 돕는 예제의 작성과정에서 << 연산자를 오버로딩 해 보았다. 이번에는 앞서 정의한 Point 클래스를 대상으로 << 연산자와 >> 연산자를 오버로딩 해 보고자 한다. 즉, 다음과 같은 유형의 연산이 가능하게 하고자한다.

``` C++
int main(void)
{
    Point pos(3, 4);
    cout << pos << endl; // [3, 4] 출력
    . . . .
}
```

이러한 문제의 해결을 위해서는 연산자 오버로딩을 해야하므로, 다음의 사실을 알고 있어야한다.
* cout은 ostream 클래스의 객체이다.
* ostream은 이름공간 std 안에 선언되어 있으며, 이의 사용을 위해서는 헤더파일 iostream 을 포함해야 한다.

cout << pos 이 구문이 가능하기 위해서는 << 연산자가 Point 클래스 안에 오버로딩 되어있어야 한다. 그리고 만약 멤버함수의 형태로 오버로딩을 한다면, 다음과 같이 해석이 가능하다. 
``` C++
cout.operator<<(pos);
```

전역 함수의 경우에는 다음과 같이 해석이 가능해야 한다.
``` C++
operator<<(cout, pos);
```

이 둘 중 우리는 전역함수의 형태로 선언하고 정의해야 한다. 왜냐하면 멤버함수의 형태로 정의를 할 경우에 cout 객체의 멤버함수를 하나 추가해야 하므로, ostream 클래스를 정정해야한다. 이는 불가능한 방법이기 때문에 전역함수에 의한 방법을 선택할수 밖에 없다.

ostream& operator<<(ostream& os, const Point& pos)

> 03_PointConsoleOutput.cpp 예제를 작성 및 확인하자.