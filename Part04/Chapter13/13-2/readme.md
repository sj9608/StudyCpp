13-2 클래스 템플릿
---
앞서 함수를 템플릿으로 정의했듯이 클래스도 템플릿으로 정의가 가능하다. 이렇게 정의된 템플릿을 가리켜 '클래스 템플릿' 이라 하며, 이를 통해 컴파일러가 만들어낸 클래스를 '템플릿 클래스' 라 한다.

**클래스 템플릿의 정의**
앞서 Chapter11 에서 우리는 다음의 클래스들을 정의한 바 있다.

``` C++
class BoundCheckIntArray { . . . }
class BoundCheckPointArray { . . . }
class BoundCheckPointPtrArray { . . . }
```

이들은 모두 배열 클래스들인데, 이렇듯 세 가지 정의를 한 이유는 저장의 대상이 달랐기 때문이다.
제공되는 기능과 내부의 행동이 모두 동일한데, 저장의 대상이 달라서 세가지 클래스를 정의하는 것은 불합리 하다.
이것은 클래스 템플릿을 이용하면 해결할 수 있다.

먼저 다음 클래스를 보자

``` C++
class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};
```
위 클래스는 좌표정보를 **정수(int)** 로 표현하도록 정의되어 있다. 
따라서 실수, 문자의 형태로 좌표를 표현 및 출력해야하는 경우에는 별도의 클래스를 정의해야만 한다. 그러나 위의 클래스를 다음과 같이 템플릿화 하면 별도의 클래스를 정의할 필요가 없다.

``` C++
template <class T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x, T y) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};
```

위의 클래스를 기반으로 객체를 생성하는 예제를 확인해보자.
> 01_PointClassTemplate.cpp

클래스 템플릿을 정의하고 객체를 생성할 때 \<int>, \<double>과 같은 자료형은 생략이 불가능하다.
**객체생성에는 반드시 자료형 정보를 명시**하도록 되어있다.

**클래스 템플릿의 선언과 정의의 분리**
클래스 템플릿도 멤버함수 클래스를 외부에 정의하는 것이 가능하다. 예를 들어서 다음과 같이 정의된 클래스 템플릿이 존재하고,

``` C++
template <class T>
class SimpleTemplate
{
public:
    T SimpleFunc(const T& ref);
}
위와 같은 클래스 템플릿이 존재할때 이 템플릿의 멤버함수 SimpleFunc는 아래와 같이 외부에 정의해야 한다.

template <class T>
T SimpleTemplate<T>::SimpleFunc(const T& ref)
{ 
    . . .
}
```

위 함수의 정의에서 SimpleTemplate<T>가 의미하는 바는 다음과 같다.
> T에 대해 템플릿화 된 SimpleTemplate 클래스 템플릿

그리고 간혹 함수를 외부에 정의할 때 template<class T> 를 빼먹는 경우가 있는데 그럴 경우 컴파일러가 에러메세지를 전달한다.

앞서  이야기 한 내용을 다음 예제에서 확인하자.
> 02_PoinClassTemplateFuncDef.cpp