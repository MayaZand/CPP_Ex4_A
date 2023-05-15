#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("create new point")
{
    CHECK_NOTHROW(Point(1,3));
    CHECK_NOTHROW(Point(1.1,2.2));
}

TEST_CASE("check the distance() method")
{
    Point p1(0,0), p2(2,0);
    CHECK(p1.distance(p2) == 2);
    CHECK(p2.distance(p1) == 2);
}

TEST_CASE("check the moveTowards() method")
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

TEST_CASE("check the isAlive() method")
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
                                    // while (n1.isAlive())
                                    // {
                                    //     n1.slash(&c);
                                    // }
    
    CHECK(c.isAlive() == false);
    CHECK(n1.isAlive() == true);

                                    // after fighting, n2 is alive and n3 is dead
                                    // while (n2.isAlive())
                                    // {
                                    //     n2.slash(&n3);
                                    // }

    CHECK(n3.isAlive() == false);
    CHECK(n2.isAlive() == true);
}

TEST_CASE("check the distance() between two characters method")
{
    Point NinjaPoint (0,0);
    OldNinja on ("oldNinja", NinjaPoint);
    Point CowboyPoint (0,2);
    Cowboy cb ("Cowboy", CowboyPoint);

    CHECK(on.distance(cb) == 2); 
}

TEST_CASE("check the hit() method")
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

TEST_CASE("check shoot() method")
{
    // if the cowboy is not dead and still have bullets:
    Point point (0,0);
    OldNinja on ("oldNinja", point);
    Cowboy cb1 ("Cowboy1", point);
    Cowboy cb2 ("Cowboy2", point);

    cb1.shoot(&on);
    cb1.shoot(&cb2);

    CHECK(on.getHitPoints() == 140); // 150 hit points -10 hit points after being shot
    CHECK(cb1.getNumOfBullets() == 5); 
    CHECK(cb1.getNumOfBullets() == 4);
    CHECK(cb2.getHitPoints() == 100); // 110 hit points -10 hit points after being shot

    // if the cowboy is not dead and doesnt have bullets:
    Point point2 (0,0);
    OldNinja on2 ("oldNinja", point);
    Cowboy cb3 ("Cowboy3", point);
    Cowboy cb4 ("Cowboy4", point);

    for (int i=0; i<6; i++)
    {
        cb1.shoot(&on); 
    }
    
    CHECK(on.getHitPoints() == 90); // -10 hitPoints * 6 shootings ---> 150 hitPoints - 60 = 90
    CHECK(cb1.getNumOfBullets() == 0);

    cb1.shoot(&on); // at this point, the cowboy ran out of bullets so the number of the ninja's hit points should stay the same.
    
    CHECK(on.getHitPoints() == 90);
}

TEST_CASE("check the hasBullets() method")
{
    Point point (0,0);
    Cowboy cb1 ("Cowboy1", point);
    Cowboy cb2 ("Cowboy2", point);

    // once a cowboy is created he should have bullets
    CHECK(cb1.hasBullets() == true);
    CHECK(cb2.hasBullets() == true);

    // after the cowboy shoots 6 times he runs out of bullets
    for (int i=0; i<6; i++)
    {
        cb1.shoot(&cb2);
    }
    
    CHECK(cb1.hasBullets() == false);
    CHECK(cb1.getNumOfBullets() == 0);
}

TEST_CASE("check the reload() method")
{
    Point point (0,0);
    Cowboy cb1 ("Cowboy1", point);
    Cowboy cb2 ("Cowboy2", point);

    // after the cowboy shoots 6 times he runs out of bullets
    for (int i=0; i<6; i++)
    {
        cb1.shoot(&cb2);
    }
    cb1.reload();

    CHECK(cb1.hasBullets() == true);
    CHECK(cb1.getNumOfBullets() == true);
}

TEST_CASE("check the move() method")
{
    Point ninjaPoint(0,0), cowboyPoint(8,8);
    YoungNinja yn ("YoungNinja", ninjaPoint);
    Cowboy* cb = new Cowboy("Cowboy3", cowboyPoint);

    yn.move(cb);

    // save the new point after calling move() method: 
    Point destPoint = yn.getLocation(); 

    CHECK((ninjaPoint.distance(destPoint) == yn.getSpeed()));

}

TEST_CASE("check the slash() method")
{
    // if the enemy is less than 1 meter away:
    Point point (0,0);
    OldNinja on ("oldNinja", point);
    YoungNinja yn ("YoungNinja", point);
    Cowboy cb ("Cowboy", point);

    on.slash(&yn);
    on.slash(&cb);

    CHECK(yn.getHitPoints() == 60);
    CHECK(cb.getHitPoints() == 70);

    // if the enemy is more than 1 meter away - no damage is done:
    Point point2 (100,100);
    OldNinja on2 ("oldNinja", point);
    YoungNinja yn2 ("YoungNinja", point2);
    Cowboy cb2 ("Cowboy", point2);

    on2.slash(&yn2);
    on2.slash(&cb2);

    CHECK(yn.getHitPoints() == 100);
    CHECK(cb.getHitPoints() == 110);
}

TEST_CASE("check the expected conditions in each of all character type constructors") 
{
    Point point (100,100);
    OldNinja on ("oldNinja", point); // suppose to be with 150 HP and speed=8
    YoungNinja yn ("YoungNinja", point); // suppose to be with 100 HP and speed=14
    TrainedNinja tn ("TrainedNinja", point); // suppose to be with 120 HP and speed=12
    Cowboy cb ("Cowboy", point); // suppose to be with 110 HP and 6 bullets

    CHECK(on.getHitPoints() == 150);
    CHECK(yn.getHitPoints() == 100);
    CHECK(tn.getHitPoints() == 120);
    CHECK(on.getSpeed() == 8);
    CHECK(yn.getSpeed() == 14);
    CHECK(tn.getSpeed() == 12);
    CHECK(cb.getNumOfBullets() == 6);
    CHECK(cb.getHitPoints() == 110);
}

TEST_CASE("check the add() method") 
{
    Point point (0,0);
    Cowboy *cowboy1 = new Cowboy("cowboy1", point);
    Cowboy *cowboy2 = new Cowboy("cowboy2", point);
    OldNinja* oldNinja = new OldNinja("oldNinja",point);
    YoungNinja* youngNinja = new YoungNinja("youngNinja",point);
    TrainedNinja* trainedNinja = new TrainedNinja("trainedNinja",point);

    // create new Teams
    Team team1(cowboy1);
    Team2 team2(cowboy2);
    SmartTeam team3(youngNinja);

    // add warriors to the team
    team1.add(oldNinja);
    team1.add(trainedNinja);
    team2.add(youngNinja);

    CHECK(team1.getTeamSize() == 3);
    CHECK(team2.getTeamSize() == 2);
    CHECK(team3.getTeamSize() == 1);
}

TEST_CASE("check the attack() method")
{
    Point point1 (1,1), point2(2,2), point3(3,3), point4(4,4), point5(5,5), point6(6,6);
    Point point7(7,7), point8(8,8), point9(9,9), point10(10,10), point11(11,11);

    Cowboy *cowboy1 = new Cowboy("cowboy1", point1);
    Cowboy *cowboy2 = new Cowboy("cowboy2", point2);
    Cowboy *cowboy3 = new Cowboy("cowboy3", point3);
    Cowboy *cowboy4 = new Cowboy("cowboy4", point4);
    Cowboy *cowboy5 = new Cowboy("cowboy5", point5);
    OldNinja* oldNinja1 = new OldNinja("oldNinja1",point6);
    OldNinja* oldNinja2 = new OldNinja("oldNinja2",point7);
    YoungNinja* youngNinja1 = new YoungNinja("youngNinja1",point8);
    YoungNinja* youngNinja2= new YoungNinja("youngNinja2",point9);
    TrainedNinja* trainedNinja1 = new TrainedNinja("trainedNinja1",point10);
    TrainedNinja* trainedNinja2 = new TrainedNinja("trainedNinja2",point11);

    // create new Teams
    Team team1(cowboy1);
    Team2 team2(oldNinja1);

    // add warriors to the team1 and team2
    team1.add(cowboy2);
    team1.add(cowboy3);
    team1.add(youngNinja1);
    team1.add(trainedNinja1);
    
    team2.add(cowboy4);
    team2.add(cowboy5);
    team2.add(oldNinja2);
    team2.add(youngNinja2);
    team2.add(trainedNinja2);

    while (team1.stillAlive())
    {
        team1.attack(&team2);
    }

    CHECK(team2.stillAlive() == 0);

}