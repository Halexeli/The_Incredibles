#pragma once
#include <iostream>


class Point
    {
    //Arguments:
    protected:
        double x;
        double y;
    public:
        Point():x(0),y(0){};
        Point(double x, double y):x(x),y(y){};
        Point(const Point& p):x(p.x),y(p.y){};
        ~Point(){};
//Affiche un point rouge
//        void afficher(){}; //On include deja Point.hh dans Screen.hh jsp comment faire
    
        const double getX(){return(x);};
        const double getY(){return(y);};

        void setX(double _x){x=_x;};
        void setY(double _y){y=_y;};

        
        void operator=(const Point& p){x=p.x;y=p.y;};
        bool operator==(const Point& p){if(x==p.x&&y==p.y){return(1);}else{return(0);}};
};
