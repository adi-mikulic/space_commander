#include <iostream>
#include "Game_Command.h"

using namespace std;

int main()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2017" << endl;
    cout << "Programming Assignment 3" << endl;

    Model model;
    View view;

    bool check = true;

    model.show_status();
    model.display(view);

    while(check)
    {
        //model.display(view);    
        check = choose_command(model, view);
    }

    return 0;

}
