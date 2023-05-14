#include "Point.hpp"

using namespace ariel;

double Point:: distance (Point p)
{
    return 1.0;
}

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

void Point:: print()
{
    
}

Point Point:: moveTowards (Point& srcPoint, Point& destPoint, double distance)
{
    // calculate the distance between the two points
    double distance_x = destPoint.getX() - srcPoint.getX();
    double distance_y = destPoint.getY() - srcPoint.getY();
    double distanceBetween = sqrt((distance_x*distance_x) + (distance_y*distance_y));

    // find the closest Point to srcPoint
    if (distanceBetween <= distance)
    {
        return destPoint;
    }
    else
    {
        double ratio = distance / distanceBetween;
        double newX = srcPoint.getX() + (destPoint.getX() - srcPoint.getX())*ratio;
        double newY = srcPoint.getY() + (destPoint.getY() - srcPoint.getY())*ratio;

        Point closestPoint (newX, newY);
        return closestPoint;
    }
}
