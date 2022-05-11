#pragma once
#ifndef __MYHEADER_H__
#include <iostream>
//#include "Game.hpp"
#include "Player.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace coup;
using namespace std;

namespace coup{
class Assassin : public Player{
    public:
        Assassin(Game& game, string name): Player(game,name,"Assassin"){};
        void coup(Player& player);
};
}