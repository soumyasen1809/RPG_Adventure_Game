#include<iostream>
#include<gtest/gtest.h>
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

TEST(TestSuite_Gameplay, MaxHP){
    player bot("Bot_testMaxHP", 55, 100, 19, 10);
    ASSERT_LE(bot.get_hp(), bot.get_max_hp());        // HP of a player must be less than equal to MaxHP
}

TEST(TestSuite_Player, TraineeTest){
    trainee bot("TraineeBot", 0, 0, 0, 0);
    EXPECT_EQ(bot.get_position(), "Trainee");       // use EXPECT_EQ for std::string, use EXPECT_STREQ for C string comparison
}
TEST(TestSuite_Player, FighterTest){
    fighter bot("FighterBot", 0, 0, 0, 0);
    EXPECT_EQ(bot.get_position(), "Fighter");
}
TEST(TestSuite_Player, MageTest){
    mage bot("MageBot", 0, 0, 0, 0, 0, 0, 0);
    EXPECT_EQ(bot.get_position(), "Mage");
}
TEST(TestSuite_Player, PlayerTest){
    player bot("PlayerBot", 0, 0, 0, 0);
    EXPECT_EQ(bot.get_position(), "Player");
}

