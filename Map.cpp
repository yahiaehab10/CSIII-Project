#include <bits/stdc++.h>
#include "Map.h"
#include "Champion.h"

using namespace std;

Map::Map()
{
    c = new Champion();
    map = new char *[10]; // allocates 10 rows as pointers

    for (int i = 0; i < 10; i++) // allocates 10 columns per row
        map[i] = new char[10];

    randomiseMap(c);
}

void Map::setCell(int x, int y, char c)
{
    map[x][y] = c;
}

Champion *Map::getChampion()
{
    return c;
}

void Map::randomiseMap(Champion *champ)
{

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            map[i][j] = 'O';

    for (int i = 0; i < 20; i++) // obstacle creation
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (map[x][y] == 'O' && !(x == 0 && y == 0))
            map[x][y] = 'x';
        else
            i--;
    }

    for (int i = 0; i < 40; i++) // gem placement
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (map[x][y] == 'O' && !(x == 0 && y == 0))
            map[x][y] = 'G';
        else
            i--;
    }

    printMap();
}

void Map::printMap()
{
    system("CLS");
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
            cout << map[i][j] << ' ';

        cout << "\n";
    }
}

char Map::objectAt(int x, int y)
{
    return map[x][y];
}

// Map *Map::getMap()
// {
//     return this;
// }