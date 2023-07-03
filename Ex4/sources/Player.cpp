#include "iostream"
#include <vector>
#include "Player.hpp"
using namespace coup;

const int to_coup = 7;
const int must_coup = 10;
Player::Player()
{
    this->cash = 0;
    this->player_id = getgame()->Players_in_game.size();
    this->game->Add_Player(*this);
    this->is_alive = true;
    this->stolen = NULL;
    this->game= NULL;
}
Player::Player(Game &game, const std::string &name)
{
    this->NICKNAME = name;
    this->cash = 0;
    this->game = &game;
    this->player_id = getgame()->Players_in_game.size();
    this->game->Add_Player(*this);
    this->is_alive = true;
    this->stolen = NULL;
}

void Player::income()
{
    getgame()->Check_Turn(*this);
    this->CheckCoins();
    this->set_Player_Action("income");
    this->cash++;
    getgame()->NextTurn();
}
void Player::foreign_aid()
{
    getgame()->Check_Turn(*this);
    this->CheckCoins();
    this->set_Player_Action("foreign_aid");
    this->cash += 2;
    getgame()->NextTurn();

}
void Player::coup(Player &p)
{


    if (this->cash < to_coup && this->role_class != "Assassin")
    {
        throw std::logic_error("not enough coins to coup");
    }
    getgame()->Check_Turn(*this);
    getgame()->in_game(p);
    this->set_Player_Action("coup");
    p.is_alive = false;
    getgame()->Remove_Player(p);
    this->cash -= to_coup;
    getgame()->NextTurn();
}

Game *Player::getgame()
{
    return game;
}
int Player::coins() const
{
    return this->cash;
}
std::string Player::role() const
{
    return this->role_class;
}

std::string Player::get_NICKNAME()
{
    return this->NICKNAME;
}
std::string Player::set_NICKNAME(std::string NICKNAME)
{
    return this->NICKNAME = std::move(NICKNAME);
}
std::string Player::get_Player_Action()
{
    return this->Player_Action;
}
void  Player::set_Player_Action(std::string Action)
{
    this->Player_Action = std::move(Action);
}
void Player::CheckCoins() const
{
    if (this->cash >= must_coup)
    {
        throw std::logic_error("must coup");
    }
}
void Player::set_player_id(int x)
{
    this->player_id = x;
}

std::string Player::get_role_class() const{return this->role_class;} 

// void Player::set_role_class(std::string role_class){
//     this->role_class = role_class;
// }
