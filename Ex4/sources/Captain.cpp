#include "iostream"
#include <vector>
#include "Captain.hpp"
using namespace coup;
Captain::Captain(Game &game, const std::string &name) : Player(game, name) { this->role_class = "Captain"; }

Captain::~Captain() {}

void Captain::block(Player &p)
{
    getgame()->Check_Turn(*this);
    if(p.get_NICKNAME()!="Captain"){
        throw std::logic_error("can block only captain");
    }
    this->set_Player_Action("block");
    this->CheckCoins();
    getgame()->in_game(p);

    if (p.get_Player_Action() == "steal")
    {
        p.cash -= 2;
        (stolen)->cash += 2;
    }
}

void Captain::steal(Player &p)
{
    getgame()->Check_Turn(*this);
    this->CheckCoins();
    getgame()->in_game(p);
    this->set_Player_Action("steal");
    if (p.cash == 1)
    {
        p.cash -= 1;
        this->cash += 1;
        this->stolen = &p;
        getgame()->NextTurn();
    }
    if (p.cash >= 2)
    {
        this->cash += 2;
        p.cash-=2;
        this->stolen = &p;
        getgame()->NextTurn();
    }
}
