11-2 배열의 인덱스 연산자 오버로딩
---

이번에는 배열 요소에 접근할 때 사용하는 **[ ] 연산자를 오버로**딩 하고자 한다. 이는 다른 연산자들과 달리 피 연산자가 기호 안으로 들어가기 때문에 다소 어색하거나 생소하게 느낄 수 있다. 또 이 연산자는 연산의 기본 특성상 **멤버함수 기반으로만** 오버로딩 하도록 제한되어있다.

**배열보다 나은 배열 클래스**
C, C++의 기본 배열은 다음의 단점을 지니고 잇다.
> 경계 검사를 하지 않는다.

때문에 다음과 같은 엉뚱한 코드가 만들어 질 수도 있다. 컴파일도 되고, 실행도 무리 없이 진행되기 때문이다.

``` C++
int main(void)
{
    int arr[3] = {1, 2, 3};
    cout << arr[-1] << endl; // 'arr의 주소 + sizeof(int) x -1' 의 위치에 접근
    cout << arr[-2] << endl; // 'arr의 주소 + sizeof(int) x -2' 의 위치에 접근
    cout << arr[3] << endl;
    cout << arr[4] << endl;
    . . . 
}
```
위의 특성의 부정적인 측면을 고려해 이를 해결하고자 '배열클래스' 라는 것을 디자인 해볼 것이다. '배열의 역할을 하는 클래스' 를 '배열 클래스' 라고 한다.

> 01_ArrayClass.cpp 예제 확인

위 유형의 클래스를 정의하면 배열 접근의 안정성을 보장받을 수 있다. 만약 안정성을 더 높이기 위해 다음과 같은 코드의 실행을 허용하지 않고자 한다면 ,
``` C++
int ain(void)
{
    BounCheckIntArray arr(5);
    for(int i = 0; i < 5 ; i ++)
        arr[i] = (i+1) * 11;

    BoundCheckIntArray cpy1(5);
    cpy1 = arr; // 안전하지 않은 코드 (이유는 밑에 설명)
    BoundCheckIntArray copy = arr; // 역시 안전하지 않은 코드
    . . . 
}
```

위 코드를 다음과 같이 복사 생성자와 대입 연산자를 private으로 선언하여, 복사, 대입을 원천적으로 막을 수 있다. 
``` C++
class BoundCheckIntArray
{
private:
    int * arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr) { }
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
public: 
    . . .
}
```

예제 01_Arrayclass.cpp 에서 정의한 BoundCheckIntArray 클래스 객체의 복사와 대입은 얕은 복사로 이어지기 때문에, 단순히 코드만 놓고보면, 깊은 복사가 진행되도록 복사 생성자와 대입 연산자를 별도로 정의해야 한다고 생각할 수 있다.
그러나 배열을 저장소의 일종이고, 저장소에 저장된 데이터의 '유일성'이 보장되어야 하기 때문에, 대부분의 경우 저장소의 복사는 불필요하거나 잘못된 일로 간주된다.

따라서 깊은복사가 진행되도록 클래스를 정의할 것이 아니라, 위의 코드에서 보이듯 빈 상태로 정의된 복사 생성자와 대입 연산자를 private 멤버로 둠으로써 복사와 대입을 원천적으로 막는 것이 좋은 선택이 되기도 한다.

**const 함수를 이용한 오버로딩의 활용**
앞서 정의한 BoundCheckIntArray 클래스에는 제약이 존재한다. 어떠한 제약이 존재하는지는 다음 예제의 컴파일 결과를 통해서 확인해보자.(컴파일 에러가 발생한다.)
이 예제는 앞선 예제에서 배열의 길이를 반환하는 함수를 추가한 것이다.

> 02_StableConstArrayProb.cpp 예제 확인

위 예제의 주석 처리한 부분이 컴파일 에러가 난다. 이유는 다음과 같다.

BoundCheckIntArray 객체의 배열이 저장된 모든 요소를 출력하는 ShowAllData 함수가 추가 되었다. 이 함수의 매개변수는 다음과 같이 선언되었다
``` C++
const BoudCheckIntArray& ref
```
함수 내에서 배열에 저장된 데이터를 변경하지 못하도록 매개변수 형이 const로 선언되었다.
그런데 문제는 다음 구문에서 나타난다.

``` C++
cout << ref[idx] << endl;
``` 
왜냐하면 이 선언은 다음과 같이 해석된다.
``` C++
ref.operator[ ](idx);
```
 이 때 호출되는 operator[ ] 함수는 const 함수가 아니기 때문이다. 그렇다고 무작정 이 함수에 const 선언을 추가하면 배열을 멤버로 선언하는 경우에는 저장 자체가 불가능 해지기 때문에 다른부분에서 컴파일 에러가 발생하게 되며, 데이터를 저장하는 배열의 특성을 고려해보면, 이는 배열 클래스로서 적절한 해결책이 아님을 알 수 있다.

아래 언급한 사실을 떠올려야 한다.
> const의 선언유무도 함수 오버로딩의 조건에 해당한다.

그리고 이로 인해서 위에 보인 예제는 다음의 예제와 같이 확장이 가능하다.
이 예제에서는 const의 선언 유무로서 operator[ ]함수를 오버로딩 하고있다.
> 03_StableConstArraySolu.cpp

위 예제에서 int형을 반환하는 operator[ ] (int idx) const 함수가 추가 되었다.
이 함수는 int& 형을 반환하는 operator[ ] (int idx) 와 오버로딩의 관계를 가지며 배열 요소의 값을 단순히 반환하는 형태로 정의 되었다.

ShowAllData(const BoundCheckIntArray& ref)
함수에서 const 참조자를 이용한 연산을 하였으므로 const 함수가 호출되며
main 함수에서 arr[i] = (i+1) * 11; 구문에선 const로 선언되지 않는 arr을 이용한 연산이니 일반 함수가 호출된다.

위 예제를 하나의 모델로해서 const 기반의 함수 오버로딩이 유용하게 사용될 수 있음을 기억하자.

**객체의 저장을 위한 배열 클래스의 정의**
앞서 보인 예제는 기본 자료형(int) 대상 배열 클래스 였기 때문에, 이번엔 객체 대상의 배열 클래스를 제시하고자 한다. 저장의 대상은 당므과 같다.

``` C++
class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point& pos)
};
ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << endl;
    return os;   
};
```
위 클래스의 객체를 저장할 수 있는 배열 클래스를 정의하되, 다음의 두 가지 형태로 각각 정의해 보고자 한다.
* Point 객체의 주소 값을 저장하는 배열 기반의 클래스
* Point 객체를 저장하는 배열 기반의 클래스

즉, 저장의 대상이 객체이냐, 객체의 주소 값이냐 에 차이가 있는 것 이다. 먼저 Point 객체를 저장하는 배열 기반의 클래스를 확인하자.

> 04_StablePointObjArray.cpp