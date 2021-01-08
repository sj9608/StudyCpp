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

