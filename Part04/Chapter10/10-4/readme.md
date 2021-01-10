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

> 02_ItreateConsoleOutput().cpp