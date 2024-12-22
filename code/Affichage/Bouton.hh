#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Bouton{
    private:
    float x;
    float y;
    float w;
    float h;
    bool signe;
    public:
    Bouton():x(0),y(0),w(2),h(1),signe(0){};
    Bouton(float _x,float _y,float _w,float _h,bool _s):x(_x),y(_y),w(_w),h(_h),signe(_s){};
    Bouton(const Bouton &p):x(p.x),y(p.y),w(p.w),h(p.h),signe(p.signe){};
    ~Bouton(){};
    bool Ispressed();
    void draw();
};