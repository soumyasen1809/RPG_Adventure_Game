#ifndef MAGE_HPP
#define MAGE_HPP

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

class mage: virtual public player
{
private:
    int mana;
    int max_mana;
    enum magic {Hocus, Pocus, Cadabra, Iceball, Fireball, Lightning};
    int magic_num = 0;
public:
    mage(std::string input_name, int start_hp, int max_hp, int start_attackpoints, int start_defencepoints, int start_mana, int max_mana, int start_magic);
    ~mage();

    // Getter functions
    int get_mana();
    int get_max_mana();

    // Setter functions
    void set_mana(int mana);
    void set_max_mana(int max_mana);

    // Other methods
    int is_magicused() override;
    int magic_attack(int spell_num);
    void restore_hp() override;
    std::string get_position() override;
};



#endif          // mage.hpp define close