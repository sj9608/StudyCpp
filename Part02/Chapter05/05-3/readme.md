05-3 복사 생성자의 호출 시점
---
**복사 생성자가 호출되는 시점은?**
``` C++
Person man1("Lee dong woo", 29);
Person man2 = man1; // 복사 생성자 호출
```
이 경우 호출되지만 크게 세가지로 구분할 수 있다.
* case 1 : 기존에 생성된 객체를 이용해 새로운 객체를 초기화 하는경우 (위)
* case 2 : Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
* case 3 : 객체를 반환하되, 참조형으로 반환하지 않는 경우

이들은 모두 공통점을 지닌다.
> "객체를 새로 생성해야 한다. 단, 생성과 동시에 동일한 자료형의 객체로 초기화 해야한다!"

> 복사 생성자의 호출횟수는 프로그램의 성능과도 관계가 있기 때문에, 호출의 시기를 이해하는 것은 매우 중요하다.

**메모리 공간의 할당과 초기화가 동시에 일어나는 상황**
``` C++
int SimpleFunc(int n)
{ . . . }
int main(void)
{
    int num = 10;
    SimpleFunc(num); // 호출되는 순간 매개변수 n이 할당과 동시에 초기화
}
```
또 한가지 더
``` C++
int SimpleFunc(int n)
{
    . . .
    return n;
}

int main(void)
{
    int num = 10;
    cout << SimpleFunc(num) << endl;
}
```
함수의 값을 반환하기 위해서도 메모리 공간의 할당과 초기화가 일어난다.

> "함수가 값을 반환하면, 별도의 메모리 공간이 할당되고, 이 공간에 반환 값이 저장된다."

위의 총 세가지 상황은 객체를 대상으로 해도 달라지지 않는다.
>SoSimple ob2 = ob1; // ob1도 SoSimple 객체라 가정

**할당 이후, 복사 생성자를 통한 초기화**
초기화는 멤버 대 멤버가 복사되는 형태로 이뤄져야 한다. 따라서 '복사 생성자의 호출'을 통해 초기화 한다. 다음 예제를 보고 언제 복사 생성자가 호출되는지 직접 확인해 보자.
> 01_PassObjCopycon.cpp 예제 확인

위 예제를 통해 함수에 인자를 전달하는 과정에서 복사 생성자가 호출됨을 확인 하였다. 그리고 이로 인해 멤버변수 num에 저장된 값이 복사 되는것도 확인하였다.

아래의 그림은 복사 생성자의 호출관계 이다.
![image](https://user-images.githubusercontent.com/52594760/103434054-13934000-4c3f-11eb-9758-9ef6c48ad410.png)

초기화의 대상은 obj객체가 아닌 ob객체이다. 그리고 ob객체는 obj객체로 초기화된다.
ob객체의 복사 생성자가 호출되면서, obj객체가 인자로 전달된 것이다.

다음 예제를 통해 복사 생성자가 호출되는 세번째 경우를 확인하자.
> 02_ReturnObjCopycon.cpp