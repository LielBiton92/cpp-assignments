#include "iostream"
#include <vector>
#include "Duke.hpp"
using namespace coup;

Duke::Duke(Game &game, const std::string &name) : Player(game, name) { this->role_class = "Duke"; }

Duke::~Duke() {}

void Duke::tax()
{
    getgame()->Check_Turn(*this);
    this->CheckCoins();
    this->cash += 3;
    getgame()->NextTurn();
}

void Duke::block(Player &p)
{
    // this->CheckCoins();

    getgame()->in_game(p);
    if (p.get_Player_Action() == "foreign_aid")
    {
        p.cash -= 2;
    }
    else
    {
        throw std::logic_error("cant blow income");
    }
}
