#pragma once
#ifndef __MYHEADER_H__
#include <iostream>
#include "Player.hpp"
//#include "Game.hpp" 
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;
using namespace coup;

namespace coup{
    class Contessa : public Player{
        public:
            Contessa(Game& game, string name): Player(game,name,"Contessa"){};
            void block(Player& assassin);
            void coup(Player& player);
    };
}