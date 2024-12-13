#include "Figure/Ellipse.hh"

int main(){
    Cercle c(Point(10,10),100);
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }    
    //sf::Cursor cursor;
    //if (cursor.loadFromSystem(sf::Cursor::Hand))
   //     window.setMouseCursor(cursor);

        c.afficher(shape);
        window.clear();
        window.draw(shape);
        window.display();
    }


    return 0;
}