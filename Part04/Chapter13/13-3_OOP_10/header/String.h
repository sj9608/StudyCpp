#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String
{
private:
    char * str;
    int len;
public:
    String();
    String(const char * s);
    String(const String &s);
    ~String();
    String& operator=(const String& s);
    String& operator+=(const String& s);
    String operator+(const String& s);
    bool operator==(const String& s);
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
};
#endif