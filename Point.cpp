#include <bits/stdc++.h>
#include "Point.h"

using namespace std;

// Point::setPoint(int a, int b) : X(a), Y(b) {}

Point::Point(int X, int Y)
{
    this->X = X;
    this->Y = Y;
}

Point::Point()
{
    this->X = 0;
    this->Y = 0;
}

void Point::setPoint(int x, int y)
{
    this->X = x;
    this->Y = y ;
}

int Point::getX()
{
    return X;
}

int Point::getY()
{
    return Y;
}