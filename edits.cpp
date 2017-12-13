// Model.cpp

// fancy winning screen

cout << "\n" << // for the memes
            "                               ^" << "\n" <<
            "                              / \\" << "\n" <<
            "                             /   \\" << "\n" <<
            "                            /     \\" << "\n" <<
            "                           |-------|" << "\n" <<
            "                           |       |" << "\n" <<
            "                           |       |" << "\n" <<
            "                           |       |" << "\n" <<
            "                           |       |" << "\n" <<
            "                           |       |" << "\n" <<
            "                           |       |" << "\n" <<
            "                           |       |" << "\n" <<
            "                          /|       |\\" << "\n" <<
            "                         / |       | \\" << "\n" <<
            "                        /  |       |  \\" << "\n" <<
            "                       /___|_______|___\\" << "\n" <<
            "                             /   \\" << "\n" <<
            "                            /_____\\" << "\n" <<
            "                             ||  |" << "\n" <<
            "                             ||  |     * * *" << "\n" <<
            "          * *        * * *   ||  |    *     *    * *" << "\n" <<
            "        *     *    *       * ||  |  *        * *     *" << "\n" <<
            "       *        *           *|| * *            *       *" << "\n" <<
            "      *           *          *                  *       *" << "\n" <<
            "     *             *        *                    *      *" << "\n" <<
            "    *                *     *                       *   *" << "\n" <<
            "    *                 *    *                      *   *" << "\n" <<
            "     * * * * * * * * * * * * * * * * * * * * * * * * *" << "\n" << endl;

            cout << 
            "                      Blast Off! You Win!" << "\n" << endl;


// random end line spacing

cout << "\n" << "Unmanned takeoff... You lose!" << "\n" << endl;

cout << "Model destructed." << "\n" << endl;

cout << "Model default constructed." << "\n" << endl;

// Astronaut.cpp

// quotes for talking -> also look for similar stuff in alien.cpp and person.cpp

cout << display_code << id_num << ": \"I'm out of oxygen! I'm dying!\"" << endl;

cout << display_code << id_num << ": \"Got " << oxygen << " oxygen.\"" 
            << endl;

cout << display_code << id_num << ": \"Depositing " << amount_moonstones
            << " moon stones.\"" << endl;

cout << display_code << id_num << ": \"Yes, commander.\"" << endl;

cout << display_code << id_num << ": \"I'm already there, see?\"" << endl;


// main.cpp

// new line stuff

cout << "\n";
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2017" << endl;
    cout << "Programming Assignment 3" << endl;
    cout << "\n";

    Model model;
    View view;

    bool check = true;

    model.show_status();
    cout << "\n";

    while(check)
    {
        model.display(view);
        cout << "\n";      
        check = choose_command(model, view);
        cout << "\n";
    }

    return 0;


///////////////// THINGS TO ADD

// add a new class, ore deposits, will be the only place player can get moonstones
    // moonstones in each deposit is NOT infinite
    // shows up on grid, obviously

// add new command to astronaut, mine stones, "m", involves player typing in
    // number of stones they wish to collect, will call start mining command in ore_deposit

// connected to mining command, ore deposits need a function, start_mining
    // DOES NOT HAPPEN INSTANTLY, takes in number of moonstones player wishes to mine,
    // and 

// player will not pick up 1 moonstone per step anymore, although there will be
    // a random chance they could pick up 1 when moving

// 

// make it possible to lock in at station when on top of one, rn you have to 
    // move off the station to do so

// make it possible for aliens to hit astronauts when astronaut at same location
    // of station or depot but not locked in)

// once astronaut locked into station, can't be hit anymore, also oxygen doesn't go down anymore

// make aliens AI, take out 2 player option

// add astroids to fly across screen randomly, and if hit astronaut, randomly choose
    // damage to inflict on it, possible to kill astronaut, make sure its shown on screen too

// change health and attack damage values so that they work better with each other

// add cool visual stuff, title, winning screen, losing screen
    // just make a seperate file, labeled "art" with functions which output the art

// make grid bigger, also more ox depots and stations

// make it so a win happens if all astronauts that are alive launch from their space stations

// if all astronauts die, player loses

// take out 'n' command, no real point to it from a game standpoint

// the player will start with a number of astronauts, and a number of space stations equal
    // to number of spawned astronauts, number will be random so diff each game

// number of ox depots is random and less than or equal to number of spawned astronauts

// add game difficulty settings
    // affects: 
        // number of astroids generated
        // ox astros can hold
        // moonstones needed to collect to launch
        // number of aliens generated
        // how long it takes for a super alien to form
        // attack damage of aliens

// make start menu, can change difficuty, access leaderboard, load previous games, start new game,
    // or continue last saved game played, if no previous game detected, prompt given to player,
    // exit game option also

// add item if astronaut picks up, adds to score, prompt outputted to player as well

// add high score, can assign name to high score
    // score determined by num astronauts who launched, 

// add save game? or continue last saved game played, if no previous game detected, prompt given to player,
    // exit game option also

// different text outputs from aliens, making more sense

// remove ID nums from aliens?

// remove move command for players to control aliens

// add super alien class
    // creation of super alien will happen at a late point in the game,
    // what will happen is 2 aliens (randomly selected) will start walking towords eachother, and when they collide
    // they will be replaced by a super alien
    // will be created more than once in the game, after the first is created 
    // prompt outputted when created
    // takes up a bigger space?
    // more damage
    // bigger range
    // slightly slower

// add tutorial

// add help command, "h", lists all commands and syntax

// at any point in game, player can exit to main menu, can't quit from entire game

// add colors?

// only one astronaut can access a depot at a time

// stations can only hold one locked astronaut, kinda like escape pods

// replace constant outputting of game status to only be outputted when player
    // types in status command "s"