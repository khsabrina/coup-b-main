#pragma once

//#include "Player.hpp" 
#ifndef __MYHEADER_H__
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;
namespace coup{
    class Player;
class Game{
    public:
        vector<Player*> _players;
        int amout_of_player=0;
        int turn_num;
        bool game_started;
        Game();
        void next_turn();
        void add(Player& player);
        string turn();
        vector<string> players();
        string winner();
};
}