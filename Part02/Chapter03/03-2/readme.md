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

이 예제를 통해 다음 사실을 알 수 있다.
* 접근제어 지시자 A가 선언되면 그 이후에 등장하는 변수나 함수는 A에 해당하는 범위 내에서 접근 가능하다.
* 그러나 새로운 접근제어 지시자 B가 선언되면, 그 이후로는 등장하는 변수나 함수는 B에 해당하는 범위 내에서 접근이 가능하다.
* 함수의 정의를 클래스 밖으로 빼도, 이는 클래스의 일부이기 때문에, 함수 내에서는 private으로 선언된 변수에 접근이 가능하다.
* 키워드 struct를 통해 정의한 구조체(클래스)에 선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면 public으로 선언된다
* 키워드 class를 통해 정의한 클래스에 선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면 private으로 선언된다.

**용어정리 : 객체(Object)와 멤버변수, 멤버함수**
구조체 변수, 클래스 변수라는 표현은 이제 어울리지 않는다. 왜냐하면 구조체와 클래스는 변수의 성격만 지니는 것이 아니기 때문이다. 이제 변수라는 표현을 대신해서 객체(Object)라는 표현을 사용한다.

> 객체는 무엇을 의미하나요? 그리고 객체라고 부르는 이유가 뭐죠?

예제 01_RacingCarClassBase.cpp의 65행에 선언된 run99는 '변수'가 아닌 **객체**이다.
그리고 클래스를 구성하는(클래스 내에 선언된) 변수를 가리켜 **'멤버변수'**라 하고 클래스를 구성하는 함수를 가리켜 **'멤버함수'** 라 한다.

**C++ 에서의 파일 분할**
어떠한 프로그램이건 하나의 파일에 모든것을 담진 않는다. 특히 C++은 클래스 별로 헤더파일과 소스파일을 생성해서 클래스의 선언과 정의를 분리하는 경우가 많기 때문에 많은 수의 파일이 만들어진다.

**파일을 나누는기준**에 대해 설명에 앞서 필요한 기초지식들
* 헤더파일의 역할을 알고있다.
* C언어를 대상으로 헤더파일에 들어가야 할 내용을 구분할 수 있다.
* 헤더파일의 중복포함을 막기 위해서 사용하는 매크로 #ifndef~#endif을 알고있다.
* 둘 이상의 파일을 컴파일해서 하나의 실행파일을 만드는 법을 알고있다.
* 링커(Linekr)가 하는일을 알고있다.

클래스 Car를 대상으로 파일을 나눌 때에는 보통 다음과 같이 파일을 구분한다.
* Car.h ⇢ 클래스의 선언을 담는다.
* Car.cpp ⇢ 클래스의 정의를 담는다.

>이에 대한 예제는 01_split 폴더를 확인하자.

**인라인함수는 헤더파일에 함께 넣자**
파일분할 예제 Car.cpp에 정의된 함수 ShowCarState와 Break를 다음과 같이 인라인화 한 다음에 그래도 Car.cpp에 두면 컴파일 에러가 발생한다.

