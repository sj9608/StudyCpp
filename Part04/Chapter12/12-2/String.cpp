#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char * str;
    // 길이 저장없음
public:
    // 디폴트 생성자 없음.
    String(char * str) // const 선언 없음
    {
        int len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
    }
    String(const String& ref)
    {
        int len = strlen(ref.str) + 1;
        str = new char[len];
        strcpy(str, ref.str);
    }
    ~String()
    {
        if(str != NULL)
            delete []str;
    }
    String& operator=(String& ref) // 대입 연산자 오버로딩 ( const 추가해야 함 )
    {
        // 기존 str 공간 체크 , delete 안함

        int len = strlen(ref.str) + 1;
        str = new char[len];
        strcpy(str, ref.str);
        return *this;
    }
    String& operator+=(const String& ref) // += 연산자 오버로딩
    {
        int len = strlen(this->str) + strlen(ref.str) + 1;
        // 새로운 임시 char* tempstr 할당
        // tempstr 에 기존 str  strcpy;
        // tempstr 에 ref.str strcat 붙이기
        // 기존 str 공간 널체크
            // 삭제
        // str에 tempstr 
        this->str = new char[len];
        strcat(this->str, ref.str);
        return *this;
    }
    bool operator==(const String& ref) // 비교 연산자 오버로딩
    {
        // 삼항연산자로 간단하게 처리할 수 있음
        // return strcmp(str, ref.str) ? false : true;
        if(strcmp(this->str, ref.str))
            return true;
        else
            return false;
    }
    String& operator+(const String& ref) // + 연산자 오버로딩 ( 반환형 참조자 형이 아닌 새로운 객체 String 으로 반환)
    {
        // char * 형 임시변수 tempstr 에 기존 공간 + 참조한 String 객체의 공간 - 1; 할당
        // 임시변수에 str 복사 및 참조객체 이어붙이기 strcpy, strcat
        // 새로 String 임시 객체 생성
        // char * 형 임시변수 공간 해제
        // 임시 객체 반환
        int len = strlen(this->str) + strlen(ref.str) + 1;
        this->str = new char[len];
        strcat(this->str, ref.str);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const String& ref);
    friend istream& operator>>(istream& is, String& ref);
};

ostream& operator<< (ostream& os, const String& ref)
{
    os << ref.str;
    return os;
}

istream& operator>> (istream& is, String& ref)
{
    char str[100];
    is >> str;
    ref.str = str; // 단순 str 대입이 아닌 새로운 객체를 생성해서 대입해야함.
    return is;
}
int main(void)
{
    String str1 = "I like ";

    cout << str1 << endl;
    return 0;
}