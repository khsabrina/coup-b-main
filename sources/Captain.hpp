#pragma once
#ifndef __MYHEADER_H__
//#include "Game.hpp"
#include "Player.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__
#include <iostream>

namespace coup{
class Captain : public Player{
    public:
        Captain(Game& game, string name): Player(game,name,"Captain"){};
        void steal(Player& player);
        void block(Player& captain);
        void coup(Player& player);
};
}