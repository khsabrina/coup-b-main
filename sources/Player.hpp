#pragma once
#ifndef __MYHEADER_H__
#include "Game.hpp" 
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;
namespace coup{
class Player{
    public:
        int num_turn;
        int coin;
        string name;
        string type;
        string last_action[3];
        Game* game;
        bool is_active;
        Player(Game& g, string n, string type);
        void income();
        void foreign_aid();
        int coins() const;
        string role() const;

};
}