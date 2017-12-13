#include <iostream>
#include "Model.h"

using namespace std;

Model::Model()
{
    time = 0;
    count_down = 10;

    person_ptrs.push_back (new Astronaut(1, Cart_Point(5,1)));
    object_ptrs.push_back (person_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());

    person_ptrs.push_back (new Astronaut(2, Cart_Point(10,1)));
    object_ptrs.push_back (person_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());

    depot_ptrs.push_back (new Oxygen_Depot(Cart_Point(1,20),1));
    object_ptrs.push_back (depot_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());

    depot_ptrs.push_back (new Oxygen_Depot(Cart_Point(10,20),2));
    object_ptrs.push_back (depot_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());
    
    station_ptrs.push_back (new Space_Station());
    object_ptrs.push_back (station_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());
    
    station_ptrs.push_back (new Space_Station(Cart_Point(5,5),2));
    object_ptrs.push_back (station_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());
    
    alien_ptrs.push_back (new Alien(1, Cart_Point(7,14)));
    object_ptrs.push_back (alien_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());
    
    alien_ptrs.push_back (new Alien(2, Cart_Point(7,5)));
    object_ptrs.push_back (alien_ptrs.back());
    active_ptrs.push_back (object_ptrs.back());

    cout << "Model default constructed." << endl;
}

Model::~Model()
{
    list<Game_Object*>::iterator iter;

    for (iter = object_ptrs.begin(); iter != object_ptrs.end(); iter++) //will the .end thing work? shouldn't it be the one after the end? also does iter++ work?
    {
        delete *iter; //did i dereference correctly?
    }

    cout << "Model destructed." << endl;
}

Person * Model::get_Person_ptr(int id)
{
    int id_ver;
    list<Person*>::iterator iter;

    for (iter = person_ptrs.begin(); iter != person_ptrs.end(); iter++)
    {
        id_ver = (*iter)->get_id();
        
        if (id_ver == id)
        {
            return *iter;
        }
    }

    throw Invalid_Input("Person ID does not exist");
}

Oxygen_Depot * Model::get_Oxygen_Depot_ptr(int id)
{
    int id_ver;
    list<Oxygen_Depot*>::iterator iter;

    for (iter = depot_ptrs.begin(); iter != depot_ptrs.end(); iter++)
    {
        id_ver = (*iter)->get_id();
        
        if (id_ver == id)
        {
            return *iter;
        }
    }

    throw Invalid_Input("Depot ID does not exist");
}

Space_Station * Model::get_Space_Station_ptr(int id)
{
    int id_ver;
    list<Space_Station*>::iterator iter;

    for (iter = station_ptrs.begin(); iter != station_ptrs.end(); iter++)
    {
        id_ver = (*iter)->get_id();
        
        if (id_ver == id)
        {
            return *iter;
        }
    }

    throw Invalid_Input("Station ID does not exist");
}

Alien * Model::get_Alien_ptr(int id)
{
    int id_ver;
    list<Alien*>::iterator iter;

    for (iter = alien_ptrs.begin(); iter != alien_ptrs.end(); iter++)
    {
        id_ver = (*iter)->get_id();
        
        if (id_ver == id)
        {
            return *iter;
        }
    }

    throw Invalid_Input("Alien ID does not exist");
}

bool Model::update() //add quiting game check statement too
{
    time++;

    bool check1 = false;
    bool check2 = false;
    bool check3 = true;
    bool check4 = true;
    bool check5 = true;

    char temp_state;

    list<Game_Object*>::iterator act_iter;

    for (act_iter = active_ptrs.begin(); act_iter != active_ptrs.end(); act_iter++) //updating all active objects
    {
        check1 = (*act_iter)->update(); //updating each object?

        if (check1)
        {
            check2 = true; //true if at least one update returns true
        }
    }

    for (act_iter = active_ptrs.begin(); act_iter != active_ptrs.end(); act_iter++) // removing dead astronauts
    {
        if ((*act_iter)->get_state() == 'x')
        {
            act_iter = active_ptrs.erase (act_iter);

            cout << "Dead object removed" << endl;
        }
    }

    list<Space_Station*>::iterator st_iter;

    for (st_iter = station_ptrs.begin(); st_iter != station_ptrs.end(); st_iter++) //checking if all stations are upgraded
    {
        temp_state = (*st_iter)->get_state();

        if (temp_state != 'u')
        {
            check3 = false;
        }
    }

    if (check3) //if all stations are upgraded
    {   
        cout << "Ready for takeoff? " << count_down << "..." << endl;

        char person_temp_state;
        int num_astronaut_check;
        int missing = 0;
        Cart_Point temp_loc;
        Cart_Point temp_dest;
        
        list<Person*>::iterator p_iter;

        for (p_iter = person_ptrs.begin(); p_iter != person_ptrs.end(); p_iter++) // checking if astronauts are locked in and at space stations
        {
            person_temp_state = (*p_iter)->get_state();

            temp_loc = (*p_iter)->get_location();
            temp_dest = (*p_iter)->get_destination();            

            if ((person_temp_state != 'l') && (temp_loc.x != temp_dest.x) && (temp_loc.y != temp_dest.y)) 
            {
                check4 = false;
            }
            
        }

        for (st_iter = station_ptrs.begin(); st_iter != station_ptrs.end(); st_iter++) // checking if all stations have 1 astronaut
        {
            num_astronaut_check = (*st_iter)->get_astronauts();

            if (num_astronaut_check < 1)
            {
                check5 = false;

                missing++;
            }
        }

        if (check4 && check5) //winning
        {
            cout << "Blast Off! You Win!" << endl;

            exit(0);
        }
        else
        {
            cout << "Missing " << missing << " astronauts!" << endl;

            count_down--;
        }
    }

    if (count_down == 0) //losing
    {
        cout << "Unmanned takeoff... You lose!" << endl;
        
        exit(0);    
    }

    return check2; //returning if any updates returned true (from beginning)
}

void Model::display(View &view)
{
    view.clear();

    list<Game_Object*>::iterator iter;

    for (iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
    {
        view.plot(*iter);
    }

    view.draw();
}

void Model::show_status()
{
    cout << "Time: " << time << " ticks" << endl;    

    list<Game_Object*>::iterator iter;

    for (iter = object_ptrs.begin(); iter != object_ptrs.end(); iter++)
    {
        (*iter)->show_status();
    }
}

void Model::handle_new_command(char TYPE, int ID, double x, double y)
{

    switch (TYPE)
    {
        case 'd':

            depot_ptrs.push_back (new Oxygen_Depot(Cart_Point(x,y),ID));
            object_ptrs.push_back (depot_ptrs.back());
            active_ptrs.push_back (object_ptrs.back());

            break;

        case 's':

            station_ptrs.push_back (new Space_Station(Cart_Point(x,y),ID));
            object_ptrs.push_back (station_ptrs.back());
            active_ptrs.push_back (object_ptrs.back());

            break;

        case 'a':

            person_ptrs.push_back (new Astronaut(ID, Cart_Point(x,y)));
            object_ptrs.push_back (person_ptrs.back());
            active_ptrs.push_back (object_ptrs.back());

            break;

        case 'x':

            alien_ptrs.push_back (new Alien(ID, Cart_Point(x,y)));
            object_ptrs.push_back (alien_ptrs.back());
            active_ptrs.push_back (object_ptrs.back());

            break;
    }

}
