14-2 클래스 템플릿의 특수화
---
앞서 공부했던 함수 템플릿의 특수화와 유사하게 **'클래스 템플릿 특수화'** 의 방법과 개념은 함수 템플릿과 매우 유사하다.

**클래스 템플릿의 특수화**
Chapter 13 에서 보았듯 함수 템플릿을 특수화 하는 이유는 특정 자료형에 대해서 구분이 되는 다른 행동을 보이기 위해서이다. 마찬가지로 **클래스 템플릿을 특수화 하는 이유는 특정 자료형을 기반으로 생성된 객체에 대해, 구분이 되는 다른 행동양식을 적용하기 위해서이다.** 즉, 클래스 템플릿을 특수화하면, 템플릿을 구성하는 멤버함수의 일부 또는 전부를 다르게 행동하도록 정의할 수 있다. 클래스 템플릿을 특수화 하는 방법은 다음과 같다.

먼저 다음과 같은 클래스 템플릿이 존재할 때

``` C++
template <class T>
class SoSimple
{
public:
    T SimpleFunc(T num) { . . . }
};
```

이를 기반으로 자료형 int에 대해 특수화 한 템플릿 클래스는 다음과 같이 정의한다.
``` C++
template <>
class SoSimple<int>
{
public:
    int SimpleFunc(int num) { . . . }
};
```

이렇게 int형 에 대해서 특수화가 되고 나면, 다음의 형태로 객체 생성시,
``` C++
SoSimple<int> obj;
```
특수화된 템플릿 클래스 SoSimple\<int> 를 대상으로 객체가 생성된다. 그럼 예제를 통해 클래스 템플릿의 특수화를 진행해보자

> 01_ClassTemplateSpecialization.cpp

위 예제에선 char* 형과 템플릿 클래스의 자료형인 Point<int>형 대상의 특수화를 보이고 있다.

**클래스 템플릿의 부분 특수화**
다음과 같이 정의된 클래스가 있다고 가정해보자.
``` C++
template <class T1, class T2>
class MySimple { . . . }
```

여기서 T1, T2를 각각 char형 과 int로 하여 특수화를 진행하면 다음의 형태가 된다.

``` C++
template <char, int>
class MySimple<char, int> { . . . }
```

템플릿 정의에 사용된, 결정되지 않은 자료형의 수가 하나 더 늘어난 상황에서의 특수화이다.
다음은 어떠한 의미를 지니는 정의인지 유추해 보자.

``` C++
template <class T1>
class MySimple<T1, int> { . . . }
```

이 역시 MySimple에 대한 특수화의 결과이다. 단 , T1, T2 모두에 대해서 특수화를 진행한 것이 아닌 T2 하나에 대해서만 부분적으로 특수화를 진행한 것이다. 
이를 가리켜 **' 클래스 템플릿의 부분 특수화 '** 라고 한다. 예제를 통해서 이를 확인해보자.

> 02_ClassTemplatePartialSpecialization.cpp