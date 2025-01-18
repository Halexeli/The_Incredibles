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
   
    std::string label;
    std::string font_file;
    uint32_t color;
    sf::Font font;
    sf::Text text;
    public:
    Bouton() : x(0), y(0), w(2), h(1), font_file("../Assets/Times_New_Roman/times_new_roman.ttf"),color(0x1A1A77FF) {
        if (!font.loadFromFile(font_file)) {
            std::cerr << "Fail load font: " << font_file << std::endl;
        }
        text.setFont(font);
    }
    //ajout constructeur pour bouton avec texte
    Bouton(float _x, float _y, float _w, float _h, const std::string& _label, uint32_t _color=0x1A1A77FF) : x(_x), y(_y), w(_w), h(_h), label(_label), font_file("../Assets/Times_New_Roman/times_new_roman.ttf"),color(_color) {
        if (!font.loadFromFile(font_file)) {
            std::cerr << "Failed to load font: " << font_file << std::endl;
        }
        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(h/2.0f);
        text.setFillColor(sf::Color(0xFFFFFFFF)); 
        sf::FloatRect textRect = text.getLocalBounds(); //centrer le texte dans le bouton
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(x + w / 2.0f, y + h / 2.0f);
    }

    Bouton(const Bouton &p) : x(p.x), y(p.y), w(p.w), h(p.h), label(p.label), font_file(p.font_file),color(p.color) {
        if (!font.loadFromFile(font_file)) {
            std::cerr << "Fail load font: " << font_file << std::endl;
        }
        text.setFont(font);
    }
    ~Bouton(){};
    void print(){std::cout<<"Bouton "<<label<<std::endl;};
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
        sf::Font font;
        sf::Text text;
    public:

        Texte() : x(0), y(0), taille(12), font_file("../Assets/Times_New_Roman/times_new_roman.ttf"), color(0x1A1A77FF), texte("pas de texte encore") {
            if (!font.loadFromFile(font_file)) {
                std::cerr << "Failed to load font: " << font_file << std::endl;
            }
            text.setFont(font);
        }

        Texte(float _x, float _y, int _taille = 12, uint32_t _color = 0x1A1A77FF, std::string _texte = "pas de texte encore", std::string _front = "../Assets/Times_New_Roman/times_new_roman.ttf")
            : x(_x), y(_y), taille(_taille), font_file(_front), color(_color), texte(_texte) {
            if (!font.loadFromFile(font_file)) {
                std::cerr << "Failed to load font: " << font_file << std::endl;
            }
            text.setFont(font);
        }

        Texte(const Texte &p) : x(p.x), y(p.y), taille(p.taille), font_file(p.font_file), color(p.color), texte(p.texte) {
            if (!font.loadFromFile(font_file)) {
                std::cerr << "Failed to load font: " << font_file << std::endl;
            }
            text.setFont(font);
        }
    ~Texte(){};
    void draw(Screen &screen);
    void add(float x);
    void set(std::string val){texte=val;};
};