#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"


int main() {
    Screen screen(800, 600); 

    Page page;
    //spiro
    Spirographe *spirographe = new Spirographe(200.f, 30.f, 0.3f); 
    page += spirographe;
    //boutons
    Bouton *plusBouton = new Bouton(50, 50, 50, 50, "+");
    page += plusBouton;
    Bouton *moinsBouton = new Bouton(50, 150, 50, 50, "-");
    page += moinsBouton;
    Bouton *resetBouton = new Bouton(50, 250, 100, 50, "Reset");
    page += resetBouton;

    sf::Clock clock;

    while (screen.isOpen()) {
        sf::Event event;
        while (screen.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                screen.close();
            }
        }

        if (plusBouton->Ispressed(screen)) {
            spirographe->setR(spirographe->getR() + 0.1);
        }

        if (moinsBouton->Ispressed(screen)) {
            spirographe->setR(spirographe->getR() - 0.1);
        }
        if (resetBouton->Ispressed(screen)) {
            spirographe->reset();
        }

        float deltaTime = clock.restart().asSeconds();
        spirographe->update(deltaTime);

        page.draw(screen);
        screen.render();
    }

    delete spirographe;
    delete plusBouton;
    delete moinsBouton;
    delete resetBouton;

    return 0;
}
