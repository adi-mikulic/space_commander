#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"

using namespace std;

class Person: public Game_Object
{

public:

    Person();
    Person(char in_code);
    Person(Cart_Point in_loc, int in_id, char in_code);
    virtual ~Person();

    void start_moving(Cart_Point dest);

    void stop();

    void show_status();

    double get_speed();

    Cart_Point get_destination();

    Cart_Vector get_delta();

    virtual void start_supplying(Oxygen_Depot * inputDepot);

    virtual void start_depositing(Space_Station * inputStation);

    virtual void go_to_station(Space_Station * inputStation);

    bool is_alive();

    void take_hit(int attack_strength);

protected:

    bool update_location();

    void setup_destination(Cart_Point dest);

    int health;

private:

    double speed;

    Cart_Point destination;

    Cart_Vector delta;
};

#endif
