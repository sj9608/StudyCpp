C++ Study
===
Part 01 C++로의 전환
---
2020. 12월 19일

> Chapter 01 C언어 기반의 C++ 1 Done

2020. 12월 20일

> Chapter 02 C언어 기반의 C++ 2 01~04 

2020년 12월 21~25일
> LINC+ 창의대첩(22~24)
> Chapter 02 C언어 기반의 C++ 2 05, 06

Part 02 객체지향의 도입
---
2020년 12월 26일
> Chapter 03 클래스의 기본
>   > 03-1 : C++에서의 구조체
>   >03-2 : 클래스와 객체
>   >03-3 : 객체지향  프로그래밍의 이해

2020년 12월 27일
> Chapter 03 예제 및 문제 정리

2020년 12월 28일
> Chapter 04 클래스의 완성
>   > 04-1 : 정보은닉
 04-2 : 캡슐화

2020년 12월 29일
> Cahpter 04 클래스의 완성
>   > 04-3 : 생성자와 소멸자

2020년 12월 30일
> Chapter 04 클래스의 완성
>   > 04-4 : 클래스와 배열 그리고 this 포인터

> Chapter 01-5 OOP 단계별 프로젝트 1단계 재진행

2020년 12월 31일
> Chapter 05 생성자와 소멸자
>   > 05-1 '복사 생성자'와의 첫 만남
>   >05-2 '깊은 복사'와 '얕은 복사'

2020년 1월 1일
> Chapter 05 생성자와 소멸자
>   > 05-3 복사 생성자의 호출 시점

> Chapter 06
>   > 06-1 const 관련 추가 설명
>   > 06-2 클래스와 함수에 대한 friend 선언
>   > 06-3 C++ 에서의 static

2020년 1월 2일
> OOP 단계별 프로젝트 02, 03, 04 단계 진행

Part 03 객체지향의 전개
---

2020년 1월 3일
> Chapter 07 상속의 이해
>   > 07-1 상속에 들어가기 앞서
> 
>   > 07-2 상속의 문법적 이해
> 
>   > 07-3 protected 선언과 상속의 세 가지 형태
>   > 07-4 상속을 위한 조건 (IS-A)

2020년 1월 4일
> Chapter 07 상속의 이해
>   > 07-5 OOP 단계별 프로젝트 05 단계 (Entity, Control 클래스의 분리 및 분할 컴파일)

> Chapter 08 상속과 다형성
>   > 08-1 객체 포인터의 참조 관계



---

[궁금함]
---
1. 매개변수로 char* 로 하는 함수에 string literal을 전달 하였을 때 발생하는 경고 문구

![image](https://user-images.githubusercontent.com/52594760/103165760-defa3f80-485e-11eb-83e0-cab264003d29.png)

이유 : C++에서 "Hello world" 같은 string literal은 const char[] 형 이다.
따라서 string literal을 전달할 때 (char *) 로 형변환을 진행하고 넘겨주면 오류가 뜨지 않는다.

해결 :
![image](https://user-images.githubusercontent.com/52594760/103165944-1ff35380-4861-11eb-9465-ef310e00171f.png)

---

[Makefile 참고 사이트] https://bowbowbow.tistory.com/12

❗ 만약 MinGW를 설치했음에도 불구하고 make 명령어를 찾을수 없다고 출력되는 경우
C:/MinGW/bin 폴더 안의 mingw-make.exe 파일을 make.exe로 변경해주면 해결 된다.