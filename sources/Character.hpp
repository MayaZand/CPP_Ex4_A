#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
    /* fields - private by default: */ 

    string characterName;
    Point& location;
    int hitPoint;


    public:
    /* counstructor: */

        Character(string characterName, Point& location, int hitPoint) : characterName(name), location(location), hitPoint(hitPoint) {}
        ~Character() = default;

    /* methods: */

    /*
    this method returns true if the character is alive, and false otherwise.
    @return true if the character is alive, and false otherwise.
    */
    bool isAlive();

    /*
    this method returns the distance between this character and other character.
    @param other is the other character.
    @return the distance between the two characters.
    */
    double distance(Character& other);

    /*
    this method subtracts the amount of hit points from the character.
    @param num is the number of points to substract.
    */
    void hit(int num);














    };
}