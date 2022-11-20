#include <bits/stdc++.h>
#include <conio.h>
#include "Champion.h"
#include "Map.h"
#include "Engine.h"

using namespace std;

Engine::Engine()
{
    c = new Champion();
    map = new Map(c);
};

Engine::Engine(Champion *champ)
{
    controller(champ);
}

void Engine::controller(Champion *champ)
{
    while (champ->getCurrentHP() > 0 || champ->getNumOfGems() < 40)
    {
        int direction = getch();
        switch (direction)
        {
        case 56:
            (*map).map[champ->getX()][champ->getY()] = 'O';
            champ->setLocation(champ->getX(), ++champ->getY());
            update(champ);
            break;

        case 54:
            (*Map).map[champ->getX()][champ->getY()] = 'O';
            champ->setLocation(++champ->getX(), champ->getY());
            update(champ);
            break;

        case 53:
            (*Map).map[champ->getX()][champ->getY()] = 'O';
            champ->setLocation(champ->getX(), --champ->getY());
            update(champ);
            break;

        case 52:
            map[champ->getX()][champ->getY()] = 'O';
            champ->setLocation(--champ->getX(), champ->getY());
            update(champ);
            break;

        default:
            break;
        }
    }
}

void Engine::update(Champion *champ)
{
    if (map->objectAt(champ->getX(), champ->getY()) == 'G')
    {
        champ->setNumOfGems(champ->getNumOfGems()++);
        map[champ->getX()][champ->getY()] = 'M';
    }
    else if (map->objectAt(champ->getX(), champ->getY()) == 'x')
    {
        champ->setCurrentHP(champ->getCurrentHP() - 40);
        map[champ->getX()][champ->getY()] = 'M';
    }
    system("CLS");
    map->printMap();
}

int main()
{
    new Engine();
    return 0;
}
