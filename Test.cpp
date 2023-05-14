#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("create new point")
{
    CHECK_NOTHROW(Point(1,3));
    CHECK_NOTHROW(Point(1.1,2.2));
}

TEST_CASE("check distance method")
{
    Point p1(0,0), p2(2,0);
    CHECK(p1.distance(p2) == 2);
    CHECK(p2.distance(p1) == 2);
}

TEST_CASE("check moveTowards method")
{
    Point srcPoint1(0,0), destPoint1(8,0);
    Point finalDest(Point::moveTowards(srcPoint1, destPoint1, 3));
    CHECK(finalDest.getX() == 3);
    CHECK(finalDest.getY() == 0);
    
    Point srcPoint2(0,0), destPoint2(0,2);
    Point finalDest2(Point::moveTowards(srcPoint2, destPoint2, 3));
    CHECK(finalDest2.getX() == 0);
    CHECK(finalDest2.getY() == 2);

    Point srcPoint3(0,0), destPoint3(0,0);
    Point finalDest3(Point::moveTowards(srcPoint3, destPoint3, 10));
    CHECK(finalDest3.getX() == 0);
    CHECK(finalDest3.getY() == 0);

    // if the distance is 0 - should return the srcPoint
    Point srcPoint4(0,0), destPoint4(10,35);
    Point finalDest4(Point::moveTowards(srcPoint4, destPoint4, 0));
    CHECK(finalDest4.getX() == 0);
    CHECK(finalDest4.getY() == 0);
}

TEST_CASE("check isAlive method in Ninja and cowboy class")
{
    Point a(0,0);
    Cowboy c ("cowboy1", a);
    OldNinja n1 ("oldNinja", a);
    YoungNinja n2 ("YoungNinja", a);
    TrainedNinja n3 ("TrainedNinja", a);

    // after creating characters they suppose to be alive
    CHECK(c.isAlive() == true);
    CHECK(n1.isAlive() == true);
    CHECK(n2.isAlive() == true);
    CHECK(n3.isAlive() == true);

    // after fighting, n1 is alive and c is dead
    while (n1.isAlive())
    {
        n1.slash(&c);
    }
    
    CHECK(c.isAlive() == false);
    CHECK(n1.isAlive() == true);

    // after fighting, n2 is alive and n3 is dead
    while (n2.isAlive())
    {
        n2.slash(&n3);
    }

    CHECK(n3.isAlive() == false);
    CHECK(n2.isAlive() == true);
}

TEST_CASE("check the distance between two characters")
{
    Point NinjaPoint (0,0);
    OldNinja on ("oldNinja", NinjaPoint);
    Point CowboyPoint (0,2);
    Cowboy cb ("Cowboy", CowboyPoint);

    CHECK(on.distance(cb) == 2); 
}

TEST_CASE("check the hit method")
{
    Point point (0,0);
    OldNinja on ("oldNinja", point);
    YoungNinja yn ("YoungNinja",point);
    TrainedNinja tn ("TrainedNinja", point);
    Cowboy cb ("Cowboy", point);

    on.hit(50);
    yn.hit(10);
    tn.hit(20);
    cb.hit(10);
    
    CHECK(on.getHitPoints() == 100);
    CHECK(yn.getHitPoints() == 90);
    CHECK(tn.getHitPoints() == 100);
    CHECK(cb.getHitPoints() == 100);

    on.hit(0);
    yn.hit(0);
    tn.hit(0);
    cb.hit(0);

    CHECK(on.getHitPoints() == 100);
    CHECK(yn.getHitPoints() == 90);
    CHECK(tn.getHitPoints() == 100);
    CHECK(cb.getHitPoints() == 100);
}

TEST_CASE("check the getName() method")
{
    Point point (0,0);
    OldNinja on ("oldNinja", point);
    YoungNinja yn ("YoungNinja",point);
    TrainedNinja tn ("TrainedNinja", point);
    Cowboy cb ("Cowboy", point);

    CHECK(on.getName() == "oldNinja");
    CHECK(yn.getName() == "YoungNinja");
    CHECK(tn.getName() == "TrainedNinja");
    CHECK(cb.getName() == "Cowboy");
}

TEST_CASE("check the getLocation() method")
{
    Point point (0,0);
    OldNinja on ("oldNinja", point);
    YoungNinja yn ("YoungNinja",point);
    TrainedNinja tn ("TrainedNinja", point);
    Cowboy cb ("Cowboy", point);

    CHECK(on.getLocation().getX() == 0);
    CHECK(on.getLocation().getY() == 0);
    CHECK(yn.getLocation().getX() == 0);
    CHECK(yn.getLocation().getY() == 0);
    CHECK(tn.getLocation().getX() == 0);
    CHECK(tn.getLocation().getY() == 0);
    CHECK(cb.getLocation().getX() == 0);
    CHECK(cb.getLocation().getY() == 0);
}

TEST_CASE("check shoot method")
{
    Point point (0,0);
    OldNinja on ("oldNinja", point);
    Cowboy cb1 ("Cowboy1", point);
    Cowboy cb2 ("Cowboy2", point);

    cb1.shoot(&on);
    cb1.shoot(&cb2);

    CHECK(on.getHitPoints() == 140);
    CHECK(cb1.getNumOfBullets() == 5);
    CHECK(cb1.getNumOfBullets() == 4);
    CHECK(cb2.getHitPoints() == 110);
}