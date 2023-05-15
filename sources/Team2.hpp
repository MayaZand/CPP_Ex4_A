#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
        public:
        /* constructor & destructor: */
        Team2(Character* leader) : Team(leader) {};
        ~Team2() = default;
        
        /*
        this method performs the attack between 2 groups.
        */
        void attack(Team* enemys) override;

        /*
        this method prints all details of the group members. 
        */
        virtual void print() override;

    };
}