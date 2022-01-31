#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include "trainee.hpp"
#include "player.hpp"
#include "gameplay.hpp"

trainee::trainee(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints):player(input_name, start_hp, max_hp, start_attackpoints, start_defencepoints){};
trainee::~trainee(){};

std::string trainee::get_position(){return "Trainee";}