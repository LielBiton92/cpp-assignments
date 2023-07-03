#include "iostream"
#include "Game.hpp"
#include "vector"
#include <string>
#include "Player.hpp"
#include <bits/stdc++.h>
using namespace coup;
const int MAX = 6;
Game::Game()
{
    this->Players_in_game.resize(0);
    this->Turn_counter = 0;
    this->numberofactions=0;
}

std::vector<std::string> Game::players()
{
    std::vector<std::string> Players;
    for (unsigned int i = 0; i < this->Players_in_game.size(); i++)
    {
        Players.push_back(this->Players_in_game.at(i).get_NICKNAME());
    }
    return Players;
}



void Game::Add_Player(Player &p)
{
    if (this->Players_in_game.size() >= MAX)
    {
        throw std::logic_error("to many players");
    }
    if (this->Turn_counter > 0)
    {
        throw std::logic_error("game already started");
    }
    int i = this->Players_in_game.size();
    this->Players_in_game.push_back(p);
    p.player_id=i;
    dead_players.push_back(&p);
    this->numberofactions++;
}





void Game::Remove_Player(Player &p)
{


        for (unsigned int i = 0; i < Players_in_game.size(); i++)
        {
            if (Players_in_game.at(i).get_NICKNAME() == p.get_NICKNAME())
            {
                auto it = Players_in_game.begin() + i;
                Players_in_game.erase(it);
            }
        }

}

std::string Game::turn()
{

    return this->Players_in_game.at(this->Turn_counter).get_NICKNAME();
}

void Game::NextTurn(){
    this->Turn_counter++;
    if(this->Turn_counter==this->dead_players.size()){
        this->Turn_counter=0;
    }
    while(!this->dead_players.at(this->Turn_counter)->is_alive){
        this->Turn_counter++;
        if(this->Turn_counter==this->dead_players.size()){
            this->Turn_counter=0;
    }
    }

}

void Game::Check_Turn(Player &p) const
{
    // if (this->turn() != p.get_NICKNAME())
    // {
    //     throw std::logic_error("its not your turn");
    // }
    if (this->Players_in_game.size() == 1)
    {
        throw std::logic_error("not enough players");
    }
    if (Turn_counter != p.player_id) {
        throw std::logic_error("asd0");
    }
}


std::string Game::winner()
{
        if (numberofactions <=1)
    {
        throw std::logic_error("not enough players");
    }
    

    if (this->Players_in_game.size() == 1 )
    {
        return this->Players_in_game.at(0).get_NICKNAME();
    }

    throw std::runtime_error("game is alive");
}

void Game::in_game(Player &p)
{
    bool flag = true;
    std::vector<std::string> playersingame = this->players();
    for (std::string &name : playersingame)
    {
        if (name == p.get_NICKNAME())
        {
            flag = false;
        }
    }
    if (flag)
    {
        throw std::logic_error("player is not in game");
    }
}
