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
    
    /* constructor & destructor: */
    Point(double x, double y) : x(x), y(y){}
    ~Point() = default;
    
    /* getters: */
    /*
    @return the x coordinate of the point
    */
    double getX();
    
    /*
    @return the y coordinate of the point
    */
    double getY();

    /*methods: */
    double distance (Point p);
    void print();
    static Point moveTowards (Point& srcPoint, Point& destPoint, double distance);










    };

    














}