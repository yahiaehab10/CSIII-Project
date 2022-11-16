#ifndef Champion_H_Included
#define Champion_H_Included
#include "Point.h"

class Champion
{
private:
    string name;
    int maxHP, currentHP, gemsCollected;
    Point location;

public:
    Champion()
    {
        name = "Mario";
        maxHP = 100;
        currentHP = maxHP;
        location.setPoint(0, 0);
    }
    ~Champion();

    int getCurrentHP();
    void setCurrentHP(int hp);
    Point getLocation();
    void setLocation(Point p);
    int getNumOfGems();
    void setNumOfGems(int gems);
    void printChampionInfo();
};

#endif