#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "Map.h"

using namespace std;

class Engine
{
private:
    Map *map;
    Champion *c;

public:
    Engine();
    void controller(Champion *champ);
    void update(Champion *champ);
    ~Engine();
};

#endif