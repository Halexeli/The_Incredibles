#pragma once
#include "Point.hh"
#include <iostream>

class Figure{
    protected :
        Point centre;
    public:
        Figure();
        Figure(const Point& p);
        Figure(const Figure& p);
        ~Figure();
        virtual void afficher()=0;
};
