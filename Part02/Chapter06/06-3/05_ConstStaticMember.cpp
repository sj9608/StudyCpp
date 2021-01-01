#include <iostream>
using namespace std;

class CountryArea
{
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

int main(void)
{
    cout << "러시아 면적: " << CountryArea::RUSSIA << "km" << endl;
    cout << "캐나다 면적 면적: " << CountryArea::CANADA << "km" << endl;
    cout << "중국 면적: " << CountryArea::CHINA << "km" << endl;
    cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "km" << endl;
    return 0;
}