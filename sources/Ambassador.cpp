#include <iostream>

#ifndef __MYHEADER_H__
//#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__
using namespace std;
using namespace coup;
int const NUM1=7;
int const NUM2= 5;

        void Ambassador::transfer(Player& duke, Player& assassin){
            if(this->game->turn_num != this->num_turn){
                throw invalid_argument{"not your turn"};
            }
            if(!duke.is_active|| !assassin.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            if(duke.coin<1){
                throw invalid_argument{"no money"};
            }
            assassin.coin++;
            duke.coin--;
            string name_player = duke.name + assassin.name;
            string type_player = duke.type + assassin.type;
            this->last_action[0] = "transfer ";
            this->game->next_turn();
        }
        void Ambassador::block(Player& captain){
            if(this->game->turn_num == this->num_turn){
                throw invalid_argument{"not your turn"};
            }
            if(!captain.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            if(captain.type != "Captain"){
                throw invalid_argument{"Can't block this type of player1"};
            }
            if(captain.last_action[0] != "steal"){
                throw invalid_argument{"Can't block this type of player"};
            }
            this->last_action[0] = "block";
            this->last_action[1] = captain.last_action[1];
            this->last_action[2]=captain.last_action[2];
            for(size_t i=0; i<this->game->_players.size();i++){
                if(this->game->_players[i]->name==this->last_action[1] && this->game->_players[i]->type==this->last_action[2]){
                    this->game->_players[i]->coin= this->game->_players[i]->coin+2;
                }
            }
            captain.coin=captain.coin-2;
            this->game->next_turn();
        }
        void Ambassador::coup(Player& player){
            if(this->coin < NUM1){
                throw invalid_argument{"no money"};
            }
            if(!player.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            if(this->game->turn_num == this->num_turn){
                this->game->next_turn();
            }
            this->last_action[0] = "coup";
            this->last_action[1]=player.name;
            this->last_action[2]=player.type;
            player.is_active = false;
            this->coin = this->coin -NUM1;
        }
