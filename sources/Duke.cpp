
#ifndef __MYHEADER_H__
#include <iostream>
//#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__
using namespace std;
using namespace coup;
int const NUM1 =7;
int const NUM2 =11;


        void Duke::tax(){
            if(game->turn_num != this->num_turn){
                throw invalid_argument{"not your turn"};
            }
            if(!this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            this->coin = this->coin +3;
            this->last_action[0] = "tax ";
            game->next_turn();
        }
        void Duke::block(Player& player){
            if(!player.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            // if(game->turn_num != this->num_turn){
            //     this->game->next_turn();
            // }
            if(player.last_action[0]!="foreign_aid"){
                throw invalid_argument{"Can't block this type of player"};
            }
            this->last_action[0] = "block";
            this->last_action[1] = player.name;
            this->last_action[2]=player.role();
            player.coin = player.coin -2;
        }
        void Duke::coup(Player& player){
            if(this->coin < NUM1){
                throw invalid_argument{"no money"};
            }
            if(!player.is_active|| !this->is_active){
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
