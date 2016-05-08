#ifndef ROOM
#define ROOM
#include "Event.h"
class Room{
    private:
        bool contains_wumpus;
        bool contains_player;
        bool contains_hazard;
        Event ** events;
    public:
        Room();
        ~Room();
        Room(Room& other);
        Room& operator=(const Room& other);
        int get_num_events();
        Event * get_event_at(int idx) const;
        void set_event_at(int idx, Event * e);
        bool has_wumpus() const;
        bool has_player() const;
        bool has_hazard() const;
        void set_hazard(bool haz);
        void set_player(bool p);
        void set_wumpus(bool w);
    
};
#endif
