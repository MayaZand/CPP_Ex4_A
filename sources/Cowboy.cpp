#include "Cowboy.hpp"

using namespace ariel;

int Cowboy::getNumOfBullets()
{
    return this->numOfBullets;
}

string Cowboy::print() const
{
    return "Cowboy";
}

bool Cowboy::hasBullets() const
{
    return false;
}

void Cowboy::shoot(Character* other)
{

}

void Cowboy::reload()
{

}