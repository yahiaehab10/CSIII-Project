#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Point.h"

const int rows = 10;
const int cols = 10;

class Map
{
private:
    char **map;

public:
    Map()
    {
        // map = (char*)malloc(100 * sizeof(char)); // AAAAAAAAA
        map = new char*[rows]; // allocates 10 rows as pointers

        for (int i = 0; i < rows; i++) // allocates 10 columns per row
            map[i] = new char[cols];
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