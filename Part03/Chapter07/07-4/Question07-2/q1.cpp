#include <iostream>
#include <cstring>

using namespace std;

class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(int wid, int hei)
        : width(wid), height(hei)
    { }

    void ShowAreaInfo()
    {
        cout << "면적 : " << width * height << endl;
    }
};

class Square : public Rectangle
{
private:
    int length;
public:
    Square(int len)
        : Rectangle(len, len)
    { }
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}