#include "Team.hpp"

Team::Team(std::string &name,  double talent)
{
    this->name = name;
    this->LS = 0;
    this->WS = 0;
    this->LongestWS = 0;
    this->LongestLS = 0;
    this->points = 0;
    this->totalpoints = 0;
    this->wins = 0;
    this->loss = 0;
    if(talent < 0){throw("talent cannot be positive");}
    this->talent = talent;
}
// Team::~Team() {
// }

unsigned int Team::get_Points()const { return this->points; }
std::string &Team::getname() { return this->name; }
unsigned int Team::get_total_points()const { return this->totalpoints; }
void Team::add_to_total_points(unsigned int score) { this->totalpoints += score; }
void Team::add_to_points(unsigned int score) { this->points += score; }
void Team::increaseWS()
{
    this->WS++;
    this->LS = 0;
    if(this->WS>=this->LongestWS){this->LongestWS = this->WS;}
}
void Team::increaseLS()
{
    this->LS++;
    this->WS = 0;
    if(this->LS>=this->LongestLS){this->LongestLS = this->LS;}
}
double Team::get_talent()const { return this->talent; }

unsigned int Team::get_wins()const { return this->wins; }
void Team::increasewin() { this->wins++; }
void Team::increaseloss() { this->loss++; }
void Team::print_stats()const
{
    std::cout << " Total wins " << this->wins << std::endl;
    std::cout << " Total loss " << this->loss << std::endl;
    std::cout << " Total points " << this->totalpoints << std::endl;
    std::cout << " Total own " << this->points << std::endl;
}

unsigned int Team::get_loss()const{return this->loss;}

bool Team::operator>(const Team &team1) const
{
    bool ans = false ;
    if(this->wins > team1.wins){
        ans = true;
    }
    return ans;
}

bool Team::operator==(const Team &team1)const{
        bool ans = false ;
    if(this->wins == team1.wins){
        ans = true;
    }
    return ans;
}
unsigned int Team::get_LongestWS()const{return this->LongestWS;}
unsigned int Team::get_LongestLS()const{return this->LongestLS;}

std::ostream& operator<<(std::ostream &out,  Team &t){
    out<< "Team name: "<< t.getname() <<" ,wins: "<< t.get_wins() << " ,loss: " << t.get_loss()<< " ,total points: "<< t.get_total_points() << " ,given points: "<< t.get_Points()  << " ,clean points: "<< (int)t.get_total_points()-(int)t.get_Points();
    return out;
}