#ifndef Point_H
#define Point_H

class Point
{
private:
    int X, Y;

public:
    Point(int X, int Y);
    Point();
    // ~Point() {}

    void setPoint(int a, int b);

    int getX();

    int getY();
};

#endif