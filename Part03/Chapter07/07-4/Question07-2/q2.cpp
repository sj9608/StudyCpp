#include <iostream>
#include <cstring>

using namespace std;

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

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    
    cout << endl;
    
    Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();

    return 0;
}