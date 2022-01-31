#ifndef TRAINEE_HPP
#define TRAINEE_HPP

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

class trainee: virtual public player
{
private:
    /* data */
public:
    trainee(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints);
    ~trainee();

    std::string get_position() override;
};



#endif          // trainee.hpp define close