#include <iostream>
#include "Game_Command.h"

using namespace std;

void do_move_command(Model &model)//add checking if inputs are valid
{

    int ID;
    double x, y;
    char choice;

    cin >> ID >> x >> y;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    cout << "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
    cin >> choice;

    if (cin.fail() || (choice != 'a' && choice != 'x'))
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    if (choice == 'a')
    {
        (model.get_Person_ptr(ID))->start_moving(Cart_Point(x,y));
    } // check valid pointers? if ID number exists?

    else if (choice == 'x')
    {
        (model.get_Alien_ptr(ID))->start_moving(Cart_Point(x,y));
    }

}

void do_work_a_depot_command(Model &model)
{

    int ID1, ID2;

    cin >> ID1 >> ID2;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    (model.get_Person_ptr(ID1))->start_supplying(model.get_Oxygen_Depot_ptr(ID2)); 

}

void do_deposit_moon_stones_command(Model &model)
{

    int ID1, ID2;

    cin >> ID1 >> ID2;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    (model.get_Person_ptr(ID1))->start_depositing(model.get_Space_Station_ptr(ID2)); 

}

void do_stop_command(Model &model)
{

    int ID;

    cin >> ID;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    (model.get_Person_ptr(ID))->stop();

}

void do_lock_in_at_station_command(Model &model)
{
    int ID1, ID2;

    cin >> ID1 >> ID2;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }
    
    if (((model.get_Space_Station_ptr(ID2))->get_state()) != 'u')
    {
        cout << "Astronaut " << ID1 << " cannot lock in at Space Station " 
        << ID2 << " becuase it's not upgraded." << endl;
    }
    else
    {
        (model.get_Person_ptr(ID1))->go_to_station(model.get_Space_Station_ptr(ID2));
    }
}

void do_go_command(Model &model, View &view)
{

    cout << "Advancing one tick..." << endl;

    model.update();
}

void do_run_command(Model &model, View &view)
{
    
    cout << "Advancing to next event..." << endl;   
    
    bool check = false;

    int x = 0;
    while (!check && (x < 5))
    {
        x++;
        check = model.update();
    }

}

void do_attack_command(Model &model)
{
    // add error checking, FOR EVERYTHING ELSE TOO
    int ID1, ID2;

    cin >> ID1 >> ID2;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    (model.get_Alien_ptr(ID1))->start_attack(model.get_Person_ptr(ID2)); // will the alien keep attacking after one iteration?


}

void do_new_command(Model &model)
{

    char TYPE;
    int ID;
    double x, y;

    cin >> TYPE >> ID >> x >> y;

    if (cin.fail()) // check for other stuff?
    {
        throw Invalid_Input("Please enter valid input!"); // should i be more specfic?
    }

    model.handle_new_command(TYPE, ID, x, y);

}

void do_quit_command()
{

    cout << "Terminating Program." << endl;

}

bool choose_command(Model &model, View &view)
{
    char command;
    
    cout << "Enter Command: ";
    cin >> command;

    try
    {

        if (command != 'm' && command != 'w' && command != 'd' && 
            command != 's' && command != 'l' && command != 'g' &&
             command != 'r' && command != 'a' && command != 'n'
              && command != 'q')
        {
            // cout << "ERROR: Please enter a valid command!" << endl;
            // return true;

            throw Invalid_Input ("Please enter a valid command!");
            // return true?

        }
        
        switch(command)
        {
            case 'm':
                
                do_move_command(model);
                
                return true;

            case 'w':

                do_work_a_depot_command(model);

                return true;

            case 'd':

                do_deposit_moon_stones_command(model);

                return true;

            case 's':

                do_stop_command(model);

                return true;

            case 'l':

                do_lock_in_at_station_command(model);

                return true;

            case 'g':

                do_go_command(model, view);

                model.show_status();
                model.display(view);

                return true;

            case 'r':

                do_run_command(model, view);

                model.show_status();
                model.display(view);

                return true;

            case 'a':

                do_attack_command(model);

                return true;

            case 'n':

                do_new_command(model);

                return true;

            case 'q':

                do_quit_command();

                return false;
        }

    }
    catch (Invalid_Input& except)
    {
        cout << "ERROR: " << except.msg_ptr << endl;
        // other actions?
    }
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
