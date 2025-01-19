#include "Bouton.hh"
#include "SFML/Window.hpp"

bool Bouton::Ispressed(Screen &screen){
    return(screen.Buttonclicked(x,y,w,h));
}

void Bouton::draw(Screen &screen) {
    screen.rect(x, y, w, h, color); //RGB
    if (!label.empty()) {
        screen.draw(text);
    }
}

void Texte::draw(Screen &screen){
    screen.text(x,y,texte,taille,color,font_file);
}

void Texte::add(float x){
    float nb=std::stof(texte);
    nb+=x;
    texte=std::to_string(nb);
}

void Texte::setText(const std::string &x){
    texte=x;
    text.setString(texte);
}