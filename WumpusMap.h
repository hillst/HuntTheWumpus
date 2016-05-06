#include "Map.h"
#include <iostream>
using namespace std;
class WumpusMap : public Map{
    public:
        WumpusMap(){
            this->rooms = new Room[20];
            this->num_rooms = 20;
            cout << "hello from wumpus map" << endl;
        }

    public:
        int* get_adjacent(int room_number){
            // returns the index of the adjacent rooms. no error checking.
            // Horrible explicit code to represent a dedecahedron.
            int * adjacent = new int[3];
            if (room_number == 4){
                adjacent[0] = 0;
                adjacent[1] = 3;
                adjacent[2] = 9;
                return adjacent;
            }
            if (room_number == 0){
                adjacent[0] = 4;
                adjacent[1] = 1;
                adjacent[2] = 5;
                return adjacent;
            }
            if (room_number == 5){
                adjacent[0] = 10;
                adjacent[1] = 14;
                adjacent[2] = 0;
                return adjacent;
            }
            if (room_number == 14){
                adjacent[0] = 19;
                adjacent[1] = 5;
                adjacent[2] = 9;
                return adjacent;
            }
            if (room_number == 15){
                adjacent[0] = 16;
                adjacent[1] = 19;
                adjacent[2] = 10;
                return adjacent;
            }
            if (room_number == 19){
                adjacent[0] = 15;
                adjacent[1] = 18;
                adjacent[2] = 14;
                return adjacent;
            }
            if (room_number < 5){
                adjacent[0] = room_number - 1;
                adjacent[1] = room_number + 1;
                adjacent[2] = room_number + 5;
                return adjacent;
            }
            if (room_number < 10){
                adjacent[0] = room_number+5;
                adjacent[1] = room_number+4;
                adjacent[2] = room_number-5;
                return adjacent;
            }
            if (room_number < 15){
                adjacent[0] = room_number+5;
                adjacent[1] = room_number-4;
                adjacent[2] = room_number-5;
                return adjacent;
            }
            if (room_number <= 19){
                adjacent[0] = room_number+1;
                adjacent[1] = room_number-1;
                adjacent[2] = room_number-5;
                return adjacent;
            }
            return adjacent;
        }
};
