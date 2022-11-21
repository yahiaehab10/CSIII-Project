#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Champion.h"
#include "Engine.h"

using namespace std;

const int rows = 10;
const int cols = 10;

class Map
{
private:
    char **map;

public:
    Map(Champion *champ, Engine *engine);

    void randomiseMap(Champion *champ, Engine *engine);
    void setCell(int x, int y, char c);
    void printMap();
    char objectAt(int x, int y);
    ~Map();
};

#endif