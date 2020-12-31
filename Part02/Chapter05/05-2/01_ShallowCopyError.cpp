#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;

public:
    Person(char *myname, int age)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        this->age = age;
    }

    void ShowPersonInfo() const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }

    ~Person()
    {
        delete[] name;
        cout << "called Destructor" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    
    return 0;
}