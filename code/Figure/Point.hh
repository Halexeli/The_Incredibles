#pragma once
#include <iostream>
#include "../Affichage/Screen.hh"


class Point
    {
    //Arguments:
    protected:
        int x;
        int y;
    public:
        Point():x(0),y(0){};
        Point(float x, float y):x(x),y(y){};
        Point(const Point& p):x(p.x),y(p.y){};
        ~Point(){};
//Affiche un point rouge
        void afficher(Screen &screen){screen.disc(x,y,0.5);};
    
        float getX(){return(x);};
        float getY(){return(y);};

        void setX(float x);
        void setY(float y);

        
        void operator=(const Point& p){x=p.x;y=p.y;};
        bool operator==(const Point& p){if(x==p.x&&y==p.y){return(1);}else{return(0);}};
};
