#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(const int &xpos, const int &ypos)
        : x(xpos), y(ypos)
    {
    }
    void ShowPointInfo() const
    {
        cout << x << ", " << y << endl;
    }
};

class Circle
{
private:
    Point center;
    int radius;
public:
    Circle(int x, int y, int r) 
        : center(x,y), radius(r)
    {
    }
    void ShowCircleInfo() const
    {
        cout << "radius : " << radius << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle InnerCircle;
    Circle OutterCircle;
public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2)
        : InnerCircle(x1, y1, r1), OutterCircle(x2, y2, r2)
    {
    }
    void ShowRingInfo() const
    {
        cout << "Inner Circle..." << endl;
        InnerCircle.ShowCircleInfo();

        cout << "Outter Circle..." << endl;
        OutterCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring * ring = new Ring(1,1,4,2,2,9);
    ring->ShowRingInfo();

    delete ring;
    return 0;
}