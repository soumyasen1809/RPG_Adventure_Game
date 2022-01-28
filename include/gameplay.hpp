#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include<memory>
#include "player.hpp"

class gameplay
{
private:
    /* data */
public:
    // gameplay(/* args */);
    // ~gameplay();

    static void fight(const std::unique_ptr<player>& game_player, const std::unique_ptr<player>& opponent_player);
    static void rest(const std::unique_ptr<player>& game_player);
    static void display_stats(const std::unique_ptr<player>& game_player);
    static void load_game();
    static void save_game(const std::unique_ptr<player>& game_player);
};


#endif      // gameplay.hpp define closed