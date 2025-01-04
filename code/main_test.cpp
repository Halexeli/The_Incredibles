#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"



int main() {
    Screen screen(960, 540); 
    //Page d'accueil
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
    Bouton *speedPlus = new Bouton(50, 350, 50, 50, ">");
    page += speedPlus;
    Bouton *speedMoins = new Bouton(50, 450, 50, 50, "<");
    page += speedMoins;
    //other half of the screen
    Bouton *resetSpeed = new Bouton(600, 50, 100, 50, "Reset Speed");
    page += resetSpeed;
    Bouton *stop = new Bouton(600, 150, 100, 50, "Stop");
    page += stop;
    Bouton *colorButton = new Bouton(600, 250, 100, 50, "Color");
    page += colorButton;
    Bouton *crayonPlus = new Bouton(600, 350, 50, 50, "pen+");
    page += crayonPlus;
    Bouton *crayonMoins = new Bouton(600, 450, 50, 50, "pen-");
    page += crayonMoins;


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

    delete spirographe;
    delete plusBouton;
    delete moinsBouton;
    delete resetBouton;
    delete speedPlus;
    delete speedMoins;
    delete resetSpeed;
    delete stop;

    return 0;
}

