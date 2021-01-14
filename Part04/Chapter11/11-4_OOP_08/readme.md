11-4 OOP 단계별 프로젝트 08단계
---

이번 단계에는 11-2 예제 05_StablePointPtrArray.cpp 에서 정의한 BoundCheckPointPtrArray 클래스를 본 프로젝트에 맞게 변경시켜 적용시키고자 한다. 그리고 일부 클래스에 대해 깊은 복사를 진행하도록 대입 연산자도 오버로딩 하고자 한다.

**프로젝트 08 단계 도입**
Account 클래스는 깊은 복사를 진행하도록 복사 생성자가 정의되어 있다. 따라서 대입 연산자도 깊은 복사가 진행되도록 정의하는 것이 좋다. 그리고 AccountHandler 클래스에는 배열이 멤버로 선언되어서 객체의 저장을 주도 하는데, 이를 이번 Chapter에서 정의한 BoundCheckPoinPtrArray 배열 클래스로 대체하고자 한다. 물론, 이를 위해서는 약간의 수정이 필요하며, 클래스의 이름도 적당히 변경할 필요가 있다.

**프로그램 설명**
실제 변경이 발생하는 헤더파일과 소스파일은 다음과 같다.
* Account.h, Account.cpp ➡️ 대입 연산자의 정의
* AccountHandler.h ➡️ BoundCheckPointPtrArray 클래스의 적용

따라서 이들 파일에 대한 버전 정보를 갱신하기 바란다. 또한 배열 클래스의 추가를 위해서 다음의 소스파일과 헤더파일을 추가하도록 하자.
* AccountArray.h, AccountArray.cpp ➡️ 배열 클래스의 선언과 정의

혹, 위에서 언급한 파일과 BankingCommonDecl.h를 제외한 다른 파일에서 수정이 발생하였다면, 무엇인가 잘못되었거나 불필요한 수정이 가해졌을 수도 있으니, 다시 한번 확인하자.