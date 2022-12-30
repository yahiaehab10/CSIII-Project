#include <bits/stdc++.h>

#include "Map.h"

using namespace std;

Map::Map()
{
    board = new Cell **[10]; // allocates 10 rows as pointers

    for (int i = 0; i < 10; i++) // allocates 10 columns per row
        board[i] = new Cell*[10];

    randomiseMap();
}

Map* Map::getMap()
{
    return this;
}

void Map::setCell(int x, int y, Cell *c)
{
    board[x][y] = c;
}


void Map::randomiseMap()
{
    for (int i = 0; i < 10; i++) // initialises the board
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = new Cell();
        }
    }

    for (int i = 0; i < 10; i++) // bomb creation
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (board[x][y]->getName() == '.' && !(x == 0 && y == 0))
        {
            board[x][y] = new Bomb();
        }
        else
            i--;
    }

    for (int i = 0; i < 10; i++) // thief creation
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (board[x][y]->getName() == '.' && !(x == 0 && y == 0))
        {
            board[x][y] = new Thief();
        }
        else
            i--;
    }

    for (int i = 0; i < 20; i++) // coin placement
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (board[x][y]->getName() == '.' && !(x == 0 && y == 0))
        {
            board[x][y] = new Coin();
        }
        else
            i--;
    }

    for (int i = 0; i < 20; i++) // potion creation
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if (board[x][y]->getName() == '.' && !(x == 0 && y == 0))
        {
            board[x][y] = new Potion();
        }
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
            cout << board[i][j]->getName() << ' ';

        cout << "\n";
    }
}

Cell *Map::objectAt(int x, int y)
{
    return board[x][y];
}

Map::~Map()
{
    delete (board);
}