#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char * m_name;
    int m_age;
public:
    Person(char * name, int age)
    {
        int len = strlen(name) + 1;
        m_name = new char[len];
        strcpy(m_name, name);
        m_age = age;
    }
    Person()
    {
        m_name = NULL;
        m_age = 0;
        cout << "called Person()" << endl;
    }

    void SetPersonInfo(char * name, int age)
    {
        m_name = name;
        m_age = age;
    }

    void ShowPersonInfo() const
    {
        cout << "이름 : " << m_name << endl;
        cout << "나이 : " << m_age << endl;
    }

    ~Person()
    {
        delete[] m_name;
        cout << "called Destructor" << endl;
    }
};

int main(void)
{
    Person * pArr[3];
    char namestr[100];
    int age;

    for(int i=0; i<3; i++)
    {
        cout << "이름 : ";
        cin >> namestr;
        cout << "나이 : ";
        cin >> age;

        pArr[i] = new Person(namestr, age);
    }

    pArr[0]->ShowPersonInfo();
    pArr[1]->ShowPersonInfo();
    pArr[2]->ShowPersonInfo();
    
    delete pArr[0];
    delete pArr[1];
    delete pArr[2];

    return 0;
}