#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Ring.h"
using namespace std;

void Ring::Init(int x1, int y1, int rad1, int x2, int y2, int rad2)
{
    InnerCircle.Init(x1, y1, rad1);
    OutterCircle.Init(x2, y2, rad2);
}

void Ring::ShowRingInfo() const
{
    cout << "Inner Circle Info" << endl;
    InnerCircle.ShowCircleInfo();
    cout << "Outter Circle Info" << endl;
    OutterCircle.ShowCircleInfo();
}