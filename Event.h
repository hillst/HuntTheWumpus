#include "State.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
class Event{
    private: 
        string message; // the message percieved when entering a tile
        string warning;
        int percept;
    
    public:
        Event();
        string get_message();
        void set_message(string m);
        int get_percept();
        void set_percept(int percept);
        void set_warning(string w);
        string get_warning();
        virtual void on_enter(State * s);
        virtual void when_adjacent();

};

class SuperBatHazard : public Event{
    public:
        SuperBatHazard();
        void on_enter(State * s);
};
