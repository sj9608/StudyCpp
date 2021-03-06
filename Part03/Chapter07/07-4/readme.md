07-4 상속을 위한 조건
---

**상속을 위한 기본 조건인 IS-A 관계의 성립**
'is-a' 관계라는 것은 '일종의 ~ 이다' 로 해석된다.

노트북 is a 컴퓨터 (노트북은 일종의 컴퓨터 이다.)
스마트폰 is a 전화기 (스마트폰은 일종의 전화기 이다.)

컴퓨터와 전화기의 기본기능은 '계산'과 '통화' 이다.
노트북과 스마트폰은 각 기능에 '이동성'이라는 특성이 추가 된 것이다.

즉, 상속관계가 서립하려면 기초 클래스와 유도 클래스간에 IS-A 관계가 성립해야한다. 

상속관계로 묶고자 하는 두 클래스가 IS-A 관계로 표현되지 않는다면, 이는 적절한 상속의 관계가 아닐 확률이 매우 높다. 아래의 예제를 확인하자.
> 01_ISAInheritance.cpp

**HAS-A 관계도 상속의 조건은 되지만 복합 관계로 이를 대신하는 것이 일반적이다.**
> 02_HASInheritance.cpp 예제 확인

위 예제는 권총을 소유한 경찰을 표현한다. 이러한 소유의 관계는 상속이 아닌 다른방식으로도 얼마든지 표현이 가능하다.

> 03_HASComposite.cpp 예제 확인

02_HASInheritance.cpp 의 코드의 경우에 다음과 같은 요구사항을 반영하기 힘들다.
* 권총을 소유하지 않은 경찰을 표현해라.
* 경찰이 권총과 수갑 뿐아니라 전기봉도 소유한다.

**상속으로 묶인 두 개의 클래스**는 강한 연관성을 띤다.

**상속은 IS-A 관계의 표현에 매우 적절하다.**