#include <bits/stdc++.h>
#include <conio.h>
#include "windows.h"

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
    PlaySound(TEXT("Resources/Theme.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    while (c->getCurrentHP() > 0 && c->getNumOfGems() < 40)
    {
        int ability = getch();
        if ((ability == 120 || ability == 88) && c->remainingAbilityMoves != 0) // 120 and 88 is X on ascii
        {
            int direction = getch();
            if (c->getName() == 'M')
            {
                map->setCell(c->getX(), c->getY(), 'O');
                int direction = getch();

                if (direction == 56) // 8
                    c->setLocation(c->getX() + 2, c->getY());

                else if (direction == 54) // 6
                    c->setLocation(c->getX(), c->getY() + 2);

                else if (direction == 53) // 5
                    c->setLocation(c->getX() - 2, c->getY());

                else if (direction == 52) // 4
                    c->setLocation(c->getX(), c->getY() - 2);
            }
            else
            {
                int direction = getch();
                if (direction == 56)
                {
                    int curr = c->getY() + 1;
                    while (curr != 9)
                    {
                        if (curr != 'G' && curr != 'O')
                            map->setCell(c->getX(), curr, 'O');
                        curr++;
                    }
                }
                else if (direction == 53)
                {
                    int curr = c->getY() - 1;
                    while (curr != 0)
                    {
                        if (curr != 'G' && curr != 'O')
                            map->setCell(c->getX(), curr, 'O');
                        curr--;
                    }
                }
                else if (direction == 54)
                {
                    int curr = c->getX() + 1;
                    while (curr != 9)
                    {
                        if (curr != 'G' && curr != 'O')
                            map->setCell(curr, c->getY(), 'O');
                        curr++;
                    }
                }
                else if (direction == 52)
                {
                    int curr = c->getX() - 1;
                    while (curr != 0)
                    {
                        if (curr != 'G' && curr != 'O')
                            map->setCell(curr, c->getY(), 'O');
                        curr--;
                    }
                }
            }
            c->remainingAbilityMoves--;
        }
        else
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
        }
        update();
    }

    if (c->getNumOfGems() == 40)
    {
        cout << "You Won! :D" << endl;
        PlaySound(TEXT("Resources/Win.wav"), NULL, SND_FILENAME);
    }
    else if (c->getCurrentHP() == 0)
    {
        cout << "You Lost! D:" << endl;
        PlaySound(TEXT("Resources/Death.wav"), NULL, SND_FILENAME);
    }
}

void Engine::update()
{
    if (map->objectAt(c->getX(), c->getY()) == 'G')
        c->setNumOfGems(c->getNumOfGems() + 1);

    else if (map->objectAt(c->getX(), c->getY()) == 'x')
        c->setCurrentHP(c->getCurrentHP() - 40);

    if (c->getName() == 'M')
        map->setCell(c->getX(), c->getY(), 'M');
    else
        map->setCell(c->getX(), c->getY(), 'L');

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
    } while (n == 2 || n != 1); // BUGS OUT AND INFINITELY LOOPS WHEN THE USER ENTERS A CHARACTER

    // delete(map);
    // delete(champ);

    return 0;
}
