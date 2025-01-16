#pragma once
#include <iostream>


class Point{
    protected:
        float x;
        float y;
    public:
        Point():x(0),y(0){};
        Point(float _x, float _y):x(_x),y(_y){};
        Point(const Point& p):x(p.x),y(p.y){};
        ~Point(){};

        void afficher();
    
        float getX() const{return(x);};
        float getY() const{return(y);};

        void setX(float _x){x=_x;};
        void setY(float _y){y=_y;};

        
        void operator=(const Point& p){x=p.x;y=p.y;};
        bool operator==(const Point& p);
        void operator+=(const Point& p){x=x+p.x;y=y+p.y;}
};
