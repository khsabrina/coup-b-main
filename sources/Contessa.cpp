
#ifndef __MYHEADER_H__
//#include "Game.hpp"
//#include "Player.cpp"
#include "Contessa.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__
#include <iostream>


//#include "Game.hpp" 
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
using namespace coup;
int const NUM1 =7;


        void Contessa::block(Player& assassin){
            if(!assassin.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            if(assassin.type !="Assassin" || assassin.last_action[0]!="coup"){
                throw invalid_argument{"Can't block this type of player"};
            }
            // if(this->game->turn_num == this->num_turn){
            //     this->game->next_turn();
            // }
            // if(assassin.last_action[0]!="coup"){
            //     throw invalid_argument{"Can't block this type of player1"};
            // }
            this->last_action[0] = "block";
            this->last_action[1] = assassin.name;
            this->last_action[2]=assassin.role();
            for(size_t i=0; i<this->game->_players.size();i++){
                if(this->game->_players[i]->name == assassin.last_action[1]){
                    cout << "here" << "\n";
                    if(this->game->_players[i]->type ==assassin.last_action[2]){
                        cout << this->game->_players[i]->name;
                        this->game->_players[i]->is_active = true;
                    }
                }
            }
            //this->game->next_turn();
        }
        void Contessa::coup(Player& player){
            if(this->coin < NUM1){
                throw invalid_argument{"no money"};
            }
            if(!player.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            this->last_action[0] = "coup";
            this->last_action[1] = player.name;
            this->last_action[2]=player.role();
            player.is_active = false;
            this->coin = this->coin -NUM1;
            if(this->game->turn_num == this->num_turn){
                this->game->next_turn();
            }
        }
