05-1 '복사 생성자'와의 첫 만남
---
**C++ 스타일의 초기화**

지금까지 우리는 아래와 같은 방식으로 변수와 참조자를 선언 및 초기화해 왔다.

```C
int num = 20;
int &ref = num;
```
하지만 C++에서는 아래의 방식으로 선언 및 초기화가 가능하다.

```C++
int num(20);
int &ref(num);
```
위 두가지 초기화 방식은 결과적으로 동일하다.

하지만 객체의 생성에서는 달라진다. 예시를 들기 위해 아래 클래스를 확인해보자
``` C++
class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, n2) : num1(n1), num2(n2)
    { }
    void ShowSimpleData()
    {
        cout << num1 << endl; 
        cout << num2 << endl; 
    }
};
```
이어서 다음 코드의 실행결과를 예상해보자.
``` C++
int main(void)
{
    SoSimple sim1(15, 20);
    SoSimple sim2 = sim1;

    sim2.ShowSimpleData();
    return0;
}
```

<img width="412" alt="image" src="https://user-images.githubusercontent.com/52594760/103399394-4298ab80-4b84-11eb-8abe-f49a1c34449e.png">

멤버대 멤버의 복사가 일어난다. 여기서 알 수 있는 사실은 아래와 같다.
``` C++
int num1 = num2;
int num1(num2); 
// 위 두 문장이 동일한 것 처럼
// 아래 두 문장 역시 동일하다.
SoSimple sim2 = sim1;
SoSimple sim2(sim1);
```

한가지 이상한 점이 있다면 모든 객체는 생성자의 호출을 동반한다고 했는데 sim2의 생성자 호출이 선언되지 않았다. sim2는 어떠한 과정을 거쳐 생성되는 것일까?

**SoSimple sim2(sim1)**
이 문장을 해석해보자. 그리고 생성자의 호출관점에서 이를 재분석해보자.
* SoSimple형 객체를 생성해라
* 객체의 이름은 sim2로 정한다.
* sim1을 인자로 받을 수 있는 생성자의 호출을 통해 객체생성을 완료한다.

위의 문장에 대한 생성자는 다음과 같이 SoSimple형 객체를 인자로 받을 수 있는 생성자가 정의 되어 있어야한다.
```
SoSimple(SoSimple &copy) { } // 이 생성자는 복사 생성자이다.
// 따로 정의하지 않아도 '디폴트 복사 생성자'로써 정의가 되어있다.

SoSimple sim2 = sim1; // 이 문장이 아래의 형태로 변환되어 객체가 생성된다.

SoSimple sim2(sim1);
```

정말 복사 생성자를 정의하지 않아도 생성이 되는지 확인 해보자.
> 01_ClassInit.cpp 예제 확인

