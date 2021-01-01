06-2 클래스와 함수에 대한 friend 선언
---
**클래스의 friend 선언**
A 클래스와 B 클래스가 있다고 가정해보자.

friend 선언은 다음과 같다
> A 클래스가 B 클래스를 대상으로 friend 선언을 하면, B 클래스는 A 클래스의 private 멤버에 직접 접근이 가능하다.
> 단, A 클래스도 B 클래스의 private 멤버에 접근을 하려면 B 클래스가 A 클래스를 대상으로 friend 선언을 해줘야 한다.
``` C++
class Boy
{
private:
    int height;
    friend class Girl;
public:
    Boy(int len) : height(len)
    { }
    . . .
};
```
Boy가 Girl 클래스 대상으로 firend 선언을 하였다. 따라서 Gril 클래스 내에서 Boy클래스의 모든 private 멤버에 직접 접근이 가능하다. friend 선언은 private 영역, public 영역에 상관없다.

아래 예제를 확인하자
> 01_MyFriendClass.cpp

❗️friend 선언은 객체지향의 중요점인 '정보은닉'의 개념을 무너 뜨리는 행위이다. 

❗️friend 선언이 있다는 것만 문법적으로 이해하자. 그리고 가급적 사용하지 않는것이 좋다. ❗️작은 문제를 해결하기 위해 더 큰 문제가 발생할 수 있다.

연산자 오버로딩을 공부하면서 유용하게 사용 될 수 있음 