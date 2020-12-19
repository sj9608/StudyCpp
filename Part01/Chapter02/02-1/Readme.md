## C언어 기본 확인
---
[문제 1] 키워드 const의 의미 (각 문장들을 설명해보자)
``` C
const int num = 10;
const int * ptr1 = &val1;
int * const ptr2 = &val2;
const int * const ptr3 = &val3;
``` 
[문제 2] 실행중인 프로그램의 메모리 공간
```C
실행중인 프로그램은 운영체제로부터 메모리 공간을 할당 받는데, 이는 크게 데이터, 스택, 힙 영역으로 나뉜다. 각각의 영역에는 어떠한 형태의 변수가 할당되는지 설명해보자. 특히 C언어의 malloc과 free 함수와 관련해서도 설명해 보자.
```
[문제 3] Call-by-value Vs Call-by-reference
```
함수의 호출형태는 크게 '값에 의한 호출(Call-by-value)'과 '참조에 의한 호출(Call-by-reference)' 로 나뉜다. 이 둘을 나누는 기준이 무엇인지, 두 int형 변수의 값을 교환하는 Swap 함수를 예로 들어가면서 설명해보자.