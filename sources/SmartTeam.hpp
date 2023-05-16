#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    
    public:
        /* constructor: */
        SmartTeam(Character *leader) : Team(leader){};

        /* METHODS: */

        /*
        this method performs the attack between 2 groups.
        @param enemys is the pointer to the other team.
        */
        void attack(Team* enemys) override;

        /*
        this method prints all details of the group members.
        */
        virtual void print() override;
    };
}