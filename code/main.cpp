#include <iostream>
#include "Affichage/Screen.hh"
#include "Affichage/Page.hh"
#include "Affichage/Bouton.hh"

int main()
{
    Screen screen(500,750);
    Page page1;
    Bouton* B1=new Bouton(100,100,50,20,0);
    Texte *T1=new Texte(200, 100, 12, 0xFF0000FF, "test");
    Polyedre_regulier *P1=new Polyedre_regulier();
    page1+=B1;
    page1+=T1;
    page1+=P1;
    // run the program as long as the window is open
    while (screen.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (screen.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            screen.close();
        }
        page1.draw(screen);
        screen.render();
    }
    delete(B1);
    delete(T1);
    delete(P1);

    return 0;
}