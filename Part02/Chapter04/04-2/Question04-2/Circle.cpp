#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

void Circle::Init(int x, int y, int r)
{
    radius = r;
    center.Init(x, y);
}

void Circle::ShowCircleInfo() const
{
    cout << "radius : " << radius << endl;
    center.ShowPointInfo();
}