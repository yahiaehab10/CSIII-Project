#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include "Champion.h"
#include "Map.h"
using namespace std;

class Engine
{
private:
    Map *map;
    Champion *c;

public:
    Engine();
    Engine(Champion *champ);
    void controller(Champion *champ);
    void update(Champion *champ);
    ~Engine();
};

#endif