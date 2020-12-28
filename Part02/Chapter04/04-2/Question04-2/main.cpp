#include "Point.h"
#include "Circle.h"
#include "Ring.h"

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}