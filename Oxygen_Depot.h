#ifndef OXYGEN_DEPOT_H
#define OXYGEN_DEPOT_H

#include <iostream>
#include "Game_Object.h"

using namespace std;

class Oxygen_Depot: public Game_Object
{
    
private:

    double amount_oxygen;

    bool check;

public:

    Oxygen_Depot(); 
    Oxygen_Depot(Cart_Point inputLoc, int inputId);
    ~Oxygen_Depot();

    bool is_empty();

    double extract_oxygen(double amount_to_extract = 20);

    bool update(); //does this need to be virtual?

    void show_status();
};

#endif