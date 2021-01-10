문제 10-3 [입력을 위한 >> 연산자의 오버로딩]
---
10-4의 예제 03_PointConsoleOutput.cpp 에서 정의한 Point 클래스를 대상으로 아래의 main 함수가 보이는 대로 데이터의 입력이 가능하도록, 그리고 실행의 예에서 보이는 대로 출력이 이루어지도록 >> 연산자를 오버로딩 하자.

**[main 함수]**
``` C++
int main(void)
{
    Point pos1;
    cout << "x, y 좌표 순으로 입력 : ";
    cin >> pos1;
    cout << pos1;

    Point pos2;
    cout << "x, y 좌표 순으로 입력 : ";
    cin >> pos2;
    cout << pos2;

    return 0;
}
```

[실행의 예]
``` bash
x, y 좌표 순으로 입력 : 3 7
[3, 7]
x, y 좌표 순으로 입력 : 4 9
[4, 9]
```