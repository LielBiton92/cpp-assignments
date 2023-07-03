#pragma once
#include "vector"
#include <string>

namespace coup{
    class Player;
    class Game{
        protected:
        public:
        unsigned int Turn_counter;
        int num_of_players();
        int numberofactions;
        std::vector<Player> Players_in_game;
        Game();
        std::vector<std::string> players(); 
        std::vector<Player *> dead_players;
        std::string turn();
        std::string winner();
        void check_Winner();
        void Add_Player(Player &p);
        void Remove_Player(Player &p);
        void in_game(Player &p);
        void Check_Turn(Player &p) const ;
        Player *coupbyassassin = NULL;
        void sort();
        void swap(Player &p1 , Player &p2);
        void NextTurn();





    };

}