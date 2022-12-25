#include <bits/stdc++.h>
#include <math.h>
#include <conio.h>

#include "Cell.h"

using namespace std;

Cell::Cell()
{
    this->name = '.';
    this->x = 0;
    this->y = 0;
}

Cell::Cell(char name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;
}

char Cell::getName()
{
    return name;
}

int Cell::getX()
{
    return x;
}

int Cell::getY()
{
    return y;
}

void Cell::setName(char name)
{
    this->name = name;
}

void Cell::setLocation(int x, int y)
{
    if (x < 10 && x >= 0)
        this->x = x;
    if (y < 10 && y >= 0)
        this->y = y;
}

Gem::Gem(int x, int y) : Cell('G', x, y)
{
    srand(time(0));
    this->amount = rand() % 6 + 5;
}

int Gem::getAmount()
{
    return amount;
}

Coin::Coin(int x, int y) : Gem(x, y)
{
}

Potion::Potion(int x, int y) : Gem(x, y)
{
}

void Coin::execute(Champion *champ)
{
    cout << "Coin is executed with amount: " << this->amount << endl;
    champ->setNumOfGems(champ->getNumOfGems() + this->amount);
}

void Potion::execute(Champion *champ)
{
    cout << "Potion is executed with amount: " << this->amount << endl;
    champ->setCurrentHP(champ->getCurrentHP() + this->amount);
}

Obstacle::Obstacle(char name, int x, int y) : Cell(name, x, y)
{
    srand(time(0));
    this->amount = rand() % 5 + 1;
}

Bomb::Bomb(int x, int y) : Obstacle('B', x, y)
{
}

Thief::Thief(int x, int y) : Obstacle('T', x, y)
{
}

void Obstacle::execute(Champion *champ)
{
    cout << "Obstacle is executed" << endl;
}

void Bomb::execute(Champion *champ)
{
    cout << "Bomb is executed with amount: " << this->amount << endl;
    champ->setCurrentHP(champ->getCurrentHP() - this->amount);
}

void Thief::execute(Champion *champ)
{
    cout << "Thief is executed with amount: " << this->amount << endl;
    champ->setNumOfGems(champ->getNumOfGems() - this->amount);
}

int Obstacle::getAmount()
{
    return amount;
}

Champion::Champion(char name) : Cell(name, 0, 0)
{
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->remainingAbilityMoves = 2;
}

Mario::Mario() : Champion('M')
{
}

Luigi::Luigi() : Champion('L')
{
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
}

int Champion::getRemainingAbilityMoves()
{
    return this->remainingAbilityMoves;
}

void Champion::setRemainingAbilityMoves(int x)
{
    this->remainingAbilityMoves = x;
}