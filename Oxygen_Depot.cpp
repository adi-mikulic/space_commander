#include <iostream>
#include "Oxygen_Depot.h"
using namespace std;

Oxygen_Depot::Oxygen_Depot() : Game_Object('O')
{
    display_code = 'O';
    state = 'f';
    amount_oxygen = 50;

    check = true;

    cout << "Oxygen_Depot default constructed." << endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId)
     : Game_Object(inputLoc, inputId, 'O')
{
    id_num = inputId;
    location = inputLoc;
    amount_oxygen = 50;
    display_code = 'O';
    state = 'f';

    check = true;

    cout << "Oxygen_Depot constructed." << endl;
}

Oxygen_Depot::~Oxygen_Depot()
{
    cout << "Oxygen_Depot destructed." << endl;
}

bool Oxygen_Depot::is_empty()
{
    if (amount_oxygen == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
    if (amount_oxygen >= amount_to_extract)
    {
        amount_oxygen = amount_oxygen - amount_to_extract;

        return amount_to_extract;
    }

    else if (amount_oxygen < amount_to_extract)
    {
        double temp = amount_oxygen;

        amount_oxygen = 0;

        return temp; 
    }
}

bool Oxygen_Depot::update()
{
    if (check) //so it only returns true once
    {
        if (is_empty())
        {
            state = 'e';
            display_code = 'o';

            cout << "Oxygen Depot " << id_num << " has been depleated." << endl;

            check = false;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Oxygen_Depot::show_status()
{
    cout << "Oxygen Depot status: ";

    cout << display_code << id_num << " at location " 
    << location << " contains " << amount_oxygen << ".";

    if (state == 'e')
    {
        cout << " Depleated." << endl;
    }
    else
    {
        cout << "\n";
    }
}
