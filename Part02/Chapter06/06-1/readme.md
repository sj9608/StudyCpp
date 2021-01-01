06-1 const 키워드에 대한 보충
---
C++ 에서 const 관련 특성이나 설명등이 많아서 const에 대한 보충을 진행함

**const 객체와 const 객체의 특성들**
변수를 상수화 하듯, 객체도 상수화가 가능하다. 그리고 객체에 const 선언이 붙게 되면, 이 객체를 대상으로는 const 멤버함수만 호출이 가능하다.
> "이 객체의 데이터 변경을 허용하지 않겠다" 는 의미를 갖기 떄문이다.

다음 예제를 통해 const 객체의 특성을 확인하자
> 01_ConstObject.cpp

**const 함수와 오버로딩**
함수의 오버로딩이 성립하려면 매개변수의 수나 자료형이 달라야 한다. 하지만 const의 선언 유무도 함수 오버로딩 조건에 해당이 된다.
``` C++
void SimpleFunc() { . . . }
void SimpleFunc() const { . . . }
```
이와 관련된 예제02
> 02_ConstOverloading.cpp 예제를 확인하자