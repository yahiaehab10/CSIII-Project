#include <bits/stdc++.h>
#include <conio.h>
#include "Map.h"

using namespace std;

Engine::Engine()
{
    c = new Champion();
    map = new Map(c, this);
};

// Engine::Engine(Champion *champ)
// {
//     controller(champ);
// }

void Engine::controller(Champion *champ)
{
    while (champ->getCurrentHP() > 0 || champ->getNumOfGems() < 40)
    {
        int direction = getch();
        if (direction == 56)
        {
            champ->setLocation(champ->getX(), champ->getY() + 1);
            update(champ);
        }
        else if (direction == 54)
        {
            champ->setLocation(champ->getX() + 1, champ->getY());
            update(champ);
        }
        else if (direction == 53)
        {
            champ->setLocation(champ->getX(), champ->getY() - 1);
            update(champ);
        }
        else if (direction == 52)
        {
            champ->setLocation(champ->getX() - 1, champ->getY());
            update(champ);
        }
        map->setCell(champ->getX(), champ->getY(), 'O');
    }
}

void Engine::update(Champion *champ)
{
    if (map->objectAt(champ->getX(), champ->getY()) == 'G')
        champ->setNumOfGems(champ->getNumOfGems() + 1);
    else if (map->objectAt(champ->getX(), champ->getY()) == 'x')
        champ->setCurrentHP(champ->getCurrentHP() - 40);

    map->setCell(champ->getX(), champ->getY(), 'M');
    system("CLS");
    map->printMap();
}

int main()
{
    new Engine();
    return 0;
}
