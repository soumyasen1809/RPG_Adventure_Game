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
#include "fighter.hpp"
#include "trainee.hpp"
#include "mage.hpp"
#include "bot_simulation.hpp"

void bot_simulation::simulate(){
    // create a trainee bot
    trainee bot_trainee("Bot", 55, 100, 19, 10);
    std::unique_ptr<player> good_bot = std::make_unique<trainee>(bot_trainee);         // players start game as a trainee
    std::cout << "Welcome trainee " << good_bot->get_name() << std::endl;
    player bot_enemy_trainee("BotGob", 20, 45, 5, 7);       // create a player enemy
    std::unique_ptr<player> bad_bot = std::make_unique<player>(bot_enemy_trainee);
    
    while (good_bot->is_alive() && bad_bot->is_alive()) {
        gameplay::fight(good_bot, bad_bot);
        if (rand()%5 == 2) {        // Choose randomly if the bot wants to rest
            std::cout << "Bot resting" << std::endl;
            gameplay::rest(good_bot);
        }
    }

    if (good_bot->is_alive()) {
        // Upgrade to fighter
        fighter bot_fighter("Bot", good_bot->get_hp(), good_bot->get_max_hp()*2, good_bot->get_attackpoints()*2, good_bot->get_defencepoints()*2);
        good_bot = std::make_unique<fighter>(bot_fighter);
        std::cout << "Welcome fighter " << good_bot->get_name() << std::endl;
        // upgrade enemy
        player bot_enemy_fighter("BotGob", 40, 75, 15, 17);       // upgrade player enemy
        bad_bot = std::make_unique<player>(bot_enemy_fighter);
        while (good_bot->is_alive() && bad_bot->is_alive()) {
            gameplay::fight(good_bot, bad_bot);
            if (rand()%5 == 0) {        // Choose randomly if the bot wants to rest
                std::cout << "Bot resting" << std::endl;
                gameplay::rest(good_bot);
            }
        }

    }

    if (good_bot->is_alive()) {
        // Upgrade to mage
        mage bot_mage("Bot", good_bot->get_hp(), good_bot->get_max_hp()*5, good_bot->get_attackpoints()*5, good_bot->get_defencepoints()*5, 50, 100, 2);
        good_bot = std::make_unique<mage>(bot_mage);
        std::cout << "Welcome mage " << good_bot->get_name() << std::endl;
        // upgrade enemy
        player bot_enemy_mage("BotGob2", 70, 95, 25, 27);       // upgrade player enemy
        bad_bot = std::make_unique<player>(bot_enemy_mage);
        while (good_bot->is_alive() && bad_bot->is_alive()) {
            gameplay::fight(good_bot, bad_bot);
            if (rand()%5 == 1) {        // Choose randomly if the bot wants to rest
                std::cout << "Bot resting" << std::endl;
                gameplay::rest(good_bot);
            }
        }

    }
    
    // TO-DO: copy mage to a trainee and fight. Use additional magic methods on top
    
}