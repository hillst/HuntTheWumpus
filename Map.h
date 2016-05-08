#ifndef MAP
#define MAP
#include "Room.h"
//do we want to use int's or something more complicated?
class Map{
    protected:
        Room * rooms;
        int num_rooms;
    public:
        Map();
        ~Map();
        Map(const Map& old_map);
        Map& operator=(const Map& other);
    
    public:
        virtual int* get_adjacent(int room_number) const =0;
        virtual Room* get_room_at(int room_number) const;
        int get_num_rooms() const;

};
#endif
