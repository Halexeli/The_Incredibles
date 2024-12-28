#pragma once
#include <iostream>


class Point{
    protected:
        int x;
        int y;
    public:
        Point():x(0),y(0){};
        Point(int x, int y):x(x),y(y){};
        Point(const Point& p):x(p.x),y(p.y){};
        ~Point(){};

        void afficher();
    
        int getX() const;
        int getY() const;

        void setX(int x);
        void setY(int y);

        
        void operator=(const Point& p);
        bool operator==(const Point& p);
};
