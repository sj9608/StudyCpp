C++ Study
===
Part 01 C++로의 전환
---
2020. 12월 19일

> Chapter 01 C언어 기반의 C++ 1 Done

2020. 12월 20일

> Chapter 02 C언어 기반의 C++ 2 01~04 

2020년 12월 21~25일
> Chapter 02 C언어 기반의 C++ 2 05, 06

Part 02 객체지향의 도입
---
2020년 12월 26일
> Chapter 03 클래스의 기본
>> 03-1 : C++에서의 구조체
>> 03-2 : 클래스와 객체
>> 03-3 : 객체지향  프로그래밍의 이해

2020년 12월 27일
> Chapter 03 예제 및 문제 정리

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