#pragma once
#include <iostream>
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

    /*methods: */
    double distance (Point p);
    void print();
    Point moveTowards (Point& srcPoint, Point& destPoint, double distance);










    };

    














}