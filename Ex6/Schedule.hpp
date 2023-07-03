#include <vector>
#include "Game.hpp"
class Team;
class Schedule{ 
    private:
        std::vector<Team*> sche;
        std::vector<Game*>games;
    public:
        Schedule(std::vector<Team*>&sched);
        // ~Schedule();
        std::vector<Game*>get_games();
};