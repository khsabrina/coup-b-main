#pragma once

#ifndef __MYHEADER_H__
#include <iostream>
//#include "Game.hpp"
#include "Player.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;

namespace coup{
class Ambassador : public Player{
    public:
        Ambassador(Game& game, string name): Player(game,name,"Ambassador"){};
        void transfer(Player& duke, Player& assassin);
        void coup(Player& player);
        void block(Player& captain);
};
}