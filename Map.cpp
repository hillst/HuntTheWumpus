
#include "Map.h"
//do we want to use int's or something more complicated?
Map::Map(){
}
Map::~Map(){
    delete [] rooms;
}
Map::Map(const Map& old_map){
    this->rooms = new Room[old_map.get_num_rooms()];
    for(int i = 0; i < old_map.get_num_rooms(); i++){
        this->rooms[i] = *old_map.get_room_at(i);
    }
}
Map& Map::operator=(const Map& other){
    delete [] this->rooms;
    Room * new_rooms = new Room[other.get_num_rooms()];
    for(int i = 0; i < other.get_num_rooms(); i++){
        new_rooms[i] = *other.get_room_at(i);
    }
    this->rooms = new_rooms;
    return *this;
}

Room* Map::get_room_at(int room_number) const{return &this->rooms[room_number]; }
int Map::get_num_rooms() const{return this->num_rooms;}

