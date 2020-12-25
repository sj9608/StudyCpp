02-6 C++에서 C 표준 함수 호출하기
---

**기존헤더파일에 .h를 빼고 맨앞에 c를추가**
``` C
#include <stdio.h> // #include <cstdio>
#include <stdlib.h> // #include <cstdlib>
#include <string.h> // #include <cstring>
#include <math.h> // #include <cmath>
```

**C++의 헤더를 선언해야 하는 이유**
C++ 관점에서, 여전히 다음형태로 함수호출을 허용하는 이유는 '하위 버전과의 호환성' 을 제공하기 위함으로 볼 수 있다.
``` C++
#include <stdio.h>
int main()
{
    printf("Hello World");
    return 0;
}
```

그리고 c++ 표준 라이브러리가 제공하는 함수들과 c표준 라이브러리가 제공하는 함수들이 완전히 일치 하는것도 아니다. 예를 들어 위 예제에서 호출한바 있는 ABS 함수는 c 표준에서 다음과 같이 선언 되어있다.
``` c
int abs(int num);
```

반면 C++ 에서는 다음과 같이 오버로딩 되어있다.
``` C++
long abs(long num);
float abs(float num);
double abs(double num);
long double abs(long double num);
```
C++ 함수에서는 함수 오버로딩이 가능하기 때문에 자료형에 따라서 함수의 이름을 달리해서 정의하지 않고 보다 사용하기 편하도록 함수를 오버로딩 해놓은 것이다. 이렇듯 C++ 문법을 기반으로 개선된형태로 라이브러리가 구성되어있으므로 가급적 C++의 표준 헤더를 이용해서 함수를 호출하는것이 좋다.

**문제 02-4**