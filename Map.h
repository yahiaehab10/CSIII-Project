#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Champion.h"

using namespace std;

const int rows = 10;
const int cols = 10;

class Map
{
private:
    char **map;
    Champion *c;

public:
    Map();

    Champion *getChampion();
    Map *getMap();
    void randomiseMap(Champion *champ);
    void setCell(int x, int y, char c);
    void printMap();
    char objectAt(int x, int y);
    ~Map();
};

#endif