#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "Map.h"

class Engine
{
private:
    Map *map;
    Champion *c;

public:
    Engine();
    void chooseChampion();
    void controller();
    void update();
    Map *getMap();
    Champion *getChampion();
    ~Engine();
};

#endif