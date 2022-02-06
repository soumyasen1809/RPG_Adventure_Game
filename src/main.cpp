#include<iostream>
#include<gtest/gtest.h>
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
#include "trainee.hpp"
#include "fighter.hpp"
#include "mage.hpp"
#include "bot_simulation.hpp"

int main(){
    // Creating the main menu
    int choice;
    std::cout << "Enter 1 to start a new game, 2 to load previous game, 3 to simulate and 4 to exit: ";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "New Game" << std::endl;
        std::string player_name;
        std::cout << "Enter your player name: ";
        std::cin >> player_name;

        // Create a player hero_trainee
        trainee hero_trainee(player_name, 55, 100, 19, 10);
        std::unique_ptr<player> good = std::make_unique<trainee>(hero_trainee);         // players start game as a trainee
        assert(good->get_hp() > 0);
        assert(good->get_max_hp() > 0);
        std::cout << "Hello " << good->get_name() << ", welcome to the game! You are a trainee." << std::endl;  // welcome message to the player

        // Create the enemy class
        std::unique_ptr<player> bad;

        int player_level_check = 0;
        
        // show in-game menu while hp > 0
        while (good->get_hp() > 0){
            int ingame_choice = 0;  // Default value set as 0, so that if user doesn't enter any value, the else condition is run
            std::cout << "Choose from in-game menu: 1 to fight, 2 to rest, 3 to show stats, 4 to save the game, 5 to exit the game" << std::endl;
            std::cout << "Remember to save your progress before quiting the game: ";
            std::cin >> ingame_choice;

            // Check if the player has levelled up
            if ((good->get_level() > 3) && (good->get_level() < 5) && (player_level_check == 0)) {
                // Upgrade the player
                fighter hero_fighter(player_name, 100, 200, 50, 30);
                good = std::make_unique<fighter>(hero_fighter);
                std::cout << "You upgraded to a fighter!" << std::endl;
                good->add_gold(10);
                std::cout << "$$ You get 10 gold $$" << std::endl;
                player_level_check = 1;         // Put a value of player_lelvel_check = 1 so that fighter level is not checked again
            }
            else if ((good->get_level() >= 5) && (player_level_check == 1)) {
                // Upgrade the player
                mage hero_mage(player_name, 200, 300, 100, 50, 20, 50, 0);
                good = std::make_unique<mage>(hero_mage);
                std::cout << "You upgraded to a mage!" << std::endl;
                good->add_gold(20);
                std::cout << "$$ You get 20 gold $$" << std::endl;
                player_level_check = 2;         // Put a value of player_lelvel_check = 2 so that mage level is not checked again
            }
            

            if (ingame_choice == 1){
                // fight with the enemy
                if (good->get_position() == "Fighter") {
                    player enemy("MegaGob", 70, 145, 35, 25);       // create a player enemy
                    bad = std::make_unique<player>(enemy);
                }
                else if (good->get_position() == "Mage") {
                    player enemy("UltiGob", 170, 245, 75, 65);       // create a player enemy
                    bad = std::make_unique<player>(enemy);
                }
                else {
                    player enemy("Gob", 20, 40, 15, 10);       // create a player enemy
                    bad = std::make_unique<player>(enemy);
                }
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
                        good->add_level();           // level up player after every successful fight
                        good->add_gold(2);
                        std::cout << "$$ You get 2 gold $$" << std::endl;
                    }
                    if (!good->is_alive()) {
                        std::cout << "You died" << std::endl;   // Not saving the round in which player died
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
        std::cout << "Starting simulation with bot" << std::endl;
        bot_simulation::simulate();
    }
    

    else if (choice == 4) {
        std::cout << "Exit Game" << std::endl;
        return EXIT_SUCCESS;
    }

    else {
        std::cout << "Wrong choice! Exit game" <<std::endl;
        return EXIT_SUCCESS;
    }
    
    
    return EXIT_SUCCESS;
}
