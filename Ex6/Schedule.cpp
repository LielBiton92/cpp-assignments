#include "Schedule.hpp"
const int HALF_GAMES = 10;
// Schedule::~Schedule(){}
Schedule::Schedule(std::vector<Team*>&sched){
    this->sche=sched;
        unsigned int v = 0;
    for(unsigned int i = 0 ; i <sche.size()-1;i++){
        unsigned int j = 0 ;
        unsigned int k = sche.size()-1;
        while(j < HALF_GAMES){
            // std::cout << "round num "<< i << " ";
            // std::cout << "Team 1 : " << this->sche.at(j)->getname() << " Team2" <<this->sche.at(k)->getname()<<std::endl; 
            Game *g = new Game(this->sche.at(j) ,this->sche.at(k));
            this->games.push_back(g);
            // std::cout << " game number "<< v++ <<std::endl;
            j++;
            k--;
        }
        this->sche.insert(this->sche.begin()+1,*(this->sche.erase(this->sche.end()-1)));



    }
    for(unsigned int i = 0 ; i <sche.size()-1;i++){
        unsigned int j = 0 ;
        unsigned int k = sche.size()-1;
        while(j < HALF_GAMES){
            // std::cout << "round num "<< i <<" ";
            // std::cout << "Team 1 : " << this->sche.at(k)->getname() << " Team2" <<this->sche.at(j)->getname()<<std::endl; 
            Game *g = new Game(this->sche.at(j) ,this->sche.at(k));
            this->games.push_back(g);
            // std::cout << " game number "<< v++ <<std::endl;
            j++;
            k--;
        }
        this->sche.insert(this->sche.begin()+1,*(this->sche.erase(this->sche.end()-1)));


    }
}
std::vector<Game*> Schedule::get_games(){return this->games;}
