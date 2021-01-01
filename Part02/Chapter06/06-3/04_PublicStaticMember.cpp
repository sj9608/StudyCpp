#include <iostream>
using namespace std;

class SoSimple
{
public:
    static int simObjCnt;
public: // 해당 키워드 선언은 불필요하지만 변수, 함수의 구분을 목적으로 삽입되기도 한다.
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt = 0;

int main(void)
{
    cout << SoSimple::simObjCnt << "번 째 SoSimple 객체" << endl;
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "번 째 SoSimple 객체" << endl;
    cout << sim1.simObjCnt << "번 째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번 째 SoSimple 객체" << endl;
    SoSimple::simObjCnt += 2;
    cout << SoSimple::simObjCnt << endl; 
    return 0;
}