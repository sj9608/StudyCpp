12-3 OOP 단계별 프로젝트 09단계
---

이번 단계에서는 우리가 직접 정의한 String 클래스를 적용하는데 목적이 있다. 따라서 String 클래스를 완성하는것이 우선이다.

**프로젝트 09단계의 도입**
경험이 부족하면, 자신이 정의한 클래스를 프로그램 전체에 적절히 적용하는데 어려움을 느낄 수 있다. 따라서 클래스를 정의하는것 만큼은 아니지만, 자신이 정의한 클래스를 활용하는 데도 연습이 필요하다. 이에 앞서 예제 StringClass.cpp를 통해서 우리가 정의한 String 클래스를 단계별 프로젝트에 적용해보고자 한다.

**프로그램 설명**
우리가 정의한 Account 클래스는 생성자에서 문자열을 동적할당하기 때문에, 소멸자 그리고 깊은 복사를 위한 복사 생성자와 대입 연산자가 정의되어 있다. 그런데 이번에 적용할 String 클래스는 메모리 공간을 동적 할당하고, 깊은 복사를 진행하는 형태로 복사 생성자와 대입 연산자가 정의되어 있기 때문에 이를 이용하면 Account 클래스의 구현이 한결 간단해진다.

조금 더 자세히 설명하면, Account 클래스의 생성자 내에서의 동적 할당이 불필요해지며, 이로 인해서 직접 정의한 소멸자와 복사 생성자 그리고 대입 연산자가 모두 불필요해진다. 바로 이러한 사실을 확인하고 다음의 결론을 스스로 내리는 것이 이번 프로젝트의 핵심이라 할 수 있다.

> 적절한 클래스의 등장은 다른 클래스의 정의를 간결하게 해준다.

참고로 String 클래스를 등장시켰다고 해서 char 형 포인터 기반의 문자열 표현을 억지로 제한할 필요는 없다. 그러나 본 프로젝트의 목적 중 하나는 직접 정의한 클래스를 적용하는데 있으니, 가급적 String 객체를 이용해서 문자열을 표현하기로 하자. 마지막으로 실제 변경이 발생하는 헤더파일과 소스파일은 다음과 같다.
* Account.h, Account.cpp
* NormalAccount.h
* HighCreditAccount.h
* AccountHandler.cpp

그리고 String 클래스의 추가를 위해서 다음의 소스파일과 헤더파일을 추가하였다.
* String.h, String.cpp