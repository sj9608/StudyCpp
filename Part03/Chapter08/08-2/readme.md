08-2 가상함수
---

가상함수는 C++ 에서 매우 중요한 부분을 차지하는 문법이다. 뿐만 아니라 앞서 소개한 예제의 문제를 완전히 해결하는데 필요한 도구이다.

**기초 클래스의 포인터로 객체를 참조하면**

C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단한다! ⭕️
실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.❌

아래의 예시를 확인하자.
기초 클래스 Base 와 유도 클래스 Derived가 존재 한다고 가정하자.
``` C++
class Base
{

};

class Derived : public Base
{
public:
    void DerivedFunc() { . . . } ;
};
```

``` C++ 
int main(void)
{
    Base * bptr = new Derived(); // 이 경우 문제 없이 컴파일 됌 ⭕️

    bptr->DerviedFunc(); // ❌  이 경우엔 컴파일 에러
}
```
이 경우 bptr은 Base형 포인터 이기 때문에 컴파일에러를 발생시킨다.

다음의 예시도 확인하자
``` C++
int main(void)
{
    Base * bptr = new Derived(); // 문제없음
    Dervied * dptr = bptr; // 컴파일 에러 ❌
    . . . .
}
```
이 예제에서 컴파일러의 판단을 확인하자.

"Dervied 클래스는 Base 클래스의 유도 클래스이니까 Base 클래스의 포인터 변수로 Derived 객체의 참조가 가능하다! 문제 없이 컴파일!"

하지만 이어지는 2번째 문장을 보자

"bptr은 Base형 포인터 이니까 bptr이 가리키는 객체는 Base 일 수 있어, 그럴 경우엔 Dervied 포인터 변수는 접근이 불가능할 수 있으니 컴파일 에러를 발생시키자!"

**위 내용의 상세설명**
> 01_FunctionOverride.cpp 예제 확인

위 예제로 알 수 있는 사실은 **포인터형에 해당하는 클래스에 정의된 멤버에만 접근이 가능한 것**이다.

**함수의 오버라이딩과 포인터 형**

이 예제의 실행 결과만 놓고 보면 다음과 같이 이야기할 수 있다.
> First형 포인터 변수를 이용하면 First 클래스에 정의된 MyFunc 함수가 호출되고, Second형 포인터변수를 이용하면 Second 클래스에 정의된 MyFunc함수가 호출되고, Third형 포인터 변수를 이용하면 Third 클래스에 정의된 MyFunc 함수가 호출된다.

**가상함수**
예제 01_FucntionOverride.cpp 를 보면서 다음과 같은 생각을 해볼 수도 있다.
> 함수를 오버라이딩 했다는 것은, 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미인데, 포인터 변수의 자료형에 따라 호출되는 함수의 종류가 달라지는 것은 문제가 있어 보인다.

이렇게 생각이 들면 멋진 판단이다. 앞서 우리가 정의한 SalesWorker 클래스의 경우에 급여계산의 방식이 다르기 때문에 GetPay 함수를 오버라이딩 하였다. 그런데 포인터의 자료형을 이유로 PermanentWorker 클래스의 GetPay 함수가 호출되어 급여를 결정하게 된다면 *판매실적에 따른 상여급을 지급하지않는 상황* 이 발생한다.

그래서 C++ 에서 이러한 상황을 막기 위해 **가상함수** 라는 것을 제공하고 있다.
이 가상함수는 C++ 의 개념이 아닌 객체지향의 개념이다. 따라서 C++, Java, C#과 같은 언어에서도 동일한 개념의 문법이 제공되고 있다.

가상함수의 동작 방식을 이해하기 위해 Frist 클래스의 MyFunc 함수를 아래와 같이 가상함수로 선언하고 다음 예제를 확인하자.

``` C++
class First
{
public:
    virtual void MyFunc() { cout << "First" << endl; }
};
```

> 02_FunctionVirtualOverride.cpp

위 예제를 통해 알 수 있는 사실은 다음과 같다.

  ✅ 함수가 가상함수로 선언되면, 해당 함수 호출시, 포인터의 자료형을 기반으로 호출대상을 결정하지 않고 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다.


**오렌지 미디어 급여관리 확장성 문제 의 완전한 해결**
> 08-1 의 03_EmployeeManager3.cpp 에서 문제가 되어 주석 처리 했던 부분 을 확인하자.

배열을 구성하는 포인터 변수가 Employee 형 포인터 변수이므로 Employee 클래스 멤버가 아닌 GetPay 함수와 ShowSalaryInfo 함수 호출 부분에서 컴파일 에러를 발생시키기 때문에 주석처리를 해두었다.

그렇다면 이 문제를 어떻게 해결해야할까? 
> 예제 03_EmployeeManager04.cpp 를 작성 해보자

위 예제에선 기본 예제의 Employee 클래스에 GetPay 함수와 ShowSalaryInfo 함수를 정의하고 가상함수로 선언하였다.

이를통해 기존 확장성 문제의 해결은 완료되었다.

---
**오렌지 미디어 급여 관리 확장성 문제의 해결을 통해서 확인한 상속의 이유**
> 상속을 하는 이유는 무엇인가?

✅ 상속을 통해 연관된 일련의 클래스에 대해 공통적인 규약을 정의할 수 있다.

조금 생소하지만 위 문제에 대해 적용해 보자면 다음과 같다.
> 상속을 통해 연관된 일련의 클래스 PermanentWorker, TemporaryWorker, SalesWorker 에 공통적인 규약을 정의할 수 있다.

위 클래스에 적용된 공통적인 규약은 Employee 클래스 이다.
다르게 말하면 , 적용하고싶은 공통규약을 모아서 Employee 클래스를 정의한 것이 된다.

이로 인해서 Employee 클래스를 상속하는 모든 클래스의 객체는 Employee 객체로 바라볼 수 있게 된 것이다.

**순수 가상함수(Pure Virutal Fucntion)와 추상 클래스(Abstract Class)**

예제 03_EmployeeManager4.cpp 의 Employee 클래스를 다시 한번 관찰하자. 이 클래스는 조금 더 개선할 여지가 남아있다.

``` C++
class Employee
{
private:
    char name[100];
public:
    Employee(char * name) { . . . }
    void ShowYourName() const { }
    virtual int GetPay() const { . . . }
    virtual void ShowSalaryInfo() const
    { }
};
```
이 클래스는 기초 클래스로서만 의미를 가질 뿐, 객체의 생성을 목적으로 정의된 클래스는 아니다. 이렇듯 **클래스 중에서는 객체생성을 목적으로 정의되지 않는 클래스가 존재한다.** 따라서 다음과 같은 문장은 프로그래머의 실수를 유발한다.
```C++
Employee * emp = new Employee("LEE");
```
하지만 이는 문법적으로 아무런 문제가 없는 문장이다. 이러한 경우에 가상함수를 **순수 가상함수**로 선언하여 객체의 생성을 문법적으로 막는 것이 좋다.

``` C++
class Employee
{
private:
    char name[100];
public:
    Employee(char * name) { . . . }
    void ShowYourName() const { }
    virtual int GetPay() const = 0; ❗️
    virtual void ShowSalaryInfo() const = 0; ❗️
};
```

**순수 가상함수란 함수의 몸체가 정의되지 않은 함수를 의미한다.** 그리고 이를 표현하기 위해 위와 같이 표시한다.

이로인해 두가지 이점을 얻었다.
✅ 하나는 객체의 잘못된 생성을 막을 수 있다는 것이고.
✅ 또 하나는 Employee 클래스의 가상 함수는 유도클래스의 함수 호출을 돕는데 의미가 있는, 실제로 실행되는 함수가 아니었는데 이를 명확히 명시하는 효과도 생겼다.

그리고 이렇듯 하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스를 가리켜 '추상 클래스' 라 한다.

**다형성**
지금까지 설명한 가상함수의 호출관계에서 보인 특성을 가리켜 '다형성' 이라 한다. 그리고 이는 객체지향을 설명하는데 있어서 매우 중요한 요소이다.

한 마디로 이렇게 이야기 할 수 있다.
> '문장은 같은데 결과는 다르다'
``` C++
class First
{
public:
    virtual void MyFunc() {cout << "First" << endl; }
};

class Second:: public First
{
public:
    virtual void MyFunc() { cout << "Second" << endl; }
};

int main(void)
{
    First * ptr = new First();
    ptr->MyFunc();
    delete ptr;

    Seoncd * ptr = new Second();
    ptr->MyFunc();
    delete ptr;

    return 0;
}
```
위 메인 함수에서 ptr->MyFunc(); 문장이 두번 나온다. ptr은 동일한 포인터 변수이다. 그럼에도 불구하고 실행결과는 다르다. 포인터 변수의 ptr이 참조하는 객체의 자료형이 다르기 때문이다. 이것이 바로 C++ 에서의 '다형성'의 예 이다.