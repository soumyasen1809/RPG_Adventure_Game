#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include<cstdlib>
#include<memory>
#include "player.hpp"
#include "gameplay.hpp"

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
        player hero(player_name, 55, 100, 25, 10);
        std::unique_ptr<player> good = std::make_unique<player>(hero);
        assert(good->get_hp() > 0);
        assert(good->get_max_hp() > 0);
        std::cout << "Hello " << good->get_name() << ", welcome to the game!" << std::endl;  // welcome message to the player
        
        // show in-game menu while hp > 0
        while (good->get_hp() > 0){
            int ingame_choice = 0;  // Default value set as 0, so that if user doesn't enter any value, the else condition is run
            std::cout << "Choose from in-game menu: 1 to fight, 2 to rest, 3 to show stats, 4 to save the game, 5 to exit the game" << std::endl;
            std::cout << "Remember to save your progress before quiting the game: ";
            std::cin >> ingame_choice;

            if (ingame_choice == 1){
                // fight with the enemy
                player enemy("Goblin", 12, 25, 15, 15);       // create a player enemy
                std::unique_ptr<player> bad = std::make_unique<player>(enemy);
                assert(bad->get_hp() > 0);
                assert(bad->get_max_hp() > 0);
                std::cout << "Beware, "<< bad->get_name() << " has appeared!" << std::endl;
                std::cout << "You starting the fight with hp of: " << good->get_hp() << " and enemy has hp of: " << bad->get_hp() << std::endl;

                // add a fight counter to each player
                good->add_numfights();
                bad->add_numfights();

                // fight
                while (good->is_alive() && bad->is_alive()) {
                    gameplay::fight(good, bad);       // while either the player or the enemy is alive, fight continues
                    if (!bad->is_alive()) {
                        std::cout << bad->get_name() << " died" << std::endl;
                    }
                    if (!good->is_alive()) {
                        std::cout << "You died" << std::endl;
                        return EXIT_SUCCESS;
                    }
                }
                
            }

            else if (ingame_choice == 2){
                // rest player
                gameplay::rest(good);
            }

            else if (ingame_choice == 3){
                // show the up-to-date player's stats
                gameplay::display_stats(good);
            }

            else if (ingame_choice == 4){
                // save game stats to a txt file
                gameplay::save_game(good);
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
        gameplay::load_game();       

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
