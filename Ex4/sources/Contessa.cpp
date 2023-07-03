#include "iostream"
#include <vector>
#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game &game, const std::string &name) : Player(game, name) { this->role_class = "Contessa"; }

Contessa::~Contessa() {}

void Contessa::block(Player &p)
{
    getgame()->in_game(p);
    if (p.get_role_class() != "Assassin")
    {
        throw std::logic_error("cAssassin");
    }

    if (p.get_Player_Action() == "kill")
    {

        Player * p2 = getgame()->coupbyassassin;
        p2 -> is_alive = true;
        getgame()->Players_in_game.insert(getgame()->Players_in_game.begin() + p2->player_id, *p2);
       
    }
    else
    {
        throw std::logic_error("last action was not a coup");
    }
}
