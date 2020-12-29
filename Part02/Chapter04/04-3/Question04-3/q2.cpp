#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER:
                cout << "과장" << endl;
                break;
        }
    }
}

class NameCard
{
private:
    char * m_name;
    char * m_compName;
    char * m_contact;
    int m_position;
public:
    NameCard(char *name, char * compName, char *contact, int position)
        : m_position(position)
    {
        m_name = new char[strlen(name) + 1];
        m_compName = new char[strlen(compName) + 1];
        m_contact = new char[strlen(contact) + 1];

        strcpy(m_name, name);
        strcpy(m_compName, compName);
        strcpy(m_contact, contact);
    }

    void ShowNameCardInfo() const
    {
        cout << "이름 : " << m_name << endl;
        cout << "회사 : " << m_compName << endl;
        cout << "전화번호 : " << m_contact << endl;
        cout << "직급 : ";
        COMP_POS::ShowPositionInfo(m_position);
        cout << endl;
    }

    ~NameCard()
    {
        delete[] m_name;
        delete[] m_compName;
        delete[] m_contact;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}