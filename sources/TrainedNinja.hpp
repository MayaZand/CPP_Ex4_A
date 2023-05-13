#include "Ninja.hpp"

using namespace std;

namespace ariel
{

    class TrainedNinja : public Ninja
    {
        /*constructor & destructor: */
        public:
        
        TrainedNinja(string name ,Point location) : Ninja(name, location, 120, 12) {}
        ~TrainedNinja() = default;

        /*
        this method prints the name of the character, the number of its hit points, and the point where the character is.
        if the character is dead, the number of hit points will not be printed, and the character's name will appear in parentheses.
        Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy.
        */
        string print() const override;

    };
}