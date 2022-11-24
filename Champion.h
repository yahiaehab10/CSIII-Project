#ifndef CHAMPION_H_INCLUDED
#define CHAMPION_H_INCLUDED

using namespace std;

class Champion
{
private:
    char name;
    int maxHP, currentHP, gemsCollected, x, y;

public:
    Champion();
    char getName();
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
};

#endif