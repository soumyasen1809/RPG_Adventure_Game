#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include "player.hpp"

player::player(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints):name(input_name), hp(start_hp), max_hp(max_hp), attack_points(start_attackpoints), defence_points(start_defencepoints){}

player::~player(){}

// void player::set_name(std::string name){name = name;}
void player::set_hp(int hp){this->hp = hp;}
void player::set_max_hp(int max_hp){this->max_hp = max_hp;}
void player::set_attackpoints(int attack_points){this->attack_points = attack_points;}
void player::set_defencepoints(int defence_points){this->defence_points = defence_points;}
void player::add_numfights(){this->num_fights+=1;}
void player::add_level(){this->level+=1;}

std::string player::get_name(){return name;}
int player::get_hp(){return hp;}
int player::get_max_hp(){return max_hp;}
int player::get_attackpoints(){return attack_points;}
int player::get_defencepoints(){return defence_points;}
int player::get_numfights(){return num_fights;}
int player::get_level(){return level;}
int player::get_gold(){return gold;}

void player::showstats(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Maximum HP: " << max_hp << std::endl;
    std::cout << "Attack Points: " << attack_points << std::endl;
    std::cout << "Defence Points: " << defence_points << std::endl;
    std::cout << "You are a: " << get_position() << std::endl;
    std::cout << "Character Level: " << level << std::endl;
    std::cout << "Money: " << gold << std::endl;
}

bool player::is_alive(){return (hp>0) ? true:false;}

void player::restore_hp(){hp = max_hp;}

std::string player::get_position(){return "Player";}

bool player::is_criticalstrike(){return false;}
int player::is_magicused(){return false;}

int player::magic_attack(int spell_num){return 0;}

void player::add_gold(int gold_amount){this->gold+=gold_amount;}
