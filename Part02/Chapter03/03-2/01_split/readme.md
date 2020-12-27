03-2 예제 01 파일분할
===

**컴파일 하는방법**
``` bash
g++ -o <실행파일 이름(.exe)> Car.cpp RacingMain.cpp
```

혹은 MakeFile문법
``` bash
01 : Car.cpp RacingMain.cpp
    g++ -o $@ $^
```