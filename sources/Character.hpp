#pragma once
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {

    protected:
        string characterName;
        Point& location;
        int hitPoint;

    public:
        /* counstructor & destructor: */

        Character(string characterName, Point &location, int hitPoint) : characterName(characterName), location(location), hitPoint(hitPoint) {}
        virtual ~Character() = default;

        /* METHODS: */

        /* getters: */

        /*
        @return the character's name.
        */
        string getName();

        /*
        @return the character's location
        */
        Point& getLocation();

        /*
        @return the number of the character's hitpoints
        */
        int getHitPoints();

        /*
        @return true if the character is alive, and false otherwise.
        */
        bool isAlive();

        /*
        @return the distance between the two characters.
        @param other is the other character.
        */
        double distance(Character &other);

        /*
        this method subtracts the amount of hit points from the character.
        @param num is the number of points to substract.
        */
        void hit(int num);

        /*
        this method prints the name of the character, the number of its hit points, and the point where the character is.
        if the character is dead, the number of hit points will not be printed, and the character's name will appear in parentheses.
        Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy.
        */
        virtual string print() const = 0;
    };
}