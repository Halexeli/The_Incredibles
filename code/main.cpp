#include <iostream>
#include "Screen.hh"
#include "Page.hh"
#include "Bouton.hh"

int main()
{
    Screen screen(500,750);
    Page page1;
    page1+=new Bouton(100,100,50,20,0);
    page1+=new Texte(200, 100, 12, 0xFF0000FF, "test");
    page1+=new Polyedre_regulier();
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

    return 0;
}