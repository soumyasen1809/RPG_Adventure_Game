#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include<memory>
#include "gameplay.hpp"
#include "player.hpp"
#include "fighter.hpp"
#include "trainee.hpp"
#include "mage.hpp"
#include <jsoncpp/json/json.h>

// gameplay::gameplay(/* args */){}

// gameplay::~gameplay(){}

void gameplay::fight(const std::unique_ptr<player>& game_player, const std::unique_ptr<player>& opponent_player){
    // hero and enemy randomly chooses to attack (damage inflicted) or defend (damage received)
    int hero_damage = (game_player->get_attackpoints()) - (opponent_player->get_defencepoints()) + (rand()%10)+1;   // choose a number from 1 to 11
    if (game_player->get_position() == "Fighter") {     // critical strike for a fighter
        if (game_player->is_criticalstrike()) {
            std::cout << "Critical strike!" << std::endl;
            hero_damage = 1.5*(game_player->get_attackpoints());
            game_player->add_gold(5);
            std::cout << "$$ You get 5 gold for a critical strike $$" << std::endl;
        }
    }
    if (game_player->get_position() == "Mage") {          // magic use for mage
        int magic_number = game_player->is_magicused();
        if (magic_number >= 0) {
            std::cout << "Magic used!" << std::endl;
            auto mana_attackpoints = game_player->magic_attack(magic_number);
            hero_damage = mana_attackpoints*game_player->get_attackpoints();
            game_player->add_gold(1);
            std::cout << "$$ You get 1 gold for magic $$" << std::endl;
        }
        
    }
    
    int enemy_damage = (opponent_player->get_attackpoints()) - (game_player->get_defencepoints()) + (rand()%10)+1;
    assert(hero_damage != 0);
    assert(enemy_damage != 0);
    std::cout << "You caused a damage of: " << hero_damage << std::endl;
    std::cout << "Enemy caused a damage of: " << enemy_damage << std::endl;

    auto enemydefencepts = opponent_player->get_hp() - hero_damage;                     // Reducing number of hp points
    opponent_player->set_hp(enemydefencepts);
    auto herodefencepts = game_player->get_hp() - enemy_damage;                      // Reducing number of hp points
    game_player->set_hp(herodefencepts);
    std::cout << "Your hp left: " << game_player->get_hp() << " and enemy hp left: " << opponent_player->get_hp() << std::endl;

};

void gameplay::rest(const std::unique_ptr<player>& game_player){
    game_player->restore_hp();
    game_player->add_numfights();      // add a fight counter to player
};

void gameplay::display_stats(const std::unique_ptr<player>& game_player){
    game_player->showstats();
};

void gameplay::save_game(const std::unique_ptr<player>& game_player){
    // Save stats in a txt file
    // std::ofstream player_stats;
    // player_stats.open("progress_stats.txt");
    // player_stats << game_player->get_name() << std::endl;
    // player_stats << game_player->get_hp() << std::endl;
    // player_stats << game_player->get_max_hp() << std::endl;
    // player_stats << game_player->get_attackpoints() << std::endl;
    // player_stats << game_player->get_defencepoints() << std::endl;
    // player_stats << game_player->get_numfights() << std::endl;
    // player_stats << game_player->get_level() << std::endl;
    // player_stats << game_player->get_gold() << std::endl;
    // player_stats.close();

    // https://programmerall.com/article/9926612018/
    // Json C++ parsing
    // Save stats in a Json file
    Json::Value jsonRoot; //Define root nodes
    Json::Value jsonItem; //Define a child object
    jsonItem["Name"] = game_player->get_name(); //adding data
    jsonItem["HP"] = game_player->get_hp();
    jsonItem["MaxHP"] = game_player->get_max_hp();
    jsonItem["AttackPoints"] = game_player->get_attackpoints();
    jsonItem["DefencePoints"] = game_player->get_defencepoints();
    jsonItem["NumFights"] = game_player->get_numfights();
    jsonItem["Level"] = game_player->get_level();
    jsonItem["Gold"] = game_player->get_gold();
    jsonRoot.append(jsonItem);

    std::ofstream ofs; //Standard output flow
    ofs.open("progress_stats.json"); //Create a file
    ofs << jsonRoot.toStyledString(); //Output
    ofs.close();

};

void gameplay::load_game(){
    // Read stats from a txt file
    std::string line;
    std::ifstream player_stats("progress_stats.txt");
    if (player_stats.is_open()) {
        std::cout << "Loading from the progress file" << std::endl;
        while (getline(player_stats, line)) {
            std::cout << line << std::endl;
        }
        player_stats.close();
    }
    else{
        std::cout << "No progress file found! Play new game" << std::endl;
    }
};
