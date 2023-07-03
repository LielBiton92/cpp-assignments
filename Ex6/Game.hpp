#include "Team.hpp"
#include <cmath>
#include <random>

class Game{
    private:
        Team *Home;
        Team *OutTeam;
        int total_points_of_game;
        int homeScore;
        int outScore;
        

    public:
        double get_home_score()const;
        double get_out_score()const;
        int get_total_points_of_game()const;


        Game(Team *Home , Team *Out);
        // ~Game();
        void ScoreGame();


};