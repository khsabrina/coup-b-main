#ifndef __MYHEADER_H__
#include "Captain.hpp"
#include "Player.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;
using namespace coup;
int const NUM1 =7;
int const NUM2 =5;

        void Captain::steal(Player& player){
            if(this->game->turn_num != this->num_turn){
                throw invalid_argument{"not your turn"};
            }
            if(player.coin ==1){
                player.coin = player.coin -1;
                this->coin = this->coin +1;
                this->game->next_turn();
                return;
            }
            if(player.coin ==0){
                this->game->next_turn();
                throw invalid_argument{"no money"};
            }
            this->last_action[0] ="steal";
            this->last_action[1] = player.name;
            this->last_action[2] = player.type;
            player.coin = player.coin -2;
            this->coin = this->coin +2;
            this->game->next_turn();
        }
        void Captain::block(Player& captain){
            if(this->game->turn_num == this->num_turn){
                throw invalid_argument{"not your turn"};
            }
            if(!captain.is_active || !this->is_active){
                throw invalid_argument{"this player is not active"};
            }
            if(captain.type == "Captain"){
                throw invalid_argument{"Can't block this type of player"};
            }
            if(captain.last_action[0]=="steal"){
                throw invalid_argument{"Can't block this type of player"};
            }
            this->last_action[0] = "block";
            this->last_action[1] = captain.name;
            this->last_action[2]=captain.role();
            for(size_t i=0; i<this->game->_players.size();i++){
                if(this->game->_players[i]->name== this->last_action[1] && this->game->_players[i]->type == this->last_action[2]){
                    this->game->_players[i]->coin= this->game->_players[i]->coin+2;
                }
            }
            this->game->next_turn();
        }
        void Captain::coup(Player& player){
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
            this->last_action[1] = player.name;
            this->last_action[2]=player.role();
            player.is_active = false;
            this->coin = this->coin -NUM1;
        }
