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
> **01_PointTemplate.h**