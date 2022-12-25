#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

class Cell
{
private:
    char name;
    int x, y;

public:
    Cell();
    Cell(char name, int x, int y);
    char getName();
    int getX();
    int getY();
    void setName(char name);
    void setLocation(int x, int y);
    ~Cell();
};

class Champion : virtual public Cell
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Champion(char name);
    int getCurrentHP();
    void setCurrentHP(int hp);
    int getNumOfGems();
    void setNumOfGems(int gems);
    void printChampionInfo();
    virtual void useAbility();
    int getRemainingAbilityMoves();
    void setRemainingAbilityMoves(int x);
};

#pragma region ChampionChildren

class Mario : virtual public Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Mario();
    void useAbility();
    ~Mario();
};

class Luigi : virtual public Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Luigi();
    void useAbility();
    ~Luigi();
};

#pragma endregion

class Obstacle : virtual public Cell
{
private:
    char name;
    int x, y, amount;

public:
    Obstacle(char name, int x, int y);
    int getAmount();
    virtual void execute(Champion *champ);
    ~Obstacle();
};

#pragma region ObstacleChildren

class Bomb : virtual public Obstacle
{
private:
    char name;
    int x, y, amount;

public:
    Bomb(int x, int y);
    void execute(Champion *champ);
    ~Bomb();
};

class Thief : virtual public Obstacle
{
private:
    char name;
    int x, y, amount;

public:
    Thief(int x, int y);
    void execute(Champion *champ);
    ~Thief();
};

#pragma endregion

class Gem : virtual public Cell
{
private:
    char name;
    int x, y, amount;
public:
    Gem(int x, int y);
    int getAmount();
    virtual void execute(Champion *champ);
    ~Gem();
};

#pragma region GemChildren

class Coin : virtual public Gem
{
private:
    char name;
    int x, y, amount;
public:
    Coin(int x, int y);
    void execute(Champion *champ);
    ~Coin();
};

class Potion : virtual public Gem
{
private:
    char name;
    int x, y, amount;
public:
    Potion(int x, int y);
    void execute(Champion *champ);
    ~Potion();
};

#pragma endregion

#endif