#include "Game.hpp"
#include <string>
#pragma once

namespace coup{
    class Game;
    class Player{
        private:
        std::string NICKNAME;
        Game *game;
        std::string Player_Action;
        

        public:
        std::string role_class;
        Player();
        Player(Game &game , const std::string &name);
        void income();
        void foreign_aid();
        void coup(Player &p);
        std::string role() const;
        bool is_alive;
        int coins() const;
        int cash;
        int player_id;
        Game* getgame();
        void set_player_id(int x);
        std::string get_NICKNAME();
        std::string set_NICKNAME(std::string NICKNAME);
        std::string get_Player_Action();
        void set_Player_Action(std::string Action);
        std::string get_role_class() const ;
        void CheckCoins() const;
        Player* stolen;
        // std::string set_role_class(std::string role_class);

    };
}