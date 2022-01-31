#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<assert.h>
#include<exception>
#include "mage.hpp"
#include "player.hpp"
#include "gameplay.hpp"

mage::mage(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints, int start_mana, int max_mana, int startmagic):player(input_name, start_hp, max_hp, start_attackpoints, start_defencepoints), mana(start_mana), max_mana(max_mana), magic_num(startmagic){
    if (magic_num >= 3) {
        std::cout << "Wrong magic spell!";
        exit(1);
    }
    
};
mage::~mage(){};

int mage::get_mana(){return mana;}
int mage::get_max_mana(){return max_mana;}

void mage::set_mana(int mana){this->mana = mana;}
void mage::set_max_mana(int max_mana){this->max_mana = max_mana;}

int mage::magic_attack(int spell_num){
    if (spell_num == magic::Cadabra) {
        std::cout << "Hitting with the Hocus spell" << std::endl;
        int mana_used = rand()%mana;      // Using part of mana left (random) for the magic spell
        mana -= mana_used;

    }
    else if (spell_num == magic::Pocus) {
        std::cout << "Hitting with the Pocus spell" << std::endl;
        int mana_used = mana;      // Using complete mana left for the magic spell
        mana -= mana_used;
    }
    else if (spell_num == magic::Hocus) {
        std::cout << "Hitting with the Cadabra spell" << std::endl;
        int mana_used = 0.5*mana;      // Using half of mana left for the magic spell
        mana -= mana_used;
    }
    
    return mana;
}

void mage::restore_hp(){
    this->set_hp(this->get_max_hp());
    mana = max_mana;
}

std::string mage::get_position(){return "Mage";}

int mage::is_magicused(){
    int magic_use_input;
    std::cout << "Do you want to use magic? Press 0 for Hocus, 1 for Pocus, 2 for Cadabra, 3 for no magic" << std::endl;
    std::cin >> magic_use_input;
    if (magic_use_input == 0) {
        this->magic_num = 0;
    }
    else if (magic_use_input == 1) {
        this->magic_num = 1;
    }
    else if (magic_use_input == 2) {
        this->magic_num = 2;
    }
    
    this->magic_num = -1;       // if not magic, then magic number = -1
    return this->magic_num;
}