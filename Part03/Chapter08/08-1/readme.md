08-1 객체 포인터의 참조관계
---

**객체 포인터 변수 : 객체의 주소 값을 저장하는 포인터 변수**
클래스를 기반으로 포인터 변수를 선언할 수 있따. 예를들어 Person이라는 이름의 클래스가 정의되었다면, Person 객체의 주소 값 저장을 위해서 Person 객체를 가리키기 위해 다음과 같이 포인터 변수를 선언할 수 있다.
> Person * ptr; // 포인터 변수 선언
> ptr = new Person(); // 포인터 변수의 객체 참조

위의 두 문장이 실행 되면 * ptr 은 Person 객체를 가리키게 된다. 그런데 !
**Person형 포인터는 Person 객체뿐만 아니라, Person을 상속하는 유도객체도 가리킬 수 있다.** 예를들어 Person을 상속하는 Student 클래스가 다음과 같이 정의 되어있을 때,

``` C++
class Student : public Person
{
    . . .
};
```

Person 형 포인터 변수는 아래의 문장에서 보이듯 Student 객체도 가리킬 수 있다.

``` C++
Person * ptr;
ptr = new Student();
```

그리고 Student 클래스를 상속하는 유도 클래스 PartTimeStudent가 다음의 형태로 정의 되었다고 가정하면,

``` C++
class PartTimeStudent : public Student
{
    . . . 
};
```

Person 형 포인터 변수는 아래 문장에서 보이듯 PartTimeStudent 객체도 가리킬 수 있다.

``` C++
Person * ptr = new PartTimeStudent();
```

뿐만 아니라, Student형 포인터 변수 역시 PartTimeStudent 객체를 가리킬 수 있다.

``` C++
Student * ptr = new PartTimeStudent();
```

---
위의 설명을 간단히 한문장으로 정리해 보자면 다음과 같다.

> C++에서, 클래스 AAA형 포인터 변수는 AAA 객체 또는 AAA 객체를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다.(객체의 주소 값을 저장할 수 있다.)

그렇다면 이게 어떻게 가능하고, C++에서 어떤 의미가 있는지 알아보자.
> 01_ObjectPointer.cpp 예제 확인

위 예제에 대한 논리적인 이해를 해보자.
예제 01_ObjectPointer.cpp 에서 보인 상속은 다음과 같이 IS-A 관계가 성립하기 때문에 적절한 상속이라 할 수 있다.
> Student is a Person
> PartTimeStudent is a Student
> PartTimeStudent is a Person

이는 다음과 같이 표현할 수도 있다.
> 학생은 사람의 일종이다.
> 근로학생은 학생의 일종이다.
> 근로학생은 사람의 일종이다.

실제로 객체지향에서 위의 문장들이 성립합(IS-A관계 성립)으로 인해서, Person형 포인터 변수를 이용해 Student, PTStudent 객체를 가리킬수 있는것이다. 이러한 특성을 그림으로 정리하면 다음과 같다.

<img width="400" alt="image" src="https://user-images.githubusercontent.com/52594760/103537232-69821500-4ed7-11eb-9243-37f81fd49916.jpg">

---
**오렌지미디어 급여관리 확장성 문제의 1차적 해결과 함수 오버라이딩**

위에서 설명한 포인터의 특성은 Chapter 07에서 소개한 확장성 문제 해결의 1차적인 실마리가 된다.
> "정규직, 영업직, 임시직 모두 고용의 한 형태이다."   
> "영업직은 정규직의 일종이다."

따라서 다음과 같이 클래스를 정의하면,
|이름| 클래스
|--|---|
|고용인|Employee|
|정규직|PermanentWorker|
|영업직|SalesWorker|
|임시직|TemporaryWorker|

IS-A 관계를 기반으로 다음과 같이 상속의 관계를 구성할 수 있다.

<img width="400" alt="image" src="https://user-images.githubusercontent.com/52594760/103541029-12cc0980-4ede-11eb-9366-6be67a936f26.png">

그리고 이는 EmployeeHandler 클래스를 다음과 같이 설계할 수 있다는 뜻이 되기 떄문에, 문제 해결의 첫 번째 실마리가 된다.

> "EmployeeHandler 클래스가 저장 및 관리하는 대상이 Employee 객체가 되게 하면, 이후에 Employee 클래스를 직접 혹은 간접적으로 상속하는 클래스가 추가되었을 때, EmployeeHandler 클래스에는 변화가 발생하지 않는다.

다음 예제는 이전 예제 Chpater 07의 EmployeeManager1.cpp 에서 Employee 클래스만 도입한 것이다.

> 02_EmployeeManager2.cpp 예제확인

이 예제의 주석처리된 부분은 잠시후에 해결하기로 하고 EmployeeHandler 객체가 여전히 PermanentWorker 객체를 저장 및 관리하고 있다는 점에만 주목하자.

이제 고용형태를 추가해 보도록 하겠다.
|고용형태| 급여산정
|--|---|
|영업직|기본급여 + 인센티브|
|임시직|시간당 급여 x 일한시간|

> 03_EmployeeManager3.cpp 예제 확인

위 예제에서 PermanentWorker 클래스에 GetPay 함수와 ShowSalaryInfo() 함수가 있는데, 유도 클래스인 TemporaryWorker, SalesWorker 클래스에서도 동일한 이름과 **형태**로 두 함수를 정의하였다.

이를 가리켜 '함수 오버라이딩' 이라 한다. (함수 오버로딩과 혼동하지말자 ❗️)

이렇게 함수가 오버라이딩 되면, 오버라이딩 된 기초 클래스의 함수는, 오버라이딩을 한 유도 클래스의 함수에 가려진다!. 그래서 SalesWorker 클래스 내에서 GetPay 함수를 호출하면 SalesWorker 클래스에 정의된 GetPay 함수가 호출된다.

SalesWorker 클래스의 GetPay 함수를 보면 다음과 같은 구문이 보인다.
> PermanentWorker::GetPay()

이는 오버라이딩 된 기초 클래스의 GetPay 함수를 호출하는 구문이다. 이를 통해 오버라이딩 된 기초클래스의 함수도 호출 할 수 있음을 알 수 있다.

