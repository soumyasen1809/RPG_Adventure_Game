#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>

double new_game(const std::string& player_name){
    std::cout << "Hello " << player_name << ", welcome to the game!" << std::endl;

    // Provide player with some initial health points (HP)
    double hp = 100;
    std::cout << "You have " << hp << "health points. Keep an eye on your health. You die if your health becomes zero." << std::endl;

    return hp;
}