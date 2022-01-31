#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include "player.hpp"
#include "gameplay.hpp"

class fighter: virtual public player
{
private:
    int critical_strike;
public:
    fighter(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints);
    ~fighter();

    bool is_criticalstrike() override;
    std::string get_position() override;
};



#endif          // fighter.hpp define close