#pragma once
#include "Point.hh"
#include <iostream>

class Figure{
    protected :
        Point centre;
    public:
        Figure():centre(Point()){};
        Figure(const Point& p):centre(Point(p)){};
        Figure(const Figure& p):centre(p.centre){};
        ~Figure(){};
        virtual void afficher()=0;
};
