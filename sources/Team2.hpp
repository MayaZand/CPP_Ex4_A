#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
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