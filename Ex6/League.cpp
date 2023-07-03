#include "League.hpp"
#include <stdexcept>
const int NUM_OF_TEAMS = 20;

League::League(){
    this->sc = NULL;
}
League::~League(){
    for(unsigned int i = 0 ; i < this->sc->get_games().size();i++){
        delete this->sc->get_games()[i];
    }
    delete this->sc;
    for(unsigned int i = 0 ; i < this->getTeams().size() ; i++){
        delete this->getTeams()[i];
    }

}

Team* League::add_random_team(){
    unsigned int i = 1;
    unsigned int j = 0;
    std::string to_add = "Barcelona";
    while(j < this->getTeams().size()){
        to_add = "Barcelona"+ std::to_string(i);
        if(this->getTeams()[j]->getname()==to_add){
            i++;
            j=0;
        }
        j++;
    }
    double random_talent = ((double) rand() / (RAND_MAX))+1;
    Team *randomTeam = new Team(to_add , random_talent);
    return randomTeam;
}

std::vector<Team*> &League::getTeams(){return this->Teams;}

void League::addTeam(Team *t){this->Teams.push_back(t);if(this->Teams.size()>NUM_OF_TEAMS){throw ("max teams is 20");}}

void League::startLeague(){
    while(this->getTeams().size()<NUM_OF_TEAMS){

        this->addTeam(add_random_team());
    }
    this->sc = new Schedule(this->getTeams());
}



void League::scoreboard(int num ){
    for(unsigned int i  = 0 ; i <this->getTeams().size();i++){
        std::cout << *this->getTeams()[i]<<std::endl;
    }
    std::cout << "*********************************"<<std::endl;
    std::vector<Team*>temp;
    for(unsigned int i = 0 ; i < this->getTeams().size();i++){
        temp.push_back(this->getTeams()[i]);
    }
    std::vector<Team*>res;
    for(unsigned int i = 0 ;i < this->getTeams().size() ; i++){
        Team *t = find_max(temp);
        res.push_back(find_max(temp));
        League::remove(temp ,t->getname());
    }
    for(unsigned int i = 0 ; i < res.size();i++){
        std::cout<< i+1 << "." << *res[i]<<std::endl;
        if(i == num-1){
            break;
        }

    }

}
void League::scoreboard(){
     this->scoreboard(this->getTeams().size());
}

Team* League::find_max(std::vector<Team*>teams){
    unsigned int i = 0;
    Team *ans = teams[0];
    for(i = 1 ; i < teams.size();i++){
        if(*teams[i]> *ans){
            // std::cout << "teams[i] wins : "<< teams[i]->get_wins() << "  ans wins : "<< ans->get_wins()<<std::endl;
            ans = teams[i];
        }
        else if(*teams[i]==*ans){
            if(teams[i]->get_total_points()-teams[i]->get_Points()>ans->get_total_points()-ans->get_Points()){
                ans = teams[i];
            }
        }
    }
    // std::cout << " ans  "<< ans->get_wins()<< std::endl;
    return ans;
}

 void League::remove(std::vector<Team*>&teams ,std::string &name){
    unsigned int j=0 ;
    for(unsigned int i = 0 ; i < teams.size();i++){
        if(teams[i]->getname()==name){
            j = i ;
        }
    }
    teams.erase(teams.begin()+j);
    // std::cout<<"size " << teams.size()<<std::endl;
}

void League::BestWS(){
        Team* BestWS = this->getTeams()[0];
    for(unsigned int i = 0 ; i < this->getTeams().size();i++ ){
        if(this->getTeams()[i]->get_LongestWS()>=BestWS->get_LongestWS()){
            BestWS = this->getTeams()[i];
        }
    }
    std::cout << "Best Win Streak is "<< BestWS->get_LongestWS()<< " by "<< BestWS->getname()<<std::endl;
}

void League::BestLS(){
        Team* BestLS = this->getTeams()[0];
    for(unsigned int i = 1 ; i < this->getTeams().size();i++ ){
        if(this->getTeams()[i]->get_LongestLS()>=BestLS->get_LongestLS()){
            BestLS = this->getTeams()[i];
        }
    }
    std::cout << "Best loss Streak is "<< BestLS->get_LongestWS()<< "  by "<< BestLS->getname()<<std::endl;

}

void League::statisticScore(){
    int j = 0 ; 
    for(unsigned int i = 1 ; i < this->getTeams().size();i++){
        if(this->getTeams()[i]->get_total_points()-this->getTeams()[i]->get_Points() > 0){
            j++;
        }
    }
    std::cout << j << "Teams "<<std::endl;
}

void League::HighestScore(){
    Game *high = this->sc->get_games()[0];
    for(unsigned int i = 1 ; i <this->sc->get_games().size();i++){
        if(this->sc->get_games()[i]->get_total_points_of_game()>high->get_total_points_of_game()){
            high = this->sc->get_games()[i];
        }
    }
    std::cout << "highest score : "<< high->get_total_points_of_game() << " game result :" << high->get_home_score() <<" - "<< high->get_out_score()<<std::endl;  
}

void League::LowestScore(){
    Game *low = this->sc->get_games()[0];
    for(unsigned int i = 1 ; i <this->sc->get_games().size();i++){
        if(this->sc->get_games()[i]->get_total_points_of_game()<low->get_total_points_of_game()){
            low = this->sc->get_games()[i];
        }
    }
    std::cout << "lowest score : "<< low->get_total_points_of_game() << " game result :" << low->get_home_score() <<" - "<< low->get_out_score()<<std::endl;  
}


void League::statistic(int num){

    this->scoreboard(num);
    this->BestWS();
    this->BestLS();
    this->statisticScore();
    this->HighestScore();
    this->LowestScore();



}

