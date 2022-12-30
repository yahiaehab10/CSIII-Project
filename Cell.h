
#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

class Cell
{
private:
    char name;

public:
    Cell();
    Cell(char name);
    void setName(char name);
    virtual char getName();
    ~Cell();
};

class Champion : public Cell
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Champion(char name);
    virtual char getName();
    virtual int getX();
    virtual int getY();
    virtual void setLocation(int x, int y);
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

class Mario : public Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Mario();
    void useAbility();
    char getName();
    int getX();
    int getY();
    void setLocation(int x, int y);
    ~Mario();
};

class Luigi : public Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Luigi();
    void useAbility();
    char getName();
    int getX();
    int getY();
    void setLocation(int x, int y);
    ~Luigi();
};

#pragma endregion

class Obstacle : public Cell
{
private:
    char name;
    int amount;

public:
    Obstacle(char name);
    virtual int getAmount();
    virtual void execute(Champion *champ);
    ~Obstacle();
};

#pragma region ObstacleChildren

class Bomb : public Obstacle
{
private:
    char name;
    int amount;

public:
    Bomb();
    int getAmount();
    void execute(Champion *champ);
    ~Bomb();
};

class Thief : public Obstacle
{
private:
    char name;
    int amount;

public:
    Thief();
    int getAmount();
    void execute(Champion *champ);
    ~Thief();
};

#pragma endregion

class Gem : public Cell
{
private:
    char name;
    int amount;
public:
    Gem(char name);
    virtual int getAmount();
    virtual void execute(Champion *champ);
    ~Gem();
};

#pragma region GemChildren

class Coin : public Gem
{
private:
    char name;
    int amount;
public:
    Coin();
    int getAmount();
    void execute(Champion *champ);
    ~Coin();
};

class Potion : public Gem
{
private:
    char name;
    int amount;
public:
    Potion();
    int getAmount();
    void execute(Champion *champ);
    ~Potion();
};

#pragma endregion

#endif