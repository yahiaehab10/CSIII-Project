#include <bits/stdc++.h>
#include "Map.h"
#include "Champion.h"
#include "Engine.h"

using namespace std;

Map::Map(Champion *champ)
{
    map = new char *[10]; // allocates 10 rows as pointers

    for (int i = 0; i < 10; i++) // allocates 10 columns per row
        map[i] = new char[10];

    randomiseMap(champ);
    // printMap();
}

void Map::randomiseMap(Champion *champ)
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = 'O';
        }
    }

    map[9][0] = champ->getName();

    for (int i = 0; i < 20; i++) // obstacle creation
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (map[x][y] == 'O') // == null?
            map[x][y] = 'x';
        else
            i--;
    }

    for (int i = 0; i < 40; i++) // gem placement
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (map[x][y] == 'O') // == null?
            map[x][y] = 'G';
        else
            i--;
    }

    printMap();
    champ->printChampionInfo();

    int n;
    cout << "Enter 2 to re-randomise OR enter 1 to start the game: ";
    cin >> n;

    if (n == 2)
    {
        system("CLS");
        randomiseMap(champ);
    }
    else if (n == 1)
        Engine *e = new Engine(champ);
    else
        cout << "Invalid Input!";
}

void Map::printMap()
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

char Map::objectAt(int x, int y)
{
    return map[x][y];
}