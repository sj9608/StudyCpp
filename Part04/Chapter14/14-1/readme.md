14-1 Chapter 13 에서 공부한 내용의 확장
---

**Point 클래스 템플릿과 배열 클래스 템플릿**
``` C++
template <class T>
class BoundCheckArray
{
private:
    T * arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray& arr) { }
    BoundCheckArray& operator=(const BoundCheckArray& arr) { }
public:
    BoundCheckArray(int len);
    T& operator[] (int idx);
    T operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};
```

위의 클래스를 기반으로 Point<int> 템플릿 클래스의 객체를 저장할 수 있는 객체의 생성은 다음과 같다.
``` C++
BoundCheckArray<Point<int>> oarr(50);
```

저장 대상이 Point<int>형 포인터라면 다음과 같이 생성하면 된다.

``` C++
BoundCheckArray<Point<int>*> oarr(50);
```

또 위의 문장은 typedef 선언을 통해 다음과 같이 구성할 수도 있다.

``` C++
typedef Point<int>* POINT_PTR;
BoundCheckArray<POINT_PTR> oparr(50);
```

다음 예제를 통해 규칙을 직접 확인해보자.
> 1_PointTemplate.h, 01_Main.cpp, ArrayTemplate.h

위 예제에서 보이듯이, 템플릿 클래스라 하여 일반 클래스와 비교해서 다른 문법체계를 지니는 것이 아닌, 우리가 알고있는 C++ 문법의 이해를 기반으로 템플릿과 관련한 다양한 확장이 가능하다.

**특정 템플릿 클래스의 객체를 인자로 받는 일반함수의 정의와 friend 선언**
Point<int>, Point<double> 과 같은 템플릿 클래스의 자료형을 대상으로도 템플릿이 아닌 일반 함수의 정의가 가능하고, 클래스 템플릿 내에서 이러한 함수를 대상으로 friend선언도 가능하다. 이와 관련해 다음 예제를 보자.

> 02_PointTemplateFriendFunction.cpp

템플릿과 관련해서 무엇이 되고, 무엇이 안되는지를 아는것도 중요하지만, 템플릿 관련 코드를 보면서 이것이 의미하는바가 무엇인지를 유추하는 것도 중요하다.