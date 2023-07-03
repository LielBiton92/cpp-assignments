#include <string>
#include <vector>
#include <iostream>


class Team {
    private:
        std::string name;
        double talent;
        unsigned int totalpoints;
        unsigned int points;
        unsigned int WS;
        unsigned int LS;
        unsigned int wins;
        unsigned int loss;
        unsigned int LongestWS;
        unsigned int LongestLS;

    public:
        Team(std::string &name ,  double talent);
        // ~Team();
        unsigned int get_Points()const;
        std::string &getname();
        unsigned int get_total_points()const;
        void add_to_total_points(unsigned int score);
        void add_to_points(unsigned int score);
        void increaseWS();
        void increaseLS();
        double get_talent()const;
        unsigned int get_wins()const;
        unsigned int get_loss()const;
        void increasewin();
        void increaseloss();
        void print_stats()const;
        bool operator>(const Team &team1)const;
        bool operator==(const Team &team1)const;
        friend std::ostream& operator<<(std::ostream &out,  Team &t);
        unsigned int get_LongestWS()const;
        unsigned int get_LongestLS()const;
        


        

};