09-3 OOP 단계별 프로젝트 07단계
---

이번 단계에서는 파일을 분할 하고자 한다. (이미 했다.)

**프로젝트 07단계의 도입**
각각의 클래스마다 선언은 .h 파일에, 정의는 .cpp 파일에 저장하는 것이 좋다. 이렇게 되면 프로그램을 관리하기도 좋고, 또 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다. 짧은 프로그램이라 할지라도 하나의 파일에 필요한 모든 요소를 담는 것은 바람직하지 못하다.

**프로그램 설명**
예를 들어 Simple 이라는 이름의 클래스가 있다면, Simple.h 와 Simple.cpp 파일을 만들자. 그리고 Simple.h 에는 클래스의 선언을, Simple.cpp에는 클래스의 정의 (멤버함수의 정의)를 담자. 그리하여 다음의 구조로 파일을 분할하자.

| 파일명| 내용 |
|:---:|:---:|
|Accounth, Account.cpp| Account 클래스의 선언과 정의|
|NormalAccount.h| NormalAccount 클래스의 선언과 정의|
|HighCreditAccount.h| HighCreditAccount 클래스의 선언과 정의|
|AccountHandler.h, AccountHandler.cpp| AccountHandler 클래스의 선언과 정의|
|BankingCommonDecl.h | 공통헤더 및 상수 선언들|
|BankingSystemMain.cpp| main 함수의 정의|