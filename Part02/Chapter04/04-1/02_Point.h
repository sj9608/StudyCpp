#ifndef __02_POINT_H__
#define __02_POINT_H__

class Point
{
private:
    int x;
    int y;

public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif