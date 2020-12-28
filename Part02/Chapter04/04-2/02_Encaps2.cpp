#include <iostream>
using namespace std;

class SinivelCap // 콧물 처치용 캡슐
{
public:
    void Take() const {cout << "콧물이 싹~ 낫습니다." << endl;}
};

class SneezeCap // 재채기 처치용 캡슐
{
public:
    void Take() const {cout << "재채기가 멎습니다." << endl;}
};

class SnuffleCap // 코막힘 처치용 캡슐
{
public:
    void Take() const {cout << "코가 뻥 뚫립니다." << endl;}
};

/* 캡슐화 추가 */
class CONTAC600
{
private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;
public:
    void Take() const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

int main(void)
{
    CONTAC600 cap;
    ColdPatient sufferer;

    sufferer.TakeCONTAC600(cap);

    return 0;
}