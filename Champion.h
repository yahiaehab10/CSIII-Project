#ifndef CHAMPION_H_INCLUDED
#define CHAMPION_H_INCLUDED

class Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Champion();
    virtual char getName();
    int getCurrentHP();
    void setCurrentHP(int hp);
    int getX();
    int getY();
    void setLocation(int x, int y);
    void setX(int x);
    void setY(int y);
    int getNumOfGems();
    void setNumOfGems(int gems);
    void printChampionInfo();
    virtual void useAbility();
    int getRemainingAbilityMoves();
    void setRemainingAbilityMoves(int x);
};

class Mario : virtual public Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y, remainingAbilityMoves;

public:
    Mario();
    void useAbility();
    char getName();
    // void printChampionInfo();
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
    // void printChampionInfo();
    ~Luigi();
};

#endif