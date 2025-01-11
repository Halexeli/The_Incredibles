#include "Page.hh"

int Page::it=0;

void Page::draw(Screen &screen) {
    for (auto it : Formes_r) {
        it->afficher(screen);
    }
    for (auto it : Spiro) {
        it->draw(screen);
    }
    for(auto it : Fond) {
        it->afficher(screen);
    }
    for (auto it : List_Bouton) {
        it->draw(screen);
    }
    for (auto it : List_string) {
        it->draw(screen);
    }
}

void Page::creer_fond(std::vector <Polyedre_irregulier*> _Fond){
    for(auto it:_Fond)
        Fond.push_back(it);
}