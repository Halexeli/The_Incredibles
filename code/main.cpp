#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"
#include "Make_page.hh"
#include "Inter_page.hh"




int main() {
    //Page d'accueil
    Screen screen(960, 540); 
    Page *page1,*page2,*current;
    page1=Page1();
    page2=Page2();
    current=page1;
    //spirographes
    std::vector<Spirographe*> spirographes;
    sf::Clock clock;
    float speed = 2.0f;
    //fenetre
    while(screen.isOpen()){
        sf::Event event;
        while (screen.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                //fermer la fenetre
                screen.close();
            }
            if(event.type==sf::Event::Resized){
                //pour que les boutons continuent de fonctionner
                sf::Vector2u taille=screen.getSize();
                screen.resized_screen(taille.x,taille.y);
            }
            if(event.type==sf::Event::MouseButtonPressed){
                //si on appuie sur un bouton, on change quelque chose
                inter(current,page1,page2,spirographes,screen);
            }
        }
        //update les spirographes
        float deltaTime = clock.restart().asSeconds() * speed;
        for(auto it:spirographes){
            it->update(deltaTime);
            it->draw(screen);
        }
        current->draw(screen);
        screen.render();
    }
    //delete les new
    for(auto it:spirographes){
            delete it;
        }
    del_page(page1);
    del_page(page2);
    return 0;
}