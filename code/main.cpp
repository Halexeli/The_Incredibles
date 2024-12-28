#include <SFML/Graphics.hpp>
#include "Spirographe/Spirographe.hh"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Spirographe with circles");

    float R = 200.f; 
    float r = 57.f; 
    float l = 0.9f;
    Spirographe spirographe(R, r, l);
    //horloge pour mesurer le temps
    sf::Clock clock;
    //game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //deltaTime: temps écoulé depuis la dernière frame
        //on multiplie par 2 pour accélérer le mouvement
        float deltaTime = clock.restart().asSeconds() * 2;

        //ceci permet de mettre à jour la position du crayon
        //comme ça on peut le dessiner en temps réel
        spirographe.update(deltaTime);
        //clear car on veut dessiner le spirographe à chaque frame i.E progressivement 
        
        window.clear();
        spirographe.draw(window);
        window.display();
    }

    return 0;
}
