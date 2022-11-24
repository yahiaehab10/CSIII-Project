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

Champion *Engine::getChampion()
{
    return c;
}

void Engine::controller()
{
    while (c->getCurrentHP() > 0 && c->getNumOfGems() < 40)
    {
        map->setCell(c->getX(), c->getY(), 'O');
        int direction = getch();

        if (direction == 56) // 8
            c->setLocation(c->getX() + 1, c->getY());

        else if (direction == 54) // 6
            c->setLocation(c->getX(), c->getY() + 1);

        else if (direction == 53) // 5
            c->setLocation(c->getX() - 1, c->getY());

        else if (direction == 52) // 4
            c->setLocation(c->getX(), c->getY() - 1);

        update();
    }

    if (c->getNumOfGems == 40)
        cout << "You Won! :D" << endl;
    else if (c->getCurrentHP == 0)
        cout << "You Lost! D:" << endl;
}

void Engine::update()
{
    if (map->objectAt(c->getX(), c->getY()) == 'G')
        c->setNumOfGems(c->getNumOfGems() + 1);

    else if (map->objectAt(c->getX(), c->getY()) == 'x')
        c->setCurrentHP(c->getCurrentHP() - 40);

    map->setCell(c->getX(), c->getY(), 'M');
    map->printMap();
    c->printChampionInfo();
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
    Map *map = e->getMap();

    int n;

    do
    {
        map->randomiseMap();
        cout << "Enter 2 to re-randomise OR enter 1 to start the game: ";
        cin >> n;
        if (n == 1)
        {
            map->setCell(0, 0, champ->getName());
            map->printMap();
            champ->printChampionInfo();
            e->controller();
        }
    } while (n == 2);

    // delete(map);
    // delete(champ);

    return 0;
}
