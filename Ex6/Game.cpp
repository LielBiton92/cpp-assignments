#include "Game.hpp"

const int EXP_HOME = 70;
const int EXP_OUT = 65;
const int VAR = 5;
const int MAX_POINTS = 100;
const int MIN_HOME_POINTS = 55;
const int MIN_OUT_POINTS= 50;
const double MULT_TALENT = 10;

        Game::Game(Team *Home , Team *Out){
            this->OutTeam = Out;
            this->Home = Home;
            this->total_points_of_game = 0;
            this->homeScore = 0;
            this->outScore = 0;
            this->ScoreGame();

            
            
            
        }
        // Game::~Game(){}

        double Game::get_home_score()const{return this->homeScore;}
        double Game::get_out_score()const{return this->outScore;}
        int Game::get_total_points_of_game()const{return this->total_points_of_game;}

        void Game::ScoreGame(){
        std::random_device rd{};
        std::mt19937 gen{rd()};

        std::normal_distribution<> Homed{EXP_HOME, VAR};
        std::normal_distribution<> Outd{EXP_OUT, VAR};



        while(homeScore < MIN_HOME_POINTS || homeScore > MAX_POINTS){
            this->homeScore = (int)std::round(Homed(gen));
        }

        while(outScore < MIN_OUT_POINTS || outScore > MAX_POINTS){
            this->outScore = (int)std::round(Outd(gen));
        }

        // std::cout << this->OutTeam->get_talent()<<std::endl;

        int homebonus = (int)(MULT_TALENT*this->Home->get_talent());
        this->homeScore+=homebonus;
        if(this->homeScore > 100){
            this->homeScore = 100;
        }
        // std::cout << "home : "<<homeScore <<std::endl;

        int outbonus = (int)(MULT_TALENT * this->OutTeam->get_talent());
        this->outScore+=outbonus;
        if(this->outScore > 100){
            this->outScore = 100;
        }
        // std::cout << "Out : "<<outScore<<std::endl;

            this->total_points_of_game = homeScore+outScore;
        

            this->Home->add_to_total_points(homeScore);
            this->Home->add_to_points(outScore);
            this->OutTeam->add_to_total_points(outScore);
            this->OutTeam->add_to_points(homeScore);
            if(homeScore >= outScore){
                this->Home->increasewin();
                this->Home->increaseWS();
                this->OutTeam->increaseloss();
                this->OutTeam->increaseLS();
        }else{
                this->OutTeam->increasewin();
                this->OutTeam->increaseWS();
                this->Home->increaseloss();
                this->Home->increaseLS();
        }


        




        }