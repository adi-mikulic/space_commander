#include <iostream>
#include <cmath>

#include "Alien.h"

using namespace std;

Alien::Alien() : Game_Object('X')
{
    speed = 5;
    attack_strength = 2;
    range = 2.0;

    target = NULL;

    cout << "default Alien constucted." << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc) 
: Game_Object(in_loc, in_id, 'X')
{
    speed = 5;
    attack_strength = 2;
    range = 2.0;
    
    target = NULL;

    cout << "Alien constucted." << endl;
}

Alien::~Alien()
{
    cout << "Alien destructed." << endl;
}

void Alien::start_moving(Cart_Point dest)
{

    if ((location.x == dest.x) && (location.y == dest.y))
    {
        cout << display_code << id_num << ": I'm already there, see?" << endl;
    }
    else
    {
        cout << "Moving " << id_num << " to " << dest << endl;

        setup_destination(dest);

        state = 'm';

        cout << display_code << id_num << ": On my way." << endl;
    }

}

void Alien::stop()
{

    //tell astronaut to stop moving or collecting oxygen, anything else needed?
    cout << "Stopping " << id_num << "." << endl;

    state = 's';

    cout << display_code << id_num << ": All right." << endl;

}

void Alien::start_attack(Person * in_target)
{

    double temp_target_dist;

    Cart_Point temp_target_location = in_target->get_location();

    temp_target_dist = cart_distance(location, temp_target_location);

    if ((temp_target_dist <= range) && (in_target->get_state() != 'x'))
    {
        cout << display_code << id_num << ": Smash!" << endl;

        target = in_target;
        target_location = temp_target_location;

        state = 'a';
    }
    else
    {
        if (in_target->get_state() == 'x')
        {
            cout << display_code << id_num << ": Target is already dead" << endl;
        }
        else
        {
            cout << display_code << id_num << ": Target is out of range" << endl;
        }
    }

}

bool Alien::update()
{

    switch (state)
    {
        case 's':

            state = 's'; 

            return false;

        case 'm':

            if (update_location())
            {
                state = 's';

                return true;
            }
            else
            {
                state = 'm';

                return false;
            }

        case 'a':

            double target_dist;

            target_dist = cart_distance(location, target_location);

            if (target_dist > range)
            {
                cout << display_code << id_num << ": Target is out of range" << endl;
                cout << display_code << id_num << ": Chaaaaaarge" << endl;

                state = 's';

                return true;
            }
            else
            {
                if (target->is_alive())
                {
                    cout << display_code << id_num << ": Destroy!" << endl;

                    target->take_hit(attack_strength);

                    state = 'a';

                    return false;
                }
                else
                {
                    cout << display_code << id_num << ": I triumph!" << endl;

                    state ='s';

                    return true;
                }
            }

    }

}

void Alien::show_status()
{

    cout << "Alien status: ";

    Game_Object::show_status();

    if (state == 's')
    {
        cout << " is stopped." << endl;
    }
    else if (state == 'a')
    {
        cout << " is attacking astronaut " << target->get_display_code() << target->get_id() << endl;
    }
    else if (state == 'm')
    {
        if ((location.x == destination.x) && (location.y == destination.y))
        {
            cout << "\n";
        }
        else
        {
            cout << " moving at speed of " << speed << " towards "
            << destination << " at each step of " << delta << endl;
        }
    }

}

bool Alien::update_location()
{

    if ((location.x == destination.x) && (location.y == destination.y))  //if person already arrived
    {
        return false;    
    }
    
    else if ((fabs(destination.x - location.x) <= fabs(delta.x)) && 
        (fabs(destination.y - location.y) <= fabs(delta.y))) //if next location will be destination
    {
        location = destination; //updating location
        cout << display_code << id_num << ": I'm there!" << endl;
        return true;
    }

    else //if not yet arrived
    {
        location = location + delta; //updating location
        cout << display_code << id_num << ": step..." << endl;
        return false;
    }

}

void Alien::setup_destination(Cart_Point dest)
{

    destination = dest;

    delta = (destination - location)*(speed/cart_distance(destination, location));

}