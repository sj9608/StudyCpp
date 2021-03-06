10-2 단항 연산자의 오버로딩
---
피연산자가 두 개인 이항 연산자와 피연산자가 한 개인 단항 연산자의 가장 큰 차이점은 피연산자의 개수이다. 그리고 이에 따른 연산자 오버로딩의 차이점은 매개변수의 개수에서 발견된다.

**증가, 감소 연산자의 오버로딩**
대표적인 단항연산자로는 다음 두 가지가 있다.
* 1 증가 연산자 ++
* 1 감소 연산자 --

앞서 정의한 Point 클래스에 ++ 연산자가 오버로딩 되어있다고 가정해보자. 이런 경우 다음의 형태로 문장 구성이 가능하다

``` C++
++pos; // pos 는 Point 객체
```

> 호출되는 함수의 이름은 ++연산자와 키워드 operator를 연결해 완성되므로 operator++ 입니다.

멤버 함수의 형태로 오버로딩이 된 경우엔 pos의 멤버함수가 호출되는 형태이니, 다음과 같이 해석되어야 한다.

``` C++
pos.operator++();
```

전달인자가 없는 이유는 단항 연산자를 오버로딩 했기 때문이다. 하나있는 피연산자의 멤버함수를 호출하는 형태이기 때문에. 

반면, 전역함수의 형태라면 피연산자가 모두 인자로 전달되므로 다음과 같이 해석되어야 한다.

``` C++
operator++(pos);
```

이를 그림으로 표현하면 다음과 같다. 

<img width="400" alt="image" src="https://user-images.githubusercontent.com/52594760/103981383-0b01b300-51c5-11eb-855f-9878b3c21860.png">

그럼 예제를 통해 단항 연산자의 오버로딩을 확인해 보자.
> 01_OneOpndOverloading.cpp 예제 확인

++ 연산은 멤버함수로 오버로딩 되었기 때문에 다음과 같이 해석이 가능하다.
``` C++
pos.operator++();
```

반면, -- 연산은 전역함수로 오버로딩 되었기 때문에 다음과 같이 해석이 가능하다.

``` C++
operaotr--(pos);
```

``` C++
++(++pos);
--(--pos);
```

위 문장구성이 가능한 이유는 연산에서 자기 자신을 객체로 반환하고 있기 때문이다.
```
Point& operator++()
{
    ++xpos;
    ++ypos;
    return *this;
}
```
this는 객체 자신의 포인터 값을 의미하므로, *this는 객체 자신을 의미한다. 반환형이 참조형으로 선언되어있기 때문에 객체 자신을 참조할 수 있는 '참조 값'이 반환된다. 반환형으로 Point 형이 선언된다면 객체 자신의 복사본을 반환을 하게 된다.

그림으로 표현하면 다음과 같다.

<img width="600" alt="image" src="https://user-images.githubusercontent.com/52594760/103983570-cf68e800-51c8-11eb-8b43-7b1f9a06e889.png">

---
문제 10-2

**전위 증가와 후위증가의 구분**
앞서 보인 예제는 전위 증가와 감소에 대하여 이야기 하였다. 
✅ 후위 연산에 대한 오버로딩은 어떻게 해야할까??
이에 대해 C++ 에선 다음과 같은 규칙을 정해놓고 있다.

``` C++
++pos ➡️ pos.operator++();
pos++ ➡️ pos.operator++(int);
```

즉, 키워드 int를 통해 후위연산과 전위연산에 대한 함수를 구분하고 있다. 

❗️여기서 사용한 int는 후위 연산을 구분하기 위한 목적으로 선택된 것일 뿐 **실제로 int형 데이터를 인자로 전달하라는 뜻과는 거리가 멀다.**

후위 연산의 결과를 보이는 예제를 확인하자
> 02_PostOpndOverloading.cpp 예제 확인

**반환형에서의 const 선언과 cosnt 객체**

``` C++
const Point operator++(int) // Point 클래스의 멤버함수
{
    const Point retObj(xpos, ypos); // 함수내에서 retObj의 변경을 막겠다.
    xpos += 1;
    ypos += 1;
    return retObj;
}

const Point operator--(Point &ref, int) // 전역함수
{
    const Point retObj(ref); // 함수내에서 retObj의 변경을 막겠다.
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retObj;
}
```
 후위 증가와 후위감소 연산자를 오버로딩한 함수들이 반환형이 const 로 선언되었다.
 > 반환의 대상이 되는 retObj객체가 const로 선언되어 있어서 ??
 
 ❌ retObj 객체가 반환되면 새로운 객체가 생성되기 때문에 retObj 객체의 const 선언 유무는 객체의 반환에 아무런 영향을 미치지 않는다. 

 ✅ operator-- 함수의 반환으로 인해서 생성되는 임시객체를 const 객체로 생성하겠다.
 ``` C++
 const Point pos(3, 4);
 ```
 이는 pos 객체를 상수화 해서 pos 객체에 저장된 값의 변경을 허용하지 않겠다는 뜻이다.
 그래서 const 객체인 pos를 대상으론 const 함수만 호출이 가능하다. 
 이는 const 함수의 특성을 반영하고있다.
 > const 함수 내에선 const 함수의 호출만 가능하도록 제한한다.

**왜 후위연산 함수에서 const 키워드를 사용하였는가??**

후위증가 및 후위 감소연산에 대해서 오버로딩 한 함수의 반환형을 const로 선언한 이유는 다음의 두 문장에서 컴파일 에러를 일으키기 위함이다.

``` C++
(pos++)++; // 컴파일 에러
(pos--)--; // 컴파일 에러
```
이는 다음의 연산을 허용하되

``` C++
int main(void)
{
    int num = 100;
    ++(++num);
    --(--num);
    . . . .
}
```

다음의 연산을 허용하지 않는 C++의 연산특성을 반영하기 위함이다.

``` C++
int main(void)
{
    int num = 100;
    (num++)++; // 컴파일 에러
    (num--)--; // 컴파일 에러
}
```