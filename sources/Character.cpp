#include "Character.hpp"

using namespace ariel;

bool Character::isAlive()
{
    return true;
}

double Character::distance(Character& other)
{
    return 1.1;
}

void Character::hit(int num)
{

}

string Character::getName()
{
    return this->characterName;
}

Point& Character::getLocation()
{
    return this->location;
}

int Character::getHitPoints()
{
    return this->hitPoint;
}
