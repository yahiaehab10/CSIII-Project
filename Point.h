#ifndef Point_H
#define Point_H

class Point
{
private:
    int X, Y;

public:
    Point(int X = 0, int Y = 0) : X(X), Y(Y) {}

    // ~Point() {}

    void setPoint(int a, int b);

    int getX();

    int getY();
};

#endif