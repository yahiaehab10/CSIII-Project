
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
    virtual int getCurrentHP();
    virtual void setCurrentHP(int hp);
    virtual int getNumOfGems();
    virtual void setNumOfGems(int gems);
    virtual void printChampionInfo();
    virtual void useAbility();
    virtual int getRemainingAbilityMoves();
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
    char getName();
    int getX();
    int getY();
    int getCurrentHP();
    void setCurrentHP(int hp);
    void setLocation(int x, int y);
    void printChampionInfo();
    int getNumOfGems();
    void setNumOfGems(int gems);
    int getRemainingAbilityMoves();
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
    char getName();
    int getX();
    int getY();
    int getCurrentHP();
    void setCurrentHP(int hp);
    void setLocation(int x, int y);
    void printChampionInfo();
    int getNumOfGems();
    void setNumOfGems(int gems);
    int getRemainingAbilityMoves();
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
    int getAmount();
    virtual void execute(Champion *champ);
    ~Obstacle();
};

#pragma region ObstacleChildren

class Bomb : public Obstacle
{
private:

public:
    Bomb();
    void execute(Champion *champ);
    ~Bomb();
};

class Thief : public Obstacle
{
private:

public:
    Thief();
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
    int getAmount();
    virtual void execute(Champion *champ);
    ~Gem();
};

#pragma region GemChildren

class Coin : public Gem
{
private:

public:
    Coin();
    void execute(Champion *champ);
    ~Coin();
};

class Potion : public Gem
{
private:

public:
    Potion();
    void execute(Champion *champ);
    ~Potion();
};

#pragma endregion

#endif