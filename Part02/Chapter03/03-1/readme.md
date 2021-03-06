Chapter 03-1 C++ 에서의 구조체
---

**구조체의 등장배경은 무엇인가?**
* 연관있는 데이터를 하나로 묶으면 프로그램의 구현 및 관리가 용이하다.
* 구조체는 연관있는 데이터를 하나로 묶는 문법적 장치이다.

**구조체 변수 선언**
``` C++
struct Car basicCar;
struct Car simpleCar;
```
C와 다르게 typedef 선언을 해주지 않아도 됀다.

**구조체 안에 함수 삽입하기**
❤️ C++ 에서는 구조체 안에 함수를 삽입하는것을 허용한다.

**구조체 안에 enum 상수의 선언**
예제 02_RacingCarFuncAdd.cpp를 보면, 매크로상수들(#define)이 존재한다.

이들 상수 역시 구조체 Car에게만 의미가 있는 상수들이다. 즉 다른영역에서 사용하도록 정의된 상수가 아니니, 이들 상수도 **구조체 내에 포함**시키는 것이 좋을 수 있다(상황마다 조금씩 달라 질 수 있다).

``` C++
strcut Car
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 10,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
    
    ∙ ∙ ∙
}
```
열거형 enum을 구조체 내부에 삽입하는것 보다 namespace를 이용해서 상수가 사용되는 영역을 명식하면 훨씬더 가독성이 좋아지는 경향이 있다.

>03_RacingCarEnum.cpp 예제를 확인하자

예제를 보니 구조체 내에 함수를 정의했기 때문에 구조체가 너무 커져버렸다.

**함수는 외부로 뺄 수 있다.**
>함수가 포함되어있는 C++의 구조체를 보는 순간, 다음의 정보들이 쉽게 눈에 들어와야 코드의 분석이 용이하다.
* 선언되어 있는 변수정보
* 정의되어 있는 함수정보

보통 프로그램을 분석할 때, 흐름 및 골격 위주로 분석하는 경우가 많다.
> 따라서 구조체를 보는 순간, 정의되어 있는 함수의 종류와 기능이 한눈에 들어오게끔 코드를 작성하는 것이 좋다. 따라서 구조체의 길이가 길어진다면 구조체 밖으로 함수를 빼낼 필요가 있다.

``` C++
struct Car
{
    . . .
    void ShowCreate();
    void Accel();
    . . .
}

void Car::ShowCreate()
{
     . . .
}
void Car::Accel()
{
    . . .
}
```
위와 같이 함수의 원형선언은 구조체 안에두고 함수의 정의를 구조체 밖으로 빼내는 것이다. 다만 빼낸 다음 함수가 어디에 정의 되어있는지에 대한 정보만 추가해주면 된다.
> 이러한 형태의 예제 04_RacingCarOuterFunc.cpp를 확인해보자.

**구조체 안에 함수의 정의를 하게되면 다음의 의미를 지닌다**
> "함수를 인라인으로 처리해라!"

반면 위의 예제와 같이 함수를 구조체 밖으로 빼내면 이러한 의미가 사라진다. 따라서 인라인의 의미를 그대로 유지하려면 아래와 같이 키워드 inline을 이용해서 인라인 처리를 명시적으로 지시해야 한다.

```C++
inline void Car::ShowCarState() { . . . }
inline void Car::Accel() { . . . }
inline void Car:Break() { . . . }
```
여기까지 C++ 에서의 구조체에 대한 설명이 끝났다.
그런데 C++ 에서의 구조체는 잠시후에 설명하는 Class의 일종으로 간주된다. 그래서 구조체 안에 함수를 정의할 수 있었던 것이다. 즉 위에서 정의한 구조체를 가리켜 '클래스'라고 표현해도 틀리지 않는다.