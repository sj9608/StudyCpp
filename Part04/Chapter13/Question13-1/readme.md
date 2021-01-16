문제 13-1 [함수 템플릿의 정의]
---
#### 문제 1
인자로 전달되는 두 변수에 저장된 값을 서로 교환하는 SwapData라는 이름의 함수를 템플릿으로 정의해보자. 그리고 다음 Point 클래스를 대상으로 값의 교환이 이뤄짐을 확인할 수 있도록 main 함수를 구성해보자.

``` C++
class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};
```

#### 문제 2
다음은 int형 배열에 저장된 값을 모두 더해서 그 결과를 반환하는 기능의 함수이다.
``` C++
int SumArray(int arr[], int len)
{
    int sum = 0;
    for(int i = 0; i< len; i++)
        sum += arr[i];
    return sum;
}
```
이 함수를 템플릿으로 정의하여 다양한 자료형의 배열을 대상으로 합을 계산하는 예제를 작성해 보자.