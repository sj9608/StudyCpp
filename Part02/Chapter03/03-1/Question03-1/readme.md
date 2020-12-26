문제 03-1 [구조체 내에 함수정의하기]
---

```C++
strcut Point
{
    int xpos;
    int ypos;
}
```
위의 구조체를 기반으로 다음의 함수를 정의하고자 한다 (자세한 기능은 실행의 예를 통해서 확인)

```C++
void MovePos(int x, int y); // 점의 좌표이동
void AddPoint(const Point &pos); // 점의 좌표증가
void ShowPosition(); // 현재 x, y 좌표정보 출력
```

단, 위의 함수들을 구조체 안에 정의를 해서 다음의 형태로 main 함수를 구성할 수 있어야 한다
.
``` C++
int main(void)
{
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition(); // [5, 14] 출력

    pos1.AddPoint(pos2);
    pos1.ShowPosition(); // [25, 44] 출력
    
    return 0;
}
```

실행의 예
``` C++
[5, 14]
[25, 44]
```