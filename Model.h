#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Person.h"
#include "Astronaut.h"
//class Astronaut;
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Alien.h"
#include "View.h" //do i have to include this much every time?
#include "Input_Handling.h"

using namespace std;

class Model
{
private:

    int time;
    int count_down;

    list<Game_Object*> object_ptrs;

    list<Game_Object*> active_ptrs;

    list<Person*> person_ptrs;

    list<Oxygen_Depot*> depot_ptrs;

    list<Space_Station*> station_ptrs;

    list<Alien*> alien_ptrs;

public:

    Model();
    ~Model();

    Person * get_Person_ptr(int id);
    Oxygen_Depot * get_Oxygen_Depot_ptr(int id);
    Space_Station * get_Space_Station_ptr(int id);
    Alien * get_Alien_ptr(int id);

    bool update();  
    void display(View &view);
    void show_status();

    void handle_new_command(char TYPE, int ID, double x, double y);

};

#endif
