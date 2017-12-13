#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include <iostream>
#include <stdlib.h>
#include "Cart_Point.h"
#include "Model.h"
#include "Alien.h"
#include "View.h"
using namespace std;

void do_move_command(Model& model);

void do_work_a_depot_command(Model& model);

void do_deposit_moon_stones_command(Model& model);

void do_stop_command(Model& model);

void do_lock_in_at_station_command(Model& model);

void do_go_command(Model& model, View& view);

void do_run_command(Model& model, View& view);

void do_attack_command(Model& model);

void do_new_command(Model& model);

void do_quit_command(Model& model);

bool choose_command(Model& model, View& view);

#endif
