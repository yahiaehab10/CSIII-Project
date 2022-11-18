#include <bits/stdc++.h>
#include "Champion.h"

using namespace std;

Champion::Champion()
{
    this->name = "Mario";
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->location = new Point(0, 0);
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

Point Champion::getLocation()
{
    return *location;
}

void Champion::setLocation(Point *p)
{
    location = p;
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
    cout << "Name: " << name << "\nLocation: " << location->getX() << ", " << location->getY() << "\nGems Collected: " << gemsCollected << endl;
}