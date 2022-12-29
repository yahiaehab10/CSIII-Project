#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Cell.h"

class Map
{
private:
    Cell* **board;

public:
    Map();
    Map *getMap();
    void randomiseMap();
    void setCell(int x, int y, Cell *c);
    void printMap();
    Cell *objectAt(int x, int y);
    ~Map();
};

#endif