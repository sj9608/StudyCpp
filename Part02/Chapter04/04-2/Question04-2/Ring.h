#ifndef __RING_H__
#define __RING_H__
#include "Circle.h"
#include "Point.h"

class Ring
{
private:
    Circle InnerCircle;
    Circle OutterCircle;
    
public:
    void Init(int x1, int y1, int rad1, int x2, int y2, int rad2);
    void ShowRingInfo() const;
};
#endif