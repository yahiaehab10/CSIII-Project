#include <bits/stdc++.h>
#include "Champion.h"
#include "Map.h"
#include "Point.h"

using namespace std;

class engine
{
private:
     Map *map ;
     Champion c;
     Point p;
public:
    engine(){
        map = new Map();
    }
    ~engine();
};

int main()
{
    engine e();
}
