04-4 클래스와 배열 그리고 this 포인터
---

**객체 배열**
객체 기반의 배열은 다음의 형태로 선언하다
``` C++
SoSimple arr[10];
```
이를 동적으로 할당하는 경우에는 다음의 형태로 선언한다.
``` C++
SoSimple * ptrArr = new SoSimple[10];
```

이러한 형태로 배열을 선언하면 열 개의 SoSimple 객체가 모여서 배열을 구성하는 형태가 된다. 배열을 선언하는 경우에도 생성자는 호출이 된다. 단, 배열의 선언과정에서는 호출할 생성자를 별도로 명시하지 못한다.(생성자에 인자를 전달하지 못한다.)

즉, 위의 형태로 배열이 생성되려면 다음 형태의 생성자가 반드시 정의되어 있어야 한다.
``` C++
SoSimple() { . . . }
```
그리고 배열선언 이후에 각각의 요소를 원하는 값으로 초기화시키길 원한다면, 일일이 초기화의 과정을 별도로 거쳐야 한다. 다음 예제를 통해 객체 배열을 조금 더 살펴보자
> 01_ObjArr.cpp

위의 실핼결과를 통해서 객체배열 생성시 void형 생성자가 호출됨을 확인할 수 있다. 그리고 배열 소멸시에도 그 배열을 구성하는 객체의 소멸자가 호출됨을 알 수 있다.

**객체 포인터 배열**
객체배열이 객체로 이뤄진 배열이라면, 객체 포인터 배열은 객체의 주소 값이 저장이 가능한 포인터 변수로 이뤄진 배열이다.
> 02_ObjPtrArr.cpp 확인

위 두 예제를 통해 '객체배열'과 '객체 포인터 배열'의 차이점을 정확히 이해하자.

**this 포인터의 이해**
멤버 함수 내에서는 this라는 이름의 포인터를 사용할 수 있다. 이는 객체 자신을 가리키는 용도로 사용되는 포인터이다.
> 03_PointerThis.cpp 예제를 확인하자

소스코드와 실행결과를 통해서 this는 객체자신의 주소 값을 의미한다는 사실을 확인 및 이해했을 것이다. 이렇듯 this 포인터는 그 주소 값과 자료형이 정해져 있지 않은 포인터이다.

**this 포인터의 활용**
함수 내에서 멤버변수에 접근하기 위한 방법으로 쓰인다
예를 들어
``` C++
class A
{
private:
    int num;
public:
    A(int num)
    {
        this->num = num; ❗️이부분
    }
}
```
위의 this->num 은 A 클래스의 num 멤버변수이고 rValue의 num은 매개변수의 num 이다.
이처럼 멤버변수 명과 매개변수 명을 달리하기 위해 고민할 필요가 없어지는 장점이 생긴다.

**Self-Reference의 반환**
Self-Reference란 객체 자신을 참조할 수 있는 참조라를 의미한다. this포인터를 이용해서 객체가 자신의 참조에 사용할 수 있는 참조자의 반환문을 구성할 수 있다.
> 04_SelfRef.cpp 예제 확인

위 예제는 하나의 객체를 생성하고 그 객체가 반환하는 참조값을 대상으로 다양한 방법으로 멤버 함수를 호출한 예제이다.

**참조의 정보(참조 값)에 대한 이해**
```c++
int main(void)
{
    int num = 8;
    int &ref = num; // ref에 무엇이 전달된다고 할까?
}
```
2번째 대입연산에선 변수 num을 참조자 ref가 참조하게 된다. 대입 연산의 과정에서 ref에 무엇이 전달된다고 해야할까?
"변수 num을 참조할 수 있는 참조의 정보가 전달된다"
더 정확히 말하자면
> "변수 num을 참조할 수 있는 참조 값이 ref에 전달되어, ref가 변수 num을 참조하게 된다."