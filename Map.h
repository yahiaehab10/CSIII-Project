#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

using namespace std;

class Map
{
private:
    char **map;

public:
    Map();
    Map *getMap();
    void randomiseMap();
    void setCell(int x, int y, char c);
    void printMap();
    char objectAt(int x, int y);
    ~Map();
};

#endif