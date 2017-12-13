#include <iostream>
#include "Astronaut.h"

using namespace std;

Astronaut::Astronaut() : Person('A')
{
    amount_moonstones = 0;
    amount_oxygen = 20;

    depot = NULL;
    home = NULL;

    cout << "Astronaut default constructed." << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Person(in_loc, in_id, 'A')
{
    amount_moonstones = 0;
    amount_oxygen = 20;

    depot = NULL;
    home = NULL;

    cout << "Astronaut constructed." << endl;
}

Astronaut::~Astronaut()
{
    cout << "Astronaut destructed." << endl;
}

double oxygen;

bool Astronaut::update()
{
    switch (state)
    {
        case 's': //return true? will it ever return false?

            if (health < 3)
            {
                display_code = 'a';
            }

            state = 's';

            return false;

        case 'm':

            if (health < 3)
            {
                display_code = 'a';
            }

            if (update_location())
            {
                state = 's';

                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;
                    state = 'x';
                }

                return true;
            }

            else
            {
                amount_moonstones++;
                amount_oxygen--;

                state = 'm';

                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;
                    state = 'x';

                    return true;
                }

                return false;
            }

        case 'o':

            if (health < 3)
            {
                display_code = 'a';
            }

            if (update_location())
            {
                state = 'g';

                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                    state = 'x';
                }

                return true;
            }

            else
            {
                amount_moonstones++;
                amount_oxygen--;

                state = 'o';

                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                    state = 'x';
                }

                return false;
            }

        case 'g':

            if (health < 3)
            {
                display_code = 'a';
            }

            oxygen = depot->extract_oxygen();

            cout << display_code << id_num << ": Got " << oxygen << " oxygen."
            << endl;

            amount_oxygen += oxygen;

            state = 's';

            return true;

        case 'i':

            if (health < 3)
            {
                display_code = 'a';
            }

            if (update_location())
            {
                state = 'd';

                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                    state = 'x';
                }

                return true;
            }

            else
            {
                amount_moonstones++;
                amount_oxygen--;

                state = 'i';

                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                    state = 'x';
                }

                return false;
            }

            break;

        case 'd': 

            if (health < 3)
            {
                display_code = 'a';
            }

            cout << display_code << id_num << ": Depositing " << amount_moonstones
            << " moon stones." << endl;

            home->deposit_moonstones(amount_moonstones);
            amount_moonstones = 0;

            state = 's';

            return true;

        case 'l':

            if (health < 3)
            {
                display_code = 'a';
            }

            if (update_location())
            {
                if (home->add_astronaut())
                {

                    if (amount_oxygen <= 0)
                    {
                        cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                        state = 'x';
                    }

                    return true;
                }

                else
                {

                    if (amount_oxygen <= 0)
                    {
                        cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                        state = 'x';
                    }

                    return false;
                }
            }

            else
            {
                amount_moonstones++;
                amount_oxygen--;            


                if (amount_oxygen <= 0)
                {
                    cout << display_code << id_num << ": I'm out of oxygen! I'm dying!" << endl;

                    state = 'x';
                }

                return false;
            }

            break;

        case 'x':

            state = 'x';

            return false;

            break;
    }
}

void Astronaut::start_supplying(Oxygen_Depot * inputDepot)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        depot = inputDepot;

        Person::setup_destination(depot->get_location()); 

        state = 'o';

        cout << "Astronaut " << id_num << " supplying from Oxygen Depot " 
        << depot->get_id() << "." << endl;
        cout << display_code << id_num << ": Yes, my lord." << endl;
    }
}

void Astronaut::start_depositing(Space_Station * inputStation)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        home = inputStation;

        Person::setup_destination(home->get_location()); 

        state = 'i';

        cout << "Astronaut " << id_num << " depositing to Space Station " 
        << home->get_id() << "." << endl;
        cout << display_code << id_num << ": Yes, my lord." << endl;
    }
}

void Astronaut::go_to_station(Space_Station * inputStation)
{
    if (state == 'x')
    {
        cout << display_code << id_num << ": I can't move, I'm dead." << endl;
    }
    else
    {
        home = inputStation;

        if ((location.x == (home->get_location()).x) && (location.y == (home->get_location()).y))
        {
            cout << display_code << id_num << ": I'm already there, see?" << endl;
        }
        else
        {
            state = 'l';

            cout << "Astronaut " << id_num << " locking in at Space Station " 
            << home->get_id() << "." << endl; 

            Person::setup_destination(home->get_location());
        }
    }
}

void Astronaut::show_status()
{
    cout << "Astronaut status: ";

    Person::show_status();

    switch (state)
    {
        case 's':

            cout << "Stopped with " << amount_oxygen << " oxygen and " 
            << amount_moonstones << " moon stones." << endl;

            break;

        case 'm':
            
            cout << "\n";

            break;

        case 'o':

            cout << " is outbound to a Depot with " << amount_oxygen
            << " oxygen and " << amount_moonstones << " moon stones." << endl;

            break;

        case 'g':

            cout << " is getting oxygen from Depot." << endl;

            break;
        
        case 'i':

            cout << " is inbound to home with load: " << amount_moonstones
            << " and " << amount_oxygen << " oxygen." << endl;

            break;

        case 'd':

            cout << " is depositing " << amount_moonstones << " moon stones." << endl;

            break;

        case 'l':

            cout << "Locked in at Space Station" << endl;

            break;

        case 'x':

            cout << "\n";

            break;
    }
}
