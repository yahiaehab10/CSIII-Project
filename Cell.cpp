#include <bits/stdc++.h>
#include <math.h>
#include <conio.h>

#include "Cell.h"

using namespace std;

Cell::Cell()
{
    this->name = '.';
}

Cell::Cell(char name)
{
    this->name = name;
}

void Cell::setName(char name)
{
    this->name = name;
}

char Cell::getName()
{
    return name;
}

Cell::~Cell()
{
}

Champion::Champion(char name) : Cell(name)
{
    this->name = name;
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->x = 0;
    this->y = 0;
    this->remainingAbilityMoves = 2;
}

char Champion::getName()
{
    return name;
}

int Champion::getX()
{
    return x;
}

int Champion::getY()
{
    return y;
}

void Champion::setLocation(int x, int y)
{
    if (x < 10 && x >= 0)
        this->x = x;
    if (y < 10 && y >= 0)
        this->y = y;
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
    this->gemsCollected = gems;
}

void Champion::printChampionInfo()
{
    cout << "Champion: " << this->name << endl;
    cout << "Location: " << this->x << ", " << this->y << endl;
    cout << "HP: " << this->currentHP << endl;
    cout << "Gems: " << this->gemsCollected << endl;
    cout << "Remaining ability moves: " << this->remainingAbilityMoves << endl;
}

void Champion::useAbility()
{
    cout << "Ability X is used" << endl;
}

int Champion::getRemainingAbilityMoves()
{
    return this->remainingAbilityMoves;
}

void Champion::setRemainingAbilityMoves(int x)
{
    this->remainingAbilityMoves = x;
}

Mario::Mario() : Champion('M')
{
    this->name = 'M';
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->remainingAbilityMoves = 2;
}

void Mario::useAbility()
{
    cout << "Mario ability is called" << endl;

    int direction = getch();

    if (direction == 56) // 8
        this->x += 2;
    // this->setLocation(this->getX() + 2, this->getY());

    else if (direction == 54) // 6
        this->y += 2;
    // this->setLocation(this->getX(), this->getY() + 2);

    else if (direction == 53) // 5
        this->x -= 2;
    // this->setLocation(this->getX() - 2, this->getY());

    else if (direction == 52) // 4
        this->y -= 2;
    // this->setLocation(this->getX(), this->getY() - 2);

    this->remainingAbilityMoves--;
}

char Mario::getName()
{
    return this->name;
}

int Mario::getX()
{
    return this->x;
}

int Mario::getY()
{
    return this->y;
}

int Mario::getCurrentHP()
{
    return this->currentHP;
}

void Mario::setCurrentHP(int hp)
{
    if (hp > this->maxHP)
        this->currentHP = this->maxHP;
    else if (hp < 0)
        this->currentHP = 0;
    else
        this->currentHP = hp;
}

void Mario::setLocation(int x, int y)
{
    if (x < 10 && x >= 0)
        this->x = x;
    if (y < 10 && y >= 0)
        this->y = y;
}

void Mario::printChampionInfo()
{
    cout << "Champion: " << this->name << endl;
    cout << "Location: " << this->x << ", " << this->y << endl;
    cout << "HP: " << this->currentHP << endl;
    cout << "Gems: " << this->gemsCollected << endl;
    cout << "Remaining ability moves: " << this->remainingAbilityMoves << endl;
}

int Mario::getNumOfGems()
{
    return this->gemsCollected;
}

void Mario::setNumOfGems(int gems)
{
    this->gemsCollected = gems;
}

int Mario::getRemainingAbilityMoves()
{
    return this->remainingAbilityMoves;
}

Mario::~Mario()
{
}

Luigi::Luigi() : Champion('L')
{
    this->name = 'L';
    this->maxHP = 100;
    this->currentHP = this->maxHP;
    this->gemsCollected = 0;
    this->remainingAbilityMoves = 2;
}

void Luigi::useAbility()
{
    cout << "Luigi ability is called" << endl;
    this->remainingAbilityMoves--;
}

char Luigi::getName()
{
    return this->name;
}

int Luigi::getX()
{
    return this->x;
}

int Luigi::getY()
{
    return this->y;
}

int Luigi::getCurrentHP()
{
    return this->currentHP;
}

void Luigi::setCurrentHP(int hp)
{
    if (hp > this->maxHP)
        this->currentHP = this->maxHP;
    else if (hp < 0)
        this->currentHP = 0;
    else
        this->currentHP = hp;
}

void Luigi::setLocation(int x, int y)
{
    if (x < 10 && x >= 0)
        this->x = x;
    if (y < 10 && y >= 0)
        this->y = y;
}

void Luigi::printChampionInfo()
{
    cout << "Champion: " << this->name << endl;
    cout << "Location: " << this->x << ", " << this->y << endl;
    cout << "HP: " << this->currentHP << endl;
    cout << "Gems: " << this->gemsCollected << endl;
    cout << "Remaining ability moves: " << this->remainingAbilityMoves << endl;
}

int Luigi::getNumOfGems()
{
    return this->gemsCollected;
}

void Luigi::setNumOfGems(int gems)
{
    this->gemsCollected = gems;
}

int Luigi::getRemainingAbilityMoves()
{
    return this->remainingAbilityMoves;
}

Luigi::~Luigi()
{
}

Obstacle::Obstacle(char name) : Cell(name)
{
    this->amount = rand() % 6 + 5;
    this->name = name;
}

int Obstacle::getAmount()
{
    return this->amount;
}

void Obstacle::execute(Champion *champ)
{
    cout << "Obstacle is executed with amount: " << this->amount << endl;
}

Obstacle::~Obstacle()
{
}

Bomb::Bomb() : Obstacle('B')
{
}

void Bomb::execute(Champion *champ)
{
    cout << "Bomb is executed with amount: " << this->getAmount() << endl;
    champ->setCurrentHP(champ->getCurrentHP() - this->getAmount());
}

Bomb::~Bomb()
{
}

Thief::Thief() : Obstacle('T')
{
}

void Thief::execute(Champion *champ)
{
    cout << "Thief is executed with amount: " << this->getAmount() << endl;
    champ->setNumOfGems(champ->getNumOfGems() - this->getAmount());
}

Thief::~Thief()
{
}

Gem::Gem(char name) : Cell(name)
{
    srand(time(0));
    this->amount = rand() % 6 + 5;
}

int Gem::getAmount()
{
    return this->amount;
}

void Gem::execute(Champion *champ)
{
    cout << "Gem is executed with amount: " << this->amount << endl;
}

Gem::~Gem()
{
}

Coin::Coin() : Gem('C')
{
}

void Coin::execute(Champion *champ)
{
    cout << "Coin is executed with amount: " << this->getAmount() << endl;
    champ->setNumOfGems(champ->getNumOfGems() + this->getAmount());
}

Coin::~Coin()
{
}

Potion::Potion() : Gem('P')
{
}

void Potion::execute(Champion *champ)
{
    cout << "Potion is executed with amount: " << this->getAmount() << endl;
    champ->setCurrentHP(champ->getCurrentHP() + this->getAmount());
}

Potion::~Potion()
{
}