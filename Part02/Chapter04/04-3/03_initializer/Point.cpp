#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos)
{
    x = xpos;
    y = ypos;
}

int Point::GetX() const {return x;}
int Point::GetY() const {return y;}

bool Point::SetX(int xpos)
{
    if(0 > xpos || 100 < xpos)
    {
        return false;
    }
    x= xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if(0 > ypos || 100 < ypos)
    {
        return false;
    }
    y = ypos;
    return true;
}