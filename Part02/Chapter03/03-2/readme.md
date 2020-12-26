03-2 클래스와 객체
---
앞서 설명한 C++의 구조체는 클래스의 일종이다. 

**클래스와 구조체의 유일한 차이점**
키워드 struct를 대신해서 class를 사용하면, 구조체가 아닌 클래스가 된다.

struct는 기본 Acces Modifier(접근제어 지시자)가 public으로 설정 되어있다.
반면 Class의 경우에는 private으로 설정 되어있기 때문에 클래스 내에 선언된 변수와 함수에 접근하려면 public Class로 지정해주어야 한다.

**접근제어 지시자(Acces Modifier)**
C++의 접근제어 지시자는 다음과 같이 총 세가지가 존재한다.
|<center>키워드</center>|<center>내용</center>| 
|:--------------------:|:-------------------------|
| public              | 어디서든 접근허용
| protected           | 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용
| private             | 클래스 내부에서만 접근허용

이 중에서 protected는 '상속'과 관련이 있으므로 나중에 살펴보자.
>예제 01_RacingCarClassBase.cpp를 확인하자
