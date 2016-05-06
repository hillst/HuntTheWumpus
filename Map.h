#include "Room.h"
//do we want to use int's or something more complicated?
class Map{
    private:
        int wumpus_pos;
        int jc_pos;
    protected:
        Room * rooms;
        int num_rooms;
    public:
        Map();
        ~Map(){
            delete [] rooms;
        }
        Map(const Map& old_map){
            this->rooms = new Room[old_map.get_num_rooms()];
            for(int i = 0; i < old_map.get_num_rooms(); i++){
                this->rooms[i] = *old_map.get_room_at(i);
            }
        }
        Map& operator=(const Map& other){
            delete [] this->rooms;
            Room * new_rooms = new Room[other.get_num_rooms()];
            for(int i = 0; i < other.get_num_rooms(); i++){
                new_rooms[i] = *other.get_room_at(i);
            }
            this->rooms = new_rooms;
            return *this;
        }
    
    public:
        virtual int* get_adjacent(int room_number);
        virtual Room* get_room_at(int room_number) const{return &this->rooms[room_number]; };
        virtual int get_wumpus_location(){ return this->wumpus_pos; };
        virtual void set_wumpus_location(int pos){ this->wumpus_pos = pos;};
        virtual int get_jc_location(){ return this->jc_pos;};
        virtual void set_jc_location(int pos){ this->jc_pos = pos; };
        int get_num_rooms() const{return this->num_rooms;}

};
