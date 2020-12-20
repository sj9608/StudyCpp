02-4 참조자와 함수
-----

Call by Value Vs Call by Reference

**일반적인 Call-By-Value 함수의 형태**
```C
int Adder(int num1, int num2)
{
    return num1 + num2;
}
```

**일반적인 Call-By-Reference 함수의 형태**

```C
void SwapByRef(int *num1, int * num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
```

일반적으로 Call-By-Reference 의미는 다음과 같다
**주소 값을 전달 받아서, 함수 외부에 선언된 변수에 접근하는 형태**

----------
C++ 에서는 두가지 방식으로 Call-by-Reference의 함수정의가 가능하다.
* 주소 값을 이용한 Call-by-Reference
* 참조자를 이용한 Call-by-Reference

참조자를 이용한 Call-by-Reference 사용 예시는 RefSwap.cpp 예제를 통해 확인해 보자.

---
**참조자를 이용한 Call-by-Reference의 단점과 const 참조자**
``` C
int num = 24;
HappyFunc(num);
printf("%d", num);
```
C언어의 관점에서 보았을 때 HappyFunc의 호출로 인한 num값의 변경은 불가능 하다. 하지만 C++에서는 num값의 변경이 일어날 수 도 있다. 아래의 예제를 확인해 보자.

``` C++
void HappyFunc(int prm) { } // 1.
void HappyFunc(int &ref) { }  // 2.
```
참조자를 이용했다면 num에 저장된 값을 변경했을 가능성도 있다.

이것이 참조자의 ❗️**단점** 이다. 
코드를 분석하는 과정에서 함수의 호출문장만 보고도 함수의 특성을 어느 정도 판단할 수 있어야 한다. 그러나 참조자를 사용하는 경우, 함수의 원형을 확인해야 하고, 확인 결과 참조자가 매개변수의 선언에 와있다면, 함수의 몸체까지 문장 단위로 확인을 해서 참조자를 통한 값의 변경이 일어나는지를 확인 해야한다.

❓하지만 이런 단점을 const 키워드를 이용하여 어느정도 극복할 수 있다.
다음함수의 원형을 보자.
```C++
void HappyFunc(const int &ref) {. . .}
```
참조자 ref에 const 선언이 추가되었다. 이는 다음의 의미를 지닌다.
```
"함수 HappyFunc 내에서 참조자 ref를 이용한 값의 변경은 하지 않겠다!"
```


따라서 아래의 원칙을 정하고 가급적 이 원칙을 지켜주는 것이 좋다.
```
"함수 내에서, 참조자를 통한 값의 변경을 진행하지 않을 경우, 참조자를
const로 선언해서, 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있게한다."
```

---
**반환형이 참조형인 경우**
``` C++
int& RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}
```

``` C++
int RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}
```
위 두개의 코드가 어떤식으로 작동 될지 상상해보자.
02_RefReturnOne.cpp 의 경우 반환형이 참조자이며 반환값을 참조자에 저장한 경우 이다. 이 경우 참조의 관계가 하나 더 추가 된다.

03_RefReturnTwo.cpp 의 경우 반환형은 참조자 이지만 반환 값은 일반 변수에 저장한 경우이다. 이 경우에는 num1, num2가 완전히 다른 변수가 된다.

마지막 으로 04_RefReturnThree.cpp 는 참조자를 반환하되, 반환형은 기본자료형인 경우이다.

03과 04의 결과 값은 같다. 하지만 반환형이 참조형일 경우엔 아래 두 코드가 컴파일 될 수 있다.
``` C++
int num2 = RefRetFuncOne(num1); // 변수에 반환 ⭕️
int &num2 = RefRetFuncOne(num1); // 참조자에 반환 ⭕️ 
``` 
하지만 반환형이 기본형일 경우엔 단순한 변수에만 반환값이 저장될 수 있다.
``` C++
int num2 = RefRetFuncTwo(num1); ⭕️
int &num2 = RefRetFuncTwo(num1); ❌
```
---
**const 참조자의 또 다른 특징**
다음 코드를 보고 논리적인 문제점이 무엇인지 찾아보자.
``` C++
const int num = 20;
int &ref = num;
ref += 10;
cout << num << endl;
```
const 선언을 통해 num을 상수화 했는데 참조자 ref를 통해 값을 변경한다❓
C++ 에선 아래 코드에서 컴파일에러를 일으킨다.
``` C++
int &ref = num; 
```
따라서 변수 num과 같이 상수화된 변수에 대한 참조자 선언은 다음과 같이 해야한다.
``` C++
const int num = 20;
const int &ref = num;
```
또 const 참조자는 상수도 참조가 가능하다.
``` C++
const int &ref = 50;
```
분명 참조자는 변수만 참조가 가능하다고 설명했는데 이게 어떻게 된 일인지 아래 설명을 참고하자.

---
**어떻게 참조자가 상수를 참조하나??**
프로그램 상에서 표현되는 숫자를 가리켜 리터럴(literal) 또는 리터럴 상수 라 한다. 그리고 이들은 다음 특징을 지닌다.
``` 
임시적으로 존재하는 값이다. 다음 행으로 넘어가면 존재하지 않는 상수다.
```
``` C++
const int &ref = 30;
```
이는 숫자 30이 메모리 공간에 계속 남아있을 때나 성립이 가능한 문장이다. 그래서 C++에서는 위의 문장이 성립할 수 있도록, const 참조자를 이용해서 상수를 참조할 때 '임시변수' 라는 것을 만든다. 그리고 이 장소에 상수 30을 저장하고선 참조자가 이를 참조하게끔 한다.

이에 대한 자세한 설명을 위한 함수를 하나 예시로 들어보도록 하자.
``` C++
int Adder(const int &num1, const int &num2)
{
    return num1 + num2;
}
```
위와 같이 정의된 함수에 인자의 전달을 목적으로 변수를 선언한다는 것은 매우 번거로운 일이 아닐 수 없다. 그러나 임시변수의 생성을 통한 const 참조자의 상수참조를 허용함으로써, 위의 함수는 다음과 같이 매우 간단히 호출이 가능해졌다.
``` C++
cout << Adder(3, 4) << endl;
```

* 문제 02-2 const 포인터와 const참조자 는 Question02-2를 확인