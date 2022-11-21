#include <bits/stdc++.h>
#include "Champion.h"

using namespace std;

Champion::Champion()
{
    this->name = 'M';
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->x = 0;
    this->y = 0;
}

int Champion::getX()
{
    return x;
}

int Champion::getY()
{
    return y;
}

void Champion::setX(int x)
{
    if (x < 10 && x >= 0)
        this->x = x;
}

void Champion::setY(int y)
{
    if (y < 10 && y >= 0)
        this->y = y;
}

void Champion::setLocation(int x, int y)
{
    if (x < 10 && x >= 0)
        this->x = x;
    if (y < 10 && y >= 0)
        this->y = y;
}

char Champion::getName()
{
    return name;
}

int Champion::getCurrentHP()
{
    return currentHP;
}

void Champion::setCurrentHP(int hp)
{
    if (hp > this->maxHP)
        this->currentHP = this->maxHP;
    else if (hp < 0)
        this->currentHP = 0;
    else
        this->currentHP = hp;
}

int Champion::getNumOfGems()
{
    return gemsCollected;
}

void Champion::setNumOfGems(int gems)
{
    if (gems < 0)
        gemsCollected = 0;
    else
        gemsCollected = gems;
}

void Champion::printChampionInfo()
{
    cout << "Location: " << y << ", " << x << "\nGems Collected: " << gemsCollected << "\nHP: " << currentHP << "\nScore: " << gemsCollected * 10 << endl;
}