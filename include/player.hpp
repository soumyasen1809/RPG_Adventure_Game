#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>

class player
{
private:
    std::string name;
    int hp;
    int attack_points;
    int defence_points;
    int max_hp;
    int num_fights = 0;
public:
    player(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints);
    ~player();
    void set_name(std::string name);
    void set_hp(int hp);
    void set_max_hp(int max_hp);
    void set_attackpoints(int attack_points);
    void set_defencepoints(int defence_points);
    void add_numfights();
    std::string get_name();
    int get_hp();
    int get_max_hp();
    int get_attackpoints();
    int get_defencepoints();
    int get_numfights();

    void showstats();   // show current statistics of the player
    bool is_alive();    // check if the player is alive
    void restore_hp();  // recover the player, restore the hp to it's max
};




#endif      // player.hpp define closed