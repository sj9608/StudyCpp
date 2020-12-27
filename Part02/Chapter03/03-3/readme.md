03-3 객체지향 프로그래밍의 이해
---
**객체지향 프로그래밍의 이해**
C++은 객체지향 언어이다. C언어는 절차지향적 언어이다.

객체지향 프로그래밍은 현실에 존재하는 사물고 대상, 그리고 그에 따른 행동을 있는 그대로 실체화 시키는 형태의 프로그래밍 이다.

**객체를 이루는 것은 데이터와 기능이다.**
객체는 하나 이상의 상태정보(데이터)와 하나 이상의 행동(기능)으로 구성된다.

**클래스 기반의 두 가지 객체생성 방법
``` C++
ClassName objName; // 일반적인 변수의 선언 방식
ClassName *ptrObj = new ClassName; // 동적 할당방식
```
즉 우리가 정의한 FruitSeller 클래스와 FruitBuyer 클래스의 객체 생성방식은 다음과 같다.
``` C++
FruitSeller seller;
FruitBuyer buyer;

// 이를 동적 할다앟려면 다음과 같이 생성하면 된다
FruitSeller *objPtr1 = new FruitSeller;
FuritBuyer *objPtr2 = new FuritBuyer;
```

> 다음의 사과장수 시뮬레이션 01_FruitSaleSim1.cpp 예제를 확인하자

45행, 61행을 주목해서 보면 코드의 흐름이 보인다.

**객체간의 대화 방법 (Message Passing)**
예제 01_FruitSaleSim1.cpp 의 45행을 보면 FruitBuyer 객체에 존재하는 함수 내에서 FruitSeller 객체의 함수 SaleApples를 호출하고 있다.
> seller 에게 사과 2,000원어치 구매

이처럼 하나의 객체가 다른 객체에게 메세지를 전달하는 방법은 함수호출을 기반으로 한다. 이러한 형태의 함수호출을 메세지 전달(Message Passing)이라 한다.

####참고
관계를 형성하는 둘 이상의 클래스
> 하나의 독립된 클래스를 정의하는 것은 쉽다. 그러나 둘 이상의 클래스를 정의하고 관계를 형성해서 정의하는 것은 쉽지 않다. 하지만 이는 매우 중요하다. 단수히 함수호출로 이해하면 별 것 아니지만, 메시지 전달의 관점에서 매우 중요하다.