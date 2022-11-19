#ifndef Champion_H_Included
#define Champion_H_Included
#include "Point.h"

using namespace std;

class Champion
{
private:
    string name;
    int maxHP, currentHP, gemsCollected;
    Point *location;

public:
    Champion();
    int getCurrentHP();
    void setCurrentHP(int hp);
    Point getLocation();
    void setLocation(Point *p);
    int getNumOfGems();
    void setNumOfGems(int gems);
    void printChampionInfo();
    ~Champion();
};

#endif