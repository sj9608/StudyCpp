문제 07-2 [IS-A 관계의 상속]
---
#### 문제 1
정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다. 그런데 정사각형은 직사각형의 일종이므로, 다음의 형태로 클래스의 상속관계를 구상하고자 한다.
``` C++
class Rectangle
{
    . . .
};

class Square : public Rectangle
{
    . . .
};
```
이에 다음 main 함수와 함께 실행이 가능하도록 위의 클래스를 완성해보자. 참고로 상속을 한다고 해서 유도 클래스에 무엇인가를 많이 담아야 한다는 생각을 버리자.
**[main 함수]**
``` C++
int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}
```
실행의 예
``` cmd
면적 : 12
면적 : 49
```

#### 문제 2

'책'을 의미하는 Book 클래스와 '전자 책'을 의미하는 Ebook 클래스를 정의하고자 한다. 그런데 '전자 책'도 '책'의 일종이므로, 다음의 형태로 클래스의 상속관계를 구성하고자 한다.( 클래스에 선언 되어야 할 멤버 변수만 제시하였다. )

``` C++
class Book
{
private:
    char * title; // 책의 제목
    char * isbn; // 국제 표준 도서 번호
    int price; // 책의 정가
};

class Ebook: public Book
{
private:
    char * DRMKey; // 보안 관련 키
    . . . .
};
```
위의 Ebook 클래스에 선언된 멤버 DRMKey는 전자 책에 삽입이 되는 보안관련 키 의 정보를 의미한다. 그럼 다음 main 함수와 함께 실행 가능하도록 위 클래스를 정의해보자.
**[main 함수]**
``` C++
int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    
    cout << endl;
    
    Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();

    return 0;
}
```

실행의 예
``` cmd
제목 : 좋은 C++
ISBN : 555-12345-890-0
가격 : 20000

제목 : 좋은 C++ ebook
ISBN : 555-12345-890-1
가격 : 10000
인증키 : fdx9w0i8kiw
```