07-3 protected 선언과 세 가지 형태의 상속
---

**protected로 선언된 멤버가 허용하는 접근의 범위**
C++ 의 접근제어 지시자에는 private, protected, public 이렇게 세가지가 존재한다. 이들의 접근 범위는 다음의 관계가 있다.
* private < protected < public 

protected의 이해를 위해 다음 클래스를 살펴보자
``` C++
calss Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
    void ShowData() const
    {
        cout << num1 << ", " << num2 << ", " << num3 << endl;
    }
};
```
위 클래스에선 private과 protecte의 차이를 볼 수 없지만 이 클래스가 상속이 되면 차이를 보인다. 아래 클래스를 확인하자

``` C++
class Derived : public Base
{
public:
    void ShowBaseMember() const
    {
        cout << num1; // 컴파일 에러
        cout << num2; // 컴파일 OK!
        cout << num3; // 컴파일 OK!
    }
};
```
위 결과로 알게 된 사실은 다음과 같다
> protected로 선언된 멤버변수는 이를 상속하는 유도 클래스에서 접근이 가능하다.

유도 클래스에만 제한적으로 접근을 허용한다는 측면에서 유용하게 사용될 수 있는 키워드 이다. 하지만 기본적으로는 **기초 클래스와 이를 상속하는 유도 클래스 사이에서도 '정보은닉'은 지켜지는게 좋다.**

**세가지 형태의 상속**
``` C++
class Derived : public Base // 퍼블릭으로 상속되었다.
class Derived : protected Base // protected 상속
class Derived : private Base // private 상속
```
자세하게 알아보자

**protected 상속**

> protected보다 접근 범위가 넓은 멤버는 protected로 변경시켜 상속하겠다.

의 의미를 지닌다.

``` C++
class Dervied : protected Base
{
접근불가:
    int num1;
protected:
    int num2;
protected:
    int num3;
};
```
이 예제를 통해 접근제어 범위가 변경되는지 확인하자.
> 01_ProtectedHeri.cpp