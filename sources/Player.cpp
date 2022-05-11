#ifndef __MYHEADER_H__
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include "Player.hpp" 
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;
using namespace coup;
int const NUM1=10;

        Player::Player(Game& g, string n, string type){
            this->name = move(n);
            this->game = &g;
            this->coin=0;
            this->type = move(type);
            this->is_active =true;
            this->num_turn =0;
            this->game->add(*this);
            // cout << this->num_turn << '\n';
            // cout << this->game->turn_num;
        }
        void Player::income(){
            if(this->game->amout_of_player == 1){
                throw invalid_argument{"there is 1 players"};
            }
            if(this->coin >=NUM1){
                throw invalid_argument{"do coup"};
            }
            this->game->game_started= true;
            // cout << this->game->turn_num << '\n';
            // cout << this->num_turn << '\n';
            if(this->game->turn_num != this->num_turn){
                throw invalid_argument{"not your turn"};
                //cout << "\n" << this->game->turn_num << " " <<this->num_turn;
            }
            this->coin+=1;
            this->last_action[0] = "income ";
            this->game->next_turn();
        }
        string Player::role() const{
            return this->type;
        }
        void Player::foreign_aid(){
            if(this->coin >=NUM1){
                throw invalid_argument{"do coup"};
            }
            if(this->game->amout_of_player == 1){
                throw invalid_argument{"there is 1 players"};
            }
            this->game->game_started= true;
            if(this->game->turn_num != this->num_turn){
                throw invalid_argument{"not your turn"};
            }
            coin+=2;
            this->last_action[0] = "foreign_aid";
            this->game->next_turn();
        }
        int Player::coins() const{
            return this->coin;
        }

