#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Point.h"

class Map
{
private:
    char *map;

public:
    Map()
    {
        map = (char*)malloc(100 * sizeof(char)); // AAAAAAAAA
    }
    ~Map();

    void randomiseMap();
    void printMap();
    char objectAt(Point location);
};

/*public void placeCovers() {
        int i = 0;
        while (i < 5) {
            int x = (int) (Math.random() * 3) + 1;
            int y = (int) (Math.random() * 5);
            if (board[x][y] == null) {
                board[x][y] = new Cover(x, y);
                i++;
            }
        }
    }*/
#endif