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

// gameplay::gameplay(/* args */){}

// gameplay::~gameplay(){}

void gameplay::fight(const std::unique_ptr<player>& game_player, const std::unique_ptr<player>& opponent_player){
    // hero and enemy randomly chooses to attack (damage inflicted) or defend (damage received)
    int hero_damage = (game_player->get_attackpoints()) - (opponent_player->get_defencepoints()) + (rand()%10)+1;   // choose a number from 1 to 11
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
    std::cout << "Player Name: " << game_player->get_name() << std::endl;
    std::cout << "Health Points: " << game_player->get_hp() << std::endl;
    std::cout << "Max Health Points: " << game_player->get_max_hp() << std::endl;
    std::cout << "Attack Points: " << game_player->get_attackpoints() << std::endl;
    std::cout << "Defence Points: " << game_player->get_defencepoints() << std::endl;
    std::cout << "Total number of fights: " << game_player->get_numfights() << std::endl;
};

void gameplay::save_game(const std::unique_ptr<player>& game_player){
    std::ofstream player_stats;
    player_stats.open("progress_stats.txt");
    player_stats << game_player->get_name() << std::endl;
    player_stats << game_player->get_hp() << std::endl;
    player_stats << game_player->get_max_hp() << std::endl;
    player_stats << game_player->get_attackpoints() << std::endl;
    player_stats << game_player->get_defencepoints() << std::endl;
    player_stats << game_player->get_numfights() << std::endl;
    player_stats.close();
};

void gameplay::load_game(){
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
