#pragma once
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

    protected:
        Character* leader;
        vector<Character*> warriors;

    public:
        /* constructor & destructor: */
        Team(Character* leader) : leader(leader), warriors(){};
        ~Team() = default;

        /* METHODS: */

        /* getters: */

        /*
        @return the size of the team (vector)
        */
        int getTeamSize();

        /*
        This method adds a cowboy or ninja to the group.
        @param newCharacter is the pointer to the character that is added to the group.
        */
        void add(Character* newCharacter);

        /*
        this method performs the attack between 2 groups.
        @param enemys is the pointer to the enemys Team.
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