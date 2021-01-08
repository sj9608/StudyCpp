#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator-()
    {
        Point pos(xpos*(-1), ypos*(-1));
        return pos;
    }
    friend Point operator~(Point& ref);
};

Point operator~(Point& ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main(void)
{
    Point pos1(3,4);
    Point pos2(10, 20);

    Point pos3 = -pos1;
    Point pos4 = ~pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    pos4.ShowPosition();

    return 0;
}
