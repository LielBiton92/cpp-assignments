#include "iostream"
#include <vector>
#include "Ambassador.hpp"
using namespace coup;

Ambassador::Ambassador(Game &game, const std::string &name) : Player(game, name) { this->role_class = "Ambassador"; }

Ambassador::~Ambassador() {}

void Ambassador::transfer(Player &p1, Player &p2)
{
    getgame()->Check_Turn(*this);
    this->CheckCoins();
    getgame()->in_game(p1);
    getgame()->in_game(p2);
    if (p1.cash < 1)
    {
        throw std::logic_error("player have no cash");
    }
    p1.cash -= 1;
    p2.cash += 1;
    getgame()->NextTurn();
}

void Ambassador::block(Player &p)
{
    this->CheckCoins();
    getgame()->in_game(p);
    std::cout << p.get_Player_Action() << std::endl;
    if (p.get_Player_Action() == "steal")
    {
        std::cout << "asdsadasdsad" << std::endl;
        p.cash -= 2;
        p.stolen->cash +=2;
    }
}
