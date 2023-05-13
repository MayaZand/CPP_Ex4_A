#include <iostream>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "vector"

using namespace std;

namespace ariel
{

    class Team
    {

        /* fields - private by default: */
        Character* leader;
        vector <Character*> warriors;

        public:
        /* constructor & destructor: */
        Team(Character* leader) : leader(leader), warriors() {};
        ~Team() = default;

        /* methods: */
 
        /*
        This method adds a cowboy or ninja to the group.
        */
        void add(Character* newCharacter);

        /*
        this method performs the attack between 2 groups.
        */
        virtual void attack(Team* enemys);

        /*
        @return the number of warriors in the group that are still alive.
        */
        int stillAlive();

        /*
        this method prints all details of the group members. 
        */
        virtual void print();














    };

}