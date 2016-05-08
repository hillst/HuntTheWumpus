#include "Room.h"
Room::Room(){
    this->contains_wumpus = false;
    this->contains_player = false;
    this->contains_hazard = false;
    //wumpus, hazard, gold, rope, by default these should all be empty.
    this->events = new Event*[4]; // this should be adjusted most likely
    for(int i =0; i < 4; i++){
        this->events[i] = new Event();
    }
}

Room::~Room(){
    delete [] this->events;
}

Room::Room(Room& other){
    this->events = new Event*[4];
    for (int i = 0; i < 4; i++){
        this->events[0] = other.get_event_at(i);
    }
    this->contains_wumpus = other.has_wumpus(); 
    this->contains_player = other.has_player();
    this->contains_hazard = other.has_hazard();
}

Room& Room::operator=(const Room& other){
    delete [] this->events;
    this->events = new Event*[4];
    for (int i = 0; i < 4; i++){
        this->events[0] = other.get_event_at(i);
    }
    this->contains_wumpus = other.has_wumpus();
    this->contains_player = other.has_player();
    this->contains_hazard = other.has_hazard();
    return *this;
}
int Room::get_num_events(){
    return 4; //ahue
}
Event * Room::get_event_at(int idx) const{ return this->events[idx]; }
void Room::set_event_at(int idx, Event * e){ 
    this->events[idx] = e; 

}
bool Room::has_wumpus() const{ return this->contains_wumpus; }
bool Room::has_player() const{ return this->contains_player; } 
bool Room::has_hazard() const{ return this->contains_hazard; }
void Room::set_hazard(bool haz){ this->contains_hazard = haz; }
void Room::set_player(bool p){ this->contains_player = p; }
void Room::set_wumpus(bool w){ this->contains_wumpus = w; }

