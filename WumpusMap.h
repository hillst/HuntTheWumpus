#include <iostream>
#include "Map.h"
using namespace std;
class WumpusMap : public Map{
    public:
        WumpusMap();
    public:
        int* get_adjacent(int room_number) const;
};
