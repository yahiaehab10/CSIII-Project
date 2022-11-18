#include <bits/stdc++.h>
#include "Map.h"

using namespace std;

Map::Map()
{
    map = new char *[rows]; // allocates 10 rows as pointers

    for (int i = 0; i < rows; i++) // allocates 10 columns per row
        map[i] = new char[cols];

    randomiseMap();
    printMap();
}

Map::randomiseMap()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = 'O';
        }
    }
    for (int i = 0; i < 20; i++) // obstacle creation
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (map[x][y] == 'O' && !(x == 0 && y == 0)) // == null?
            map[x][y] = 'x';
        else
            i--;
    }

    for (int i = 0; i < 40; i++) // gem placement
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (map[x][y] == 'O' && !(x == 0 && y == 0)) // == null?
            map[x][y] = 'Y';
        else
            i--;
    }
}

Map::printMap()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << "\n";
    }
}

// Map::objectAt(Point location)
// {
// }

int main()
{
    Map *map = new Map();
    return 0;
}
