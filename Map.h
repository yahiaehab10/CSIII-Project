#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Point.h"

const int rows = 10;
const int cols = 10;

class Map
{
private:
    char **map;
    // char[][] map;

public:
    Map();

    void randomiseMap();
    void printMap();
    char objectAt(Point location);
    // int randomiseMap();
    // int printMap();
    // int objectAt(Point location);
    ~Map();
};

#endif