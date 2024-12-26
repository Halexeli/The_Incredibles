#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Screen.hh"

class Bouton{
    //Pour créer un bouton et pouvoir l'afficher
    private:
    float x;
    float y;
    float w;
    float h;
    bool signe;
    std::string font_file;
    public:
    Bouton():x(0),y(0),w(2),h(1),signe(0),font_file("../../Assets/Times_New_Roman/times_new_roman.ttf"){};
    Bouton(float _x,float _y,float _w,float _h,bool _s):x(_x),y(_y),w(_w),h(_h),signe(_s),font_file("../../Assets/Times_New_Roman/times_new_roman.ttf"){};
    Bouton(const Bouton &p):x(p.x),y(p.y),w(p.w),h(p.h),signe(p.signe),font_file("../../Assets/Times_New_Roman/times_new_roman.ttf"){};
    ~Bouton(){};
    bool Ispressed(Screen &screen);
    void draw(Screen &screen);
};

class Texte{
    //Pour créer un texte et l'afficher
    private:
    float x;
    float y;
    int taille;
    std::string font_file;
    uint32_t color;
    std::string texte;
    public:
    Texte():x(0),y(0),taille(12),font_file("../../Assets/Times_New_Roman/times_new_roman.ttf"),color(0xFF0000FF),texte("pas de texte encore"){};
    Texte(float _x,float _y,int _taille=12,uint32_t _color=0xFF0000FF,std::string _texte="pas de texte encore",std::string _front="../../Assets/Times_New_Roman/times_new_roman.ttf")
    :x(_x),y(_y),taille(_taille),font_file(_front),color(_color),texte(_texte){};
    Texte(const Texte &p):x(p.x),y(p.y),taille(p.taille),font_file(p.font_file),color(p.color),texte(p.texte){};
    ~Texte(){};
    void draw(Screen &screen);
};