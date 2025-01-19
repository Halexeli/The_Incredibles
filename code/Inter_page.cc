#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

int inter_in(Page *current, Spirographe *spirographes, Screen &screen, float &speed) {
    static int sommetCount = 4;
    static bool lastPlusPressed = false; //pour pas changer nbr sommets trop vite
    static bool lastMinusPressed = false;

    if (current->get_Bouton(1)->Ispressed(screen))
        return 1;

    if (current->get_Bouton(2)->Ispressed(screen)) {
        if (!lastPlusPressed && sommetCount < 5) {
            sommetCount++;
            spirographes->setSommets(sommetCount);
            current->get_String(0)->setText(std::to_string(sommetCount));
            lastPlusPressed = true;
        }
    } else {
        lastPlusPressed = false;
    }
    if (current->get_Bouton(3)->Ispressed(screen)) {
        if (!lastMinusPressed && sommetCount > 3) { 
            sommetCount--;
            spirographes->setSommets(sommetCount);
            current->get_String(0)->setText(std::to_string(sommetCount));
            lastMinusPressed = true; 
        }
    } else {
        lastMinusPressed = false;
    }
    if (current->get_Bouton(4)->Ispressed(screen)) {
        spirographes->deplacerx(0.5);
        spirographes->clear_crayon();
        current->get_String(2)->add(0.5);
    } else if (current->get_Bouton(5)->Ispressed(screen)) {
        spirographes->deplacerx(-0.5);
        spirographes->clear_crayon();
        current->get_String(2)->add(-0.5);
    } else if (current->get_Bouton(6)->Ispressed(screen)) {
        spirographes->deplacery(0.5);
        spirographes->clear_crayon();
        current->get_String(3)->add(0.5);
    } else if (current->get_Bouton(7)->Ispressed(screen)) {
        spirographes->deplacery(-0.5);
        spirographes->clear_crayon();
        current->get_String(3)->add(-0.5);
    } else if (current->get_Bouton(8)->Ispressed(screen)) {
        spirographes->aug_taille(0.5);
        spirographes->clear_crayon();
        current->get_String(4)->add(0.5);
    } else if (current->get_Bouton(9)->Ispressed(screen)) {
        spirographes->aug_taille(-0.5);
        spirographes->clear_crayon();
        current->get_String(4)->add(-0.5);
    } else if (current->get_Bouton(10)->Ispressed(screen)) {
        spirographes->aug_crayon(0.001);
        spirographes->clear_crayon();
        current->get_String(6)->add(0.001);
    } else if (current->get_Bouton(11)->Ispressed(screen)) {
        spirographes->aug_crayon(-0.001);
        spirographes->clear_crayon();
        current->get_String(6)->add(-0.001);
    } else if (current->get_Bouton(13)->Ispressed(screen)) { // Speed +
        speed += 0.1f;
    } else if (current->get_Bouton(14)->Ispressed(screen)) { // Speed -
        speed = std::max(0.1f, speed - 0.1f); 
    }

    return 0;
}

int inter3(Page *current, Spirographe *spirographe, Screen &screen) {
    return 0;
}

void inter(Page *&current, Page *page1, Page *page2, Page *page3, std::vector<Spirographe*>& spirographes, Screen &screen, float &speed) {
    if (current->get_id() == 0) {
        if (page1->get_Bouton(0)->Ispressed(screen)) {
            current = page2;
            spirographes.push_back(new Spirographe(100.f, 20.f, 0.3f));
        }
    } else if (current->get_id() == 1) {
        if (inter_in(current, spirographes.back(), screen, speed))
            current = page3;
        if (page2->get_Bouton(12)->Ispressed(screen))
            current = page1;
    } else if (current->get_id() == 2) {
        if (inter_in(current, nullptr, screen, speed))
            current = page1;
    }
}