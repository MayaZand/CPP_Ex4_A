#include "Character.hpp"

using namespace std;


namespace ariel
{

    class Cowboy : public Character
    {
        /* fields - private by default: */
        int numOfBullets = 6;

        /*constructor & destructor: */
        public:
        Cowboy(string name, Point& point) : Character(name, point, 110) {} 
        ~Cowboy() = default;

        /* override methods: */

        /*
        this method prints the name of the character, the number of its hit points, and the point where the character is.
        if the character is dead, the number of hit points will not be printed, and the character's name will appear in parentheses.
        Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy.
        */
        string print() const override;

        /* methods: */

        /* getters: */

        /*
        @return the cowboy's num of bullets
        */
        int getNumOfBullets();

        /*
        @return true if the cowboy's gun still has bullets, and false otherwise.
        */
        bool hasBullets() const;

        /*
        this method will subtract 10 hit points from the enemy if the cowboy is not dead and has bullets left,
        he shoots the enemy and loses 1 bullet. otherwise, no damage will be done to the enemy.
        */
        void shoot(Character* other);

        /*
        this method loads the gun with six new bullets.
        */
        void reload();
    };
}