#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include "fighter.hpp"
#include "player.hpp"
#include "gameplay.hpp"

fighter::fighter(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints):player(input_name, start_hp, max_hp, start_attackpoints, start_defencepoints){};
fighter::~fighter(){};

bool fighter::is_criticalstrike(){return (rand()%10 == 7) ? true:false;}    // generate a random number and check if number is 7 (can change to any number of choice) for a critical strike

std::string fighter::get_position(){return "Fighter";}