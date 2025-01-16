#include "Page.hh"

int Page::it=0;


void Page::draw(Screen &screen) {
    for (auto it : List_Bouton) {
        it->draw(screen);
    }
    for (auto it : List_string) {
        it->draw(screen);
    }
}
