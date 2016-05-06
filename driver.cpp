#include "WumpusMap.h"
void print_adjacent(int * a){
    cout << "adjacent rooms: " ;
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
}
void explore(){
    int i = 0;
    int pos = 0;
    srand(1338); // seed RNG
    Map *m = new WumpusMap();    
    m->set_jc_location(pos);
    int move = -1;
    while (i < 2000){
        int * adjacent = m->get_adjacent(pos);
        print_adjacent(adjacent);
        move = rand() % 3;
        pos = adjacent[move];
        m->set_jc_location(pos);
        cout << "moved to: " << pos << endl;
        i++; 
    }
}

int main(){
    explore();
}

