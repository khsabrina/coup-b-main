
#ifndef __MYHEADER_H__
#include <iostream>
#include "Assassin.hpp"
#define __MYHEADER_H__
#endif // __MYHEADER_H__
using namespace coup;
using namespace std;
int const NUM1 =3;
int const NUM2 =7;
int const NUM3 =10;
        void Assassin::coup(Player& player){
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
            if(this->coin >NUM2){
                this->last_action[0] = "coup no contessa";
                this->coin = this->coin -NUM2;
            }
            else{
            this->coin = this->coin -NUM1;
            }
        }
