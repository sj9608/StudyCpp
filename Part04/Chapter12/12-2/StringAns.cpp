#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char * str;
    int len;
public:
    String() // 디폴트 생성자
    {
        len = 0;
        str = NULL;
    }
    String(const char *s) // 생성자
    {
        len = strlen(s) + 1;
        str = new char[len];
        strcpy(str, s);
    }
    String(const String& s) // 깊은 복사생성자
    {
        len = s.len;
        str = new char[len];
        strcpy(str, s.str);
    }
    ~String() // 소멸자
    {
        if(str != NULL)
            delete []str;
    }
    String& operator=(const String& s) // 대입연산자 오버로딩
    {
        if(str!= NULL) // str 문자열의 공간이 할당되었다면
            delete []str;

        len = s.len;
        str = new char[len];
        strcpy(str, s.str);
        return *this;
    }
    String& operator+=(const String& s) // += 연산자 오버로딩
    {
        len += (s.len - 1);
        char* tempstr = new char[len];
        strcpy(tempstr, str);
        strcat(tempstr, s.str);

        if(str != NULL)
            delete []str;
        str = tempstr;
        return *this;
    }
    bool operator==(const String& s) // == 연산자 오버로딩
    {
        return strcmp(str, s.str) ? false : true;
    }
    String operator+(const String& s) // + 연산자 오버로딩
    {
        char *tempstr = new char[len+s.len-1];
        strcpy(tempstr, str);
        strcat(tempstr, s.str);

        String temp(tempstr); // String temp = tempstr;
        delete []tempstr;
        return temp;
    }
    friend ostream& operator<<(ostream&, const String&); // << 연산자 오버로딩 단순출력 const
    friend istream& operator>>(istream&, String&); // >> 연산자 오버로딩 입력값 집어넣어야함 no const
};

ostream& operator<<(ostream& os, const String& s)
{
    os << s.str;
    return os;
}

istream& operator>>(istream& is, String& s)
{
    char str[100];
    is >> str;
    s = String(str);
    return is;
}

int main(void)
{
    String str1 = "I like ";
    String str2 = "String class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if(str1 == str3)
        cout << "동일 문자열" << endl;
    else
        cout << "동일하지 않은 문자열" << endl;

    String str4;
    cout << "문자열 입력 : ";
    cin >> str4;
    cout << "입력하신 문자열 : " << str4 << endl;

    return 0;
}