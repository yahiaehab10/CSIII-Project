#include <bits/stdc++.h>
using namespace std;

class Map
{
private:
    char **map;
    int rows = 10;
    int cols = 10;
public:
    Map()
    {
        map = new char *[rows]; // allocates 10 rows as pointers

        for (int i = 0; i < rows; i++) // allocates 10 columns per row
            map[i] = new char[cols];

        randomiseMap();
        printMap();
    }
    void randomiseMap()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                map[i][j] = 'O';
            }
        }
        for (int i = 0; i < 20; i++) // obstacle creation
        {
            int x = rand() % 10;
            int y = rand() % 10;

            if (map[x][y] == 'O' && !(x == 0 && y == 0)) // == null?
                map[x][y] = 'x';
            else
                i--;
        }

        for (int i = 0; i < 40; i++) // gem placement
        {
            int x = rand() % 10;
            int y = rand() % 10;

            if (map[x][y] == 'O' && !(x == 0 && y == 0)) // == null?
                map[x][y] = 'Y';
            else
                i--;
        }
    }
    void printMap()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << map[i][j] << ' ';
            }
            cout << "\n";
        }
    }
    ~Map();
};

class Point
{
private:
    int X, Y;

public:
    Point(int x, int y)
    {
        this->X = X;
        this->Y = Y;
    }
    Point()
    {
        this->X = 0;
        this->Y = 0;
    }
    void setPoint(int x, int y)
    {
        this->X = x;
        this->Y = y;
    }
    int getX()
    {
        return X;
    }
    int getY()
    {
        return Y;
    }
    ~Point();
};

class Champion
{
private:
    string name;
    int maxHP, currentHP, gemsCollected;
    Point *location;

public:
    Champion()
    {
        this->name = "Mario";
        this->maxHP = 100;
        this->currentHP = this->maxHP;
        this->gemsCollected = 0;
        this->location = new Point(0, 0);
    }
    int getCurrentHP()
    {
        return currentHP;
    }
    void setCurrentHP(int hp)
    {
        if (hp > this->maxHP)
            this->currentHP = this->maxHP;
        else if (hp < 0)
            this->currentHP = 0;
        else
            this->currentHP = hp;
    }
    Point getLocation()
    {
        return *location;
    }
    void setLocation(Point *p)
    {
        location = p;
    }
    int getNumOfGems()
    {
        return gemsCollected;
    }

    void setNumOfGems(int gems)
    {
        if (gems < 0)
            gemsCollected = 0;
        else
            gemsCollected = gems;
    }

    void printChampionInfo()
    {
        cout << "Name: " << name << "\nLocation: " << location->getX() << ", " << location->getY() << "\nGems Collected: " << gemsCollected << endl;
    }
    ~Champion();
};

int main(){
    Map *map = new Map();
}