
#include <stdlib.h>
#include "State.h"
#include "Map.h"
#include "WumpusMap.h"
State::State(){
    srand(1337);
    this->map = new WumpusMap();
    this->wumpus_pos = rand() % this->map->get_num_rooms();
    this->jc_pos = rand() % this->map->get_num_rooms();
    this->gold_pos = rand() % this->map->get_num_rooms();
    if (this->wumpus_pos == this->jc_pos){
        this->jc_pos = this->map->get_adjacent(this->wumpus_pos)[0];
    }
}
State::State(Map *m){
    this->map = m;     
}

State::~State(){
    delete [] this->map;

}

State& State::operator=(const State& other){
    State * state = new State();
    delete [] this->map;
    *this->map = *other.get_map();
    this->jc_pos = other.get_jc_pos();
    this->player_alive = other.get_player_alive();
    this->wumpus_pos = other.get_wumpus_pos();
    this->gold_found = other.get_gold_found();
    this->gold_pos = other.get_gold_pos();
    this->wumpus_alive = other.get_wumpus_alive();
    return *this;

}

State::State(const State& other){
    *this->map = *other.get_map();
    this->jc_pos = other.get_jc_pos();
    this->player_alive = other.get_player_alive();
    this->wumpus_pos = other.get_wumpus_pos();
    this->gold_found = other.get_gold_found();
    this->gold_pos = other.get_gold_pos();
    this->wumpus_alive = other.get_wumpus_alive();

}
Map * State::get_map() const{
    return this->map;
}

Room* State::get_player_room() const{ return this->map->get_room_at(this->jc_pos); }
int State::get_jc_pos() const{ return this->jc_pos; }
void State::set_jc_pos(int pos) { this->jc_pos = pos; }
int State::get_wumpus_pos() const{ return this->wumpus_pos; }
void State::set_wumpus_pos (int pos){ this->wumpus_pos = pos; }
int State::get_gold_pos() const{return this->gold_pos;}
void State::set_gold_pos(int pos){this->gold_pos = pos;}
bool State::get_player_alive() const{return this->player_alive;}
void State::set_player_alive(bool alive){this->player_alive = alive;}
bool State::get_wumpus_alive() const{return this->wumpus_alive;}
void State::set_wumpus_alive(bool alive){this->wumpus_alive = alive;}
bool State::get_gold_found() const{return this->gold_found;}
void State::set_gold_found(bool found){this->gold_found = found;}

