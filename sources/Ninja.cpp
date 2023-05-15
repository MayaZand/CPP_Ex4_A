#include "Ninja.hpp"

using namespace ariel;

int Ninja::getSpeed()
{
    return this->speed;
}

string Ninja::print() const
{
    return "Ninja";
}

void Ninja::move(Character* enemy)
{
   this->location = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
}

void Ninja::slash(const Character* enemy)
{

}


