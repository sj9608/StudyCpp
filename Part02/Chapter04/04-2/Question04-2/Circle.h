#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include "Point.h"

class Circle
{
private:
    Point center;
    int radius;
public:
    void Init(int x, int y, int r);
    void ShowCircleInfo() const;
};
#endif