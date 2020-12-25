02-5 malloc & free를 대신하는 new & delete
---

**new & delete**
길이 정보를 인자로 받아서 해당 길이의 문자열 저장이 가능한 배열을 생성하고, 그 배열의 주소값을 반환하는 함수를 정의해보자.
> 01_MemMalFree.cpp 확인

``` C++
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr(int len)
{
    char * str = (char*)malloc(sizeof(char) * len);
    return str;
}

int main(void)
{
    char * str = MakeStrAdr(10);
    strcpy(str, "I am so happy");
    cout << str << endl;

    return 0;
}
```
---

위 예제는 C언어에서 동적할당을 보이기 위한 것이다. 이 방법에는 두가지 불편 사항이 따른다.
* 할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야 한다.
* 반환형이 void인 포인터이기 때문에 적절한 형변환을 거쳐야 한다.

C++ 에서 제공하는 new, delete 를 사용하면 이런 불편한 점이 사라진다.
각각 malloc과 free를 대신하는 키워드 이다.

* int 형 변수의 할당
* double형 변수의 할당 
* 길이가 3인 배열의 할당
* 길이가 7인 double형 배열의 할당
``` C++
int *ptr = new int;
double *ptr2 = new double;
int * arr1 = new int[3];
double * arr2 = new double[7];
```

* delete 사용방법
``` C++
delete ptr1;
delete []arr1;
```

자세한 예시는 02_NewDelete.cpp 에 정리해 두었다. **참고**

---
**객체의 생성에서는 반드시 new & delete**

```
new 와 malloc 함수의 동작 방식에는 차이가 있다.
```

**힙에 할당된 변수? 이제 포인터를 사용하지 않아도 접근할 수 있어요.**

참조자의 선언은 상수가 아닌 변수를 대상으로만 가능함을 알고 있을 것이다.
(const참조자가 아닌 경우). 그렇다면 new 연산자를 이용해서 할당된 메모리 공간에도 참조자의 선언이 가능할까? 정의에 따르면, 변수의 자격을 갖추기 위해서는 메모리 공간이 할당되고, 그 공간을 의미하는 이름이 존재해야하지만, C++에서는 new 연산자를 이용해서 할당된 메모리 공간도 변수로 간주하여 참조자의 선언이 가능하도록 하고 있다. 따라서 다음과 같은 문장의 구성이 가능하다.

``` C++
int *ptr = new int;
int &ref = *ptr;
ref = 20;
cout << *ptr << endl; // 출력 결과 20
```