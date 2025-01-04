#pragma once
#include <iostream>


class Point{
    protected:
        float *x;
        float *y;
    public:
        Point();
        Point(float _x, float _y);
        Point(const Point& p);
        ~Point();

        void afficher();
    
        float getX() const;
        float getY() const;

        void setX(float _x);
        void setY(float _y);

        
        void operator=(const Point& p);
        bool operator==(const Point& p);
};
