#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char * str;
public:
    String(char * str)
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
    String& operator=(String& ref)
    {
        int len = strlen(ref.str) + 1;
        str = new char[len];
        strcpy(str, ref.str);
        return *this;
    }
    String& operator+=(const String& ref)
    {
        int len = strlen(this->str) + strlen(ref.str) + 1;
        this->str = new char[len];
        strcat(this->str, ref.str);
        return *this;
    }
    bool operator==(const String& ref)
    {
        if(strcmp(this->str, ref.str))
            return true;
        else
            return false;
    }
    String& operator+(const String& ref)
    {
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
    ref.str = str;
    return is;
}
int main(void)
{
    String str1 = "I like ";

    cout << str1 << endl;
    return 0;
}