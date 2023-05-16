#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    
    public:
        /* constructor: */
        Team2(Character *leader) : Team(leader){};

        /* METHODS: */

        /* override methods: */

        /*
        this method performs the attack between 2 groups.
        @param enemys is the pointer to the enemys Team.
        */
        void attack(Team *enemys) override;

        /*
        this method prints all details of the group members.
        */
        virtual void print() override;
    };
}