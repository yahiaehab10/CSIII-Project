#include <bits/stdc++.h>
#include <conio.h>
#include "windows.h"

#include "Engine.h"

using namespace std;

Engine::Engine()
{
    this->chooseChampion();
    map = new Map();
}

void Engine::chooseChampion()
{
    cout << "Choose your champion (M for Mario, L for Luigi): " << endl;
    int input = getch();
    if (input == 77 || input == 109) // 77 and 109 is M in ASCII
        this->c = new Mario();
    else if (input == 76 || input == 108) // 76 and 108 is L in ASCII
        this->c = new Luigi();

    system("CLS");
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
        int input = getch();
        if ((input == 120 || input == 88) && c->getRemainingAbilityMoves() > 0) // 120 and 88 is X in ASCII
        {
            // map->setCell(c->getX(), c->getY(), new Cell());
            c->useAbility();
            if (c->getName() == 'L')
            {
                int direction = getch();
                if (direction == 54)
                {
                    int curr = c->getY() + 1;
                    while (curr <= 9)
                    {
                        if (map->objectAt(c->getX(), curr)->getName() == 'B' || map->objectAt(c->getX(), curr)->getName() == 'T')
                            map->setCell(c->getX(), curr, new Cell());
                        curr++;
                    }
                }
                else if (direction == 52)
                {
                    int curr = c->getY() - 1;
                    while (curr >= 0)
                    {
                        if (map->objectAt(c->getX(), curr)->getName() == 'B' || map->objectAt(c->getX(), curr)->getName() == 'T')
                            map->setCell(c->getX(), curr, new Cell());
                        curr--;
                    }
                }
                else if (direction == 56)
                {
                    int curr = c->getX() + 1;
                    while (curr <= 9)
                    {
                        if (map->objectAt(c->getX(), curr)->getName() == 'B' || map->objectAt(c->getX(), curr)->getName() == 'T')
                            map->setCell(curr, c->getY(), new Cell());
                        curr++;
                    }
                }
                else if (direction == 53)
                {
                    int curr = c->getX() - 1;
                    while (curr >= 0)
                    {
                        if (map->objectAt(c->getX(), curr)->getName() == 'B' || map->objectAt(c->getX(), curr)->getName() == 'T')
                            map->setCell(curr, c->getY(), new Cell());
                        curr--;
                    }
                }
            }
        }
        else
        {
            // map->setCell(c->getX(), c->getY(), new Cell());

            if (input == 56) // 8
                c->setLocation(c->getX() + 1, c->getY());

            else if (input == 54) // 6
                c->setLocation(c->getX(), c->getY() + 1);

            else if (input == 53) // 5
                c->setLocation(c->getX() - 1, c->getY());

            else if (input == 52) // 4
                c->setLocation(c->getX(), c->getY() - 1);
        }
        update();
    }

    if (c->getNumOfGems() >= 40)
    {
        cout << "You Won! :D" << endl;
        PlaySound(TEXT("Resources/Win.wav"), NULL, SND_FILENAME);
    }
    else if (c->getCurrentHP() <= 0)
    {
        cout << "You Lost! D:" << endl;
        PlaySound(TEXT("Resources/Death.wav"), NULL, SND_FILENAME);
    }
}

void Engine::update()
{
    if (map->objectAt(c->getX(), c->getY())->getName() == 'P')
    {
        Potion *temp = (Potion *)map->objectAt(c->getX(), c->getY());
        temp->execute(c);
    }
    // else if (map->objectAt(c->getX(), c->getY())->getName() == 'C')
    // {
    //     Coin *temp = (Coin *)map->objectAt(c->getX(), c->getY());
    //     temp->execute(c);
    // }
    // else if (map->objectAt(c->getX(), c->getY())->getName() == 'T')
    // {
    //     Thief *temp = (Thief *)map->objectAt(c->getX(), c->getY());
    //     temp->execute(c);
    // }
    // else if (map->objectAt(c->getX(), c->getY())->getName() == 'B')
    // {
    //     Bomb *temp = (Bomb *)map->objectAt(c->getX(), c->getY());
    //     temp->execute(c);
    // }

    c->setCurrentHP(c->getCurrentHP() - 1);

    // map->setCell(c->getX(), c->getY(), c);
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
            map->setCell(0, 0, champ);
            map->printMap();
            champ->printChampionInfo();
            e->controller();
        }
    } while (n == 2 || n != 1); // BUGS OUT AND INFINITELY LOOPS WHEN THE USER ENTERS A CHARACTER

    delete (e);

    return 0;
}
