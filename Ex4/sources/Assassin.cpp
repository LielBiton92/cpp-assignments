#include "iostream"
#include <vector>
#include "Assassin.hpp"
const int to_coup = 7;
const int assassin_coup = 3;

using namespace coup;

Assassin::Assassin(Game &game, const std::string &name) : Player(game, name) { this->role_class = "Assassin"; }

Assassin::~Assassin() {}

void Assassin::coup(Player &p)
{
    getgame()->in_game(p);

    if (this->cash < assassin_coup)
    {
        std::cout << "youe have only " << this->coins() << std::endl;
        throw std::invalid_argument("nosst enough coins");
    }
    if (this->cash >= to_coup)
    {
        Player::coup(p);
    }
    if (this->cash >= assassin_coup && this->cash < to_coup)
    {
        this->set_Player_Action("kill");
        p.is_alive = false;
        getgame()->Remove_Player(p);
        this->cash -= assassin_coup;
        getgame()->coupbyassassin = &p;
        getgame()->NextTurn();
    }
}
