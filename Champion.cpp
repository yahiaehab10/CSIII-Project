#include <bits/stdc++.h>
#include <conio.h>

#include "Champion.h"

using namespace std;

Champion::Champion()
{
    this->name = 'C';
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->x = 0;
    this->y = 0;
    this->remainingAbilityMoves = 2;
}

Mario::Mario() : Champion()
{
    // cout << "Mario is created" << endl;
    this->name = 'M';
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->x = 0;
    this->y = 0;
    this->remainingAbilityMoves = 2;
}

Luigi::Luigi() : Champion()
{
    // cout << "Luigi is created" << endl;
    this->name = 'L';
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->x = 0;
    this->y = 0;
    this->remainingAbilityMoves = 2;
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

char Mario::getName()
{
    return name;
}

char Luigi::getName()
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
    cout << "Location: " << y << ", " << x << endl;
    cout << "Gems Collected: " << gemsCollected << endl;
    cout << "HP: " << currentHP << endl;
    cout << "Score: " << gemsCollected * 10 << endl;
    cout << "Remaining Ability Moves: " << remainingAbilityMoves << endl;
}

// void Mario::printChampionInfo()
// {
//     cout << "Mario" << endl;
//     cout << "Location: " << y << ", " << x << endl;
//     cout << "Gems Collected: " << gemsCollected << endl;
//     cout << "HP: " << currentHP << endl;
//     cout << "Score: " << gemsCollected * 10 << endl;
//     cout << "Remaining Ability Moves: " << remainingAbilityMoves << endl;
// }

// void Luigi::printChampionInfo()
// {
//     cout << "Luigi" << endl;
//     cout << "Location: " << y << ", " << x << endl;
//     cout << "Gems Collected: " << gemsCollected << endl;
//     cout << "HP: " << currentHP << endl;
//     cout << "Score: " << gemsCollected * 10 << endl;
//     cout << "Remaining Ability Moves: " << remainingAbilityMoves << endl;
// } WHY U NO WORK

void Champion::useAbility()
{
    cout << "Abilty X is called" << endl;
}

void Mario::useAbility()
{
    cout << "Mario ability is called" << endl;

    int direction = getch();

    if (direction == 56) // 8
        this->setLocation(this->getX() + 2, this->getY());

    else if (direction == 54) // 6
        this->setLocation(this->getX(), this->getY() + 2);

    else if (direction == 53) // 5
        this->setLocation(this->getX() - 2, this->getY());

    else if (direction == 52) // 4
        this->setLocation(this->getX(), this->getY() - 2);

    this->setRemainingAbilityMoves(this->getRemainingAbilityMoves() - 1);
}

void Luigi::useAbility()
{
        cout << "Luigi Ability is called" << endl;
        /* int direction = getch();
        if (direction == 56)
        {
            int curr = this->getY() + 1;
            while (curr != 9)
            {
                if (curr != 'G' && curr != 'O')
                    map->setCell(this->getX(), curr, 'O');
                curr++;
            }
        }
        else if (direction == 53)
        {
            int curr = this->getY() - 1;
            while (curr != 0)
            {
                if (curr != 'G' && curr != 'O')
                    map->setCell(this->getX(), curr, 'O');
                curr--;
            }
        }
        else if (direction == 54)
        {
            int curr = this->getX() + 1;
            while (curr != 9)
            {
                if (curr != 'G' && curr != 'O')
                    map->setCell(curr, this->getY(), 'O');
                curr++;
            }
        }
        else if (direction == 52)
        {
            int curr = this->getX() - 1;
            while (curr != 0)
            {
                if (curr != 'G' && curr != 'O')
                    map->setCell(curr, this->getY(), 'O');
                curr--;
            }
        }

        this->setRemainingAbilityMoves(this->getRemainingAbilityMoves() - 1); */
}

int Champion::getRemainingAbilityMoves()
{
    return this->remainingAbilityMoves;
}

void Champion::setRemainingAbilityMoves(int x)
{
    this->remainingAbilityMoves = x;
}