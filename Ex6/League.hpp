#include "stdio.h"
#include "vector"
#include "Schedule.hpp"
class Team;
class League{
    private:
        std::vector<Team*> Teams;
        Schedule *sc;

    public:
        League();
        ~League();

        std::vector<Team*>&getTeams();
        void addTeam(Team *t);
        void startLeague();
        void scoreboard(int num );
        void scoreboard();
        static Team* find_max(std::vector<Team*> teams);
        static void remove(std::vector<Team*>&teams ,std::string &name);
        Team *add_random_team();
        void statistic(int num);
        void BestWS();
        void BestLS();
        void statisticScore();
        void HighestScore();
        void LowestScore();
};

