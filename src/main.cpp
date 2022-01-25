#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include<cstdlib>
#include "player.hpp"

int main(){
    // Creating the main menu
    int choice;
    std::cout << "Enter 1 to start a new game, 2 to load previous game and 3 to exit: ";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "New Game" << std::endl;
        std::string player_name;
        std::cout << "Enter your player name: ";
        std::cin >> player_name;
        // Create a player hero
        player hero(player_name, 20, 20, 6, 6);
        assert(hero.get_hp() > 0);
        assert(hero.get_max_hp() > 0);
        std::cout << "Hello " << hero.get_name() << ", welcome to the game!" << std::endl;  // welcome message to the player
        
        // show in-game menu while hp > 0
        while (hero.get_hp() > 0){
            int ingame_choice = 0;  // Default value set as 0, so that if user doesn't enter any value, the else condition is run
            std::cout << "Choose from in-game menu: 1 to fight, 2 to rest, 3 to show stats, 4 to save the game, 5 to exit the game" << std::endl;
            std::cout << "Remember to save your progress before quiting the game: ";
            std::cin >> ingame_choice;
            if (ingame_choice == 1){
                // fight with the enemy
                player enemy("Goblin", 5, 5, 1, 1);       // create a player enemy
                std::cout << "Beware, "<< enemy.get_name() << " has appeared!" << std::endl;

                // add a fight counter to each player
                hero.add_numfights();
                enemy.add_numfights();

                // fight
                while ((hero.get_hp() > 0) || (enemy.get_hp() > 0)) {       // while either the player or the enemy is alive, fight continues
                    // hero and enemy randomly chooses to attack (damage inflicted) or defend (damage received)
                    int hero_damage = (rand()%10)+1;   // choose a number from 1 to 10
                    int enemy_damage = (rand()%10)+1;
                    assert(hero_damage != 0);
                    assert(enemy_damage != 0);
                    std::cout << "Your damage of: " << hero_damage << std::endl;
                    std::cout << "Enemy damage of: " << enemy_damage << std::endl;
                    std::cout << "Your hp left: " << hero.get_hp() << " and enemy hp left: " << enemy.get_hp() << std::endl;

                    auto enemydefencepts = enemy.get_defencepoints() - hero_damage;     // Reducing number of defence points
                    enemy.set_defencepoints(enemydefencepts);
                    enemydefencepts = enemy.get_hp() - hero_damage;                     // Reducing number of hp points
                    enemy.set_hp(enemydefencepts);
                    auto herodefencepts = hero.get_defencepoints() - enemy_damage;      // Reducing number of defence points
                    hero.set_defencepoints(herodefencepts);
                    herodefencepts = hero.get_hp() - enemy_damage;                      // Reducing number of hp points
                    hero.set_hp(herodefencepts);
                    
                    if (enemy.get_hp() <= 0) {
                        std::cout << enemy.get_name() << "died" << std::endl;
                    }
                    if (hero.get_hp() <= 0) {
                        std::cout << "You died" << std::endl;
                        break;
                    }

                }
                
                
            }
            else if (ingame_choice == 2){
                // rest player
                hero.restore_hp();
            }
            else if (ingame_choice == 3){
                // show the up-to-date player's stats
                std::cout << "Player Name: " << hero.get_name() << std::endl;
                std::cout << "Health Points: " << hero.get_hp() << std::endl;
                std::cout << "Max Health Points: " << hero.get_max_hp() << std::endl;
                std::cout << "Attack Points: " << hero.get_attackpoints() << std::endl;
                std::cout << "Defence Points: " << hero.get_defencepoints() << std::endl;
            }
            else if (ingame_choice == 4){
                // save game stats to a txt file
                std::ofstream player_stats;
                player_stats.open("progress_stats.txt");
                player_stats << hero.get_name() << std::endl;
                player_stats << hero.get_hp() << std::endl;
                player_stats << hero.get_max_hp() << std::endl;
                player_stats << hero.get_attackpoints() << std::endl;
                player_stats << hero.get_defencepoints() << std::endl;
                player_stats.close();
            }
            else if (ingame_choice == 5){
                std::cout << "Exit Game" << std::endl;
                return EXIT_SUCCESS;
            }
            else{
                std::cout << "Wrong choice! Exit game" <<std::endl;
                return EXIT_SUCCESS;
            }
            
        }
        
    }
    else if (choice == 2) {
        std::cout << "Load Game" << std::endl;
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
            std::cout << "No progress file found! Exit game" << std::endl;
            return EXIT_SUCCESS;
        }
        

    }
    else if (choice == 3) {
        std::cout << "Exit Game" << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cout << "Wrong choice! Exit game" <<std::endl;
        return EXIT_SUCCESS;
    }
    
    
    return EXIT_SUCCESS;
}