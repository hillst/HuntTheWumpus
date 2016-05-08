#include "Event.h"
#include <string>


using namespace std;
Event::Event(){
    this->message = "";
    this->warning = "";
    this->percept = -1;
}
string Event::get_message(){ return this->message; }
void Event::set_message(string m){
    this->message = m;
}
int Event::get_percept(){
    return this->percept;
}
void Event::set_percept(int percept){
    this->percept = percept;
}   
void Event::set_warning(string w) {this->warning = w;}
string Event::get_warning() { return this->warning; }
void Event::on_enter(State * s){cout << this->message;} //what happens when you enter this tile.
void Event::when_adjacent(){cout << this->warning;} //what happens when you are adjacent to this tile


SuperBatHazard::SuperBatHazard(){
    this->set_message("ZAP--SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!\n");
    this->set_warning("You hear wings flapping.");
}
void SuperBatHazard::on_enter(State * s){
    // so While this
    cout << this->get_message();
    int random_pos = rand() % 20;
    s->set_jc_pos(random_pos);
    cout << "Jeremy Cole is now at position " << random_pos << endl;
}
