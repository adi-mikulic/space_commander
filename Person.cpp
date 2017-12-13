#include <iostream>
#include <cmath>
#include "Person.h"

using namespace std;

Person::Person() : Game_Object('P')
{
    speed = 5;

    health = 5;

    cout << "Person default constructed." << endl;
}

Person::Person(char in_code) : Game_Object(in_code)
{
    speed = 5;

    health = 5;

    cout << "Person contructed." << endl;

    state = 's';
    display_code = in_code;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code)
     : Game_Object(in_loc, in_id, in_code)
{
    speed = 5;

    health = 5;

    cout << "Person contructed." << endl;
}

Person::~Person()
{
    cout << "Person destructed." << endl;
}

void Person::start_moving(Cart_Point dest)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
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
}

void Person::stop()
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        //tell astronaut to stop moving or collecting oxygen, anything else needed?
        cout << "Stopping " << id_num << "." << endl;

        state = 's';

        cout << display_code << id_num << ": All right." << endl;
    }
}

void Person::show_status()
{
    Game_Object::show_status();

    if (state == 's')
    {
        cout << " is stopped. ";
    }
    else if (state == 'l')
    {
        cout << " is locked. ";
    }
    else if (state == 'x')
    {
        cout << " is dead. ";
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
            << destination << " at each step of " << delta ;
        }
    }
}

double Person::get_speed() //my getters
{
    return speed;
}

Cart_Point Person::get_destination()
{
    return destination;
}

Cart_Vector Person::get_delta()
{
    return delta;
}

void Person::start_supplying(Oxygen_Depot * inputDepot)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        cout << "Sorry, I can't work a depot." << endl;
    }
}

void Person::start_depositing(Space_Station * inputStation)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        cout << "Sorry, I can't work a station." << endl;
    }
}

void Person::go_to_station(Space_Station * inputStation)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        cout << "Sorry, I can't lock into a station." << endl;
    }
}

bool Person::is_alive()
{
    if (state == 'x')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Person::take_hit(int attack_strength)
{
    health -= attack_strength;

    if (health <= 0)
    {
        cout << display_code << id_num << ": Gasp!" << endl;

        state = 'x';
    }
    else
    {
        cout << display_code << id_num << ": Ouch!" << endl;
    }
}

bool Person::update_location()
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

void Person::setup_destination(Cart_Point dest)
{
    destination = dest;

    delta = (destination - location)*(speed/cart_distance(destination, location));
}

