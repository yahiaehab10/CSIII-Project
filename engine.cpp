#include <bits/stdc++.h>
#include <conio.h>
#include "Engine.h"
#include "Map.h"

using namespace std;

Engine::Engine()
{
    c = new Champion();
    map = new Map();
}

Map *Engine::getMap()
{
    return map;
}

void Engine::controller(Champion *champ)
{
    while (champ->getCurrentHP() > 0 && champ->getNumOfGems() < 40)
    {
        map->setCell(champ->getX(), champ->getY(), 'O');
        int direction = getch();
        if (direction == 56) // 8
        {
            champ->setLocation(champ->getX() + 1, champ->getY());
            update(champ);
        }
        else if (direction == 54) // 6
        {
            champ->setLocation(champ->getX(), champ->getY() + 1);
            update(champ);
        }
        else if (direction == 53) // 5
        {
            champ->setLocation(champ->getX() - 1, champ->getY());
            update(champ);
        }
        else if (direction == 52) // 4
        {
            champ->setLocation(champ->getX(), champ->getY() - 1);
            update(champ);
        }
    }
}

void Engine::update(Champion *champ)
{
    if (map->objectAt(champ->getX(), champ->getY()) == 'G')
        champ->setNumOfGems(champ->getNumOfGems() + 1);

    else if (map->objectAt(champ->getX(), champ->getY()) == 'x')
        champ->setCurrentHP(champ->getCurrentHP() - 40);

    map->setCell(champ->getX(), champ->getY(), 'M');
    map->printMap();
    champ->printChampionInfo();
}

Champion *Engine::getChampion()
{
    return c;
}

Engine::~Engine()
{
    delete (c);
    delete (map);
}

int main()
{
    Engine *e = new Engine();
    Champion *champ = e->getChampion();

    int n;

    do
    {
        e->getMap()->randomiseMap();
        cout << "Enter 2 to re-randomise OR enter 1 to start the game: ";
        cin >> n;
        if (n == 1)
        {
            e->getMap()->setCell(0, 0, champ->getName());
            e->getMap()->printMap();
            champ->printChampionInfo();
            e->controller(champ);
        }
    } while (n == 2);

    return 0;
}
