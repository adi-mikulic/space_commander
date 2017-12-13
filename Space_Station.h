#ifndef SPACE_STATION_H
#define SPACE_STATION_H

#include <iostream>
#include "Game_Object.h"
using namespace std;

class Space_Station: public Game_Object
{
    
private:

    double amount_moonstones;

    int number_astronauts;

    bool check;

public:

    Space_Station();
    Space_Station(Cart_Point inputLoc, int inputId);
    ~Space_Station();

    void deposit_moonstones(double deposit_amount);

    bool add_astronaut();

    int get_astronauts();

    bool update(); ///does this need to be virtual?

    void show_status();
};

#endif