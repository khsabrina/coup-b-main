//#pragma once

#ifndef __MYHEADER_H__
#include "Player.hpp" 
//#include "Game.hpp" 
#include <iostream>
//#include "Game.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <string>
#define __MYHEADER_H__
#endif // __MYHEADER_H__

using namespace std;
using namespace coup;
int const MAGIC_NUMBER = 6;



        Game::Game(){
            this->_players.reserve(MAGIC_NUMBER);
            this->amout_of_player=0;
            this->turn_num=1;
            this->game_started = false;
        }
        void Game::next_turn(){
            if(turn_num == amout_of_player){
            for(size_t i=0;i<amout_of_player;i++){
                if(this->_players[i]->is_active && this->_players[i]->num_turn != turn_num){
                    //cout << amout_of_player;
                    turn_num = (int)i+1;
                    //cout << turn_num;
                    return;
                    }
                }
            }
            for(size_t i=(size_t)turn_num-1;i<amout_of_player;i++){
                if(this->_players[i]->is_active && this->_players[i]->num_turn != turn_num){
                    //cout << amout_of_player;
                    turn_num = (int)i+1;
                    //cout << turn_num;
                    return;
                }
            }
            for(size_t i=0;i<amout_of_player;i++){
                if(this->_players[i]->is_active){
                    if(turn_num == i+1){
                        winner();
                        return;
                    }
                    turn_num = (int)i+1;
                    return;
                }
            }
            //cout << turn_num;
        }
        void Game::add(Player& player){
            if(this->amout_of_player == MAGIC_NUMBER){
                throw invalid_argument{"there is 6 players"};
            }
            if (this->game_started){
                throw invalid_argument{"game started"};
            }
            _players.push_back(&player);
            this->amout_of_player= this->amout_of_player + 1;
            player.num_turn = this->amout_of_player;
            //cout << player.num_turn << '\n';
        }
        string Game::turn(){
            return _players[(size_t)(turn_num-1)]->name;
        }
        vector<string> Game::players(){
            size_t count=0;
            for(size_t i=0;i< this->_players.size(); i++){
                if( _players[i]->is_active){
                    count++;
                }
            }
            //cout << count << "\n";
            vector<string> str_players(count);
            count =0;
            //str_players.reserve((size_t)this->amout_of_player);
            //cout << "\n" << this->_players.size();
            for(size_t i=0;i< this->_players.size(); i++){
                if( _players[i]->is_active){
                    str_players[count] = _players[i]->name;
                    count++;
                }
            }
            // for(size_t i=0;i< this->amout_of_player; i++){
            //     cout << str_players[i];
            // }
            return str_players;
        }
        string Game::winner(){
            if(this->amout_of_player == 1){
                throw invalid_argument{"there is 1 players"};
            }
            int count =0;
            string winner;
            for(size_t i=0;i< this->_players.size(); i++){
                if(count >= 2){
                    throw invalid_argument{"Can't block this type of player"};
                }
                
                if( this->_players[i]->is_active){
                    winner = this->_players[i]->name;
                    count++;
                }
            }
            if(count >1){
                throw invalid_argument{"there is 6 players"};
            }
            return winner;
        }
