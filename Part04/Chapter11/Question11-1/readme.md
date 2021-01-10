문제 11-1 [깊은 복사를 하는 대입 연산자의 정의]
---
#### 문제 1.
Chapter 07에서 예제 HASComposite.cpp를 통해 다음의 두 클래스를 정의 하였다

``` C++
class Gun
{
private:
    int bullet;
public:
    Gun(int bnum)
        : bullet(bnum)
    { }
    void Shot()
    {
        cout << "BBANG" << endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun * pistol;
public:
    Police(int bnum, int bcuffs)
        :handcuffs(bcuffs)
    {
        if(bnum > 0)
        {
            pistol = new Gun(bnum);
        }
        else
        {
            pistol = NULL;
        }
    }
    void Shot()
    {
        if(pistol== NULL)
        {
            cout << "총알 없다." << endl;
        }
        else pistol->Shot();
    }
    void PutHandcuff()
    {
        cout << "SNAP" << endl;
        handcuffs--;
    }
    ~Police()
    {
        if(pistol != NULL)
            delete pistol;
    }
};
```
이에 Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입 연산자와 복사 생성자를 동시에 정의하고 이의 확인을 위한 main 함수도 적절히 정의해보자.

#### 문제 2.
Chapter 07의 문제 07-2 의 두 번째 문제에서는 다음의 두 클래스 정의를 요구 하였따.

``` C++
class Book
{
private:
    char * title; // 책의 제목
    char * isbn; // 국제 표준 도서 번호
    int price; // 책의 정가
public:
    Book(char * title, char * isbn, int price)
        : price(price)
    {
        this->title = new char[strlen(title) + 1];
        this->isbn = new char[strlen(isbn) + 1];

        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }

    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }

    void ShowBookInfo()
    {
        cout << "제목 : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "가격 : " << price << endl;
    }
};

class Ebook: public Book
{
private:
    char * DRMKey; // 보안 관련 키
public:
    Ebook(char * title, char * isbn, int price, char * drm)
        : Book(title, isbn, price)
    {
        DRMKey = new char[strlen(drm) + 1];
        strcpy(DRMKey, drm);
    }

    ~Ebook()
    {
        delete[] DRMKey;
    }

    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키 : " << DRMKey << endl;
    }
};
```
이 때 정의한 두 클래스를 대상으로 Book 클래스도, Ebook 클래스도 깊은 복사가 진행이 되도록 복사 생성자와 대입 연산자를 정의하고, 이의 확인을 위한 main 함수도 적절히 정의해보자. 참고로 이 문제의 해결을 위해서는 생각해봐야 할 요소들이 몇가지 존재한다. 특히 앞서 말한 다음 사실을 완전히 이해한 다음에 이 문제를 해결하기 바란다.
> C++ 에서 AAA형 참조자는 AAA객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다.