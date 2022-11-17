#include <iostream>
#include "Map.h"

Map::Map()
{
    // AAAAAAAAA
    map = new char *[rows]; // allocates 10 rows as pointers

    for (int i = 0; i < rows; i++) // allocates 10 columns per row
        map[i] = new char[cols];
}

Map ::void randomiseMap()
{
}

Map ::void printMap()
{
}

Map ::char objectAt(Point location)
{
}