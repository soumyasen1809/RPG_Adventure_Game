#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include "new_game.hpp"

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
        double hp = new_game(player_name);
        
        // show in-game menu while hp > 0
        while (hp > 0){
            int ingame_choice;
            std::cout << "Choose from in-game menu: 1 to fight, 2 to show stats, 3 to save the game, 4 to exit the game" << std::endl;
            std::cout << "Remember to save your progress before quiting the game: ";
            std::cin >> ingame_choice;
            if (ingame_choice == 1){
                /* code */
            }
            else if (ingame_choice == 2){
                // show the up-to-date player's stats
                std::cout << "Name: " << player_name << std::endl;
                std::cout << "Health Points: " << hp << std::endl;
            }
            else if (ingame_choice == 3){
                // save game stats to a txt file
                std::ofstream player_stats;
                player_stats.open("progress_stats.txt");
                player_stats << player_name << std::endl;
                player_stats << hp << std::endl;
                player_stats.close();
            }
            else if (ingame_choice == 4){
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