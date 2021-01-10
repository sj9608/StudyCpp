#include <iostream>
using namespace std;

class Person
{
private:
    char * name;
    int age;
public:
    Person(char *mychar, int myage)
    {
        int len = strlen(mychar) + 1;
        name = new char[len];
        strcpy(name, mychar);
        age = myage;
    }
    void ShowPersonData() const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }

    Person& operator=(const Person& ref)
    {
        delete []name;
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
    
    ~Person()
    {
        delete []name;
        cout << "called Destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);

    man2 = man1;

    man1.ShowPersonData();
    man2.ShowPersonData();
    return 0;
}