06-3 C++ 에서의 static
---
**C언어에서 이야기한 static**

* 전역변수에 선언된 static의 의미
  * 선언된 파일 내에서만 참조를 허용하겠다는 의미
* 함수내에 선언된 static의 의미
  * 한번만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다.

이를 확인할 수 있는 간단한 예제 01을 확인해보자
> 01_CCmoStatic.cpp

Static 변수는 전역변수와 마찬가지로 초기화 하지않으면 0으로 초기화 된다. 그리고 초기화는 딱 한번 된다. cnt는 Counter함수가 호출될 때마다 새롭게 할당되는 지역변수가 아니다.

**전역변수가 필요한 상황**
C++에서 static이 지니는 의미를 이야기 하기위해 전역변수가 필요한 상황을 연출하기 위한 아래 예제를 확인하자.
> 02_NeedGlobal.cpp

위 예제의 문제는 simObjCnt, cmxObjcnt가 전역변수로 선언되 어떤 함수에서도 접근하여 오해 또는 문제의 소지가 일어날 여지가 있다. 이를 해결하기 위해 스태틱 멤버변수로 선언해주면 된다.

**static 멤버변수(클래스 변수)**
static 멤버변수는 '클래스 변수'라고도 한다. 일반적인 멤버변수와 달리 클래스당 하나씩만 생성되기 때문이다. 다음은 전역변수 simObjCnt를 SoSimple 클래스의 static 변수로 선언한 예이다.

``` C++
class SoSimple
{
private:
    static int simObjCnt; // static 멤버 변수, 클래스 변수
public:
    SoSimple()
    {
        simObjCnt++;
        cout << simObjCnt << "번 째 SoSimple 객체" << endl;
    }
};
int SoSimple::simObjCnt = 0; // static 멤버변수의 초기화
```

위의 static 변수 simObjCnt는 SoSimple객체가 생성될 때 마다 함꼐 생성되어 객체별로 유지되는 변수가 아니다. 객체를 생성하건 하지않건, 메모리공간에 **딱 하나만** 할당이 되어서 공유되는 변수이다. 예를들어 다음과 같이 총 3개의 SoSimple 객체를 생성하게 되면,
``` C++
int main(void)
{
    SoSimple sim1;
    SoSimple sim2;
    SoSimple sim3;
}
```
다음과 같이 sim1, sim2, sim3 객체가 static 변수 simObjCnt를 공유하는 구조가 된다.
<img width="343" alt="image" src="https://user-images.githubusercontent.com/52594760/103435743-a9869500-4c56-11eb-899d-306079c0259b.png">

**static 변수를 생성자에서 초기화 하면 안되는 이유**
SoSimple의 생성자를 다음과 같이 정의한다면, 객체가 생성될 때 마다 변수 simObjCnt는 0으로 초기화 된다.
``` C++
SoSimple()
{
    simObjCnt = 0;
    simObjCnt++;
    cout << simObjCnt << "번 째 SoSimple 객체" << endl;
}
```
따라서 static 멤버변수의 초기화 문법은 다음과 같이 정의되어 있다.
``` C++
int SoSimple::simObjCnt = 0;
```

**Static 멤버변수의 또 다른 접근방법**
static 멤버 변수는 어디서든 접근이 가능한 변수이다. static 멤버 변수가 private으로 선언되면 해당 클래스의 객체들만 접근이 가능하지만. public으로 선언되면 클래스의 이름 또는 객체의 이름을 통해서 어디서든 접근이 가능하다. 또 **static 멤버변수가 객체 내에 존재하지 않는다**는 사실도 더불어 증명하고있다. (static 멤버변수는 객체 외부에 존재함)
> 04_PublicStaticMember.cpp 예제 확인

**static 멤버 함수**
static 멤버 함수 역시 그 특성이 static 멤버 변수와 동일하다.
* 선언된 클래스의 모든 객체가 공유한다.
* public으로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능하다.
* **객체의 멤버로 존재하는 것이 아니다.**

객체의 멤버로 존재하지 않는다는 사실이 아래와 같은 코드에서 컴파일 에러를 일으킨다.
``` C++
class SoSimple
{
private:
    int num1;
    static int num2;
public:
    SoSimple(int n) : num1(n) { }
    static void Adder(int n)
    {
        num1 += n; // ❗️ 컴파일 에러 발생
        num2 += n;
    }
};
int SoSimple::num2 = 0;
```
위 예제를 통해 하나의 사실을 유추할 수 있다.
> "static 멤버함수 내에서는 static 멤버 변수와 static 멤버함수만 호출이 가능하다"

**const static 멤버**
클래스 내에 선언된 const 멤버변수(상수)의 초기화는 이니셜라이저를 통해야만한다.
그러나 const static으로 선언되는 멤버변수(상수)는 다음과 같이 선언과 동시에 초기화가 가능하다.
> 05_ConstStaticMember.cpp 예제확인


**키워드 mutable**
앞서 키워드 const, explicit에 대해 공부하였고 이 둘은 나름의 의미가 있으며 매우 유용하게 사용되는 키워드 들이다. 하지만 이번에 설명하는 mutalbe키워드는 사용 빈도수를 낮춰야 하는 키워드 이다. 
> "const 함수 내에서의 값의 변경을 예외적으로 허용한다" 라는 뜻을 가지고있다.

> 06_Mutable.cpp 예제확인

mutable 키워드를 통해 const선언이 의미 없어지게 만들기 때문에 사용을 지양해야한다.