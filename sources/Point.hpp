#pragma once
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{
    class Point
    {
        /* fields - private by default: */
        double x;
        double y;

    public:
        /* constructor: */
        Point(double x, double y) : x(x), y(y) {}

        /* METHODS: */

        /* getters: */

        /*
        @return the x coordinate of the point
        */
        double getX();

        /*
        @return the y coordinate of the point
        */
        double getY();

        /*
        @return the distance between this point and other point.
        @param other is the other point.
        */
        double distance(Point other);

        /*
        this method prints the X ant Y coordinate of the point  in this formate: (x,y)
        */
        void print();

        /*
        this method accepts source point, destination point and a distance.
        @return the closest point to the destination point, which is at most the given distance from the source point.
        @param srcPoint is the source point
        @param destPoint is the destination point
        @param distance is the max distance that can be moved from the source point to the destination point.
        */
        static Point moveTowards(Point &srcPoint, Point &destPoint, double distance);
    };
}