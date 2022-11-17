#include <bits/stdc++.h>
#include "Champion.h"


Champion::getCurrentHP()
{
    return currentHP;
}

Champion::setCurrentHP(int hp)
{
    if (hp > this->maxHP)
        this->currentHP = this->maxHP;
    else if (hp < 0)
        this->currentHP = 0;
    else
        this->currentHP = hp;
}

Champion::getLocation()
{
    return location;
}

Champion::setLocation(Point p)
{
    location = p;
}

Champion::getNumOfGems()
{
    return gemsCollected;
}

Champion::setNumOfGems(int gems)
{
    if (gems < 0)
        gemsCollected = 0;
    else
        gemsCollected = gems;
}

Champion::void printChampionInfo()
{
    cout << "Name: " << name << "\nLocation: " << location << "\nGems Collected: " << gemsCollected << endl;
}