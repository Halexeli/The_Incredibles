#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"
#include "Make_page.hh"



int main() {
    Screen screen(960, 540); 
    //Page d'accueil
    Page *page1;
    //spiro
    page1=Page1();
    page1->draw(screen);
    screen.render();
    return 0;
}

/*
    sf::Clock clock;
    float speed = 0.5f;
    //green pour bien commencer
    sf::Color currentCol= sf::Color::Green;
    //current size crayon

    std::srand(static_cast<unsigned int>(std::time(nullptr)));


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
        if (resetSpeed->Ispressed(screen)) {
            speed = 0.5f;
        }
        if (resetBouton->Ispressed(screen)) {
            spirographe->reset();
        }
        if ((speed < 0.0f) || (stop->Ispressed(screen))) {
            speed = 0.0f;
        }
        else{
            if (speedPlus->Ispressed(screen)) {
                speed += 0.001f; 
            }
            if ((speedMoins->Ispressed(screen))) {
                speed -= 0.001f;
            }
        }
        if (colorButton->Ispressed(screen)) {
            currentCol = sf::Color(
                std::rand() % 256, // Red
                std::rand() % 256, // Green
                std::rand() % 256  // Blue
            );
            spirographe->setColor(currentCol);
        }
        if (spirographe->getCrayonSize() < 0.0f) {
            spirographe->setCrayonSize(0.0f);
        }
        if (crayonPlus->Ispressed(screen)) {
            spirographe->setCrayonSize(spirographe->getCrayonSize() + 0.001);
        }

        if (crayonMoins->Ispressed(screen) && spirographe->getCrayonSize() > 0.0f) {
            spirographe->setCrayonSize(spirographe->getCrayonSize() - 0.001);
        }

        float deltaTime = clock.restart().asSeconds() * speed;
        spirographe->update(deltaTime);
        page.draw(screen);
        screen.render();
    }
*/