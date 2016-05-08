#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Room.h"
#include "State.h"
#include "WumpusMap.h"
using namespace std;
void print_adjacent(int * a){
    cout << "adjacent rooms: " ;
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
}
void explore(){
    int i = 0;
    int pos = 0;
    srand(1338); // seed RNG
    State * state = new State();
    SuperBatHazard s;
    Event * e = &s;
    state->get_player_room()->set_event_at(0, e);

    // we really want this to say, for each event in this room.
    for (int i = 0; i < 4; i++){
        cout << i << endl;
        state->get_player_room()->get_event_at(i)->on_enter(state);   
    }
    
    
}



int main(){
    explore();
}

