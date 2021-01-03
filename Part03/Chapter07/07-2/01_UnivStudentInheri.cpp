#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    int age;
    char name[50];
public:
    Person(int myage, char * myname) : age(myage)
    {
        strcpy(name, myname);
    }

    void WhatYourName() const
    {
        cout << "my name is : " << name << endl;
    }

    void HowOldAreYou() const
    {
        cout << "I'm " << age << " years old" << endl;
    }
};

class UnivStudent : public Person
{
private:
    char major[50];
public:
    UnivStudent(char * myname, int myage, char * mymajor)
        : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }

    void WhoAreYou()
    {
        WhatYourName();
        HowOldAreYou();
        cout << "my Major is " << major << endl << endl;
    }
};

int main()
{
    UnivStudent std1("Lee", 22, "Computer eng.");
    std1.WhoAreYou();

    UnivStudent std2("Kim", 21, "Electronic eng.");
    std2.WhoAreYou();

    return 0;
}