#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Champion.h"

const int rows = 10;
const int cols = 10;

class Map
{
private:
    char **map;

public:
    Map(Champion* champ);

    void randomiseMap(Champion *champ);
    void printMap();
    char objectAt(int x, int y);
    ~Map();
};

#endif