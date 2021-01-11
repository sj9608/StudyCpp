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
    Book(const Book& ref)
        : price(ref.price)
    {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];

        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }
    
    Book& operator=(const Book& ref)
    {
        delete []title;
        delete []isbn;

        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];

        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        return *this;
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
    Ebook(const Ebook& ref)
        : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }
    Ebook& operator=(const Ebook& ref)
    {
        Book::operator=(ref);
        delete[] DRMKey;

        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
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
    Book book1("kim", "123", 1000);
    Book book2("kor", "345", 2000);
    Book book3 = book1;
    Book book4("eng", "567", 2030);

    book1.ShowBookInfo();
    book2.ShowBookInfo();
    book3.ShowBookInfo();
    book4.ShowBookInfo();

    book4 = book2;
    book4.ShowBookInfo();

    Ebook eb1("jb", "242", 1030, "4444");
    Ebook eb2("eb2", "243", 2030, "5555");
    Ebook eb3("eb3", "245", 2080, "666");
    Ebook eb4 = eb1;

    eb1.ShowEBookInfo();
    eb2.ShowEBookInfo();
    eb3.ShowEBookInfo();
    eb4.ShowEBookInfo();

    eb3 = eb1;
    eb3.ShowEBookInfo();

    return 0;
}