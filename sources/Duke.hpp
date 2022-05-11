#pragma once

#ifndef __MYHEADER_H__
#include <iostream>
//#include "Game.hpp"
#include "Player.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__


namespace coup{
    class Duke : public Player{
        public:
            Duke(Game& game, string name): Player(game,name,"Duke"){};
            void tax();
            void block(Player& player);
            void coup(Player& player);
    };
}