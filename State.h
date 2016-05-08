#ifndef STATE
#define STATE
#include <stdlib.h>
class Map;
class Room;
class State{
    private:
        int jc_pos;
        int wumpus_pos;
        int gold_pos;
        bool player_alive;
        bool wumpus_alive;
        bool gold_found;
        Map * map;
        
    public:
        State();
        State(Map *m);

        ~State();
        
        State& operator=(const State& other);

        State(const State& other);
        Map * get_map() const;
        Room* get_player_room() const;
        int get_jc_pos() const;
        void set_jc_pos(int pos);
        int get_wumpus_pos() const;
        void set_wumpus_pos (int pos);
        int get_gold_pos() const;
        void set_gold_pos(int pos);
        bool get_player_alive() const;
        void set_player_alive(bool alive);
        bool get_wumpus_alive() const;
        void set_wumpus_alive(bool alive);
        bool get_gold_found() const;
        void set_gold_found(bool found);
        
};
#endif
