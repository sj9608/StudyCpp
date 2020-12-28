문제 04-2 [다양한 클래스의 정의]
---
다음의 Point 클래스를 기반으로하여 원을 의미하는 Circle 클래스를 정의하자.

``` C++
class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
}
```

Circle 객체에는 좌표상의 위치 정보(원의 중심좌표)와 반지름의 길이 정보를 저장 및 출력할 수 있어야 한다. 그리고 정의한 Circle 클래스를 기반으로 Ring 클래스도 정의하자. 링은 두 개의 원으로 표현 가능하므로(바깥쪽 원과 안쪽 원), 두개의 Circle 객체를 기반으로 정의가 가능하다. 참고로 안쪽원과 바깥쪽 원의 중심좌표가 동일하다면 두께가 일정한 링을 표현하는 셈이되며, 중심좌표가 동일하지 않다면 두께가 일정하지 않은 링을 표현하는 셈이 된다. 이렇게 해서 클래스의 정의가 완료되었다면, 다음 main 함수를 기반으로 실행을 시키자.

``` C++
int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring ShowRingInfo();
    return 0;
}
```

Init 함수 호출을 통해서 전달된 1, 1, 4는 안쪽 원의 정보에 해당하며 (순서대로 x, y, radian), 이어서 전달된 2, 2, 9는 바깥쪽 원의 정보에 해당한다. 그리고 실행결과는 다음과 같거나 유사해야 한다.

``` bash
Inner Circle Info...
radius : 4
[1, 1]
Outter Circle Info...
radius : 9
[2, 2]
``` 

캡슐화를 항상 고민하자.