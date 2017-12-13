#ifndef ALIEN_H
#define ALIEN_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Person.h"

using namespace std;

class Alien: public Game_Object
{

private:

    int attack_strength;

    double range;

    Person * target;

    double speed;

    Cart_Point destination;

    Cart_Vector delta;

    Cart_Point target_location;

public:

    Alien();
    Alien(int in_id, Cart_Point in_loc);
    ~Alien();

    void start_moving(Cart_Point dest);

    void stop();

    void start_attack(Person * in_target);

    bool update();

    void show_status();

protected:

    bool update_location();

    void setup_destination(Cart_Point dest);
};

#endif
